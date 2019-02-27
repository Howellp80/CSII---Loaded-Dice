/*********************************************************************
** Program Filename: Die.cpp
** Author: Parker Howell
** Date: 1-22-16
** Description: Die class implementation file
** Input: An int number of sides for the die.
** Output: An int value with occurance odds of 1/N.
*********************************************************************/

#include "Die.hpp"
#include <cstdlib>


// default constructor sets sides to 6.
Die::Die()
{
	setSides(6);
}


// constructor with parameter to set the amount of sides for the die.
Die::Die(int s)
{
	setSides(s);
}


// sets the member variabe "sides".
void Die::setSides(int s)
{
	sides = s;
}


// getter function to return the number of sides this die object has. 
int Die::getSides()
{
	return sides;
}



/*********************************************************************
** Function: roll()
** Description: Simulates a roll of a die and returns the int value.
** Parameters: None.
** Pre-Conditions: A random num generator must be seeded first.
** Post-Conditions: Returns a random int limited by the size of the die.
*********************************************************************/
int Die::roll()
{
	return std::rand() % sides + 1;
}


