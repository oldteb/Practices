/*
 * Class: Blackjack
 *
 * Date: 11/08/2014
 * 
 * Author£º Yunhe Tang
 */
package yunhe.cardgame;

import java.util.List;

public class Blackjack extends Game{
	
	final String type = "Blackjack";
	final int rounds = 2;
	List<Player> players;
	CardPool cp;
	int numberofPlayers;
	
	
	Blackjack(List<Player> players, CardPool cp){
		this.players = players;
		this.cp = cp;
		numberofPlayers = players.size();
	}
	
	void deal(){
		for(int i = 0; i < rounds; i++){
			for(int j = 0; j < numberofPlayers; j++){
				int c = cp.getNext();
				System.out.println("Player "+ players.get(j).getName() + " gets " + c);
				players.get(j).getCard(c);
			}
		}
		
		for(Player p : players){
			System.out.print("Player " + p.getName() + "'s cards are: ");
			p.printCards();
			System.out.println();
		}
	
	}
	
}
