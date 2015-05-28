package operatingSystem.ProducerConsumerProblem;

public class ProducerConsumerTest {
	
	public static void main(String[] args) {
		Bucket buck = new Bucket(10);
		Producer p1 = new Producer(buck);
		Producer p2 = new Producer(buck);
		Consumer c = new Consumer(buck);
		
		new Thread(p1).start();
		new Thread(p2).start();
		new Thread(c).start();
		
	}
	
}
