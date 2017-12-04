/*
 * HashTable.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: KVTran
 */



# include "HashTable.h"

signed HashTable::wordID = -1;
vector<string> HashTable::keyVector;

/************* Access Functions *************/




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


/************ Manipulation Procedures ************/

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



/*
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
*/



/************ Additional Functions ************/

void HashTable::printBucket_table1(ostream& out, int index) const
{
	assert(0 <= index && index <= SIZE1);
	Table1[index].inOrderPrint(cout);
}
