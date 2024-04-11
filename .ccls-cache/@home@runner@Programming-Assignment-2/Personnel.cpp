#include "Personnel.h"

Personnel::Personnel() //Default Constructor
{
  IDnum = 0;
  Name = "";
  Email = "";
}

Personnel::Personnel(int _IDnum, const string & _Name, const string & _Email) //OL Constructor
{
  IDnum = _IDnum;
  Name = _Name;
  Email = _Email;
}

int Personnel::getIDnum() const
{
  return IDnum;
}
  
string Personnel::getName() const
{
  return Name;
}
  
string Personnel::getEmail() const
{
  return Email;
}
  
