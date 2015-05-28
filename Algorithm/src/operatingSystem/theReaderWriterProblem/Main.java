package operatingSystem.theReaderWriterProblem;

public class Main {
	
	public static Item wter = new Item(0);
	public static Item rder = new Item(0);
	
	public static void main(String argv[]){
		Integer[] buf = new Integer[1];
//		for(int i = 0; i < buf.length; i++){
			buf[0] = new Integer(0);
//		}
			
		Reader r0 = new Reader("0",buf);
		Reader r1 = new Reader("1",buf);
		Writer w0 = new Writer("0", buf);
		Writer w1 = new Writer("1", buf);
		
		new Thread(r0).start();
		new Thread(r1).start();
		new Thread(w0).start();
		new Thread(w1).start();
		
			
		
	}
}
