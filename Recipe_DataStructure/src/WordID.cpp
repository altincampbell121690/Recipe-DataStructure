
/*
 * Recipe.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: KVTran, Erik Rakley, Altin Campbell
 */

# include "WordID.h"
# include <iostream>
# include <iomanip>

/**Constructor*/

wordID::wordID() : word(""), id(-1){};
wordID::wordID(string WORD, int ID)
{
	word = WORD;
	id = ID;
}

wordID::~wordID() {};


/**Access Functions**/

string wordID::get_Word() {
    return word;
}

int wordID::get_ID() {
    return id;
}


/**Manipulation Procedures**/

void wordID::set_Word(string WORD) {
    word = WORD;
}

void wordID::set_ID(int ID) {
    id = ID;
}


/**Additional Functions*/

ostream& operator<<(ostream& os, const wordID& wordID)
{
	os << "- word: " << wordID.word << endl;
	os << "- id: " << wordID.id << endl;
	return os;
}


bool wordID::operator == (const wordID& wordID)
{
    return ((this->word == wordID.word) && (this->id == wordID.id));
}

bool wordID::operator > (const wordID& wordID)
{
// compares two recipes to determine if one comes after the other
// alphabetically by name, secondarily by category if the two
// Recipes contain the same name, and lastly by flavor if the two
// recipes have the same name and category
// returns false if the two Recipes are the same
	if (this->word.compare(wordID.word) > 0) return true;
	else if (this->word.compare(wordID.word) == 0 && this->id >  wordID.id)
	{
		return true;
	}
	else
	return false;
}

bool wordID::operator < (const wordID& wordID)
{
// compares two recipes to determine if one comes after the other
// alphabetically by name, secondarily by category if the two
// Recipes contain the same name, and lastly by flavor if the two
// recipes have the same name and category
// returns false if the two Recipes are the same
	if (this->word.compare(wordID.word) < 0) return true;
	else if (this->word.compare(wordID.word) == 0 && this->id <  wordID.id)
	{
		return true;
	}
	else
	return false;
}
