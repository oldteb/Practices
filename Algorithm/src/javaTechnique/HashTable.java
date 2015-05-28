package javaTechnique;

import java.util.concurrent.SynchronousQueue;

public class HashTable<K,V>{
	private int capacity = 256;
	private float load_factor = 0.75f;
	private int threshold = 192;
	
	private int size = 0;
	
	private Entry[] buckets;
	
	public HashTable(){
		buckets = new Entry[capacity];  // can't create generics array...
	}
	
	public HashTable(int initial_capacity, float load_factor){
		this.capacity = initial_capacity;
		this.load_factor = load_factor;
		this.threshold = (int)((float)initial_capacity * load_factor);
		buckets = new Entry[initial_capacity];
	}
	
	private int hashToBucket(int hashCode, int capacity){
		return (hashCode & 0x7fffffff) % capacity;  // use table.length instead of init_capa
	}
	
	public synchronized V put(K key, V value){    // make operation thread safe.
		int idx = hashToBucket(key.hashCode(), capacity);
		for(Entry<K,V> entry = buckets[idx]; entry != null; entry = entry.next){
			if(entry.hash == key.hashCode() && 
				(entry.key == key || entry.key.equals(key))){      // very important!!
				V oldValue = entry.value;
				entry.value = value;
				return oldValue;
			}
		}
		Entry<K,V> newEntry = new Entry<K,V>(key,value,key.hashCode());
		newEntry.next = buckets[idx];
		buckets[idx] = newEntry;
		this.size++;
		
		// chack the need to expand table
		if(size > threshold)  rehash();

		return null;
	}
	
	
	public V get(K key){
		int idx = hashToBucket(key.hashCode(),capacity);
		for(Entry<K,V> entry = buckets[idx]; entry != null; entry = entry.next){
			if(entry.hash == key.hashCode() && 
				(entry.key == key || entry.key.equals(key))){      // very important!!
				return entry.value;
			}
		}
		return null;
	}
	
	private void rehash(){  // no need to be synchronized, since it is inside the put()
		int oldCapacity = capacity;
		capacity = 2 * capacity + 1;
		threshold = (int)((float)capacity * load_factor);
		Entry<K,V>[] newbuckets = new Entry[capacity];
		for(int idx = 0; idx < oldCapacity; idx++){
			Entry<K,V> nextEntry;
			for(Entry<K,V> entry = buckets[idx]; entry != null; entry = nextEntry){
				nextEntry = entry.next;
				int newidx = hashToBucket(entry.hash, capacity);
				entry.next = newbuckets[newidx];
				newbuckets[newidx] = entry;
			}
		}
		buckets = newbuckets;
	}
	
	

}

class Entry<K,V>{
	K key;
	V value;
	int hash;
	Entry<K,V> next;
	
	Entry(K key, V value, int hash){
		this.key = key;
		this.value = value;
		this.hash = hash;
	}
	
	
}
