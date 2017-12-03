/*
 * HashTable.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: KVTran
 */



# include "HashTable.h"

vector<string> HashTable::keyVector;

/************* Access Functions *************/




int HashTable::hash(string& key) const
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++) sum += (int) key[i];
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
	if (Table2[index].isEmpty()) return -1;
	else if (Table2[index].linearSearch(key) == -1) return -1;
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


/************ Manipulation Procedures ************/


void HashTable::insert(Recipe recipe)
{

	vector<string> keys = recipe.get_keys();
	for (int i = 0; i < keys.size(); i++)
	{
		string key = keys[i];
		int index = search_table2(key);
		if (index == -1)    // keyword not found in table 2
		{
			Table2[index].insertStop(key);
			keyVector.push_back(key);
			wordID++;                                // determine an index to use in table1
			Table1[wordID].insert(recipe);           // insert word into table 2
		}
		else
		{
			int indexTable1 = search_KeyVector(key); // get the index for table 1
			Table1[indexTable1].insert(recipe);      // insert recipe object into that index of table 1
		}
	}
}




/************ Additional Functions ************/

void HashTable::printBucket_table1(ostream& out, int index) const
{
	assert(0 <= index && index <= SIZE1);
	Table1[index].inOrderPrint(cout);
}
