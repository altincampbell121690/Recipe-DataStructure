/*
 * HashTable.h
 *
 *  Created on: Dec 3, 2017
 *      Author: KVTran
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

# include <string>
# include "Recipe.h"
# include "BST.h"
# include "List.h"

class HashTable {
public:
	/*Constructor and Destructor*/
	HashTable() { };
	~HashTable() { };


	/*Access function*/
	int hash (string& key) const;
    //returns the hash value for the given key for table 2
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: any string

	int countBucket_table1(int index) const;
    //counts the number of recipes at this index
    //returns the count
    //pre: 0<= index < SIZE
	int countBucket_table2(int index) const;
    //counts the number of recipes at this index
    //returns the count
    //pre: 0<= index < SIZE


	int search_table2(string key) const;
    //Searches for the index of the key in the table2
    //returns the index at which recipe is located
    //returns -1 if recipe is not in the table

	int search_KeyVector(string& key) const;


	/************* Manipulation Procedures *************/

	void insert(Recipe recipe);
    //inserts a new recipe into the table
    //calls the hash function on the key to determine
    //the correct bucket

	void remove(Recipe recipe);
    //removes recipe from the table
    //calls the hash function on the key to determine
    //the correct bucket
    //pre: recipe is in the table


	/*Additional Function*/
	void printBucket_table1(ostream& out, int index) const;
    //Prints all the recipes at index according to inOrderPrint
    //pre: 0<= index < SIZE
    //Should print according to the following formula:
	//prints out a recipe to the designated stream in the following format
    // -Name: <name>
	// -Category: <category>
	// -Flavor: <flavor>
	// -Ingredient: <Ingredient as a list>
	// -Time: <time>
	// -Difficulty: <difficulty>
	// -Direction: <Direction steps>
	// blank line

	void printTable(ostream& out) const;
    //Prints the first recipe at each index
    //along with a count of the total books
    //at each index by calling count_bucket
    //as a helper function
    //Prints in the format:
    //Recipe in the Group:
    //<new line>
    //Group <bucket>
    // -Name: <name>
	// -Category: <category>
	// -Flavor: <flavor>
	// -Ingredient: <Ingredient as a list>
	// -Time: <time>
	// -Difficulty: <difficulty>
	// -Direction: <Direction steps>
    //+<number of elements at this index> -1 more similar book(s)
    //<new line><new line><new line>

private:
	static const int SIZE1 = 50;
	static const int SIZE2 = 800;
	static signed wordID;
	static vector<string> keyVector;

	BST<Recipe> Table1[SIZE1];
	List<string> Table2[SIZE2];
};


signed HashTable::wordID = -1;




#endif /* HASHTABLE_H_ */
