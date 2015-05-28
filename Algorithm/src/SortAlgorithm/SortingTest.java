package SortAlgorithm;

public class SortingTest {
	static int[] A = {6,-1,5,-2,0,-8,-2,3,7,6,-9,2};
	
	public static void main(String[] argv){
		//BubbleSort bs = new BubbleSort();
		//InsertionSort is = new InsertionSort();
		//SelectionSort ss = new SelectionSort();
		HeapSort hs = new HeapSort();
		//HSort hs1 = new HSort();
		//QuickSort qs = new QuickSort();
		//MergeSort ms = new MergeSort();
		hs.sort(A);
		for(int i: A){
			System.out.print(i + " ");
		}
	}
}
