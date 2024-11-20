/*

Header file for single linked list class library

*/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>
class Node{
  public: 
    Node* n; 
    void* v;
    Node(void* p); 
};

class Slist {
  public: 
  Node* header;
  int l;
  Slist(void* v);
  Slist();
  ~Slist();
// add(value)				//Adds a new value to the end of this list.
void add(void* value);

// clear()					//Removes all elements from this list.
void clear();

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool equals(Slist list);

//get(index)				//Returns the element at the specified index in this list.
Node* get(int i);

//insert(index, value)		//Inserts the element into this list before the specified index.
void insert(int i, void* value);

//exchg(index1, index2)		//Switches the payload data of specified indexex.
void exchg(int i1, int i2);

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void swap(int i1, int i2);

// isEmpty()				//Returns true if this list contains no elements.
bool isEmpty();

// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.
//void mapAll(std::function<double> fn);

// remove(index)			//Removes the element at the specified index from this list.
void remove(int i);

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void set(int i, void* v);

// size()					//Returns the number of elements in this list.
int size();

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
Slist subList(int i, int l);

// toString()				//Converts the list to a printable string representation.
std::string toString();
};
#endif