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
    vector <Subject> classSchedule;
    int numberOfClasses;

  public:
    Student();

    Student(int _IDnum, const string & _Name, const string & _Email) : Personnel(_IDnum, _Name, _Email)
    {
      
    }

    void createSchedule();

    void updateSchedule(vector <Subject> & _classSchedule);

    void saveFile(ofstream &outFile);

    vector <Subject> getSchedule();

    void markAttendance(const string &date, char status);
    
};

#endif