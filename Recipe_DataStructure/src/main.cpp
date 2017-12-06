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
	bst.inOrderPrint(cout);
	//idTable.printTable(cout);
	//idTable.printTableID(cout);

	//idTable.printBucket(cout, 54);
	//string userInput = "cream";
	//KeyWordSearch(userInput, idTable);

	string nameTest = "Vanilla Pudding";
	string categoryTest = "Pudding";
	string flavorTest = "Vanilla";
	Recipe recipeTest(nameTest, categoryTest, flavorTest, "", 1, 1, "");
	cout << bst.search(recipeTest) << endl;;

	PrimaryKeySearch(bst, nameTest, categoryTest, flavorTest);

	// close the file openning
	fin1.close();
	fin2.close();
	return 0;

}


