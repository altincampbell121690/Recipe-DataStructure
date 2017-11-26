//============================================================================
// Name        : Recipe_DataStructure.cpp
// Author      : Khang V. Tran
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

#include "Recipe.h"

void readAndStore(ifstream& fin);
// This function read in data from the text file
// and create Recipe object

int main() {


	// open database and check
	ifstream fin;
	fin.open("database.txt");
	if (fin.fail())
	{
		cout << "Fail to open input file" << endl;
		exit(-1);
	}

	readAndStore(fin);

	// close the file openning
	fin.close();
	return 0;
}

void readAndStore(ifstream& fin)
{
	string name, category, flavor, buf;
	string ingredients = "";
	string direction = "";
	unsigned time, difficulty;

	int count = 0;
	while (getline(fin, name))
	{
		count++;
		cout << count << "." << endl;

		getline(fin, category);
		getline(fin, flavor);

		// read and concatenate ingredients until hitting a #
		do
		{
			getline(fin, buf);
			if (buf.find("#") == std::string::npos) ingredients += buf;
		} while(buf.find("#") == std::string::npos);

		getline(fin, buf);
		time = stoi(buf);

		getline(fin, buf);
		difficulty = stoi(buf);

		// read and concatenate to direction until hitting a #
		do
		{
			getline(fin, buf);
			if (buf.find("#") == std::string::npos) direction += buf;
		} while(buf.find("#") == std::string::npos);

		// get the blankspace
		getline(fin, buf);


		Recipe recipe(name, category, flavor, ingredients, time, difficulty, direction);
		cout << recipe << endl;

		// reset Ingredients and Direction for the next recipe to be read in
		ingredients = "";
		direction = "";
	}



}



