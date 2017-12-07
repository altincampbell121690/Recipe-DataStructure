
//============================================================================
// Name        : Hashtable.cpp
// Author      : Altin & Erik the great
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include "List.h"
#include "BST.h"
#include "Recipe.h"
#include "WordID.h"
#include <vector>
using namespace std;
class HashTable {
public:
	/**Constructors*/

	HashTable() {
	}
	//constructor

	~HashTable() {
	}
	//destructor

	/**Access Functions*/

	int hash(string key) const;
	//returns the hash value for the given key
	//the hash value is the sum of
	//of the ASCII values of each char in the key
	//% the size the of the table
	//Key for this table: title + author

	int countBucket(int index) const;
	//counts the number of Books at this index
	//returns the count
	//pre: 0<= index < SIZE
	int VECsearch(string word) const;
	//Searches for b in the table
	//returns the index at which b is located
	//returns -1 if b is not in the table
	int BSTsearch(Recipe r) const;
	//Searches for b in the table
	//returns the index at which b is located
	//returns -1 if b is not in the table
	int IDsearch(wordID id);
	//Searches for b in the table
	//returns the index at which b is located
	//returns -1 if b is not in the table

	/**Manipulation Procedures*/
	void IDinsert(wordID idWOrd);
	//inserts a new book into the table
	//calls the hash function on the key to determine
	//the cortherect bucket

	void IDremove(wordID idWord);
	//removes idWord from  table
	//calls the hash function on the key to determine
	//the correct bucket
	//pre: b is in the table

	void BSTinsert(Recipe r);
	//inserts a new Recipe into the table
	//calls the hash function on the key to determine
	//the correct bucket

	void BSTremove(Recipe r);
	//removes r from the table
	//calls the hash function on the key to determine
	//the correct bucket
	//pre: b is in the table

	/**Additional Functions*/

	void printBucket(ostream& out, int index) const;
	//Prints all the books at index
	//pre: 0<= index < SIZE
	//Should print according to the following formula:
	//Prints each book at that index in the format:
	//<title> by <author>
	//$<X.XX>
	//ISBN#: <isbn>
	//followed by a blank line

	void printTable(ostream& out) const;
	//Prints the first book at each index
	//along with a count of the total books
	//at each index by calling count_bucket
	//as a helper function
	//Prints in the format:
	//Books in the Catalogue:
	//<new line>
	//Group <bucket>
	//<title> by <author>
	//$<X.XX>
	//ISBN: <isbn>
	//+<number of elements at this index> -1 more similar book(s)
	//<new line><new line><new line>

	void printTableID(ostream& out) const;

	int Counter = 0;
	//string Array[50];
	vector<string> wordBank;

private:

	static const int SIZE = 1000;
	List<wordID> listTable[SIZE];
	BST<Recipe> bstTable[SIZE];
};

#endif /* HASHTABLE_H_ */




/*

 * HashTable.h
 *
 *  Created on: Dec 3, 2017
 *      Author: KVTran


#ifndef HASHTABLE_H_
#define HASHTABLE_H_

# include <string>
# include "Recipe.h"
# include "BST.h"
# include "List.h"

class HashTable {
public:
	Constructor and Destructor
	HashTable() { };
	~HashTable() { };


	Access function
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


	************ Manipulation Procedures ************

	void insert(Recipe recipe);
    //inserts a new recipe into the table
    //calls the hash function on the key to determine
    //the correct bucket

	void remove(Recipe recipe);
    //removes recipe from the table
    //calls the hash function on the key to determine
    //the correct bucket
    //pre: recipe is in the table


	Additional Function
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
	static const int SIZE1 = 1000;
	static const int SIZE2 = 800;
	static signed wordID;
	static vector<string> keyVector;

	BST<Recipe> Table1[SIZE1];
	List<string> Table2[SIZE2];
};





#endif  HASHTABLE_H_
*/


