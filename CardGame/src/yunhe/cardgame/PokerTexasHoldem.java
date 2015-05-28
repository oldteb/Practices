/*
 * Class: PokerTexasHoldem
 *
 * Date: 11/08/2014
 * 
 * Author£º Yunhe Tang
 */
package yunhe.cardgame;
import java.util.List;

public class PokerTexasHoldem extends Game{

	final String type = "PokerTexasHoldem";
	final int rounds = 2;
	final int numberofCommunityCards = 5;
	List<Player> players;
	int[] comCards;
	CardPool cp;
	int numberofPlayers;
	
	
	PokerTexasHoldem(List<Player> players, CardPool cp){
		this.players = players;
		this.cp = cp;
		numberofPlayers = players.size();
		comCards = new int[numberofCommunityCards];
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
		
		System.out.print("The community cards are: ");
		for(int i = 0; i < numberofCommunityCards; i++){
			int temp = cp.getNext();
			System.out.print(temp + " ");
			comCards[i] = temp;
		}
		
		
	
	}
	
}
