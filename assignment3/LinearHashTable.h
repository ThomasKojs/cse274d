/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

	static const int w = 32;
	static const int r = 8;
	array<T> t;
	array<T> u;
	int n;   // number of values in T
	int q;   // number of non-null entries in T
	int d;   // t.length = 2^d
	//int length = 1<<d;
	T null, del;
	void resize();
	int hash(T x) {
	    return (x%(t.length + u.length) + x/(2*t.length))%((t.length + u.length));
	}
	int hash2(T x, int i){
	  return (hash(x) + i*(1 + (hash(x)%((t.length + u.length) - 1))))%(t.length + u.length);
	}


public:
	// FIXME: get rid of default constructor
	//LinearHashTable();
	LinearHashTable(T null, T del);
	virtual ~LinearHashTable();
	bool add(T x);
	bool addSlow(T x);
	int countNullsFront();
	int countNullsBack();
	T remove(T x);
	T find(T x);
	int size() { return n; }
	int getLength(){ return t.length + u.length; }
	void clear();
	// FIXME: yuck
	void setNull(T null) { this->null = null; t.fill(null); }
	void setDel(T del) { this->del = del; }
};

//template<class T>
//LinearHashTable<T>::LinearHashTable() : t(2) {
///*
//	this->null = null;
//	this->del = del;
//*/
//	n = 0;
//	q = 0;
//	d = 1;
//}


template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) : t(2, null), u(2, null) {
	this->null = null;
	this->del = del;
	n = 0;
	q = 0;
	d = 1;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
	d = 1;
	while ((1<<d) < 3*n) d++;
	array<T> tnew(1<<(d-1), null);
	array<T> unew(1<<(d-1), null);
	q = n;
	int probe;

	T temp;
	for(int h = 0; h < (t.length + u.length); h++){
	    if(h < t.length) temp = t[h];
	    else temp = u[h - t.length];
	    int i = 0;

	    if(temp != null && temp != del){
		probe = hash2(temp, i);

		while((probe < tnew.length && tnew[probe] != null) ||
		    (probe >= tnew.length && unew[probe - tnew.length] != null)){
		    i++;
		    probe = hash2(temp, i);
		}
		if(probe < tnew.length && tnew[probe] == null) tnew[probe] = temp;
		if(probe >= tnew.length
		    && unew[probe - tnew.length]) unew[probe - tnew.length] = temp;
	    }

	}

	t = tnew;
	u = unew;
}

template<class T>
void LinearHashTable<T>::clear() {
	n = 0;
	q = 0;
	d = 1;
	array<T> tnew(2, null);
	t = tnew;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
	if (find(x) != null) return false;
	if (2*(q+1) > (t.length + u.length)) resize();   // max 50% occupancy
	int i = 0;
	int probe = hash2(x, i);

	while((probe < t.length && t[probe] != null)
	    || (probe >= t.length && u[probe-t.length] != null)){
	    if(probe < t.length && t[probe] != del){
		    i++;
		    //i = (i == (t.length + u.length-1)) ? 0 : i + 1;
		    probe = hash2(x, i);
	    }
	    if(probe >= t.length){
		i++;
		//i = (i == (t.length + u.length-1)) ? 0 : i + 1;
		probe = hash2(x, i);
	    }
	}

	if(probe < t.length){
	    if (t[probe] == null) q++;
	    n++;
	    t[probe] = x;
	    return true;
	}

	else{
	    if (u[probe - t.length] == null) q++;
	    n++;
	    u[probe - t.length] = x;
	    return true;
	}
}

//	while (t[probe] != null && t[probe] != del){
//		i = (i == t.length-1) ? 0 : i + 1; // increment i
//		probe = hash2(x, i);
//	}


template<class T>
T LinearHashTable<T>::find(T x) {
	int i = 0;
	int probe = hash2(x, i);
	while ((probe < t.length && t[probe] != null)
	    || (probe >= t.length && u[probe - t.length] != null)){
	    if(probe < t.length && t[probe] == x) return t[probe];
	    if(probe >= t.length && u[probe - t.length] == x) return u[probe - t.length];
	    //if(i > (t.length + u.length)) break;
	    i++;
	    probe = hash2(x, i);
	}
	return null;
}

template<class T>
T LinearHashTable<T>::remove(T x) {
	int i = 0;
	int probe = hash2(x, i);
	while ((probe < t.length && t[probe] != null)
	    || (probe >= t.length && u[probe - t.length] != null)){
		if(probe < t.length && t[probe] != del){
		T y = t[probe];
		if (y != del && x == y) {
			t[probe] = del;
			n--;
			if (8*n < t.length) resize(); // min 12.5% occupancy
			return y;
		}
		}
		if(probe >= t.length && u[probe - t.length] != del){
		T y = u[probe - t.length];
		if (y != del && x == y) {
		        u[probe - t.length] = del;
		    	n--;
		    	if (8*n < t.length) resize(); // min 12.5% occupancy
		    	return y;
		    }
		}
		i++;
		//i = (i == (t.length + u.length-1)) ? 0 : i + 1;  // increment i
		probe = hash2(x, i);
	}
	return null;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
	if (2*(q+1) > t.length) resize();   // max 50% occupancy
	int i = hash(x);
	while (t[i] != null) {
			if (t[i] != del && x.equals(t[i])) return false;
			i = (i == t.length-1) ? 0 : i + 1; // increment i
	}
	t[i] = x;
	n++; q++;
	return true;
}

template<class T>
int LinearHashTable<T>::countNullsFront(){
  int count = 0;
  for(int i = 0; i < t.length; i++){
      if(t[i] == null) count++;
  }
  return count;
}

template<class T>
int LinearHashTable<T>::countNullsBack(){
  int count = 0;
  for(int i = 0; i < u.length; i++){
      if(u[i] == null) count++;
  }
  return count;
}

} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
