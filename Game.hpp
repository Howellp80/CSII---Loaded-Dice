/****************************************************************************************
** Program Filename: Game.cpp
** Author: Parker Howell
** Date: 1-22-16
** Description: Dice based game of War. Will roll a die for 2 players. The player with 
**              the highest roll wins the round. Player with most rounds won, wins the 
**              game.
** Input: Game is created with a bool value for if player 1 is using a loaded die 
**		  (1 = yes, 0 = no). A bool value for if player 2 is using a loaded die (1 = yes,
**        0 = no).  An int value for the amount of sides  both dice will have. An int 
**        value for how many rounds to play. 
** Output: For each round, displays the roll of each player and declares the round
**         winner. After all rounds, displays the game winner and the  totals, and 
**         averages, for both players. As well as the size of the dies used, and if 
**         either of the dies were weighted or not.
****************************************************************************************/

#ifndef GAME_H
#define GAME_H

// Note: system("CLS") works with win / visual studio.use "clear" for *nix...
//       change value in main.cpp too!
#define CLEAR_SCREEN "clear"


#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Die.hpp"
#include "LoadedDie.hpp"

class Game
{
private:
	int dSides,             // how many sides both dice have.
		rounds,             // how many rounds the game will run to determine the winner.
		p1Rolled,       // stores returned value of player 1's roll.
		p2Rolled,       // stores returned value of player 2's roll.
		p1Total,        // cumulative total of player 1's rolls for the game.
		p2Total,        // cumulative total of player 1's rolls for the game.
		p1Points,       // how many rounds player 1 has won.
		p2Points;       // how many rounds player 2 has won.
	bool p1Loaded,          // is player 1's die loaded?
		 p2Loaded;          // is player 2's die loaded?
	Die norm;               // a Die object
	LoadedDie load;         // a loadedDie object


public:

/****************************************************************************************
** Game object constructor
** Parameters: P1l sets Player 1's die to loaded or not, P2l sets Player 2's die to 
**             loaded or not, s sets the amount of sides the dice will use, and r sets 
**             the rounds that will be played. A random number generator will be seeded. 
** Actions: After the game sets its member variables and seed a num generator, it will 
**          play each round, outputting the score and round winner. After all rounds, a 
**          overall winner will be declared and information about the game will be 
**          displayed. The game will then return to the main menu in Main.
****************************************************************************************/
	Game(bool p1L, bool p2L, int s, int r);



	/****************************************************************************************
	** Function: rollEm()
	** Parameters: none.
	** Preconditions: Properly created Game object.
	** Postconditions: Runs the game. For each round, rolls the appropriate die for each
	**                 Player, compares the values, and displays the winner. At the end of
	**                 the rounds, final results are displayed. Finally the user is returned
	**                 to the main menu in Main.
	****************************************************************************************/
	void rollEm();



	/****************************************************************************************
	** Function: compare()
	** Parameters: p1 is Player 1's rolled die value. p2 is Player 2's rolled die value.
	** Preconditions: Is passed 2 int values.
	** Postconditions: Returns either a:    1 - p1's value was higher than p2's.
	**                                      2 - p2's value was higher than p1's.
	**                                      3 - both values are equal.
	****************************************************************************************/
	int compare(int p1, int p2);



	// getters
	int getDSides();
	int getRounds();
	int getP1Rolled();
	int getP2Rolled();
	int getP1Total();
	int getP2Total();
	int getP1Points();
	int getP2Points();
	bool getP1Loaded();
	bool getP2Loaded();


	//setters
	void setDSides(int);
	void setRounds(int);
	void setP1Rolled(int);
	void setP2Rolled(int);
	void setP1Total(int);
	void setP2Total(int);
	void setP1Points(int);
	void setP2Points(int);
	void setP1Loaded(bool);
	void setP2Loaded(bool);

};

#endif