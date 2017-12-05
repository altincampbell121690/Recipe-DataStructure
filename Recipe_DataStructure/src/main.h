/*
 * main.h
 *
 *  Created on: Dec 5, 2017
 *      Author: KVTran
 */

#ifndef MAIN_H_
#define MAIN_H_

# include <iostream>
# include <fstream>

# include <algorithm>
# include <vector>
# include <sstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

# include "Recipe.h"
# include "BST.h"
#include "HashTable.h"
#include "WordID.h"


void idCreator(Recipe&, HashTable&);

void readAndStore(ifstream& fin, string& nonKeys, BST<Recipe>& bst,
		HashTable& ht);
// This function read in data from the text file
// and create Recipe object
void readAndAppend(ifstream& fin, string& str);
// Read in a file and append every single word
// separated by a space into a string
void setKeysForObject(Recipe& recipe, string& nonKeys);
// wrapper function:
// call getKeysFromString for every field of the object
void getKeysFromString(string field, string nonKeys, vector<string>& keys);
// Helper function: from the field (type string), check if each word is in nonKey string
// If not, process the word, and append it into keys vector of object
void printStringVector(ostream& out, vector<string> v);
// print out a string vector
// all element are separated with a space





void readAndAppend(ifstream& fin, string& str) {
	string buf;
	while (fin >> buf)
		str += " " + buf;
}

void setKeysForObject(Recipe& recipe, string& nonKeys) {
	vector<string> keys;
	getKeysFromString(recipe.get_name(), nonKeys, keys);
	getKeysFromString(recipe.get_category(), nonKeys, keys);
	getKeysFromString(recipe.get_flavor(), nonKeys, keys);
	getKeysFromString(recipe.get_ingredients(), nonKeys, keys);
	getKeysFromString(recipe.get_direction(), nonKeys, keys);
	recipe.set_keys(keys);
}

void getKeysFromString(string field, string nonKeys, vector<string>& keys) {
	istringstream iss(field);
	while (iss) {
		string word;
		iss >> word;
		if (nonKeys.find(word) == std::string::npos)
			keys.push_back(word);
	}

	// process the key in keys vector
	for (unsigned int i = 0; i < keys.size(); i++) {
		for (unsigned int j = 0; j < keys[i].length(); j++) {
			if (isupper(keys[i][j]))
				keys[i][j] = tolower(keys[i][j]);
		}
		if (ispunct(keys[i][keys[i].length() - 1])) {
			keys[i] = keys[i].substr(0, keys[i].length() - 1);
		}
	}
	// sort and make unique of the vector
	sort(keys.begin(), keys.end());
	keys.erase(unique(keys.begin(), keys.end()), keys.end()); // only take the unique keys

}

void printStringVector(ostream& out, vector<string> v) {
	for (unsigned int i = 0; i < v.size(); i++)
		out << v[i] << " ";
	out << endl;
}




#endif /* MAIN_H_ */
