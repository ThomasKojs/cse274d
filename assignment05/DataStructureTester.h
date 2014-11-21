
#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "ArrayDeque.h"

namespace ods {

template<class H>
class DataStructureTester {
protected:
  H list;
  ArrayDeque<int> rnd;
  //srand(1);


public:
  DataStructureTester();
  virtual ~DataStructureTester();
  void AddRandom(int i);
  int DoSequentialAdd(int start, int end, int step);
  int DoRandomAdd(int n);
  int DoSequentialRemove(int start, int end, int step);
  int DoRandomRemove(int n);
  int DoSequentialFind(int start, int end, int step);
  int DoRandomFind(int n);
};

template<class H>
DataStructureTester<H>::DataStructureTester(){
	H list;
	ArrayDeque<int> rnd;
}

template<class H>
DataStructureTester<H>::~DataStructureTester(){
}

template<class H>
int DataStructureTester<H>::DoSequentialAdd(int start, int end, int step){
	clock_t t = clock();
	for(int i =start; i <= end; i+=step){
		list.add(i);
	}
	return (((float)(clock() - t))/CLOCKS_PER_SEC)*1000;
}

template<class H>
int DataStructureTester<H>::DoSequentialRemove(int start, int end, int step){
	clock_t t = clock();
	for(int i =start; i <= end; i+=step){
		list.remove(i);
	}
	return (((float)(clock() - t))/CLOCKS_PER_SEC)*1000;
}

template<class H>
int DataStructureTester<H>::DoSequentialFind(int start, int end, int step){
	clock_t t = clock();
	for(int i = start; i <= end; i+=step){
		list.find(i);
	}
	return (((float)(clock() - t))/CLOCKS_PER_SEC)*1000;
}

template<class H>
int DataStructureTester<H>::DoRandomAdd(int n){
	srand(time(NULL));
	clock_t t = clock();
	for(int i =0; i<n; i++){
		list.add(rand()%10000000);
	}
	return (((float)(clock() - t))/CLOCKS_PER_SEC)*1000;
}

template<class H>
int DataStructureTester<H>::DoRandomRemove(int n){
	srand(time(NULL));
	clock_t t = clock();
	for(int i =0; i<n; i++){
		list.remove(rand()%10000000);
	}
	return (((float)(clock() - t))/CLOCKS_PER_SEC)*1000;
}

template<class H>
int DataStructureTester<H>::DoRandomFind(int n){
	srand(time(NULL));
	clock_t t = clock();
	for(int i =0; i<n; i++){
		list.find(rand()%10000000);
	}
	return (((float)(clock() - t))/CLOCKS_PER_SEC)*1000;
}


}
