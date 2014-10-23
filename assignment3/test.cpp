
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include <iostream>

using namespace ods;
using namespace std;


int main(){
  cout << "Testing ChainedHashTable" << endl;

  ChainedHashTable<int> ht;

  ht.setLocalFactor(1);


  cout << "Test Add Function: " << endl;
  for(int i = 0; i < 33; i++){
  cout << ht.add(i);
  }

  cout << endl;
  cout << ht.displayLists() << endl;
  cout << ht.getLongestList();
  cout << endl;

  cout << "Test Find Function: " << endl;
  for(int i = 0; i < 33; i++){
    cout << ht.find(i) << ", ";
  }
  cout << endl;

  cout << "Test Remove Function:" << endl;
  for(int i = 0; i < 33; i+=2){
    cout << ht.remove(i) << ", ";
  }
  cout << endl;

  cout << ht.displayLists();

  cout << endl;

  ChainedHashTable<int> ht2;

  ht2.setLocalFactor(3);


  cout << "Test Load Factor Change: " << endl;
  for(int i = 0; i < 33; i++){
    cout << ht2.add(i);
  }

  cout << endl;
  cout << ht2.displayLists() << endl;
  cout << ht2.getLongestList();
  cout << endl;


  cout << endl;
  cout << endl;
  cout << endl;


  cout<< "|||||||||||||||||||||||" << endl;
  cout << "Testing LinearHashTable" << endl << endl;

  LinearHashTable<int> lt(-1, -2);


  cout << "Add 15 items" << endl;
  for(int i = 0; i < 30; i+=2){
      cout << lt.add(i);
  }
  cout<< endl;

  cout << "Number of items: " << lt.size() << endl;
  cout << "Size of table: " << lt.getLength() << endl;

  cout << "Find items " << endl;
  for(int i = 0; i < 32; i++){
      cout << lt.find(i) << ", ";
  }

  cout << endl;
  cout << "Nulls in Front array : " << lt.countNullsFront() << endl;
  cout << "Nulls in Back array : " << lt.countNullsBack() << endl;
  cout << "Number of items: " << lt.size() << endl;
  cout << "Size of table: " << lt.getLength() << endl;


    cout << endl;
  cout << "Remove all but 3 items" << endl;
  for(int i = 128; i > 4; i-=2){
      lt.remove(i);
  }
  cout << "Number of items: " << lt.size() << endl;
  cout << "Size of table: " << lt.getLength() << endl;
  cout << "Nulls in Front array : " << lt.countNullsFront() << endl;
  cout << "Nulls in Back array : " << lt.countNullsBack() << endl;


  cout << endl;

  return 0;
}

