package SortAlgorithm;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

public class MergeSort {
	void sort(int[] buf){
		if(buf == null || buf.length == 0)  return;
		mergeSort(buf,0,buf.length-1);
	}
	
	void mergeSort(int[] buf, int bgn, int end){
		if(bgn >= end)  return;
		int mid = (bgn+end)/2;
		mergeSort(buf,bgn,mid);
		mergeSort(buf,mid+1,end);
		merge(buf,bgn,mid,end);
	}
	
	void merge(int[] buf, int bgn, int mid, int end){
		// non in-place
		int[] left = new int[mid-bgn+2];
		int[] right = new int[end-mid+1];
		for(int i = 0; i < left.length-1; i++)
			left[i] = buf[i+bgn];
		for(int i = 0; i < right.length-1; i++)
			right[i] = buf[i+mid+1];
		left[left.length-1] = Integer.MAX_VALUE;
		right[right.length-1] = Integer.MAX_VALUE;
		
		for(int k = bgn, i = 0, j = 0; k <= end; k++){
			if(left[i] < right[j])  buf[k] = left[i++];
			else  buf[k] = right[j++];
		}
	}
}
