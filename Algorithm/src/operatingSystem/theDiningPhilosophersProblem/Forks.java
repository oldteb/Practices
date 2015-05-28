package operatingSystem.theDiningPhilosophersProblem;

public class Forks {
	Fork[] forks = null;
	
	
	Forks(int num){
		forks = new Fork[num];
		for(int i = 0; i < num ; i++){
			forks[i] = new Fork();
		}
	}
	
	
	public void eatwith(int id, int i, int j){
		synchronized(this){
			while(forks[i].check() == false || forks[j].check() == false){
				try {
					System.out.println(id + " is waiting.");
					this.wait();
					System.out.println(id + " is waking up.");
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			forks[i].use();
			forks[j].use();
		}
		System.out.println(id + " is eating.");
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println(id + " done the eating.");
		synchronized(this){
			forks[i].release();
			forks[j].release();
			this.notify();
		}
	}		
	
}
