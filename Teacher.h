#ifndef TEACHER_H
#define TEACHER_H
#include "Personnel.h"
#include <iostream>
#include <string>
#include <vector>
#include "myClass.h"

//THIS CLASS IS VERY SIMILAR TO THE STUDENT CLASS, BUT IT IS FOR TEACHERS.
using namespace std;

class Teacher: public Personnel
{
  protected:
    vector <string> subjects; // just a vector of strings that hold the subjects of a teacher
    int numberOfClasses;

  public:
    Teacher();

    Teacher(int _IDnum, const string & _Name, const string & _Email) : Personnel(_IDnum, _Name, _Email)
    {

    }

    void createSubjects(int _numberOfSubjects); // this function allows you to create a list of subjects for a teacher.

    void updateSubjects(Teacher &teacher); // this function allows you to update the subjects of a teacher.

    void saveToFile(ofstream &outFile); // this function saves the details of a teacher to a file, like their id number , name, email, etc.
    int getNumberOfClasses() const;
    vector <string> getSubjects(); // just a getter that returns the subjects of the teacher.

    void printTeacher(); // this function prints out the teacher information to the console.

    void printTeacherSchedule() const; // this function prints out the teacher schedule to the console.

};

#endif