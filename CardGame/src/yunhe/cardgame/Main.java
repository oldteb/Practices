/*
 * Class: Main
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
 * This is the main entrance of the program
 * 
 */
public class Main {

	public static void main(String argv[]){
		List<Player> players = new ArrayList<Player>();
		// Here you can choose different values for number of players and type of game to play
		// Value range for numberofPlayers is 1~6
		// Value range for gametoPlay is 0~2, they represents: Blackjack, Poker7Card, PokerTexasHoldem respectively
		int numberofPlayers = 6;
		int gametoPlay = 2;
		
		for(int i = 0; i < numberofPlayers; i++){
			players.add(new Player(Integer.toString(i)));
		}
		
		List<Game> games = new ArrayList<Game>();
		games.add(new Blackjack(players, new CardPool()));
		games.add(new Poker7Card(players, new CardPool()));
		games.add(new PokerTexasHoldem(players, new CardPool()));
		
		games.get(gametoPlay).deal();

	}
}
