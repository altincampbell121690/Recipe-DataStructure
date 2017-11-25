//============================================================================
// Name        : Recipe_DataStructure.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

void readAndStore(ifstream& fin);

int main() {
	ifstream fin;
	fin.open("database.txt");
	if (fin.fail())
	{
		cout << "Fail to open input file" << endl;
		exit(-1);
	}

	readAndStore(fin);

	fin.close();
	return 0;
}

void readAndStore(ifstream& fin)
{
	string name, category, flavor, buf;
	string ingredients = "";
	string direction = "";
	string time, difficulty;
	while (getline(fin, name))
	{
		cout << "Name: " << name << endl;

		getline(fin, category);
		cout << "Category: " << category << endl;

		getline(fin, flavor);
		cout << "Flavor: " << flavor << endl;

		do
		{
			getline(fin, buf);
			if (buf.find("#") == std::string::npos) ingredients += buf;
		} while(buf.find("#") == std::string::npos);
		cout << "Ingredients: " << ingredients << endl;

		getline(fin, time);
		cout << "Time: " << time << endl;

		getline(fin, difficulty);
		cout << "Difficulty: " << difficulty << endl;

		do
		{
			getline(fin, buf);
			if (buf.find("#") == std::string::npos) direction += buf;
		} while(buf.find("#") == std::string::npos);
		cout << "Direction: " << direction << endl;

		getline(fin, buf);
		cout << buf << endl;

		ingredients = "";
		direction = "";
	}



}



