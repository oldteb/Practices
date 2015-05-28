package operatingSystem.ProducerConsumerProblem;

public class Producer implements Runnable{
	static private int idCount = 1;
	int ID;
	private Bucket buck;
	
	Producer(Bucket buck){
		this.buck = buck;
		this.ID = idCount++;
	}

	@Override
	public void run() {
		for(int i = 0; i < 10; i++){
			try {
				buck.put(i);
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
