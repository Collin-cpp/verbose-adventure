#include "slist.h"

/*

Class Library File

*/

#include <string>
#include <iostream>


  Node::Node(void* p){
    v = p;
  }



// Constructor

  Slist::Slist(void* v){
    header = new Node(v);
    l = 1;
  }
  Slist::Slist(){
     l = 1;
     header = nullptr;
  }

// Destructor
  Slist::~Slist(){
    Node* temp = header; 
    while (header != NULL){
      header = header->n;
      delete temp;
      temp = header; 
    }
  }
// add(value)				//Adds a new value to the end of this list.
void Slist::add(void* value){
  Node* temp = get(l-1);
  temp->n = new Node(value);
  l++;
}

// clear()					//Removes all elements from this list.
void Slist::clear(){
  Node* temp = header; 
    while (header != NULL){
      header = header->n;
      delete temp;
      temp = header; 
    }
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool Slist::equals(Slist list){
  Node* temp = header; 
  Node* temp2 = list.header; 
  while (temp->n != NULL && temp2->n != NULL){
    temp = temp->n;
    temp2 = temp2->n;
    if ((temp->v) != temp2->v){
      return false; 
    }
  }
  return true;
}

//get(index)				//Returns the element at the specified index in this list.
Node* Slist::get(int i){
  Node* temp = header; 
  for (int n = 0; n<i; n++){
    if (temp->n != NULL){
      temp = temp->n;
    }
  }
  return temp;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void Slist::insert(int i, void* value){
  Node* temp = header; 
  for (int n = 0; n<i; n++){
    if (temp->n != NULL){
      temp = temp->n;
    }
  }
  Node* next = temp->n;
  temp->n = new Node(value);
  temp->n->n = next; 
  l++;
}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
void Slist::exchg(int i1, int i2){
  Node* temp = header; 
  for (int n = 0; n<=i1; n++){
    if (temp->n != NULL){
      temp = temp->n;
    }
  }
  Node* temp1 = header; 
  for (int n = 0; n<=i2; n++){
    if (temp1->n != NULL){
      temp1 = temp1->n;
    }
  }
  Node* temp2 = temp; 
  temp->n = temp1->n;
  temp->v = temp1->v;
  temp1->n = temp2->n;
  temp1->v = temp2->v;
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void Slist::swap(int i1, int i2){ // need to still do
  Node* temp = header; 
  for (int n = 0; n<i1; n++){
    if (temp->n != NULL){
      temp = temp->n;
    }
  }
  Node* temp1 = header; 
  for (int n = 0; n<i2; n++){
    if (temp1->n != NULL){
      temp1 = temp1->n;
    }
  }
  Node* temp2 = temp; 
  if(temp == NULL){
    if(temp1->n->n == NULL){
      temp2 = temp1; 
      temp1->n = header; 
      header = temp2; 
      header->n = temp1->n->n;
      temp1->n->n = NULL;
    }
    else{
      temp2 = temp1; 
      temp1->n = header; 
      header = temp2; 
      header->n = temp1->n->n;
      temp1->n->n = temp2->n->n;
    }
  }
  else{
    if(temp1->n->n == NULL){
      temp->n = temp1->n; 
      temp = temp1; 
      temp2->n->n = temp1->n->n;
      temp1->n->n = NULL;
    }
    else{
      temp->n = temp1->n; 
      temp = temp1; 
      temp->n->n = temp1->n->n;
      temp1->n->n = temp2->n->n;
    }
  }
}

// isEmpty()				//Returns true if this list contains no elements.
bool Slist::isEmpty(){
  return header == NULL;
}

// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.
//void mapAll(std::function<double> fn);

// remove(index)			//Removes the element at the specified index from this list.
void Slist::remove(int i){
  Node* temp = get(i-1);
  if (temp == NULL){
    temp = header; 
    header = temp->n;
  }
  else{
    delete temp; 
  }
  l--;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void Slist::set(int i, void* v){
  Node* temp = get(i);
  temp->v = v; 
}

// size()					//Returns the number of elements in this list.
int Slist::size(){
  if (isEmpty()){
    return 0;
  }
  Node* temp = header; 
  int count = 1; 
  while (temp->n != NULL){
    temp = temp->n;
    count++;
  }
  return count; 
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
Slist Slist::subList(int i, int l){
  Node* temp = get(i);
  Slist rtn = new Slist(temp);
  for (int n =0; n < l; n++){
    temp = temp->n;
    rtn.add(temp);
  }
  return rtn; 
}

// toString()				//Converts the list to a printable string representation.
std::string Slist::toString(){
  return "yup, this is a list turned into a string, and this method is never used, and has minimal description, so this does work for this purpose, as it is quite descriptive of this list"; 
}
