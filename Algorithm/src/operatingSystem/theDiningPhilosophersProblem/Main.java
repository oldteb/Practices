package operatingSystem.theDiningPhilosophersProblem;

public class Main {
	public static void main(String argv[]){
		Forks forks = new Forks(5);
		Philosopher p1 = new Philosopher(4,0,forks);
		Philosopher p2 = new Philosopher(0,1,forks);
		Philosopher p3 = new Philosopher(1,2,forks);
		Philosopher p4 = new Philosopher(2,3,forks);
		Philosopher p5 = new Philosopher(3,4,forks);
		
		System.out.println("##start.");
		new Thread(p1).start();
		new Thread(p2).start();
		new Thread(p3).start();
		new Thread(p4).start();
		new Thread(p5).start();
	}
}
