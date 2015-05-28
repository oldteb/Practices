package operatingSystem.theReaderWriterProblem;

public class Reader implements Runnable{
	
	String id;
	Integer[] buf;
	
	Reader(String id, Integer[] buf){
		this.id = id;
		this.buf = buf;
	}
	
	public void run(){
		
		for(int i = 0; i < 5; i++){
			synchronized(Main.wter){
				synchronized(Main.rder){
					Main.rder.changeTo(Main.rder.getValue()+1);
				}
			}
			
			System.out.println(id + "starts reading.");
			try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println(id + "end reading. value = " + buf[0]);
			
			synchronized(Main.rder){
				Main.rder.changeTo(Main.rder.getValue()-1);
				Main.rder.notifyAll();
			}
			
			try {
				Thread.sleep(700);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
		System.out.println("Reader "+ id + " finished!");
		
	}
}
