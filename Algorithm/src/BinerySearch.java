
public class BinerySearch {
	int search(int[] buf, int target){
		if(buf == null || buf.length == 0)  return -1;
		return BS(buf,target,0,buf.length-1);
	}
	
	int BS(int[] buf, int target, int bgn, int end){
		if(bgn == end){
			if(buf[bgn] == target)  return bgn;
			else  return -1;
		}
		int mid = (bgn+end)/2;
		if(target > buf[mid])
			return BS(buf,target,mid+1,end);
		else
			return BS(buf,target,bgn,mid);
	}
	
	public static void main(String[] args) {
		Object obj = new Object();
		BinerySearch bs = new BinerySearch();
		int[] A = {-9, -6,-5,-2,0,1,2,3,6,7,9};
		System.out.println(bs.search(A, -5));
		
	}
}
