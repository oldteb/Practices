package SortAlgorithm;

public class QuickSort {
	public void sort(int[] buf, int s, int r){
		if(s < r){
			int m = partition(buf,s,r);
			sort(buf,s,m-1);
			sort(buf,m+1,r);
		}
	}
	
	int partition(int[] buf, int s, int r){
		int i = s-1;
		int temp = 0;
		int pivot = buf[r];
		for(int j = s; j < r; j++){
			if(buf[j] <= pivot){
				temp = buf[++i];
				buf[i] = buf[j];
				buf[j] = temp;
			}
		}
		temp = buf[++i];
		buf[i] = pivot;
		buf[r] = temp;
		return i;
	}
	
	public static void main(String[] argv){
		QuickSort qs = new QuickSort();
		int[] A = {-1,-2,0,-8,3,6,-9};
		qs.sort(A, 0, A.length-1);
		for(int i: A){
			System.out.print(i + " ");
		}
	}
	
}
