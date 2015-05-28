package operatingSystem.theReaderWriterProblem;

public class Item {
	
	int value;
	
	Item(int v){
		value = v;
	}
	
	void changeTo(int newValue){
		value = newValue;
	}
	
	int getValue(){
		return value;
	}
	
}
