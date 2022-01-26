/* Author: Suyash Pandit
Date: January 26, 2022.
This is the second part of the Linked List project.
The code has been updated to recreate the Student List project, but with Linked Lists instead of vectors. */

#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

void add(Node* current, Node* next, Student* s);
void print(Node* current);
float average(Node* current, float sum, int num);
void remove(Node* previous, Node* current, int id);

int main() {
  char action[20];
  char newfirst[20];
  char newlast[20];
  int newid;
  int removeid;
  float newgpa;
  
  /* I created a "dummy student" as the head.
  This ensures I never have to reassign it, which makes life easier.
  When printing students, this "dummy student" is not shown. */
  
  strcpy(newfirst, "Dummy");
  strcpy(newlast, "Student");
  Student* dummy = new Student(newfirst, newlast, -1, 0.00);
  Node* head = new Node(dummy);
  
  while (true) {
    cout << "What would you like to do? (ADD, PRINT, DELETE, QUIT, AVERAGE) ";
    cin >> action;
    if (strcmp(action, "ADD") == 0) {
      // prompt for basic info
      cout << "\nFirst name: ";
      cin >> newfirst;
      cout << "Last name: ";
      cin >> newlast;
      cout << "ID: ";
      cin >> newid;
      cout << "GPA: ";
      cin >> newgpa;
      cout << "\n";
      Student* s = new Student(newfirst, newlast, newid, newgpa);
      add(head, head->getNext(), s);
      /* cout << head->getNext()->getStudent()->getID();
      if (head->getNext()->getNext() != NULL) {
        cout << head->getNext()->getNext()->getStudent()->getID();
      } */
    }
    else if (strcmp(action, "PRINT") == 0) {
      if (head->getNext() == NULL) {
	cout << "\nNo students. Nothing to print!\n" << endl;
      }
      else {
        cout << "\n";
        print(head);
      }
    }
    else if (strcmp(action, "AVERAGE") == 0) {
      if (head->getNext() == NULL) {
	cout << "\nYou can't do that without any students.\n" << endl;
      }
      else {
	cout << "\nAverage GPA: " << fixed << setprecision(2) << average(head->getNext(), 0, 0) << "\n" << endl;
      }
    }
    else if (strcmp(action, "DELETE") == 0) {
      if (head->getNext() == NULL) {
	cout << "You can't do that without any students." << endl;
      }
      else {
	cout << "\nID of student to remove: ";
	cin >> removeid;
	remove(head, head->getNext(), removeid);
      }
    }
    else if (strcmp(action, "QUIT") == 0) {
      break;
    }
    else {
      cout << "Command not recognized." << endl;
    }
  }
  return 0;
}

void add(Node* current, Node* next, Student* s) {
  Node* n = new Node(s);
  // find where it should go based on ID number
  if (next == NULL) {
    current->setNext(n);
  }
  else if (s->getID() < next->getStudent()->getID()) {
    current->setNext(n);
    n->setNext(next);
  }
  else {
    add(next, next->getNext(), s);
  }
}

void print(Node* current) {
  Student* s = current->getStudent();
  if (s->getID() != -1) { // don't print the dummy
    // print student name, id, and gpa
    cout << s->getFirst() << " " << s->getLast() << endl;
    cout << "ID: " << s->getID() << endl;
    cout << "GPA: " << fixed << setprecision(2) << s->getGPA() << "\n" << endl;
  }
  if (current->getNext() != NULL) {
    // print next student in list
    print(current->getNext());
  }
}

float average(Node* current, float sum, int num) {
  // adjust sum and number of students
  sum = sum + current->getStudent()->getGPA();
  num++;
  if (current->getNext() == NULL) {
    return sum/num;
  }
  else {
    return average(current->getNext(), sum, num);
  }
}

void remove(Node* previous, Node* current, int id) {
  if (current == NULL) {
    // reached end of list
    cout << "\nThere's no student with that ID. Nothing has been deleted.\n" << endl;
  }
  else if (current->getStudent()->getID() != id) {
    // check next student in list
    remove(current, current->getNext(), id);
  }
  else {
    previous->setNext(current->getNext());
    delete current;
    cout << "Student deleted.\n" << endl;
  }
}
