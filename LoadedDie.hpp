/****************************************************************************************
** Program Filename: LoadedDie.cpp
** Author: Parker Howell
** Date: 1-22-16
** Description: LoadedDie class implementation file. Edited to Inherit from Die Class.
**              Identical to Die Class except for roll() which should return higher
**              values than a normal die object.
** Input: An int number of sides for the die.
** Output: An int value with occurance odds of higher than 1/N.
****************************************************************************************/

#ifndef LOADED_H
#define LOADED_H
#include"Die.hpp"


class LoadedDie : public Die
{
public:

	// default constructor sets sides to 6.
	LoadedDie();

	// constructor with parameter to set the amount of sides for the die.
	LoadedDie(int);



	/***************************************************************************************
	** Function: roll()
	** Description: Simulates a roll of a loaded die and returns the int value.
	** Parameters: None.
	** Pre-Conditions: A random num generator must be seeded first.
	** Post-Conditions: Returns values on average higher than a normal (1/N) die.
	***************************************************************************************/
	int roll();
};
#endif
