#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <iostream>
#include <string>
using namespace std;

//THIS WHOLE CLASS SORT OF JUST EXISTS AS AN ABSTRACT CLASS SO THAT THE STUDENT AND TEACHER CLASSES CAN BE DERIVED FROM IT AND MAKE USE OF IT.
class Personnel
{
  protected:
    int IDnum;
    string Name;
    string Email;
  
  public:

    //Constructors
    Personnel();
    Personnel(int _IDnum, const string & _Name, const string & _Email);

    //setters
    void setIDnum(int _IDnum);
    void setName(string _Name);
    void setEmail(string _Email);
    //getters
    int getIDnum() const;
    string getName() const;
    string getEmail() const;

};

#endif