package SortAlgorithm;

public class InsertionSort {
	void sort(int[] buf){
		if(buf == null || buf.length == 0)  return;
		for(int i = 1; i < buf.length; i++){
			int temp = buf[i];
			int j = i;
			while(j > 0 && buf[j-1] > temp){
				buf[j] = buf[j-1];
				j--;
			}
			buf[j] = temp;
		}
	}
}
