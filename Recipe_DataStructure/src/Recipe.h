/*
 * Recipe.h
 *
 *  Created on: Nov 25, 2017
 *      Author: KVTran
 */

#ifndef RECIPE_H_
#define RECIPE_H_

# include <string>
# include <ostream>
#include <algorithm>
#include <vector>
using namespace std;

class Recipe {

private:
	string name;
	string category;
	string flavor;
	string ingredients;
	unsigned time;
	unsigned difficulty;
	string direction;

public:
	/**Constructors**/
	Recipe();
	Recipe(string n, string c, string f, string i,unsigned t, unsigned d, string dir);

    /**Access Functions**/
	string get_name();
	string get_category();
	string get_flavor();
	unsigned get_time();
	unsigned get_difficulty();
	string get_ingredients();
	string get_direction();

	/**Manipulation Procedures*/
	void set_name(string n);
	void set_category(string c);
	void set_flavor(string f);
	void set_time(unsigned t);
	void set_difficulty(unsigned d);
	void set_ingredients(string i);
	void set_direction(string dir);


	/**Additional Functions*/
	friend ostream& operator<<(ostream& os, const Recipe& recipe);
	//prints out a recipe to the designated stream in the following format
    // -Name: <name>
	// -Category: <category>
	// -Flavor: <flavor>
	// -Ingredient: <Ingredient as a list>
	// -Time: <time>
	// -Difficulty: <difficulty>
	// -Direction: <Direction steps>
	//note that the << is required to be a friend function, not a member function
	//note2: do not print out the <> as part of the output

	bool operator == (const Recipe& recipe);
	//compares two books to determine if they are the same book

	bool operator < (const Recipe& recipe);
	//compares two books to determine if one comes before the other
	//alphabetically by title and secondarily by author if the two
	//books contain the same title
	//returns false if the two books are the same

	bool operator > (const Recipe& recipe);
	//compares two books to determine if one comes after the other
	//alphabetically by title and secondarily by author if the two
	//books contain the same title
	//returns false if the two books are the same
};



#endif /* RECIPE_H_ */
