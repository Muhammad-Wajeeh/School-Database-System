#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Subject
{
  protected:

  string subName;
  string Time;
  string Day;

  public:
    Subject()
    {
      
    }

    Subject(const string &_subName, const string &_Time, const string &_Day):subName(_subName), Time(_Time), Day(_Day)
    {
      
    }

};

#endif