
public class Fibonacci {
	
	
	public static int[] Fibonacci_iter(int num){
		if(num < 1){
			return null;
		}
		int[] rst = new int[num];
			
		for(int i = 0; i < rst.length ; i++){
			if(i == 0 || i == 1){
				rst[i] = 1;
			}
			else{
				rst[i] = rst[i-1] + rst[i-2];
			}
		}
		
		return rst;
	}
	
	public static boolean Fibonacci_rec(int num, int level, int[] rst){
		if(num < 1){
			return false;
		}
		if(num == level){
			return true;
		}
		if(level == 0 || level == 1){
			rst[level] = 1;
			return Fibonacci_rec(num, level+1, rst);
		}
		else{
			rst[level] = rst[level-1]+rst[level-2];
			return Fibonacci_rec(num, level+1, rst);
		}
	}
	
	public static void main(String argv[]){
		Fibonacci fib = new Fibonacci();
		int[] buf = new int[10];
		fib.Fibonacci_rec(10,0,buf);
		for(int i : buf){
			System.out.print(i + " ");
		}
	}
	
	
}
