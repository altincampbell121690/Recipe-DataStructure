/*
 * Recipe.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: KVTran
 */

# include "Recipe.h"
# include <iostream>
# include <iomanip>

/**Constructor*/

Recipe::Recipe() : name(""), category(""), flavor(""), ingredients(""), time(0), difficulty(0), direction("") {};

Recipe::Recipe(string n, string c, string f, string i,unsigned t, unsigned d, string dir)
{
	name = n;
	category = c;
	flavor = f;
	ingredients = i;
	time = t;
	difficulty = d;
	direction = dir;
}



/**Access Functions**/

string Recipe::get_name() {
    return name;
}

string Recipe::get_category() {
    return category;
}

string Recipe::get_flavor() {
    return flavor;
}

string Recipe::get_ingredients() {
    return ingredients;
}

unsigned Recipe::get_time() {
	return time;
}

unsigned Recipe::get_difficulty() {
	return difficulty;
}

string Recipe::get_direction() {
	return direction;
}

/**Manipulation Procedures**/

void Recipe::set_name(string n) {
    name = n;
}

void Recipe::set_category(string c) {
    category = c;
}

void Recipe::set_flavor(string f) {
    flavor = f;
}

void Recipe::set_ingredients(string i) {
    ingredients = i;
}

void Recipe::set_time(unsigned t) {
	time = t;
}

void Recipe::set_difficulty(unsigned d) {
	difficulty = d;
}

void Recipe::set_direction(string dir) {
	direction = dir;
}


/**Additional Functions*/

ostream& operator<<(ostream& os, const Recipe& recipe)
{
	os << "- Name: " << recipe.name << endl;
	os << "- Category: " << recipe.category << endl;
	os << "- Flavor: " << recipe.flavor << endl;
	os << "- Ingredients: " << endl;
	os << recipe.ingredients << endl;
	os << "- Time:" << recipe.time << endl;
	os << "- Difficulty: " << recipe.difficulty << endl;
	os << "- Direction: " << recipe.direction << endl;

	return os;
}


bool Recipe::operator == (const Recipe& recipe)
{
    return ((name == recipe.name) && (category == recipe.category) && (flavor == recipe.flavor));
}

bool Recipe::operator > (const Recipe& recipe)
{
// compares two recipes to determine if one comes after the other
// alphabetically by name, secondarily by category if the two
// Recipes contain the same name, and lastly by flavor if the two
// recipes have the same name and category
// returns false if the two Recipes are the same
	if (name.compare(recipe.name) > 0) return true;
	else if (name.compare(recipe.name) == 0 && category.compare(recipe.category) > 0)
	{
		return true;
	}
	else if (name.compare(recipe.name) == 0 && category.compare(recipe.category) == 0 && flavor.compare(recipe.flavor) > 0)
	{
		return true;
	}
	return false;
}

bool Recipe::operator < (const Recipe& recipe)
{
// compares two recipes to determine if one comes after the other
// alphabetically by name, secondarily by category if the two
// Recipes contain the same name, and lastly by flavor if the two
// recipes have the same name and category
// returns false if the two Recipes are the same
	if (name.compare(recipe.name) < 0) return true;
	else if (name.compare(recipe.name) == 0 && category.compare(recipe.category) < 0)
	{
		return true;
	}
	else if (name.compare(recipe.name) == 0 && category.compare(recipe.category) == 0 && flavor.compare(recipe.flavor) < 0)
	{
		return true;
	}
	return false;
}





