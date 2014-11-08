/*
 * BinaryTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstdlib>
#include <iostream>

#include "ArrayDeque.h"
using namespace std;

namespace ods {

template<class N>
class BTNode {
public:
	N *left;
	N *right;
	N *parent;
	BTNode() {
		left = right = parent = NULL;
	}
};

template<class Node>
class BinaryTree {
protected:
	Node *r;    // root node
	Node *nil;  // null-like node
	int check;
	virtual int
	size(Node *u);
	virtual int
	height(Node *u);
	virtual void
	traverse(Node *u);

public:
	virtual ~BinaryTree();
	BinaryTree();
	BinaryTree(Node *nil);
	virtual void clear();
	virtual int depth(Node *u);
	virtual int size();
	virtual int size2();
	virtual int height();
	virtual int height2(Node *u);
	virtual void traverse();
	virtual void traverse2();
	virtual void bfTraverse();
	virtual bool isBalanced();
	virtual int isBalanced(Node *u);
	virtual void testPart1();
	virtual void testPart2();
};

class BTNode1: public BTNode<BTNode1> {
};

template<class Node>
BinaryTree<Node>::~BinaryTree() {
	clear();
}

template<class Node>
void BinaryTree<Node>::clear() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		if (next == u->parent)
			delete u;
		u = next;
	}
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree(Node *nil) {
	this->nil = nil;
	r = nil;
	check = 0;
}

template<class Node>
BinaryTree<Node>::BinaryTree() {
	nil = NULL;
	r = nil;
	check = 0;
}

template<class Node>
int BinaryTree<Node>::depth(Node *u) {
	int d = 0;
	while (u != r) {
		u = u->parent;
		d++;
	}
	return d;
}

template<class Node>
int BinaryTree<Node>::size() {
	return size(r);
}

template<class Node>
int BinaryTree<Node>::size(Node *u) {
	if (u == nil)
		return 0;
	return 1 + size(u->left) + size(u->right);
}

template<class Node>
bool BinaryTree<Node>::isBalanced() {
	int ret = isBalanced(r);
	if (ret == (-10)) {
		return false;
	}
	return true;
}

template<class Node>
int BinaryTree<Node>::isBalanced(Node *u) {
	if (u == nil) {
		return 0;
	}
	int l = isBalanced(u->left);
	int r = isBalanced(u->right);
	if (l == -10 || r == -10) {
		return -10;
	} else {
		if (abs(l - r) < 2) {
			return 1 + l + r;
		} else {
			return -10;
		}
	}
}

template<class Node>
int BinaryTree<Node>::size2() {
	Node *u = r, *prev = nil, *next;
	int n = 0;
	while (u != nil) {
		if (prev == u->parent) {
			n++;
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
	return n;
}

template<class Node>
int BinaryTree<Node>::height() {
	return height(r);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
	if (u == nil)
		return -1;
	return 1 + max(height(u->left), height(u->right));
}

template<class Node>
int BinaryTree<Node>::height2(Node *u) {
	Node *t = u->parent;
	Node *prev = nil;
	Node *next;
	int diff = 0;
	int height = 0;

	if (u->left != nil) {
		prev = u;
		u = u->left;
		height++;
	} else if (u->right != nil) {
		prev = u;
		u = u->right;
		height++;
	} else {
		return 0;
	}

	while (u != t) {
		if (prev == u->parent) {
			if (u->left != nil) {
				if (diff == 0) {
					height++;
				} else {
					diff++;
				}
				next = u->left;
			} else if (u->right != nil) {
				if (diff == 0) {
					height++;
				} else {
					diff++;
				}
				next = u->right;
			} else {
				diff--;
				next = u->parent;
			}
		} else if (prev == u->left) {
			if (u->right != nil) {
				diff++;
				next = u->right;
			} else {
				diff--;
				next = u->parent;
			}
		} else {
			diff--;
			next = u->parent;
		}
		prev = u;
		u = next;
	}
	return height;
}

template<class Node>
void BinaryTree<Node>::traverse() {
	traverse(r);
}

template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
	if (u == nil)
		return;
	traverse(u->left);
	traverse(u->right);
}

template<class Node>
void BinaryTree<Node>::traverse2() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
}

template<class Node>
void BinaryTree<Node>::bfTraverse() {
	ArrayDeque<Node*> q;
	if (r != nil)
		q.add(q.size(), r);
	while (q.size() > 0) {
		Node *u = q.remove(q.size() - 1);
		if (u->left != nil)
			q.add(q.size(), u->left);
		if (u->right != nil)
			q.add(q.size(), u->right);
	}
}

template<class Node>
void BinaryTree<Node>::testPart1(){
	cout << "Testing Part 1: Height2 function" << endl;
		cout << "||||||||||||||||||||||||||||||||" << endl;

		cout << "The height of the tree is: " << height() << endl;
		cout << "The height2 from the root: " << height2(r) << endl;
		cout << "The height2 of the left subtree: " << height2(r->left) << endl;
		cout << "the height2 of the right subtree: " << height2(r->right) << endl;
}

template<class Node>
void BinaryTree<Node>::testPart2(){
	  cout << "Testing Part 2: isBalanced function" << endl;
	  cout << "||||||||||||||||||||||||||||||||" << endl;

	  if(isBalanced()){
	  cout << "This tree isBalanced(): " << isBalanced() << endl;
	  }else cout << "This tree is not balanced: " << isBalanced() << endl;
	  cout << endl << endl;

}

} /* namespace ods */
#endif /* BINARYTREE_H_ */
