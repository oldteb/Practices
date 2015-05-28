package SortAlgorithm;

public class BubbleSort {
	void sort(int[] buf){
		if(buf == null || buf.length == 0)  return;
		for(int i = buf.length-1, count = 1; i > 0 && count > 0; i--){
			count = 0;
			for(int j = 0; j < i; j++){
				if(buf[j] > buf[j+1]){
					swap(buf,j);
					count++;
				}
			}
		}
		
	}
	
	private void swap(int[] buf, int y){
		int temp = buf[y+1];
		buf[y+1] = buf[y];
		buf[y] = temp;
	}
}
