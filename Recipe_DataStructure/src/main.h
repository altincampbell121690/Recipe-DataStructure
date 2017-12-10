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
# include "HashTable.h"
# include "WordID.h"



void idCreator(Recipe&, HashTable&);
void keyWordStat(ostream& out, HashTable& ht);
void mostUsed(ostream& out, HashTable& ht);

void readAndStore(ifstream& fin, string& nonKeys, BST<Recipe>& bst,
		HashTable& ht, int& count);
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

void KeyWordSearch(string userInput, HashTable& HT);



void PrimaryKeySearch(BST<Recipe>& bst, string& name, string& category, string& flavor);
// print the exact object from the separated BST
// Should be used in option 3




void idCreator(Recipe& recipe, HashTable& hashTable1) {
	wordID one;
	for (unsigned int i = 0; i < recipe.get_keys().size(); i++) {
		one.set_Word(recipe.get_keys()[i]);
		hashTable1.IDinsert(one);
	}

}

void readAndStore(ifstream& fin, string& nonKeys, BST<Recipe>& bst, HashTable& idHT, int& count) {
	string name, category, flavor, buf;
	string ingredients = "";
	string direction = "";
	unsigned time, difficulty;
	vector<string> keys;

	//int count = 0;
	while (getline(fin, name)) {
		count++;
		//cout << count << "." << endl;

		getline(fin, category);
		getline(fin, flavor);

		// read and concatenate ingredients until hitting a #
		do {
			getline(fin, buf);
			if (buf.find("#") == string::npos)
				ingredients += buf + "\n";
		} while (buf.find("#") == string::npos);

		getline(fin, buf);
		time = stoi(buf);

		getline(fin, buf);
		difficulty = stoi(buf);

		// read and concatenate to direction until hitting a #
		do {
			getline(fin, buf);
			if (buf.find("#") == string::npos)
				direction += buf;
		} while (buf.find("#") == string::npos);

		// get the blankspace
		getline(fin, buf);

		// create the keys vector

		// Create the recipe object
		Recipe recipe(name, category, flavor, ingredients, time, difficulty,
				direction);
		setKeysForObject(recipe, nonKeys); // the object key was empty until we setKeys

		//printStringVector(cout, recipe.get_keys());
		//cout << endl
		//<< "**************************************************************"
		//<< endl;

		// Insert the object into the
		bst.insert(recipe);
		idCreator(recipe, idHT);
		idHT.BSTinsert(recipe);

		// reset Ingredients and Direction for the next recipe to be read in
		ingredients = "";
		direction = "";
	}

}




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


void KeyWordSearch(string userInput, HashTable& HT)
{
	int index = HT.VECsearch(userInput);
	if (index == -1)
	{
		cout << "Found no recipes with this key word" << endl;
		return;
	}
	HT.printBucket(cout,index);
}

void PrimaryKeySearch(BST<Recipe>& bst, string& name, string& category, string& flavor)
{
	Recipe recipe(name, category, flavor, "test", 1, 1, "");
	if (!bst.search(recipe))
	{
		cout << "This recipe does not exist." << endl;
	}
	else
	{
		bst.printNode_Wrapper(recipe);
	}
}


void printStringVector(ostream& out, vector<string> v) {
	for (unsigned int i = 0; i < v.size(); i++)
		out << v[i] << " ";
	out << endl;
}


void keyWordStat(ostream& out, HashTable& ht){
	string keyWord;
	cout << "Please enter an ingredient, flavor, or category \n";
	getline(cin, keyWord);
	int index = ht.VECsearch(keyWord);
	if(index == -1)
		out << "there are 0 recipes that fit this description \n";
	else{
		out << "there are " << ht.countBucket(index)<<" recipes that fit this description \n";
	}
}

void mostUsed(ostream& out, HashTable& ht){
	int Size = 0, index = -1;
	for (int i = 0; i < ht.getWordBankSIZE(); i++){
		if (Size < ht.countBucket(i)){
			Size = ht.countBucket(i);
			index = i;
		}
	}
 out << ht.getWordBank(index) << " is the most used ingredient/flavor with " << Size << "associated recipes\n";
}


#endif /* MAIN_H_ */
