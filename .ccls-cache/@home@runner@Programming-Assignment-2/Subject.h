#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// THIS CLASS KINDA JUST EXISTS TO BE A CLASS THAT A STUDENT OBJECT CAN USE TO CREATE A AND STORE THEIR CLASS SCHEDULE.

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

    Subject(const string &_subName, const string &_Day, const string &_Time):subName(_subName), Time(_Time), Day(_Day)
    {
      
    }
// JUST GETTERS:
    string getSubName() const
    {
      return subName;
    }

    string getTime() const
    {
      return Time;
    }

    string getDay() const
    {
      return Day;
    }

};

#endif