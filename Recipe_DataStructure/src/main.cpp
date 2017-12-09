//============================================================================
// Name        : Recipe_DataStructure.cpp
// Author      : Khang V. Tran
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


# include "main.h"

void displayOptions(HashTable & ht, BST<Recipe> & bst, string& nonKeys);

void addObj(HashTable& ht, BST<Recipe>& bst, string& nonKeys);

void searchRecipes(HashTable& ht, BST<Recipe> & recipe);
//void searchRecipes( );

void writeData();

void statistics();



//TODO: Remove the testing stuff and move it to a test file. Or delete it entirely.
int main() {

	cout << "Welcome to the Recipe catalogue!" << endl;
	int count = 0;

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
	readAndStore(fin1, nonKeys, bst, idTable, count);


	//bst.inOrderPrint(cout);
	//idTable.printTable(cout)
	//idTable.printTableID(cout);
	//idTable.printBucket(cout, 54);
	//string userInput = "cream";
	//KeyWordSearch(userInput, idTable);




	// the real program to be run
	displayOptions(idTable, bst, nonKeys);


	// Aoother Testing Zone
	string nameTest = "Tapioca Pudding";
	string categoryTest = "Pudding";
	string flavorTest = "Vanilla";
	Recipe recipeTest(nameTest, categoryTest, flavorTest, "", 1, 1, "");
	setKeysForObject(recipeTest, nonKeys);
	//cout << bst.search(recipeTest) << endl;
/*
 	// Test Zone for remove from HT
	Recipe Test = bst.getNode_Wrapper(recipeTest);
	cout << Test << endl;
	cout << "#################################" << endl << endl;;
	idTable.printBucket(cout, 55);
	cout << "#################################" << endl << endl;;
	idTable.BSTremove(Test);
    idTable.printBucket(cout,55);
	cout << "#################################" << endl<< endl;
*/

/*
	// Test Zone for remove from the separated BST
	cout << bst.search(recipeTest) << endl;   // print 1 if found
	//PrimaryKeySearch(bst, nameTest, categoryTest, flavorTest); // search and print the exact object
	bst.inOrderPrint(cout);
	cout << "#################################" << endl<< endl;
	bst.remove(recipeTest);
	bst.inOrderPrint(cout);
*/

	//idTable.printTableID(cout);
	//cout << "#################################" << endl;
	//idTable.BSTinsert(recipeTest);
	//idTable.printTable(cout);
	//idTable.BSTremove(recipeTest);
	//idTable.printTable(cout);


	// close the file openning
	fin1.close();
	fin2.close();
	return 0;

}

void displayOptions(HashTable & ht, BST<Recipe> & bst, string& nonKeys)
{
    int option = 0;

	while (option != 7) {
	    cout << endl;
	    cout << "1. Add recipe" << endl;
	    cout << "2. Delete recipe" << endl;
	    cout << "3. Search recipe" << endl;
	    cout << "4. Sort recipes" << endl;
	    cout << "5. Write results to file" << endl;
	    cout << "6. Display statistics" << endl;
	    cout << "7. Quit" << endl;
	    cout << "\nEnter the option you wish to perform (1-7): ";
	    cin >> option;

	    if (cin.fail())
	    {
	    		cin.clear();
	    		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        	cout << endl << "Please enter numbers not letters" << endl;
	    }


	    //blank cases refer to the options provided above
	    switch (option) {
	    case 1:
	    {
	    		cin.ignore();
	    		addObj(ht, bst, nonKeys);
	    		break;
	    }
	    case 2:
	    {

	    		break;
	    }
	    case 3:
	    {
	    		cin.ignore();
	    		searchRecipes(ht, bst);
			break;
	    }
	    case 4:
	    {
	    		cout <<endl;
	    		cout << "List of Recipes, sorted by Name, secondly by Category, and thirdly by Flavor:" << endl;
	    		bst.inOrderPrint(cout);
	    		cout << endl << "End of sorting" << endl;
	    		break;
	    }
	    case 5:
	    {
	    		writeData();
	    		break;
	    }
	    case 6:
	    {
	    		break;
	    }
	    case 7:
	    {
	    		break;
	    }
		return;
		{
			break;
		}
	    default:
		cout << "Invalid option. Try again with option from 1-7." << endl << endl;
	    }
	}

}


void addObj(HashTable& ht, BST<Recipe>& bst, string& nonKeys)
{
	string name, category, flavor, ingredients, direction, buf;
	unsigned difficulty, time;

	cout << "Enter the information needed or enter 0 to terminate the process!" << endl;;
	cout << "Enter the name: ";
	getline(cin, name);
	if (name == "0") return;

	cout << "Enter the category: ";
	getline(cin, category);
	if (category == "0") return;


	cout << "Enter the flavor: ";
	getline(cin, flavor);
	if (flavor == "0") return;

	cout << "Enter the ingredients, use commas as delimeter: ";
	getline(cin, ingredients);
	if (ingredients == "0") return;


	cout << "Enter the time: ";
	getline(cin, buf);
	time = stod(buf);
	if (time == 0) return;


	cout << "Enter the difficulty (1 if unsure): ";
	getline(cin, buf);
	difficulty = stod(buf);
	if (difficulty == 0) return;


	cout << "Enter the direction: ";
	getline(cin, direction);
	if (direction == "0") return;

	Recipe recipe(name, category, flavor, ingredients, time, difficulty, direction);
	setKeysForObject(recipe, nonKeys);
	if (bst.search(recipe))
	{
		cout << endl << "This recipe is already in the catalouge. Return to menu" << endl;
		return;
	}
	bst.insert(recipe);      // insert to the separated BST
	idCreator(recipe, ht);
	ht.BSTinsert(recipe);    // insert to the HashTable
	cout << endl << "The recipe has been inserted to the catalouge:" << endl;
	cout << recipe << endl;

	//bst.printNode_Wrapper(recipe);   // tested: New eecipe has been inserted into the separated BST
	// ht.printTable(cout);            // tested: new recipe has been inserted into the HT

}




void searchRecipes(HashTable& ht, BST<Recipe> & bst)
{
    int option;
    cout << "Search" << endl << endl;
    cout << "1. Exact search with name, category, and flavor" << endl;
    cout << "2. Keyword Search" << endl;
    cout << "3. Quit" << endl;
    cout << "\nEnter the option you wish to perform (1-3): ";
    cin >> option;
    //blank cases refer to the options for search
    switch (option) {
    case 1:
    {
    		cin.ignore();
    		string name, category, flavor;
    		cout << "Enter the name: ";
    		getline(cin, name);
    		cout << "Enter the category: ";
    		getline(cin, category);
    		cout << "Enter your flavor: ";
    		getline(cin, flavor);

    		Recipe recipe(name, category, flavor, "", 1, 1, "");
    		if (!bst.search(recipe))
    		{
    			cout << "This recipe does not exist in our catalogue" << endl;
    		}
    		else
    		{
    			bst.printNode_Wrapper(recipe);
    		}
    		break;
    }
    case 2:
    {

    		break;
    }
    case 3:
    {
    		return;
    }
    default:
	cout << "Invalid option. Try again." << endl << endl;
    }
    cout << "End of search" << endl;
}

void writeData() {
    //TODO: What needs to happen here?
}

void statistics() {
    //TODO: provide the functions for collecting the statistics here.
}


