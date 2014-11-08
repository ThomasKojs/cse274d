#include <iostream>

#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace ods;


int main() {
  BinarySearchTree<BSTNode1<int>, int> tree;
  tree.add(50);
  tree.add(40);
  tree.add(20);
  tree.add(10);
  tree.add(8);
  tree.add(9);
  tree.add(15);
  tree.add(30);
  tree.add(24);
  tree.add(22);
  tree.add(38);
  tree.add(45);
  tree.add(43);
  tree.add(47);
  tree.add(70);
  tree.add(65);
  tree.add(77);
  tree.add(75);
  tree.add(90);

  tree.testPart1();
  tree.testPart2();
  tree.testPart3(); //Only works for this particular tree
  tree.testPart4(); //Only works for this particular tree

  return 0;
}

