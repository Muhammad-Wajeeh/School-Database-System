#include "Class.h"

Class::Class()
{
   className = "";
   dayOfWeek = "";
   Time = "";
   Teacher = "";
}

Class::Class(const string &_className, const string & _dayOfWeek, const string &_Time, const string &_Teacher, const vector <string> & _studentList, int _classID)
{
   className = _className;
   dayOfWeek = _dayOfWeek;
   Time = _Time;
   Teacher = _Teacher;
   studentList = _studentList; // will have he user make  a vector of student names and then equate it to this
   classID = _classID;
}

string Class::getClassName() const
{
  return className;
}

string Class::getDayOfWeek() const
{
  return dayOfWeek;
}

string Class::getTeacher() const
{
  return Teacher;
}

int Class::getclassID() const
{
  return classID;
}

void Class::updateStudentList(vector <string> & _studentList)
{
  cout << "1. Add a new name\n";
  cout << "2. Delete a name\n";
  cout << "3. Change a name\n";
  cout << "Enter your choice (1-3): ";

  int choice;
  cin >> choice;

  switch (choice) {
      case 1: {
          // Add a new name
          string newName;
          cout << "Enter the new name: ";
          cin >> newName;
          studentNames.push_back(newName);
          cout << "New name added successfully!\n";
          break;
      }
      case 2: {
          // Delete a name
          int position;
          cout << "Enter the position of the name to delete (1-" << studentNames.size() << "): ";
          cin >> position;

          if (position >= 1 && position <= studentNames.size()) {
              studentNames.erase(studentNames.begin() + position - 1);
              cout << "Name deleted successfully!\n";
          } else {
              cout << "Invalid position!\n";
          }
          break;
      }
      case 3: {
          // Change a name
          int position;
          cout << "Enter the position of the name to change (1-" << studentNames.size() << "): ";
          cin >> position;

          if (position >= 1 && position <= studentNames.size()) {
              cout << "Enter the new name: ";
              cin >> studentNames[position - 1];
              cout << "Name changed successfully!\n";
          } else {
              cout << "Invalid position!\n";
          }
          break;
      }
      default:
          cout << "Invalid choice!\n";
  }
  }
}

