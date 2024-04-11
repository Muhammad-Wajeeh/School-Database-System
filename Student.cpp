#include "Student.h"


Student::Student()
{
  
}

void Student::createSchedule()
{
  Subject subject;
  string subname, Day, Time;
  cout << "how many subjects would you like to add?" << endl;
  int numSubjects;
  cin >> numSubjects;
  for (int i = 0; i < numSubjects; i++)
  {
    cout << "What is the name of subject " << i+1 << " ?" << endl;
    cin >> subname;
    cout << "What day is the subject?" << endl;
    cin >> Day;
    cout << "What time is the subject?" << endl;
    cin >> Time;
    subject = Subject(subname, Day, Time);
    classSchedule.push_back(subject);
  }
}

void Student::updateSchedule(Student &student)
{
    cout << "1. Add a new subject" << endl;
    cout << "2. Delete a subject" << endl;
    cout << "3. Change a subject" << endl;
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            // Add a new name
            Subject subject;
            string subname, Day, Time;
          cout << "Enter the name of the new subject: ";
            cin >> subname;
          cout << "Enter the Day of the new subject: ";
            cin >> Day;
          cout << "Enter the Time of the new subject: ";
            cin >> Time;
            subject = Subject(subname, Day, Time);
            student.classSchedule.push_back(subject);
            cout << "New subject added successfully!" << endl;
            break;
        }
        case 2: {
            // Delete a name
            int position;
            cout << "Enter the position of the Subject to delete (1-" << student.classSchedule.size() << "): ";
            cin >> position;

            if (position >= 1 && position <= student.classSchedule.size()) {
                student.classSchedule.erase(student.classSchedule.begin() + position - 1);
                cout << "Subject deleted successfully!" << endl;
            } else {
                cout << "Invalid position!" << endl;
            }
            break;
        }
        case 3: {
            // Change a name
            int position;
            cout << "Enter the position of the Subject to change (1-" << student.classSchedule.size() << "): ";
            cin >> position;

            if (position >= 1 && position <= student.classSchedule.size()) {
            
                Subject subject;
                string subname, Day, Time;
              cout << "Enter the new name of the subject: ";
                cin >> subname;
              cout << "Enter the new day of the subject: ";
                cin >> Day;
              cout << "Enter the new time of the subject: ";
                cin >> Time;
                subject = Subject(subname, Day, Time);
                student.classSchedule[position - 1] = subject;
                cout << "Subject changed successfully!" << endl;
            } else {
                cout << "Invalid position!" << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
}

void Student::saveFile(ofstream &outFile) 
{
    outFile << IDnum << " " << Name << " " << Email << endl;
}

vector <Subject> Student::getSchedule() const
{
    return classSchedule;
}

void Student::markAttendance(const string &date, char status)
{
  ofstream outFile("student_attendance_info.txt", ios::app);
  if (outFile.is_open()) 
    {
      if (status == 'A' || status == 'P' || status == 'T')
      {
        outFile << Name << " " << date << " " << status << endl;
        outFile.close();
      }
      else
        cout << "Invalid status. Please enter A, P, or T. A meaning absent, P meaning present, or T meaning Tardy" << endl;
    }
  else 
    {
       cout << "Error opening file for writing!" << endl;
    }
  outFile.close();
}

void Student::submitAssignment(const string &assigenmentName, const string &subjectName, int grade)
{
  ofstream outFile("student_assignment_info.txt", ios::app);
  if (outFile.is_open())
  {
    outFile << Name << " " << assigenmentName << " " << subjectName << " " << grade << endl;
  }
  else
    cout << "Error opening file for writing!" << endl;
  outFile.close();
}

int Student::calculateClassGrade(const string &studentName, const string &subjectName)
{
  ifstream file("student_assignment_info.txt");
  if (!file.is_open()) 
  {
    cout << "Error opening file." << endl;
  }
  
  vector <string> grades;
  string line;
  while (getline(file, line)) 
  {
    if (line.find(subjectName) != string::npos && line.find(studentName) != string::npos)
    {
      istringstream iss(line);
      string string;
      while (iss >> string) 
      { 
        if (isNumber(string) == true)
          grades.push_back(string);
      }
    }
    
  }
  file.close();

  

  int finalGrade = 0;
  int sumGrade = stoi(grades.at(0));
  for (int i = 1; i < grades.size(); i++)
    {
      sumGrade = sumGrade + stoi(grades.at(i));
    }
  finalGrade = sumGrade / grades.size();
  return finalGrade;
}

bool Student::isNumber(const string& string) 
{
  try {
      int result = stoi(string);
      result++;
      return true;
      } 
  catch (const invalid_argument& string) 
    {
      return false;
    }
}

void Student::printStudent()
{
  cout << "Student Name: " << Name << endl;
  cout << "Student ID: " << IDnum << endl;
  cout << "Student Email: " << Email << endl;
  cout << endl;
}

void Student::printStudentSchedule() const
{
  for (int i = 0; i < classSchedule.size(); i++)
    {
      string subname = classSchedule.at(i).getSubName();
      string Day = classSchedule.at(i).getDay();
      string Time = classSchedule.at(i).getTime();
      
      cout << "Subject Name: " << subname << endl;
      cout << "Day: " << Day << endl;
      cout << "Time: " << Time << endl;
      cout << endl;
    }
}

int Student::getNumberOfClasses() const
{
  return numberOfClasses;
}
