#include "Student.h"


Student::Student()
{
  
}

void Student::createSchedule()
{
  Subject subject;
  string subname, Day, Time;
  cout << "What is the name of the subject?" << endl;
  cin >> subname;
  cout << "What day is the subject?" << endl;
  cin >> Day;
  cout << "What time is the subject?" << endl;
  cin >> Time;
  Subject(subname, Day, Time);
  classSchedule.push_back(subject);
}

void Student::updateSchedule(vector <Subject> & _classSchedule)
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
            Subject subject;
            string subname, Day, Time;
            cin >> subname >> Day >> Time;
            Subject(subname, Day, Time);
            _classSchedule.push_back(subject);
            cout << "New name added successfully!\n";
            break;
        }
        case 2: {
            // Delete a name
            int position;
            cout << "Enter the position of the name to delete (1-" << _classSchedule.size() << "): ";
            cin >> position;

            if (position >= 1 && position <= _classSchedule.size()) {
                _classSchedule.erase(_classSchedule.begin() + position - 1);
                cout << "Name deleted successfully!\n";
            } else {
                cout << "Invalid position!\n";
            }
            break;
        }
        case 3: {
            // Change a name
            int position;
            cout << "Enter the position of the name to change (1-" << _classSchedule.size() << "): ";
            cin >> position;

            if (position >= 1 && position <= _classSchedule.size()) {
                cout << "Enter the new name: ";
                Subject subject;
                string subname, Day, Time;
                cin >> subname >> Day >> Time;
                Subject(subname, Day, Time);
                _classSchedule[position - 1] = subject;
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

void Student::saveFile(ofstream &outFile) 
{
    outFile << IDnum << " " << Name << " " << Email << endl;
}

vector <Subject> Student::getSchedule()
{
    return classSchedule;
}

void Student::markAttendance(const string &date, char status)
{
  ofstream outFile("student_attendance_info.txt");
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
       cerr << "Error opening file for writing!" << endl;
    }
}