/****************************************************************************************
** Program Filename: Die.hpp
** Author: Parker Howell
** Date: 1-22-16
** Description: Creates a die of N sides that can be rolled to return a value. 
** Input: An int number of sides for the die.
** Output: An int value with occurance odds of 1/N.
****************************************************************************************/

#ifndef DIE_H
#define DIE_H


class Die
{
protected:
	
	int sides;      // how many side the die has.

public:

	// default constructor sets sides to 6.
	Die();

	// constructor with parameter to set the amount of sides for the die. 
	Die(int);

	// sets the member variabe "sides".
	void setSides(int);

	// getter function to return the number of sides this die object has.
	int getSides();



	/***************************************************************************************
	** Function: roll()
	** Description: Simulates a roll of a die and returns the int value.
	** Parameters: None.
	** Pre-Conditions: A random num generator must be seeded first.
	** Post-Conditions: Returns a random int limited by the size of the die.
	***************************************************************************************/
	int roll();

};

#endif
