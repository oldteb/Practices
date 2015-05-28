package operatingSystem.theDiningPhilosophersProblem;

public class Philosopher implements Runnable{

	int id;
	int left_fork;
	int right_fork;
	static int index = 0;
	Forks forks = null;
	int bites = 5;
	
	Philosopher(int lf, int rf, Forks forks){
		left_fork = lf;
		right_fork = rf;
		id = index++;
		this.forks = forks;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i = 0; i < bites; i++){
			forks.eatwith(id,left_fork, right_fork);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println(id + "done the eating.");
	}

}
