#ifndef Class_H
#define Class_H

#include <iostream>
#include <string>
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
    Class();
    Class(const string &_className, const string & _dayOfWeek, const string &_Time, const string &_Teacher, const vector <string> & _studentList);

    string getClassName() const;
    string getDayOfWeek() const;
    string getTeacher() const;
    string getTime() const;
    int getclassID() const;
    void updateStudentList(vector <string> & _studentList);
    
};

#endif