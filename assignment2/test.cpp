/*
/*
 * tester.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Thomas
 */

#include "DLList.h"
#include <iostream>

using namespace ods;
using namespace std;


int main(){

  DLList<int> list;

  for(int i=0; i<15; i++){
    list.add(0, i);
  }
  for(int i=15; i>=0; i--){
    list.add(0, i);
  }


  cout << "Testing isPalindrome method" << endl;

  for(int i = 0; i < list.size(); i++){
      cout << list.get(i) << ", ";
  }
  cout << endl;
  cout << list.isPalindrome() << endl;
  cout << "List no longer a palindrome: " << endl;
  list.add(0, 2);
  for(int i = 0; i < list.size(); i++){
      cout << list.get(i) << ", ";
  }
  cout << endl;
  cout<< list.isPalindrome();
  cout << endl;


  cout << "Testing rotate method" << endl;

  DLList<int> rot;
  for(int i=0; i<5; i++){
      rot.add(i, i);
  }
  for(int i = 0; i < rot.size(); i++){
      cout << rot.get(i) << ", ";
  }
  cout << endl;
  rot.rotate(2);
  cout << "Rotate 2" << endl;
  for(int i = 0; i < rot.size(); i++){
      cout << rot.get(i) << ", ";
  }
  cout << endl;
  rot.rotate(6);
  cout << "Rotated 6 times" << endl;
  for(int i = 0; i < rot.size(); i++){
      cout << rot.get(i) << ", ";
  }
  cout << endl;

  cout << "Testing absorb method" << endl;
  DLList<int> l1;
  DLList<int>* l2 = new DLList<int>;
  for(int i=0; i<10; i++){
      l1.add(0, i);
  }
  for(int i=0; i<6; i++){
      l2->add(0, i);
  }
  cout << "l1: ";
  for(int i = 0; i < l1.size(); i++){
      cout << l1.get(i) << ",  ";
  }
  cout << endl;
  cout << "l2: ";
  for(int i = 0; i < l2->size(); i++){
      cout << l2->get(i) << ", ";
  }
  cout  << endl;
  l1.absorb(*l2);
  cout << "l1: ";
  for(int i = 0; i < l1.size(); i++){
      cout << l1.get(i)<< ", ";
  }
  for(int i = 0; i < l2->size(); i++){
      cout << l2->get(i) << endl;
  }
  cout << endl;

  cout << "Testing deal method" << endl;
  DLList<int> d;
  for(int i = 0; i < 6; i++){
      d.add(i, i);
  }
  for(int i = 0; i< d.size(); i++) cout << d.get(i) << ", ";
  cout << endl;
  DLList<int> c = d.deal();
  cout << "Original Function: " << endl;
  for(int i = 0; i< d.size(); i++) cout << d.get(i) << ", ";
  cout << endl;
  cout << "Returned Function: " << endl;
  for(int i = 0; i< c.size(); i++) cout << c.get(i) << ", ";

  return 0;
}




