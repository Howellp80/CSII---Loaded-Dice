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

#include "LoadedDie.hpp"
#include "Die.hpp"
#include <stdlib.h>


// default constructor sets sides to 6.
LoadedDie::LoadedDie()
{
	setSides(6);
}

// constructor with parameter to set the amount of sides for the die.
LoadedDie::LoadedDie(int s)
{
	setSides(s);
}



/***************************************************************************************
** Function: roll()
** Description: Simulates a roll of a loaded die and returns the int value.
** Parameters: None.
** Pre-Conditions: A random num generator must be seeded first.
** Post-Conditions: Returns values on average higher than a normal (1/N) die.
***************************************************************************************/
int LoadedDie::roll()
{
	int result = (rand() % sides) + 1,
		midpoint = (sides / 2);
	if (result <= midpoint){			
		if (sides > 3)	 
			result += (midpoint / 2);		
		else result++;
	}
	return result;
}
