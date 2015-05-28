package operatingSystem.theDiningPhilosophersProblem;

public class Fork {
	int id;
	boolean aval;
	static int index = 0;
	
	Fork(){
		id = index++;
		aval = true;   //  idle...
	}
	
	boolean check(){
		return aval;
	}
	
	void use(){
		aval = false;
	}
	
	void release(){
		aval = true;
	}
}
