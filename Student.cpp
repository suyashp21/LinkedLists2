#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

Student::Student(char* newfirst, char* newlast, int newid, float newgpa) {
  first = new char[20];
  strcpy(first, newfirst);
  last = new char[20];
  strcpy(last, newlast);
  id = newid;
  gpa = newgpa;
}

Student::~Student() {
  delete first;
  delete last;
}

char* Student::getFirst() {
  return first;
}

char* Student::getLast() {
  return last;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa;
}
