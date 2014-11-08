/*
 /*
 * BinarySearchTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <climits>
#include <cmath>
#include <iostream>
#include "BinaryTree.h"
#include "utils.h"
#include "DLList.h"
using namespace std;

namespace ods {

template<class Node, class T>
class BSTNode : public BTNode<Node> {
public:
    T x;
    int pre_order;
    int in_order;
    int post_order;
};

/**
 * A binary search tree class.  The Node parameter should be a subclass
 * of BSTNode<T> (or match it's interface)
 */
template<class Node, class T>
class BinarySearchTree : public BinaryTree<Node> {
protected:
    using BinaryTree<Node>::r;
    using BinaryTree<Node>::nil;
    int n;
    int o;
    T null;
    virtual Node *findLast(T x);
    virtual bool addChild(Node *p, Node *u);
    virtual void splice(Node *u);
    virtual void remove(Node *u);
    virtual void rotateRight(Node *u);
    virtual void rotateLeft(Node *u);
    virtual bool add(Node *u);
    virtual void preOrderNumber(Node *u);
    virtual void inOrderNumber(Node *u);
    virtual void postOrderNumber(Node *u);

public:
    BinarySearchTree();
    BinarySearchTree(T null);
    virtual ~BinarySearchTree();
    virtual bool add(T x);
    virtual bool remove(T x);
    virtual T find(T x);
    virtual T findEQ(T x);
    virtual int size();
    virtual void clear();
    virtual void preOrderNumber();
    virtual void inOrderNumber();
    virtual void postOrderNumber();
    virtual Node* getR();
    virtual DLList<T> getLE(T x);
    virtual Node* getNode(T x);
    virtual void testPart3();
    virtual void testPart4();
};

template<class T>
class BSTNode1 : public BSTNode<BSTNode1<T>, T> { };

template<class T>
class BinarySearchTree1 : public BinarySearchTree<BSTNode1<T>, T> {
public:
    BinarySearchTree1();
};


/*
 * FIXME: Why doesn't this work?
template<class Node>
BinarySearchTree<Node,int>::BinarySearchTree()  {
    this->null = INT_MIN;
    n = 0;
}
*/

template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree() {
    this->null = (T)NULL;  // won't work for non-primitive types
    n = 0;
    o=0;
}


template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree(T null) {
    this->null = null;
    n = 0;
    o=0;
}

template<class Node, class T>
Node* BinarySearchTree<Node,T>::findLast(T x) {
    Node *w = r, *prev = nil;
    while (w != nil) {
        prev = w;
        int comp = compare(x, w->x);
        if (comp < 0) {
            w = w->left;
        } else if (comp > 0) {
            w = w->right;
        } else {
            return w;
        }
    }
    return prev;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::findEQ(T x) {
    Node *w = r;
    while (w != nil) {
        int comp = compare(x, w->x);
        if (comp < 0) {
            w = w->left;
        } else if (comp > 0) {
            w = w->right;
        } else {
            return w->x;
        }
    }
    return null;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::find(T x) {
    Node *w = r, *z = nil;
    while (w != nil) {
        int comp = compare(x, w->x);
        if (comp < 0) {
            z = w;
            w = w->left;
        } else if (comp > 0) {
            w = w->right;
        } else {
            return w->x;
        }
    }
    return z == nil ? null : z->x;
}

template<class Node, class T>
BinarySearchTree<Node,T>::~BinarySearchTree() {
    // nothing to do - BinaryTree destructor does cleanup
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::addChild(Node *p, Node *u) {
        if (p == nil) {
            r = u;              // inserting into empty tree
        } else {
            int comp = compare(u->x, p->x);
            if (comp < 0) {
                p->left = u;
            } else if (comp > 0) {
                p->right = u;
            } else {
                return false;   // u.x is already in the tree
            }
            u->parent = p;
        }
        n++;
        return true;
    }

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(T x) {
    Node *p = findLast(x);
    Node *u = new Node;
    u->x = x;
    return addChild(p, u);
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(Node *u) {
    Node *p = findLast(u->x);
    return addChild(p, u);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::splice(Node *u) {
    Node *s, *p;
    if (u->left != nil) {
        s = u->left;
    } else {
        s = u->right;
    }
    if (u == r) {
        r = s;
        p = nil;
    } else {
        p = u->parent;
        if (p->left == u) {
            p->left = s;
        } else {
            p->right = s;
        }
    }
    if (s != nil) {
        s->parent = p;
    }
    n--;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::remove(Node *u) {
    if (u->left == nil || u->right == nil) {
        splice(u);
        delete u;
    } else {
        Node *w = u->right;
        while (w->left != nil)
            w = w->left;
        u->x = w->x;
        splice(w);
        delete w;
    }
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::remove(T x) {
    Node *u = findLast(x);
    if (u != nil && compare(x, u->x) == 0) {
        remove(u);
        return true;
    }
    return false;
}

template<class Node, class T> inline
int BinarySearchTree<Node, T>::size() {
    return n;
}

template<class Node, class T> inline
void BinarySearchTree<Node, T>::clear() {
    BinaryTree<Node>::clear();
    n = 0;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateLeft(Node *u) {
    Node *w = u->right;
    w->parent = u->parent;
    if (w->parent != nil) {
        if (w->parent->left == u) {
            w->parent->left = w;
        } else {
            w->parent->right = w;
        }
    }
    u->right = w->left;
    if (u->right != nil) {
        u->right->parent = u;
    }
    u->parent = w;
    w->left = u;
    if (u == r) { r = w; r->parent = nil; }
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateRight(Node *u) {
    Node *w = u->left;
    w->parent = u->parent;
    if (w->parent != nil) {
        if (w->parent->left == u) {
            w->parent->left = w;
        } else {
            w->parent->right = w;
        }
    }
    u->left = w->right;
    if (u->left != nil) {
        u->left->parent = u;
    }
    u->parent = w;
    w->right = u;
    if (u == r) { r = w; r->parent = nil; }
}

template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber(){
  o = 0;
  preOrderNumber(r);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber(Node *u){
  if(u == nil) return;
  u->pre_order = o;
  o++;
  preOrderNumber(u->left);
  preOrderNumber(u->right);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber(){
    o =0;
    inOrderNumber(r);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber(Node *u){
    if(u == nil) return;
    inOrderNumber(u->left);
    u->in_order = o;
    o++;
    inOrderNumber(u->right);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumber(){
  o =0;
  postOrderNumber(r);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumber(Node *u){
  if(u == nil) return;
  postOrderNumber(u->left);
  postOrderNumber(u->right);
  u->post_order = o;
  o++;

}

template<class Node, class T>
Node* BinarySearchTree<Node, T>::getR(){
  return r;
}

template<class Node, class T>
DLList<T> BinarySearchTree<Node, T>::getLE(T x){
  DLList<T> ret;
  Node *prev;
  Node *u = r;
  int c = 0;
  while(u->left != nil){
      prev = u;
      u = u->left;
  }
  while(compare(u->x, x)<=0){
      ret.add(u->x);
      cout << u->x << ", ";
	  if(u->right != nil){
	      prev = u;
	      u = u->right;
	      while(u->left != nil){
		  prev = u;
		  u = u->left;
	      }
	  }else{
	      prev = u;
	      u = u->parent;
	      while(u->right == prev && u != r){
		  prev = u;
		  u = u->parent;
	      }
	      if(u == r) c++;
	      if(c >1) break;
	  }
  }

  return ret;
}

template<class Node, class T>
Node* BinarySearchTree<Node,T>::getNode(T x) {
    Node *w = r, *z = nil;
    while (w != nil) {
        int comp = compare(x, w->x);
        if (comp < 0) {
            z = w;
            w = w->left;
        } else if (comp > 0) {
            w = w->right;
        } else {
            return w;
        }
    }
    return z == nil ? nil : z;
}

template<class Node, class T>
void BinarySearchTree<Node,T>::testPart3() {
	cout << "Testing Part 3: Ordering and getNode" << endl;
	cout << "||||||||||||||||||||||||||||||||" << endl;

	preOrderNumber();
	inOrderNumber();
	postOrderNumber();

	cout << "Printing out pre-ordered numbers: " << endl;

	cout << "50 is:  " << getNode(50)->pre_order << ",  ";
	cout << "40 is:  " << getNode(40)->pre_order << ",  ";
	cout << "20 is:  " << getNode(20)->pre_order << ",  ";
	cout << "10 is:  " <<  getNode(10)->pre_order << ",  ";
	cout << "8 is:  " << getNode(8)->pre_order << ",  ";
	cout << "9 is:  " << getNode(9)->pre_order << ",  ";
	cout << "15 is:  " << getNode(15)->pre_order << ",  ";
	cout << "30 is:  " << getNode(30)->pre_order << ",  ";
	cout << "24 is:  " << getNode(24)->pre_order << ",  ";
	cout << "22 is:  " << getNode(22)->pre_order << ",  ";
	cout << "38 is:  " << getNode(38)->pre_order << ",  ";
	cout << "45 is:  " << getNode(45)->pre_order << ",  ";
	cout << "43 is:  " << getNode(43)->pre_order << ",  ";
	cout << "47 is:  " << getNode(47)->pre_order << ",  ";
	cout << "70 is:  " << getNode(70)->pre_order << ",  ";
	cout << "65 is:  " << getNode(65)->pre_order << ",  ";
	cout << "77 is:  " << getNode(77)->pre_order << ",  ";
	cout << "75 is:  " << getNode(75)->pre_order << ",  ";
	cout << "90 is:  " << getNode(90)->pre_order << endl;

	cout << "Printing out in-ordered numbers: " << endl;

	cout << "50 is:  " << getNode(50)->in_order << ",  ";
	cout << "40 is:  " << getNode(40)->in_order << ",  ";
	cout << "20 is:  " << getNode(20)->in_order << ",  ";
	cout << "10 is:  " <<  getNode(10)->in_order << ",  ";
	cout << "8 is:  " << getNode(8)->in_order << ",  ";
	cout << "9 is:  " << getNode(9)->in_order << ",  ";
	cout << "15 is:  " << getNode(15)->in_order << ",  ";
	cout << "30 is:  " << getNode(30)->in_order << ",  ";
	cout << "24 is:  " << getNode(24)->in_order << ",  ";
	cout << "22 is:  " << getNode(22)->in_order << ",  ";
	cout << "38 is:  " << getNode(38)->in_order << ",  ";
	cout << "45 is:  " << getNode(45)->in_order << ",  ";
	cout << "43 is:  " << getNode(43)->in_order << ",  ";
	cout << "47 is:  " << getNode(47)->in_order << ",  ";
	cout << "70 is:  " << getNode(70)->in_order << ",  ";
	cout << "65 is:  " << getNode(65)->in_order << ",  ";
	cout << "77 is:  " << getNode(77)->in_order << ",  ";
	cout << "75 is:  " << getNode(75)->in_order << ",  ";
	cout << "90 is:  " << getNode(90)->in_order << endl;

	cout << "Printing out post-ordered numbers: " << endl;

	cout << "50 is:  " << getNode(50)->post_order << ",  ";
	cout << "40 is:  " << getNode(40)->post_order << ",  ";
	cout << "20 is:  " << getNode(20)->post_order << ",  ";
	cout << "10 is:  " <<  getNode(10)->post_order << ",  ";
	cout << "8 is:  " << getNode(8)->post_order << ",  ";
	cout << "9 is:  " << getNode(9)->post_order << ",  ";
	cout << "15 is:  " << getNode(15)->post_order << ",  ";
	cout << "30 is:  " << getNode(30)->post_order << ",  ";
	cout << "24 is:  " << getNode(24)->post_order << ",  ";
	cout << "22 is:  " << getNode(22)->post_order << ",  ";
	cout << "38 is:  " << getNode(38)->post_order << ",  ";
	cout << "45 is:  " << getNode(45)->post_order << ",  ";
	cout << "43 is:  " << getNode(43)->post_order << ",  ";
	cout << "47 is:  " << getNode(47)->post_order << ",  ";
	cout << "70 is:  " << getNode(70)->post_order << ",  ";
	cout << "65 is:  " << getNode(65)->post_order << ",  ";
	cout << "77 is:  " << getNode(77)->post_order << ",  ";
	cout << "75 is:  " << getNode(75)->post_order << ",  ";
	cout << "90 is:  " << getNode(90)->post_order << endl;


}

template<class Node, class T>
void BinarySearchTree<Node, T>:: testPart4(){
	cout << endl << "Testing Part 4: getLE function " << endl;
	cout << "||||||||||||||||||||||||||||||||" << endl;
	cout << "Gets List less than 44: ";
	getLE(44);
	cout << endl;
	cout << "Gets List less than 125: ";
	getLE(125);
	cout << endl;

}


/*
template<class T>
BinarySearchTree1<T*>::BinarySearchTree1() : BinarySearchTree<BSTNode1<T*>, T*>(NULL) {
}
*/


} /* namespace ods */
#endif /* BINARYSEARCHTREE_H_ */
