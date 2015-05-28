package operatingSystem.ProducerConsumerProblem;

public class Consumer implements Runnable{
	
	static int idCount = 1;
	int ID;
	private Bucket buck;
	
	Consumer(Bucket buck){
		this.buck = buck;
		this.ID = idCount++;
	}
	
	@Override
	public void run(){
		int[] recv = new int[20];
		for(int i = 0; i < 20; i++){
			try {
				recv[i] = buck.get();
				recv[++i] = buck.get();
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
		for(int i : recv)
			System.out.print(i + ", ");

	}
}
