/*
 * Class: CardPool
 *
 * Date: 11/08/2014
 * 
 * Author£º Yunhe Tang
 */
package yunhe.cardgame;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * This class is in charge of distributing the cards
 */
public class CardPool {
	
	List<Integer> cards;
	
	CardPool(){
		this.cards = new ArrayList<Integer>();
		
		for(int i = 0; i < 52; i++){
			cards.add(i);
		}
	}
	
	public int getNext(){
		Random rand = new Random();
		int randomNum = rand.nextInt((cards.size()-1) + 1);
		int rst = cards.get(randomNum);
		cards.remove(randomNum);
		
		return rst;

	}
	
}
