#pragma once
// Author:			Westley Case 
// Assignment:		Project 4
// File:			Tree.h
// Instructor:		Dr. Reza Sanati 
// Class:			CS2420 
// Date Written:	6/5/2015
// Description:		Utilizeing AVL-Trees to organize integer data.
// ===============================================================
#include"Node.cpp"
// ===============================================================
class Tree
{
public:
	// Tree()
	// Purpose: default constrictor for tree
	// Parameters: none
	// Returns: none
	Tree();

	// insert()
	// Purpose: insetr the int data into tree
	// Parameters: int data
	// Returns: a Node pointer created from data
	Node* insert(int);

	// insertR()
	// Purpose: Actually place the node in its correct location of tree
	// Parameters: Node pointer root, and int data
	// Returns: Node pointer
	Node* insertR(Node*, int);

	// balance()
	// Purpose: calls the methods to check and balance the tree when its unbalanced
	// Parameters: Node pointer
	// Returns: Node Pointer
	Node* balance(Node*);

	// ckBalance()
	// Purpose: Checks the left and right branch depths for unbalanced numbers
	// Parameters: Node* root
	// Returns: int diff of left and right
	int ckBalance(Node*);

	// LLbalance()
	// Purpose: balances for the letf left unbalance
	// Parameters: Node pointer
	// Returns: Node pointer
	Node* LLbalance(Node*);

	// LRbalance()
	// Purpose: balances for the letf right unbalance
	// Parameters: Node pointer
	// Returns: Node pointer
	Node* LRbalance(Node*);

	// RLbalance()
	// Purpose: balances for the right left unbalance
	// Parameters: Node pointer
	// Returns: Node pointer
	Node* RLbalance(Node*);

	// RRbalance()
	// Purpose: balances for the right right unbalance
	// Parameters: Node pointer
	// Returns: Node pointer
	Node* RRbalance(Node*);

	// getRoot()
	// Purpose: return the root
	// Parameters: void
	// Returns: Node pointer
	Node* getRoot() const;

	// branchHeight()
	// Purpose: gets the deepest branch height for the ckBalance()
	// Parameters: Node pointer
	// Returns: int of the deepest branch
	int branchHeight(Node*);
private:
	Node* root;
};


