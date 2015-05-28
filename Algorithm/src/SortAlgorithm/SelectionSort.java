package SortAlgorithm;

public class SelectionSort {
	void sort(int[] buf){
		if(buf == null || buf.length == 0)  return;
		for(int i = 0; i < buf.length-1; i++){
			int min = i;
			for(int j = i+1; j < buf.length; j++){
				if(buf[min] > buf[j]){
					min = j;
				}
			}
			int temp = buf[i];
			buf[i] = buf[min];
			buf[min] = temp;
		}
	}
}
