/*
 * Class: Poker7Card
 *
 * Date: 11/08/2014
 * 
 * Author£º Yunhe Tang
 */
package yunhe.cardgame;

import java.util.List;

public class Poker7Card extends Game{
	final String type = "Poker7Card";
	final int rounds = 7;
	List<Player> players;
	CardPool cp;
	int numberofPlayers;
	
	
	Poker7Card(List<Player> players, CardPool cp){
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
