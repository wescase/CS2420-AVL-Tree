#include "Tree.h"
// Author:			Westley Case 
// Assignment:		Project 4
// File:			Tree.cpp
// Instructor:		Dr. Reza Sanati 
// Class:			CS2420 
// Date Written:	6/5/2015
// Description:		Utilizeing AVL-Trees to organize integer data.
// ===============================================================

Tree::Tree()
{
	root = nullptr;
}

Node* Tree::insert(int _data)
{
	// insert to recursive insert.
	root = insertR(root, _data);
	return root;
}

Node* Tree::insertR(Node* _root, int _data) // _root here is the root that the data will be inserted to.
{
	if (_root == nullptr)
	{
		_root = new Node(_data);
		return _root;
	}
	else
	{
		if (_data > _root->data)
		{
			_root->Rchild = insertR(_root->Rchild, _data);
			_root = balance(_root);
			return _root;
		}
		else if (_data < _root->data)
		{
			_root->Lchild = insertR(_root->Lchild, _data);
			_root = balance(_root);
			return _root;
		}
		return _root;
	}
}

Node* Tree::balance(Node* _node)
{
	// check for balance factors
	int balFactor = ckBalance(_node);
	// chack the balance factors to move shit if it needs moving
	if (balFactor > 1)
	{
		if (ckBalance(_node->Lchild) > 0)
		{
			// check the childs child to see if its LL or LR
			//call the reorganize of a LL
			return LLbalance(_node);
		}
		else
		{
			// call the reorganize of LR
			return LRbalance(_node);
		}
	}
	else if (balFactor < -1)
	{	
		if (ckBalance(_node->Rchild) < 0)
		{
			//call the reorganize of a RR
			return RRbalance(_node);
		}
		else
		{
			// call the reorganize of RL
			return RLbalance(_node);
		}
	}
	return _node;
}

int Tree::ckBalance(Node* _node)
{
	int Lheight = branchHeight(_node->Lchild);
	int Rheight = branchHeight(_node->Rchild);
	int bal = Lheight - Rheight;
	return bal;
}

int Tree::branchHeight(Node* _node)
{
	if (_node != nullptr)
	{
		int lBranch = branchHeight(_node->Lchild);
		int rBranch = branchHeight(_node->Rchild);
		int deepest = lBranch > rBranch ? lBranch : rBranch;
		return deepest + 1;
	}
}
Node* Tree::LLbalance(Node* _p)
{
	Node* child = _p->Lchild;
	_p->Lchild = child->Rchild;
	child->Rchild = _p;

	return child;
}

Node* Tree::LRbalance(Node* _p)
{
	Node* child = _p->Lchild;

	_p->Lchild = RRbalance(child);
	return LLbalance(_p);
}

Node* Tree::RLbalance(Node* _p)
{
	Node* child = _p->Rchild;

	_p->Rchild = LLbalance(child);
	return RRbalance(_p);
}

Node* Tree::RRbalance(Node* _p)
{
	Node* child = _p->Rchild;

	_p->Rchild = child->Lchild;
	child->Lchild = _p;
	return child;
}

Node* Tree::getRoot() const
{
	return root;
}