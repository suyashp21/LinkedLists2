/* Node.h, code written by Emily MacPherson*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Student.h"

using namespace std;

class Node
{
public:
  Node(Student* newStudent); //constructor
  ~Node(); //deconstructor
  Node* getNext(); //returns next node in list
  void setNext(Node* newNext); //set next node in list
  Student* getStudent(); //returns pointer to this node's student
  Node* next;
  Student* student;
};

#endif
