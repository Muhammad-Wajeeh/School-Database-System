#include "myClass.h"

myClass::myClass()
{
   className = "";
   dayOfWeek = "";
   Time = "";
   Teacher = "";
}

myClass::myClass(const string &_className, const string & _dayOfWeek, const string &_Time, const string &_Teacher, int _classID, const vector <string> & _studentList)
{
   className = _className;
   dayOfWeek = _dayOfWeek;
   Time = _Time;
   Teacher = _Teacher;
   studentList = _studentList;// will have he user make  a vector of student names and then equate it to this
   classID = _classID;
}

string myClass::getClassName() const
{
  return className;
}

string myClass::getDayOfWeek() const
{
  return dayOfWeek;
}

string myClass::getTeacher() const
{
  return Teacher;
}

int myClass::getclassID() const
{
  return classID;
}

string myClass::getTime() const
{
  return Time;
}

void myClass::createStudentList(int numberOfStudents)
{
  int size;
  size = numberOfStudents; // size here is exactly the same as numberOfSubjects, its just easier to type size.
  string studentName;
  int counter = 1;
  for (int i = 0; i < size; i++)
    {
      cout << "insert student's name" << counter++ << ": "<< endl;
      cin >> studentName;
      studentList.push_back(studentName);
    }
}

void myClass::updateStudentList(vector <string> & _studentList)
{
  cout << "1. Add a new name" << endl;
  cout << "2. Delete a name" << endl;
  cout << "3. Change a name" << endl;
  cout << "Enter your choice (1-3): ";

  int choice;
  cin >> choice;

  switch (choice) {
      case 1: {
          // Add a new name
          string newName;
          cout << "Enter the new name: ";
          cin >> newName;
          _studentList.push_back(newName);
          cout << "New name added successfully!"<<endl;
          break;
      }
      case 2: {
          // Delete a name
          int position;
          cout << "Enter the position of the name to delete (1-" << _studentList.size() << "): ";
          cin >> position;

          if (position >= 1 && position <= _studentList.size()) {
              _studentList.erase(_studentList.begin() + position - 1);
              cout << "Name deleted successfully!"<<endl;
          } else {
              cout << "Invalid position!"<<endl;
          }
          break;
      }
      case 3: {
          // Change a name
          int position;
          cout << "Enter the position of the name to change (1-" << _studentList.size() << "): ";
          cin >> position;

          if (position >= 1 && position <= _studentList.size()) {
              cout << "Enter the new name: ";
              cin >> _studentList[position - 1];
              cout << "Name changed successfully!"<<endl;
          } else {
              cout << "Invalid position!"<<endl;
          }
          break;
      }
      default:
          cout << "Invalid choice!"<<endl;
  }

 
}

void myClass::saveToFile(ofstream& outFile) const 
{
    outFile << className << " " << dayOfWeek << " " << Time << " " << Teacher << " " << classID;
    for (int i = 0; i < studentList.size(); ++i) {
        outFile << " " << studentList[i];
    }
    outFile << endl;
}

void myClass::generateAttendanceReport(string date)
{
  ifstream file("student_attendance_info.txt");
  if (!file.is_open()) 
  {
    cout << "Error opening file." << endl;
    return;
  }

  vector <string> data;
  string line;
  while (getline(file, line)) 
  {
    if (line.find(date) != string::npos)
    {
      cout << line << endl;
      // istringstream iss(line);
      // string string;
      // while (iss >> string) 
      // {
      //     data.push_back(string);
      // }
    }
  }
  file.close();
  // for (int i = 0; i < data.size(); i++)

  
}

void myClass::enterExamGrades(const string &studentName, const string &examName, int grade)
{
  ofstream outfile("exam_grades.txt", ios::app);
  if (!outfile.is_open())
    cout << "Error opening file." << endl;

  outfile << studentName << " " << examName << " Grade: " << grade << endl; 

  outfile.close();

  
}

void myClass::printClass() const
{
  cout << "Class Name: " << className << endl;
  cout << "Day of Week: " << dayOfWeek << endl;
  cout << "Time: " << Time << endl;
  cout << "Teacher: " << Teacher << endl;
  cout << "Class ID: " << classID << endl;
  cout << "Student List: " << endl;
  for (int i = 0; i < studentList.size(); i++)
    {
      cout << studentList[i] << endl;
    }
  cout << endl;
}



