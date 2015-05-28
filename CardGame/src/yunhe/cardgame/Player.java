/*
 * Class: Player
 *
 * Date: 11/08/2014
 * 
 * Author£º Yunhe Tang
 */
package yunhe.cardgame;


public class Player {
	
	String id = null;
	int[] cards = new int[52];
	
	Player(String name){
		id = name;
	}
	
	public void getCard(int card){
		cards[card] = 1;
	}
	
	public String getName(){
		return id;
	}
	
	public boolean hasCard(int card){
		if(cards[card] == 0)
			return false;
		else
			return true;
	}
	
	public void printCards(){
		for(int i = 0; i < 52; i++){
			if(cards[i] == 1){
				System.out.print(i + " ");
			}
		}
	}

}
