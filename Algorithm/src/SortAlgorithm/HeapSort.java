package SortAlgorithm;

public class HeapSort {
	
	private int size;
	
	void sort(int[] buf){
		size = buf.length;
		buildHeap(buf);
		while(size > 1){	
			int temp = buf[0];
			buf[0] = buf[size-1];
			buf[size-1] = temp;
			size--;
			heapify(buf,0);
		}
	}
	
	void buildHeap(int[] buf){
		for(int i = buf.length/2-1; i >= 0; i--){
			heapify(buf,i);
		}
	}
	
	void heapify(int[] buf, int idx){
		if(idx > size/2-1 || idx < 0 || size <= 1)  return;
		int sub = 2*(idx+1)-1;
		if(sub+1 < size && buf[sub] < buf[sub+1])  sub++;		
		if(buf[idx] < buf[sub]){
			int temp = buf[sub];
			buf[sub] = buf[idx];
			buf[idx] = temp;
			heapify(buf,sub);
		}
	}
}
