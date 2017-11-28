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
#include "Hashtable.h"
#include "BST.h"
#include "List.h"
#include "wordID.h"
#include <assert.h>

using namespace std;


/************************Access Functions*****************/
int HashTable::hash(string key) const
{
	int sum = 0;
	for (unsigned int i = 0; i < key.length(); i++)
		sum += (int)key[i];
	return (sum % SIZE);
}
int HashTable::countBucket(int index) const
{
	assert((0 <= index) && (index < SIZE));
	return Table[index].getSize();
}

int HashTable::VECsearch(string word)const{
	vector<string>::iterator Iterator;
	int i = 0;
	int index = -1;
	for (Iterator = wordBank.begin(); Iterator != wordBank.end(); Iterator++,i++){
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
void HashTable::printBucket(ostream& out, int index) const
{
	assert((0 <= index) && (index < SIZE));
	Table1[index].inOrderPrint(out);
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
void HashTable::printTable(ostream& out) const
{
	out << "Books in the Catalogue:\n" << endl;
	for(int i = 0; i < SIZE; i++)
	{
		if(!Table[i].isEmpty())
		{
			out << "Group: " << i+1;
		    out << Table1[i].getRoot();
		    out << '+' << countBucket(i)-1 << " or more similar book(s)\n" << endl;
		}
	}
}

/*********************Manipulation Procedures**************/
void HashTable::BSTinsert(Recipe r, int index){
	///need to call something to ensure the keyword array has key words
	vector<string>::iterator Iterator1;
	vector<string>::iterator Iterator2;
	int j = 0;
	int k = 0;
	//for (int i = 0; i < SIZE; i++){//goes through the hashBST index
		for(Iterator1= r.keyword.begin(); Iterator1 != r.keyword.end(); Iterator1++, j++){
			for(Iterator2= wordBank.begin(); Iterator2 != wordBank.end(); Iterator2++, k++){
				if(k < SIZE){
			       if (r.keyword[j] == wordBank[k])
				       Table1[k].insert(r);
				}

		     }
		}

}

void HashTable::BSTremove(Recipe r){

}

int HashTable::IDsearch(wordID id) const{
	string key = id.get_Word();
	int index = hash(key);
		if (Table[index].linearSearch(id) > -1)
		return index;
		else return -1;
}

//inserts a new book into the table
//calls the hash function on the key to determine
//the correct bucket
void HashTable::IDinsert(wordID id){
	string key = id.get_Word();
	int index = hash(key);
	if (IDsearch(id) == -1){
		id.set_ID(Counter);
		Table[index].insertStop(id);
		wordBank[Counter]=id.get_Word();
		Counter++;
	}
	else
	cout << "already in table" << endl;

}

//removes b from the table
//calls the hash function on the key to determine
//the correct bucket
//pre: b is in the table
void HashTable::IDremove(wordID id){
	string key = id.get_Word();
	int i = hash(key);
	assert(Table[hash(key)].linearSearch(id));
	int index = Table[i].linearSearch(id);
	Table[i].advanceToIndex(index);
	Table[i].deleteIterator();
}
