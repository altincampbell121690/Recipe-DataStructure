//============================================================================
// Name        : Recipe_DataStructure.cpp
// Author      : Khang V. Tran
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


# include "main.h"


int main() {

	HashTable idTable;
	BST<Recipe> bst;

	// open database and check
	ifstream fin1;
	fin1.open("database.txt");
	if (fin1.fail()) {
		cout << "Fail to open input file" << endl;
		exit(-1);
	}

	ifstream fin2;
	fin2.open("non_key_words.txt");
	if (fin2.fail()) {
		cout << "Fail to open non_key_words file" << endl;
		exit(-1);
	}

	string nonKeys = "";
	readAndAppend(fin2, nonKeys);

	//cout << (nonKeys) << endl;;
	//cout << endl << "**************************************************************" << endl;

	readAndStore(fin1, nonKeys, bst, idTable);
	//bst.inOrderPrint(cout);
	//idTable.printTable(cout);
	//idTable.printTableID(cout);

	idTable.printBucket(cout, 54);


	// close the file openning
	fin1.close();
	fin2.close();
	return 0;

}

void idCreator(Recipe& recipe, HashTable& hashTable1) {
	wordID one;
	for (unsigned int i = 0; i < recipe.get_keys().size(); i++) {
		one.set_Word(recipe.get_keys()[i]);
		hashTable1.IDinsert(one);
	}

}

void readAndStore(ifstream& fin, string& nonKeys, BST<Recipe>& bst,
		HashTable& idHT) {
	string name, category, flavor, buf;
	string ingredients = "";
	string direction = "";
	unsigned time, difficulty;
	vector<string> keys;

	int count = 0;
	while (getline(fin, name)) {
		count++;
		//cout << count << "." << endl;

		getline(fin, category);
		getline(fin, flavor);

		// read and concatenate ingredients until hitting a #
		do {
			getline(fin, buf);
			if (buf.find("#") == string::npos)
				ingredients += buf;
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

