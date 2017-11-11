/*
 * List.h
 *
 *	Khang Vinh Tran, Tri Doan
 *  CIS 22C, Lab6
*/

# include "BST.h"

int main()
{
	cout << "- Insert 15, 6, 3, 7, 2, 4, 13 ,9, 18,17, 20 into the tree" << endl << endl;
	const int arraySize = 11;
	int dataArray[arraySize] = {15, 6, 3, 7, 2, 4, 13 ,9, 18,17, 20};
	BST<int> bst1;
	for (int i = 0; i < arraySize; i++)
		bst1.insert(dataArray[i]);
	cout << "************ Test InsertNode, InOrderPrint, PreOrderPrint and PostOrderPrint ************" << endl << endl;
	cout << "- Test inOrderPrint(), Should print 2 3 6 7 9 13 15 17 18 20: " << endl;
	bst1.inOrderPrint(cout);
	cout << endl << "- Test preOrderPrint(), Should print 15 6 3 2 4 7 13 19 18 17 20: " << endl;
	bst1.preOrderPrint(cout);
	cout << endl << "- Test postOrderPrint(), Should print 2 4 3 9 13 7 6 17 20  18 15: " << endl;
	bst1.postOrderPrint(cout);

	cout << endl << "************ Test Search ************" << endl << endl;
	cout << "- Test whether 15 (root node) is in the tree. Should print 'Found':" << endl;
	if (bst1.search(15)) cout << "Found" << endl;
	cout << endl << "- Test whether 17 (leaf node) is in the tree. Should print 'Found':" << endl;
	if (bst1.search(17)) cout << "Found" << endl;
	cout << endl << "- Test whether 18 (neither root nor leaf node) is in the tree. Should print 'Found':" << endl;
	if (bst1.search(18)) cout << "Found" << endl;
	cout << endl << "- Test whether 6 (left subtree) is in the tree. Should print 'Found':" << endl;
	if(bst1.search(6)) cout << "Found" << endl;
	cout << endl << "- Test whether 8 is in the tree. Should print 'Not Found':" << endl;
	if (!bst1.search(8)) cout << "Not Found" << endl << endl;

	cout << " *************Test getSize and isEmpty **************" << endl << endl;
	cout << "Should print out size 11" << endl;
	cout << bst1.getSize() << endl;
	cout << "Should print out 'Not empty'" << endl;
	if (!bst1.isEmpty()) cout << "Not empty" << endl << endl;
	cout << "*************Test Minimum, Maximum, getRoot and getHeight **************"<< endl << endl;
	cout << "Should print out the minimum element" << endl;
	cout << bst1.minimum() << endl;
	cout << "Should print out the maximum element" << endl;
	cout << bst1.maximum() << endl;
	cout << "Should print out the element at the root" << endl;
	cout << bst1.getRoot() << endl;
	cout << "Should print out the height" << endl;
	cout << bst1.getHeight() << endl << endl;

	cout << "*************Test CopyConstructor*************" << endl << endl;
	cout << "bst1 contains: ";
	bst1.inOrderPrint(cout);
	BST<int> bst2(bst1);
	cout << "bst2 contains: ";
	bst2.inOrderPrint(cout);
	cout << endl;
	cout << "*************Test remove and deleteNode and InOrderPrint*************" << endl;
	bst2.inOrderPrint(cout);
	cout << "Remove the root (number 15)" << endl;
	bst2.remove(15);
	bst2.inOrderPrint(cout);
	cout << "Remove the leaf node (number 2)" << endl;
	bst2.remove(2);
	bst2.inOrderPrint(cout);
	cout << "Remove the node with only one child (number 13)" << endl;
	bst2.remove(13);
	bst2.inOrderPrint(cout);
	cout << "Remove the node with two child (number 18)" << endl;
	bst2.remove(18);
	bst2.inOrderPrint(cout);
	return 0;
}
