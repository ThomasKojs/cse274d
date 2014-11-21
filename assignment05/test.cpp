#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace ods;
using namespace std;

int main(){
	int times = 20;

	int CHT_seqAdd_avg = 0;
	int CHT_seqRemove_avg = 0;
	int CHT_seqFind_avg = 0;
	int CHT_rndAdd_avg = 0;
	int CHT_rndRemove_avg = 0;
	int CHT_rndFind_avg = 0;

	int LHT_seqAdd_avg = 0;
	int LHT_seqRemove_avg = 0;
	int LHT_seqFind_avg = 0;
	int LHT_rndAdd_avg = 0;
	int LHT_rndRemove_avg = 0;
	int LHT_rndFind_avg = 0;

	int BST_seqAdd_avg = 0;
	int BST_seqRemove_avg = 0;
	int BST_seqFind_avg = 0;
	int BST_rndAdd_avg = 0;
	int BST_rndRemove_avg = 0;
	int BST_rndFind_avg = 0;

	int RBT_seqAdd_avg = 0;
	int RBT_seqRemove_avg = 0;
	int RBT_seqFind_avg = 0;
	int RBT_rndAdd_avg = 0;
	int RBT_rndRemove_avg = 0;
	int RBT_rndFind_avg = 0;

	DataStructureTester<BinarySearchTree<BSTNode1<int>,int> > bst;
	for(int i = 0; i < times; i++){
		BST_seqAdd_avg += bst.DoSequentialAdd(1, 50000, 1);
		BST_rndAdd_avg += bst.DoRandomAdd(50000);
		BST_seqFind_avg += bst.DoSequentialFind(1, 50000, 1);
		BST_rndFind_avg += bst.DoRandomFind(50000);
		BST_seqRemove_avg += bst.DoSequentialRemove(1, 50000, 1);
		BST_rndRemove_avg += bst.DoRandomRemove(50000);
		cout << i << "|";
	}
	cout  << endl;

	BST_seqAdd_avg = (int) BST_seqAdd_avg/times;
	BST_seqRemove_avg = (int) BST_seqRemove_avg/times;
	BST_seqFind_avg = (int) BST_seqFind_avg/times;
	BST_rndAdd_avg = (int) BST_rndAdd_avg/times;
	BST_rndRemove_avg = (int) BST_rndRemove_avg/times;
	BST_rndFind_avg = (int) BST_rndFind_avg/times;

	cout << "BinarySearchTree average sequential add is " << BST_seqAdd_avg << endl;
	cout << "BinarySearchTree average sequential remove is " << BST_seqRemove_avg << endl;
	cout << "BinarySearchTree average sequential find is " << BST_seqFind_avg << endl;
	cout << "BinarySearchTree average random add is " << BST_rndAdd_avg << endl;
	cout << "BinarySearchTree average random remove is " << BST_rndRemove_avg << endl;
	cout << "BinarySearchTree average random find is " << BST_rndFind_avg << endl;


	DataStructureTester<ChainedHashTable<int> > cht;
	for(int i = 0; i < times; i++){
		CHT_seqAdd_avg += cht.DoSequentialAdd(1, 50000, 1);
		CHT_rndAdd_avg += cht.DoRandomAdd(50000);
		CHT_seqFind_avg += cht.DoSequentialFind(1, 50000, 1);
		CHT_rndFind_avg += cht.DoRandomFind(50000);
		CHT_seqRemove_avg += cht.DoSequentialRemove(1, 50000, 1);
		CHT_rndRemove_avg += cht.DoRandomRemove(50000);
		cout << i << "|";
	}
	cout  << endl;

	CHT_seqAdd_avg = (int) CHT_seqAdd_avg/times;
	CHT_seqRemove_avg = (int) CHT_seqRemove_avg/times;
	CHT_seqFind_avg = (int) CHT_seqFind_avg/times;
	CHT_rndAdd_avg = (int) CHT_rndAdd_avg/times;
	CHT_rndRemove_avg = (int) CHT_rndRemove_avg/times;
	CHT_rndFind_avg = (int) CHT_rndFind_avg/times;

	cout << "ChainedHashTable average sequential add is " << CHT_seqAdd_avg << endl;
	cout << "ChainedHashTable average sequential remove is " << CHT_seqRemove_avg << endl;
	cout << "ChainedHashTable average sequential find is " << CHT_seqFind_avg << endl;
	cout << "ChainedHashTable average random add is " << CHT_rndAdd_avg << endl;
	cout << "ChainedHashTable average random remove is " << CHT_rndRemove_avg << endl;
	cout << "ChainedHashTable average random find is " << CHT_rndFind_avg << endl;




	DataStructureTester<LinearHashTable<int> > lht;
	for(int i = 0; i < times; i++){
		LHT_seqAdd_avg += lht.DoSequentialAdd(1, 50000, 1);
		LHT_rndAdd_avg += lht.DoRandomAdd(50000);
		LHT_seqFind_avg += lht.DoSequentialFind(1, 50000, 1);
		LHT_rndFind_avg += lht.DoRandomFind(50000);
		LHT_seqRemove_avg += lht.DoSequentialRemove(1, 50000, 1);
		LHT_rndRemove_avg += lht.DoRandomRemove(50000);
		cout << i << "|";
	}
	cout  << endl;

	LHT_seqAdd_avg = (int) LHT_seqAdd_avg/times;
	LHT_seqRemove_avg = (int) LHT_seqRemove_avg/times;
	LHT_seqFind_avg = (int) LHT_seqFind_avg/times;
	LHT_rndAdd_avg = (int) LHT_rndAdd_avg/times;
	LHT_rndRemove_avg = (int) LHT_rndRemove_avg/times;
	LHT_rndFind_avg = (int) LHT_rndFind_avg/times;

	cout << "LinearHashTable average sequential add is " << LHT_seqAdd_avg << endl;
	cout << "LinearHashTable average sequential remove is " << LHT_seqRemove_avg << endl;
	cout << "LinearHashTable average sequential find is " << LHT_seqFind_avg << endl;
	cout << "LinearHashTable average random add is " << LHT_rndAdd_avg << endl;
	cout << "LinearHashTable average random remove is " << LHT_rndRemove_avg << endl;
	cout << "LinearHashTable average random find is " << LHT_rndFind_avg << endl;


	DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > rbt;
	for(int i = 0; i < times; i++){
		RBT_seqAdd_avg += rbt.DoSequentialAdd(1, 50000, 1);
		RBT_rndAdd_avg += rbt.DoRandomAdd(50000);
		RBT_seqFind_avg += rbt.DoSequentialFind(1, 50000, 1);
		RBT_rndFind_avg += rbt.DoRandomFind(50000);
		RBT_seqRemove_avg += rbt.DoSequentialRemove(1, 50000, 1);
		RBT_rndRemove_avg += rbt.DoRandomRemove(50000);
		cout << i << "|";
	}
	cout << endl;

		RBT_seqAdd_avg = (int) RBT_seqAdd_avg/times;
		RBT_seqRemove_avg = (int) RBT_seqRemove_avg/times;
		RBT_seqFind_avg = (int) RBT_seqFind_avg/times;
		RBT_rndAdd_avg = (int) RBT_rndAdd_avg/times;
		RBT_rndRemove_avg = (int) RBT_rndRemove_avg/times;
		RBT_rndFind_avg = (int) RBT_rndFind_avg/times;

		cout << "RedBlackTree average sequential add is " << RBT_seqAdd_avg << endl;
		cout << "RedBlackTree average sequential remove is " << RBT_seqRemove_avg << endl;
		cout << "RedBlackTree average sequential find is " << RBT_seqFind_avg << endl;
		cout << "RedBlackTree average random add is " << RBT_rndAdd_avg << endl;
		cout << "RedBlackTree average random remove is " << RBT_rndRemove_avg << endl;
		cout << "RedBlackTree average random find is " << RBT_rndFind_avg << endl;

	return 0;
}


