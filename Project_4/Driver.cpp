#pragma
// Author:			Westley Case 
// Assignment:		Project 4
// File:			Driver.cpp
// Instructor:		Dr. Reza Sanati 
// Class:			CS2420 
// Date Written:	6/5/2015
// Description:		Utilizeing AVL-Trees to organize integer data.
// ===============================================================
#include"Driver.h"
// ===============================================================
void inOrder(Node*);
void preOrder(Node*);
// ===============================================================

int main()
{
	// Create the file stream.
	fstream inFile;
	string fileName;

	cout << "Westley Case\n" << "CS 2420-001\n" << "Program 4 - AVL-Tree\n" << endl;
	while (fileName == "")
	{
		// Create the Tree Object, variables used
		Tree intTree;
		int nData;
		
		// Ask user for filename
		cout << "Please enter a file, or enter q to quit:  "; 
		getline(cin, fileName);
		if (fileName == "q")
			break;

		// otherwise try to open the file
		inFile.open(fileName);
		if (inFile)
		{
			while (!inFile.eof())
			{
				inFile >> nData;

				if (inFile.fail())
				{
					cout << "The valid data in your file has been read:\n" << endl;
					break;
				}
				// Insert each int from the file.
				intTree.insert(nData);
			}
		}		
		// Print out to console.
		cout << "In-Order Traverse" << endl;
		inOrder(intTree.getRoot());
		cout << "Pre-Order Traverse" << endl;
		preOrder(intTree.getRoot());
		
		inFile.close();
		fileName = "";
	}
}


/// ======================= Helper Functions =============================
void inOrder(Node* _root)
{
	if (_root != nullptr)
	{
		inOrder(_root->Lchild);
		cout << _root->data << endl;
		inOrder(_root->Rchild);
	}
}

void preOrder(Node* _root)
{
	stack<Node*> printStack;
	Node* p = _root;
	loop:
	while (p != nullptr)
	{
		cout << p->data << endl;
		printStack.push(p);
		p = p->Lchild;
	}

	if (!printStack.empty())
	{
		p = printStack.top();
		printStack.pop();
		p = p->Rchild;
		goto loop;
	}
}
