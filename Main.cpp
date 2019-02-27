/****************************************************************************************
** Program Filename: Main.cpp
** Author: Parker Howell
** Date: 1-22-16
** Description: A menu system to gather information with which to create a a GameWar 
**              object with. The game will have 1 user and 2 "players" roll either a 
**              normal or a loaded die in a game of war. The highest roll wins the round.
**              The most won rounds wins the game. The loadedDie returns on average 
**              higher values than the normal die.
** Input: User will input via the menu, how many sides the dice will have, if either of the
**        players will be using loaded die, and how many rounds to play for the game.
** Output: Menu system. Game console output comes from GameWar class.
****************************************************************************************/

#include "Game.hpp"
#include <iostream>


// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
//       change value in Game.hpp too!
#define CLEAR_SCREEN "clear"


int main(){
	int sides,              // how many sides the dice should have.
		rounds,             // how many rounds to play in the game.
		p1isLoaded,         // menu choice for if player 1 is using a loaded die.
		p2isLoaded;         // menu choice for if player 2 is using a loaded die.
	bool p1Loaded,          // converted menu choice for if player 1 is using a loaded die.
		 p2Loaded;          // converted menu choice for if player 2 is using a loaded die.


	// main menu 
	system(CLEAR_SCREEN);
	do {
		std::cout << std::endl;
		std::cout << "Welcome to a dice based game of War." << std::endl;
		std::cout << "Please choose the number of sides each die should" << std::endl;
		std::cout << "have for this game, or enter \"5\" to quit." << std::endl << std::endl;
		std::cout << "1. Both dice will each have 4 sides." << std::endl;
		std::cout << "2. Both dice will each have 6 sides." << std::endl;
		std::cout << "3. Both dice will each have 12 sides." << std::endl;
		std::cout << "4. Both dice will each have 20 sides." << std::endl;
		std::cout << "5. to Qiut." << std::endl;
		std::cin >> sides;

		// validate main menu selection 
		while ((sides < 1) || (sides > 5)){
			std::cout << "Please choose 1-5." << std::endl;
			std::cin >> sides;
		}


		// if the user didn't Qiut. 
		if (sides != 5){

			// convert the entered sides selection to a sides value. 
			if (sides == 1)
				sides = 4;
			else if (sides == 2)
				sides = 6;
			else if (sides == 3)
				sides = 12;
			else // (sides == 4)
				sides = 20;


			// get the amount of rounds to play for the game. 
			system(CLEAR_SCREEN);
			std::cout << std::endl;
			std::cout << "How many rounds should be played in this game?" << std::endl;
			std::cout << "Please enter an integer value between 1 and 10000." << std::endl;
			std::cin >> rounds;

			// validate rounds 
			std::cout << std::endl;
			while ((rounds < 1) || (rounds > 10000)){
				std::cout << "Please enter an integer value between 1 and 10000." << std::endl;
				std::cin >> rounds;
			}


			// get if the players are using normal or loaded dies.
			// Player 1 
			system(CLEAR_SCREEN);
			std::cout << std::endl;
			std::cout << "Will Player 1 be using a standard or loaded die?" << std::endl;
			std::cout << "(A loaded die rolls higher average values.)" << std::endl << std::endl;
			std::cout << "1. Standard Die." << std::endl;
			std::cout << "2. Loaded Die." << std::endl;
			std::cin >> p1isLoaded;

			// validate player 1 selection. 
			while ((p1isLoaded < 1) || (p1isLoaded > 2)){
				std::cout << std::endl;
				std::cout << "Please enter 1 or 2." << std::endl;
				std::cin >> p1isLoaded;
			}

			// Player 2 
			std::cout << std::endl;
			std::cout << "Will Player 2 be using a standard or loaded die?" << std::endl;
			std::cout << "(A loaded die rolls higher average values.)" << std::endl << std::endl;
			std::cout << "1. Standard Die." << std::endl;
			std::cout << "2. Loaded Die." << std::endl;
			std::cin >> p2isLoaded;

			// validate player 2 selection. 
			while ((p2isLoaded < 1) || (p2isLoaded > 2)){
				std::cout << std::endl;
				std::cout << "Please enter 1 or 2." << std::endl;
				std::cin >> p2isLoaded;
			}

			// convert player die selections to bool values.
			if (p1isLoaded == 1)
				p1Loaded = false;
			else
				p1Loaded = true; 

			if (p2isLoaded == 1)
				p2Loaded = false;
			else
				p2Loaded = true;

			system(CLEAR_SCREEN);


			//create a game object which will run the game.
			Game gameofwar(p1Loaded, p2Loaded, sides, rounds);

		}

	// If the user didn't quit return to the main menu.
	} while (sides != 5);

	return 0;
}