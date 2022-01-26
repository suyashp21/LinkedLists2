#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(char* newfirst, char* newlast, int newid, float newgpa); // constructor
  ~Student(); // destructor
  // returns student info
  char* getFirst();
  char* getLast();
  int getID();
  float getGPA();
 private:
  char* first;
  char* last;
  int id;
  float gpa;
};
#endif
