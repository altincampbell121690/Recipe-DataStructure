/*
 * List.h
 *
 *	Khang Vinh Tran, Tri Doan
 *  CIS 22C, Lab 8
*/


#include <iostream>
#include <cstddef> //for NULL
#include <assert.h>
#include <string>
#include "HashTable.h"
#include "Recipe.h"
#include "BST.h"

using namespace std;

int HashTable::hash(string key) const
{

	int index;
	int sum = 0;
	for(unsigned int i = 0; i < key.length(); i++)
	{
		sum += (int)key[i];
	}
	index = sum % SIZE;

	return index;
}

int HashTable::countBucket(int index) const
{
	assert(0 <= index && index < SIZE);
	return Table[index].getSize();
}

int HashTable::search(Recipe b) const
{
	string key = b.get_Name() + b.get_Category();
	int index = hash(key);
	if (Table[index].isEmpty()) return -1;
	else if (!Table[index].search(b)) return -1;
	else return index;
}

void HashTable::insert(Recipe b)
{
	string key = b.get_Name() + b.get_Category();
	int index = hash(key);
	Table[index].insert(b);
}

void HashTable::remove(Recipe b)
{
	string key = b.get_Name() + b.get_Category();
	int index = hash(key);
	Table[index].remove(b);
}

void HashTable::printBucket(ostream& out, int index) const
{
	assert(0 <= index && index <= SIZE);
	Table[index].inOrderPrint(out);
}


void HashTable::printTable(ostream& out) const
{
	out << "Books in the Recipe:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (!Table[i].isEmpty())
		{
			out << "Group " << i+1 << endl;
			out << Table[i].getRoot() << endl;
			out << "+" << countBucket(i) - 1 <<" more similar book(s)" << endl << endl << endl;
		}
	}
}
