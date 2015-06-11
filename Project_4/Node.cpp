#pragma once
// Author:			Westley Case 
// Assignment:		Project 4
// File:			Node.cpp
// Instructor:		Dr. Reza Sanati 
// Class:			CS2420 
// Date Written:	6/5/2015
// Description:		Utilizeing AVL-Trees to organize integer data.
// ===============================================================
struct Node
{
	// Node()
	// Purpose: constructor for the Node
	// Parameters: int data
	// returns: none
	Node(int _data)
	{
		data = _data;
		Lchild = nullptr;
		Rchild = nullptr;
	}
	int data;
	Node* Rchild;
	Node* Lchild;
};