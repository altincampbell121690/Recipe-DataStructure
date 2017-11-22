/*
 * Recipe.h
 *
 *  Created on: Nov 15, 2017
 *      Author: KVTran Team 2
 */

#ifndef RECIPE_H_
#define RECIPE_H_

# include <iostream>
# include <string>
using namespace std;

class Recipe
{
private:
	string name;
	string category;
	string flavor;
	//static const int SIZE = 10;
	string ingredidients;
	int time;
	double rating;
	string directions;
public:
	/** Constructor **/
	Recipe();
	Recipe(string n, string c, string f, string i, int t, double r, string d);

	/**Access function**/
	string get_Name();
	string get_Category();
	string get_Flavor();
	string get_Ingredients();
	int get_Time();
	double get_Rating();
	string get_Directions();

	/**Manipulation functions**/
	void set_Name(string n);
	void set_Category(string c);
	void set_Flavor(string f);
	void set_Ingedients(string i);
	void set_Time(int t);
	void set_Rating(int r);
	void set_Directions(string d);

	/**Additional functions**/
	friend ostream& operator<<(ostream& os, const Recipe& recipe);
	bool operator==(const Recipe& recipe);
	bool operator<(const Recipe& recipe);
	bool operator>(const Recipe& recipe);

};





#endif /* RECIPE_H_ */
