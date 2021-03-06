/*
 * Author: Daniel Zelfo
 * Class: CSCI 220
 * Date: 9/9/2019
 * Program: Game Scores Program v1.1 - EXTRA CREDIT
 * Description: 
 *			v1.0 (9/9/2019)
 *				This program uses two classes, GameScore and GameEntry. 
 *				The GameEntry class is used to create game entries with specific names, scores, and dates. 
 *				The GameScore class is used to keep track of up to 5 top-scored game entries.
 *			v1.1 (9/9/2019) EXTRA CREDIT #1
 *				Users can construct a new GameScores object using a file name. 
 *				The constructor will open that file and create game entries using the information inside it.
 *				The class also Uses a text file to save the top 5 scores game.
 *			v1.2 (9/10/2019) EXTRA CREDIT #2
 *				The GameScore class can remove all entries before a given date using remove(string date).
 *
 *
 */

#include <iostream>
#include <fstream>
#include "GameEntry.hpp"
#include "GameScore.hpp"

using namespace std;

void gameScoresMain()
{	
	//creating games scores #1-2 using the game names
	GameScore g1("Classic Pac-Man"),
		   	  g2("Modern Pac-Man");

	//creating game entries #1-7
	GameEntry e1("Jill", 980, "08/05/2019"),
			  e2("Jack", 600, "08/18/2019"),
			  e3("Rob", 875, "07/30/2019"),
			  e4("Rob", 900, "08/02/2019"),
			  e5("Jane", 999, "08/22/2019"),
			  e6("Kim", 800, "08/22/2019"),
			  e7("Tom", 200, "08/22/2019");
	
	//creating game #3 from a text file
	GameScore g3("GameScores/pacman.txt", true);

	//adding entries #1-4 to game #1
	g1.add(e1);
	g1.add(e2);
	g1.add(e3);
	g1.add(e4);

	//removing all entries before 8/5/2019
	g1.remove("08/05/2019");

	//printing game scores #1
	g1.print();

	//adding game entries #1-4 to game scores #2
	g2.add(e1);
	g2.add(e2);
	g2.add(e3);
	g2.add(e4);

	//trying an invalid remove
	g2.remove(0);

	//adding game entries #5-7 to game scores #2
	g2.add(e5);
	g2.add(e6);
	g2.add(e7);
	
	//printing game scores #2
	g2.print(); 


	//printing game #3
	g3.print();

	//adding entry #2 to game #1
	g3.add(e2);

	//printing game #3
	g3.print();

	//saving game #3 to a text file
	g3.save("GameScores/pacman.txt");
}

