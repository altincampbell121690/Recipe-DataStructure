//============================================================================
// Name        : HashBST.cpp
// Author      : Altin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <assert.h>

#include "HashTable.h"

using namespace std;

int HashTable::Counter = 0;
vector<string> HashTable::wordBank;


/************************Access Functions*****************/
int HashTable::hash(string key) const {
	int sum = 0;
	for (unsigned int i = 0; i < key.length(); i++)
		sum += (int) key[i];
	return (sum % SIZE);
}
int HashTable::countBucket(int index) const {
	assert((0 <= index) && (index < SIZE));
	return bstTable[index].getSize();
}

int HashTable::VECsearch(string word) const {
	vector<string>::iterator Iterator;
	//int i = 0;
	int index = -1;
	for (unsigned int i = 0; i < wordBank.size(); i++) {
		if (wordBank[i] == word)
			index = i;
	}
	return index;
}

//search array for word
//returns -1 if b is not in the table

/*int HashTable::search(Recipe r) const // FIXXX++++++++++++++++++++++
 {
 string key = r.get_Name()+r.get_Category()+r.get_Flavor();
 if (Table1[hash(key)].isEmpty()){
 cout << "empty\n";
 return -1;
 }
 else if(Table1[hash(key)].search(r))
 return hash(key);
 else{
 cout << "NOT FOUND\n";
 return -1;
 }

 }*/
//Prints all the books at index according to inOrderPrint
//pre: 0<= index < SIZE
//Should print according to the following formula:
//Prints each book at that index in the format:
//<title> by <author>
//$<X.XX>
//ISBN#: <isbn>
//followed by a blank line
void HashTable::printBucket(ostream& out, int index) const {
	assert((0 <= index) && (index < SIZE));
	bstTable[index].inOrderPrint(out);
}

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
void HashTable::printTable(ostream& out) const {
	out << "Recipes in the Catalogue:\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (!bstTable[i].isEmpty()) {
			out << "Group: " << i + 1;
			out << bstTable[i].getRoot();
			out << '+' << countBucket(i) - 1 << " or more similar recipe(s)\n"
					<< endl;
		}

	}
}

void HashTable::printTableID(ostream& out) const {
	out << "Word ID's in the Catalogue:\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (!listTable[i].isEmpty()) {
			out << "Group: " << i + 1;
			listTable[i].print();
			out << '+' << countBucket(i) - 1 << " or more similar keyword(s)\n"
					<< endl;
		}
	}
}

/*********************Manipulation Procedures**************/
void HashTable::BSTinsert(Recipe r) {
	///need to call something to ensure the keyword array has key words
/***************************************
string keyword = r.get_keys()[1];
int index = VECsearch(keyword);
if (bstTable[index].search(r)){
****************************************8**/
	unsigned int j;
	unsigned int k;
	//cout << "num of key words in recipe vector: " << r.get_keys().size()<< endl;
	for (j = 0; j < r.get_keys().size(); j++) {
		if (j < r.get_keys().size())
			for (k = 0; k < wordBank.size(); k++) {
				if (r.get_keys()[j] == wordBank[k]) {
					bstTable[k].insert(r);

				}

			}
	}
	//return true
}
/*******
else{
	cout << "this recipe exists already\n";
   return false;
   }
 }
*********/

void HashTable::BSTremove(Recipe r) {
	unsigned int j;
	unsigned int k;
	//for (int i = 0; i < SIZE; i++){//goes through the hashBST index
	for (j = 0; j < r.get_keys().size(); j++) {
		for (k = 0; k < wordBank.size(); k++) {
			if (r.get_keys()[j] == wordBank[k])
				bstTable[k].remove(r);

		}
	}
}

int HashTable::IDsearch(wordID id) {
	string key = id.get_Word();
	int index = hash(key), found = -1;
	//if (listTable[index].linearSearch(id) > -1)
	listTable[index].pointIterator();
	for (int i = 1; i <= listTable[index].getSize(); i++) {
		if (id.get_Word() == listTable[index].getIterator().get_Word())
			found = listTable[index].getIndex();
		//cout << id.get_Word() << " == "
				//<< listTable[index].getIterator().get_Word() << endl;
		listTable[index].advanceIterator();
	}

	return found;
}

//inserts a new book into the table
//calls the hash function on the key to determine
//the correct bucket
void HashTable::IDinsert(wordID id) {
	string key = id.get_Word();
	int index = hash(key);
	if (IDsearch(id) == -1) {
		id.set_ID(Counter);
		listTable[index].insertStop(id);
		wordBank.push_back(id.get_Word());
		//wordBank[Counter]=id.get_Word();
		Counter++;
	}
	//else
	//cout << "Already in the table." << endl;

}

//removes b from the table
//calls the hash function on the key to determine
//the correct bucket
//pre: b is in the table
void HashTable::IDremove(wordID id) {
	string key = id.get_Word();
	int i = hash(key);
	assert(listTable[hash(key)].linearSearch(id));
	int index = listTable[i].linearSearch(id);
	listTable[i].advanceToIndex(index);
	listTable[i].removeIterator();
}













/*

 * HashTable.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: KVTran




# include "HashTable.h"

signed HashTable::wordID = -1;
vector<string> HashTable::keyVector;

************ Access Functions ************




int HashTable::hash(string& key) const
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++) sum += (int) key[i];
	cout << "Hash Value: " << sum % SIZE2 << endl;
	return (sum % SIZE2);
}

int HashTable::countBucket_table1(int index) const
{
	assert(0 <= index && index < SIZE1);
	return Table1[index].getSize();

}

int HashTable::countBucket_table2(int index) const
{
	assert(0 <= index && index < SIZE2);
	return Table2[index].getSize();
}

// search the index of the key word in table 2
int HashTable::search_table2(string key) const
{
	int index = hash(key);
	cout << "search_table2 index: " << index << endl;
	if (Table2[index].isEmpty())
	{
		cout << "search Table2: index empty" << endl;
		return -1;
	}
	else if (Table2[index].linearSearch(key) == -1)
	{
		cout << "search Table2: Not found" << endl;
		return -1;
	}
	else return index;
}



int HashTable::search_KeyVector(string& key) const
{
	for (int i = 0; i < keyVector.size(); i++)
	{
		if (keyVector[i] == key) return i;
	}
	return -1;
}


*********** Manipulation Procedures ***********

void HashTable::insert(Recipe recipe)
{
	vector<string> keys = recipe.get_keys();
	cout << "Number of Keys: "<< keys.size() << endl;
	for (int i = 0; i < keys.size(); i++)
	{
		string key = keys[i];
		cout << i << ": " << key << endl;
		int wordID = search_KeyVector(key);
		if (wordID != -1)
		{
			cout << key << ": word already exist" << endl;
			Table1[wordID].insert(recipe);
		}
		else
		{
			cout << key << ": new word" << endl;
			keyVector.push_back(key);
			wordID = search_KeyVector(key);
			Table1[wordID].insert(recipe);

			int idTable2 = hash(key);
			Table2[idTable2].insertStart(key);
		}

	}
}




void HashTable::insert(Recipe recipe)
{
	vector<string> keys = recipe.get_keys();
	cout << "Number of Keys: "<< keys.size() << endl;
	for (int i = 0; i < keys.size(); i++)
	{
		string key = keys[i];
		cout << i << ": " << key << endl;
		int index = search_table2(key);
		cout << "index: " << index << endl;
		if (index == -1)    // keyword not found in table 2
		{
			Table2[index].insertStop(key);
			//Table2[index].print();
			keyVector.push_back(key);
			wordID++;                                // determine an index to use in table1
			cout << "check in key not found. wordID: " << wordID << endl;
			Table1[wordID].insert(recipe);           // insert word into table 2
			cout << "check in key not found end" << endl;
		}
		else
		{
			cout << "check in key found" << endl;
			int indexTable1 = search_KeyVector(key); // get the index for table 1
			Table1[indexTable1].insert(recipe);      // insert recipe object into that index of table 1
		}
	}
}




*********** Additional Functions ***********

void HashTable::printBucket_table1(ostream& out, int index) const
{
	assert(0 <= index && index <= SIZE1);
	Table1[index].inOrderPrint(cout);
}
*/
