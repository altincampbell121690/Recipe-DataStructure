/*
 * Recipe.h
 *
 *  Created on: Nov 15, 2017
 *      Author: KVTran Team 2
 */

#ifndef WORDID_H_
#define WORDID_H_

# include <iostream>
# include <string>
using namespace std;

class wordID
{
private:
	    string word;
	    int id;
public:
	/** Constructor **/
	wordID();
	wordID(string word,int ID);

	/**Access function**/
	string get_Word();
	int get_ID();

	/**Manipulation functions**/
	void set_Word(string word);
	void set_ID(int ID);

	/**Additional functions**/
	friend ostream& operator<<(ostream& os, const wordID& IDword);
	bool operator==(const wordID& IDword);
	bool operator<(const wordID& IDword);
	bool operator>(const wordID& IDword);

};





#endif /* RECIPE_H_ */
