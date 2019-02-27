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

#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"
#include <iostream>
#include <iomanip>


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
Game::Game(bool p1L, bool p2L, int s, int r)
{
	setP1Loaded(p1L);
	setP2Loaded(p2L);
	setDSides(s);
	setRounds(r);


	// set the seed for the die rolls. 
	srand(static_cast<unsigned long>(time(0)));

	// adjusts the dice sides to the user enterd value, and resets points and totals.
	norm.setSides(s);
	load.setSides(s);
	p1Total = 0;
	p2Total = 0;
	p1Points = 0;
	p2Points = 0;

	// begins the game.
	rollEm();

}



/****************************************************************************************
** Function: rollEm()
** Parameters: none.
** Preconditions: Properly created Game object.
** Postconditions: Runs the game. For each round, rolls the appropriate die for each 
**                 Player, compares the values, and displays the winner. At the end of 
**                 the rounds, final results are displayed. Finally the user is returned
**                 to the main menu in Main.
****************************************************************************************/
void Game::rollEm()
{
	// for each round of the game...
	for (int i = 0; i < rounds; i++){

		if (p1Loaded == true)
			p1Rolled = load.roll();
		else
			p1Rolled = norm.roll();

		if (p2Loaded == true)
			p2Rolled = load.roll();
		else
			p2Rolled = norm.roll();


		// display who rolled what
		std::cout << "Player 1 rolled: " << p1Rolled << std::endl;
		std::cout << "Player 2 rolled: " << p2Rolled << std::endl;
		

		// figure out who won the round, and adjust scores.
		if (p1Rolled > p2Rolled){
			std::cout << " - Player 1 wins the round." << std::endl << std::endl;
			p1Points++;
		}
		else if (p2Rolled > p1Rolled){
			std::cout << " - Player 2 wins the round." << std::endl << std::endl;
			p2Points++;
		}
		else //  p1Rolled == p2Rolled
			std::cout << " - This round was a tie. No points awarded." 
			<< std::endl << std::endl;


		// adjust totals...
		p1Total += p1Rolled;
		p2Total += p2Rolled;
	}


	// make it purdy to look at...  :P
	std::cout << "     *********************************     " << std::endl << std::endl;


	// different displays for the 3 conditions of Player 1 winning, Player2 winning,
	// or a tie game.
	switch (compare(p1Points, p2Points)){
	case 1:  // Player 1 wins.
		std::cout << "         Player 1 wins the game!!!" << std::endl;
		std::cout << std::fixed << std::showpoint << std::setprecision(2);
		std::cout << "     With a final score of " << p1Points << " - " << p2Points 
			<< std::endl << std::endl;
		std::cout << "Player 1 averge roll: " << p1Total << "/" << rounds << " = " 
			<< (static_cast <double> (p1Total) / rounds) << std::endl;
		std::cout << "Player 2 averge roll: " << p2Total << "/" << rounds << " = " 
			<< (static_cast <double> (p2Total) / rounds) << std::endl;
		break;

	case 2:  // Player 2 wins.
		std::cout << "         Player 2 wins the game!!!" << std::endl;
		std::cout << std::fixed << std::showpoint << std::setprecision(2);
		std::cout << "     With a final score of " << p2Points << " - " << p1Points << std::endl 
			<< std::endl;
		std::cout << "Player 2 averge roll: " << p2Total << "/" << rounds << " = " 
			<< (static_cast <double> (p2Total) / rounds) << std::endl;
		std::cout << "Player 1 averge roll: " << p1Total << "/" << rounds << " = " 
			<< (static_cast <double> (p1Total) / rounds) << std::endl;
		break;

	case 3:  // Tie game.
		std::cout << "         The game was a tie. Boo!!!" << std::endl;
		std::cout << std::fixed << std::showpoint << std::setprecision(2);
		std::cout << "     With a final score of " << p1Points << " - " << p2Points << std::endl 
			<< std::endl;
		std::cout << "Player 1 averge roll: " << p1Total << "/" << rounds << " = " 
			<< (static_cast <double> (p1Total) / rounds) << std::endl;
		std::cout << "Player 2 averge roll: " << p2Total << "/" << rounds << " = " 
			<< (static_cast <double> (p2Total) / rounds) << std::endl;
		break;
	}


	// displays the die sides used and if either player used a loaded die.
	std::cout << "Both Players used a " << dSides << " sided die." << std::endl;
	if (p1Loaded)
		std::cout << "Player 1's die was Loaded." << std::endl;
	else
		std::cout << "Player 1's die was Normal." << std::endl;

	if (p2Loaded)
		std::cout << "Player 2's die was Loaded." << std::endl;
	else
		std::cout << "Player 2's die was Normal." << std::endl;


	// returns user to main menu after the game has ended. 
	std::cout << std::endl << "Press \"enter\" to return to the main menu.";
	std::cin.ignore();
	std::cin.get();
	system(CLEAR_SCREEN);

}



/****************************************************************************************
** Function: compare()
** Parameters: p1 is Player 1's rolled die value. p2 is Player 2's rolled die value.
** Preconditions: Is passed 2 int values.
** Postconditions: Returns either a:    1 - p1's value was higher than p2's.
**                                      2 - p2's value was higher than p1's.
**                                      3 - both values are equal.
****************************************************************************************/
int Game::compare(int p1, int p2)
{
	if (p1 > p2)
		return 1;
	else if (p1 < p2)
		return 2;
	else // they're equal
		return 3;
}




/***********************************************************
**   getters...
************************************************************/
int Game::getDSides()
{
	return dSides;
}


int Game::getRounds()
{
	return rounds;
}


int Game::getP1Rolled()
{
	return p1Rolled;
}


int Game::getP2Rolled()
{
	return p2Rolled;
}


int Game::getP1Total()
{
	return p1Total;
}


int Game::getP2Total()
{
	return p2Total;
}

int Game::getP1Points()
{
	return p1Points;
}


int Game::getP2Points()
{
	return p2Points;
}


bool Game::getP1Loaded()
{
	return p1Loaded;
}


bool Game::getP2Loaded()
{
	return p2Loaded;
}
// end getters.


/***********************************************************
** setters...
************************************************************/
void Game::setDSides(int s)
{
	dSides = s;
}


void Game::setRounds(int r)
{
	rounds = r;
}


void Game::setP1Rolled(int p1R)
{
	p1Rolled = p1R;
}


void Game::setP2Rolled(int p2R)
{
	p2Rolled = p2R;
}


void Game::setP1Total(int p1T)
{
	p1Total = p1T;
}


void Game::setP2Total(int p2T)
{
	p2Total = p2T;
}


void Game::setP1Points(int p1P)
{
	p1Points = p1P;
}


void Game::setP2Points(int p2P)
{
	p2Points = p2P;
}


void Game::setP1Loaded(bool p1L)
{
	p1Loaded = p1L;
}


void Game::setP2Loaded(bool p2L)
{
	p2Loaded = p2L;
}
// end setters.





