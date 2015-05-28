package operatingSystem.ProducerConsumerProblem;

public class Bucket {

	private int count = 0;
	private int[] buf;
	
	Bucket(int size){
		buf = new int[size];
	}
	
	synchronized void put(int i) throws InterruptedException{
		while(count >= buf.length){
			wait();
		}
		buf[count++] = i;
		System.out.println("item " + i + " added.");
		notifyAll();
	}
	
	synchronized int get() throws InterruptedException{
		while(count <= 0){
			wait();
		}
		int temp = buf[count-1];
		buf[count-1] = 0;
		count--;
		System.out.println("item " + temp + " removed.");
		notifyAll();
		return temp;
	}
	
}
