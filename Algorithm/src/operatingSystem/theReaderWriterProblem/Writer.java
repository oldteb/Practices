package operatingSystem.theReaderWriterProblem;

import java.util.Random;

public class Writer implements Runnable{
	
	String id;
	Integer[] buf;
	
	Writer(String id, Integer[] buf){
		this.id = id;
		this.buf = buf;
	}
	
	public void run(){
		
		for(int i = 0; i < 5; i++){
			synchronized(Main.wter){
				synchronized(Main.rder){
					while(Main.rder.getValue() != 0){
						try {
							Main.rder.wait();
						} catch (InterruptedException e) {
							e.printStackTrace();
						}
					}
				}
			
				System.out.println("Writer "+ id + "starts writing.");
				Random rand = new Random();
				buf[0] = rand.nextInt(50) + 1;
				System.out.println("Writer "+ id + "end reading. New value = " + buf[0]);
			}
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
		System.out.println("Writer "+ id + " finished!");
		
	}
}
