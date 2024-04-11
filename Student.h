#ifndef STUDENT_H
#define STUDENT_H
#include "Personnel.h"
#include <iostream>
#include <string>
#include <vector>
#include "myClass.h"
#include "Subject.h"


using namespace std;

class Student: public Personnel/*, public Subject*/
{
  protected:
    vector <Subject> classSchedule; // This is a vector of Subject objects which each object holds information on when that subject occurs, what it is, etc.
    int numberOfClasses;

  public:
    Student();

    Student(int _IDnum, const string & _Name, const string & _Email) : Personnel(_IDnum, _Name, _Email)
    {
      
    }

    void createSchedule(); // just creates the schedule for the student.

    void updateSchedule(Student &student); //allows you to update that schedule if youd like.

    void saveFile(ofstream &outFile);// another saveToFile function that saves the details of a student to a file, like their id number , name, email, etc.
    int getNumberOfClasses() const;
    vector <Subject> getSchedule() const; //just a getter that returns the schedule of the student.

    void markAttendance(const string &date, char status); //this function allows you to mark attendance for a specific date for that student.

    void submitAssignment(const string &assigenmentName, const string &subjectName, int grade); //this function allows you to submit an assignment for a specific subject for that student.

    int calculateClassGrade(const string &studentName, const string &subjectName); //calculates the average of the grades of a student for a class

    bool isNumber(const string& string); // this is kind of just like a helper function for calculateClassGrade, it checks if a string is a number or not.

    void printStudent(); //this function prints out the student information to the console.

    void printStudentSchedule() const; //this function prints out the student schedule to the console.
};

#endif