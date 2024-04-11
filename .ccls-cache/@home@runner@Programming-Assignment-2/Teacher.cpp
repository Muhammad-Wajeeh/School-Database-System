#include "Teacher.h"


Teacher::Teacher()
{

}

void Teacher::createSubjects(int numberOfSubjects)
{
  int size;
  size = numberOfSubjects; // size here is exactly the same as numberOfSubjects, its just easier to type size.
  string subjectName;
  int counter = 1;
  for (int i = 0; i < size; i++)
    {
      cout << "insert subject" <<counter++ << " name" << ": "<< endl;
      cin >> subjectName;
      subjects.push_back(subjectName);
    }
}

void Teacher::updateSubjects(Teacher &teacher)
{
    cout << "1. Add a new subject" << endl;
    cout << "2. Delete a subject" << endl;
    cout << "3. Change a subject"<< endl;
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            // Add a new name
            string newName;
            cout << "Enter the new subject: ";
            cin >> newName;
              teacher.subjects.push_back(newName);
            cout << "New subject added successfully!"<<endl;
            break;
        }
        case 2: {
            // Delete a name
            int position;
            cout << "Enter the position of the subject to delete (1-" << teacher.subjects.size() << "): ";
            cin >> position;

            if (position >= 1 && position <= teacher.subjects.size()) {
                  teacher.subjects.erase(teacher.subjects.begin() + position - 1);
                cout << "subject deleted successfully!" <<endl;
            } else {
                cout << "Invalid position!" <<endl;
            }
            break;
        }
        case 3: {
            // Change a name
            int position;
            cout << "Enter the position of the subject to change (1-" << teacher.subjects.size() << "): ";
            cin >> position;

            if (position >= 1 && position <= teacher.subjects.size()) {
                cout << "Enter the new subject: ";
                cin >> teacher.subjects[position - 1];
                cout << "subject changed successfully!" <<endl;
            } else {
                cout << "Invalid position!" <<endl;
            }
            break;
        }
        default:
            cout << "Invalid choice!" <<endl;
    }
}

void Teacher::saveToFile(ofstream &outFile) 
{
    outFile << IDnum << " " << Name << " " << Email << endl;
}

vector <string> Teacher::getSubjects()
{
    return subjects;
}

void Teacher::printTeacher()
{
    cout << "ID: " << IDnum << endl;
    cout << "Name: " << Name << endl;
    cout << "Email: " << Email << endl;
  
  for (int i = 0; i < subjects.size(); i++)
    {
      cout << subjects.at(i) << " ";
    }
  cout << endl;
}

void Teacher::printTeacherSchedule() const
{
  for (int i = 0; i < subjects.size(); i++)
    {
      cout << subjects.at(i) << " ";
    }
}

int Teacher::getNumberOfClasses() const
{
  return numberOfClasses;
}
