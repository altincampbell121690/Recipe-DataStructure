//============================================================================
// Name        : HashTEST.cpp
// Author      : Altin & Erik the great
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include "Hashtable.h"
#include "BST.h"
#include "List.h"
#include "Recipe.h"
#include "WordID.h"
#include <vector>

using namespace std;

//Function Prototypes

 int main()
 {
 HashTable Hash1;
 wordID cake, cake2, cake3, cake4, cake5, cake6;
 cout << "counter: "<< Hash1.Counter << endl;
 cake.set_Word("cake");
 Hash1.IDinsert(cake);
 cout << "counter: "<< Hash1.Counter << endl;
 cake2.set_Word("straw cake");
 Hash1.IDinsert(cake2);


 cake3.set_Word("Berry");
 Hash1.IDinsert(cake3);
 //cout << Hash1.Counter << endl;

 cake4.set_Word("Sugar");
 Hash1.IDinsert(cake4);
 //cout << Hash1.Counter << endl;


 cout << "counter: "<< Hash1.Counter << endl;
 vector<string> str;
 str.push_back("straw cake");
 str.push_back("cake");
 str.push_back("Berry");
 str.push_back("Sugar");

 Recipe Cake("Straw cake","cake","Berry","Sugar",0, 5,"bake");
 Cake.set_keys(str);

 Hash1.BSTinsert(Cake);
 Hash1.printTable(cout);

 cake5.set_Word("Apple");
 Hash1.IDinsert(cake5);
 cake6.set_Word("Apple cake");
 Hash1.IDinsert(cake6);
 //cout << Hash1.Counter << endl;
 vector<string> str2;
 str2.push_back("Apple cake");
 str2.push_back("cake");
 str2.push_back("Apple");
 str2.push_back("Sugar");

 Recipe Pie("Apple cake","cake","Apple","Sugar",0, 5,"roast");
 Pie.set_keys(str2);

 Hash1.BSTinsert(Pie);
 //cout << "crash" << endl;
 Hash1.BSTremove(Cake);
 Hash1.printTable(cout);
 }


/****************************TEST*******************************
 * counter: 0
 counter: 1
 counter: 4
 num of key words in recipe vector: 4
 word in the vector is: straw cake
 0
 inserted
 1
 2
 3
 word in the vector is: cake
 inserted
 0
 1
 2
 3
 word in the vector is: Berry
 0
 1
 inserted
 2
 3
 word in the vector is: Sugar
 0
 1
 2
 inserted
 3
 Recipes in the Catalogue:

 Group: 1- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +0 or more similar recipe(s)

 Group: 2- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +0 or more similar recipe(s)

 Group: 3- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +0 or more similar recipe(s)

 Group: 4- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +0 or more similar recipe(s)

 num of key words in recipe vector: 4
 word in the vector is: Apple cake
 0
 1
 2
 3
 4
 inserted
 5
 word in the vector is: cake
 inserted
 0
 1
 2
 3
 4
 5
 word in the vector is: Apple
 0
 1
 2
 3
 inserted
 4
 5
 word in the vector is: Sugar
 0
 1
 2
 inserted
 3
 4
 5
 Recipes in the Catalogue:

 Group: 1- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +1 or more similar recipe(s)

 Group: 2- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +0 or more similar recipe(s)

 Group: 3- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +0 or more similar recipe(s)

 Group: 4- Name: Straw cake
 - Category: cake
 - Flavor: Berry
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: bake
 +1 or more similar recipe(s)

 Group: 5- Name: Apple cake
 - Category: cake
 - Flavor: Apple
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: roast
 +0 or more similar recipe(s)

 Group: 6- Name: Apple cake
 - Category: cake
 - Flavor: Apple
 - Ingredients:
 Sugar
 - Time:0
 - Difficulty: 5
 - Direction: roast
 +0 or more similar recipe(s)
 */
