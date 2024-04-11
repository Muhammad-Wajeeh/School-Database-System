#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class myClass
{
  protected:
    string className;
    string dayOfWeek;
    string Time;
    string Teacher;
    vector <string> studentList;
    int classID;

  public:
    myClass(); //default constructor
    myClass(const string &_className, const string & _dayOfWeek, const string &_Time, const string &_Teacher,int _classID, const vector <string> & _studentList); //OL constructor

//these are all just getters taht return their respective variable
    string getClassName() const; 
    string getDayOfWeek() const;
    string getTeacher() const;
    string getTime() const;
    int getclassID() const;
//this is the printClass function which doesnt do anything but print out the class information for the myClass object
    void printClass() const;

//these just create a studentList and allow you to update it if youd like.
    void createStudentList(int numberOfStudents);
    void updateStudentList(vector <string> & _studentList);

//this is the saveToFile function which saves the information of the myClass object to a file, it wasnt really as necessary as i thought to create this since I think i only used it once, nonetheless its there.
    void saveToFile(ofstream& outFile) const;

//this just uses the date that passed through it as a paramaeter and searches the student_attendance.txt file for the date and generates the attendance report for students on that date.
    void generateAttendanceReport(string date); 

// allows you to enterExamGrades and stores them into a file called exam_grades.txt
    void enterExamGrades(const string &studentName, const string &examName, int grade);
};

#endif