#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
    myClass();
    myClass(const string &_className, const string & _dayOfWeek, const string &_Time, const string &_Teacher,int _classID, const vector <string> & _studentList);

    string getClassName() const;
    string getDayOfWeek() const;
    string getTeacher() const;
    string getTime() const;
    int getclassID() const;

    void createStudentList(int numberOfStudents);
    void updateStudentList(vector <string> & _studentList);

    void saveToFile(ofstream& outFile) const;
    
};

#endif