//============================================================================
// Name        : Recipe_DataStructure.cpp
// Author      : Khang V. Tran
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


# include "main.h"

void displayOptions();
void searchRecipes();
void writeData();
void statistics();

//TODO: Remove the testing stuff and move it to a test file. Or delete it entirely.
int main() {

	cout << "Welcome to the Recipe Search!" << endl;

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

	// the real program to be run
	displayOptions();

	string nameTest = "Vanilla Pudding";
	string categoryTest = "Pudding";
	string flavorTest = "Vanilla";
	Recipe recipeTest(nameTest, categoryTest, flavorTest, "", 1, 1, "");
	cout << bst.search(recipeTest) << endl;

	PrimaryKeySearch(bst, nameTest, categoryTest, flavorTest);

	// close the file openning
	fin1.close();
	fin2.close();
	return 0;

}

void displayOptions() {
        int option = 0;

	while (option != 7) {
	    cout << endl << "1. Add recipe" << endl;
	    cout << "2. Delete recipe" << endl;
	    cout << "3. Search recipe" << endl;
	    cout << "4. Sort recipes" << endl;
	    cout << "5. Write results to file" << endl;
	    cout << "6. Display statistics" << endl;
	    cout << "7. Quit" << endl;
	    cout << "\nEnter the option you wish to perform (1-7)";
	    cin >> option;

	    //blank cases refer to the options provided above
	    switch (option) {
	    case 1:
	    case 2:
	    case 3:
		searchRecipes();
		break;
	    case 4:
	    case 5:
		writeData();
		break;
	    case 6:
	    case 7:
		return;
	    default:
		cout << "Invalid option. Try again." << endl << endl;
	    }
	}

}

// I apologize for the difference in indentation in advance.
void searchRecipes() {
    
#ifdef __APPLE__ //can't confirm that this works on windows machines
    system("cls"); // clears the console for readability. only works on unix.
#endif
    
    int option;
    
    cout << "Search" << endl << endl;
    cout << "1. Exact search" << endl;
    cout << "2. Keyword Search" << endl;
    cout << "3. Quit" << endl;
    cout << "\nEnter the option you wish to perform (1-3):";
    cin >> option;

    //blank cases refer to the options for search
    switch (option) {
    case 1:
    case 2:
    case 3:
	return;
    default:
	cout << "Invalid option. Try again." << endl << endl;
    }
}

void writeData() {
    //TODO: What needs to happen here?
}

void statistics() {
    //TODO: provide the functions for collecting the statistics here.
}


