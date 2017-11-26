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

    HashTable(){}
    //constructor

    ~HashTable(){}
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
    int VECsearch(string word)const;
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table
    int BSTsearch(Recipe r) const;
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table
    int IDsearch(wordID id) const;
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

    void BSTinsert(Recipe r, int index);
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

     vector<string> wordBank;
     int Counter = 0;
    //string Array[50];

private:

    static const int SIZE = 50;
    List<wordID> Table[SIZE];
    BST<Recipe> Table1[SIZE];
};

#endif /* HASHTABLE_H_ */
