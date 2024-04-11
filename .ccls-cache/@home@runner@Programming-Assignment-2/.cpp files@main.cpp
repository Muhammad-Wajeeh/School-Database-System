#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Personnel.h"
#include "myClass.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

void classCreator()
{
  string className, dayOfWeek, Time, Teacher;
  int classID;
  vector <myClass> classes;
  ofstream outFile("class_info.txt");
  cout << "Welcome to the School Management System! Please begin with creating your classes" << endl;

  for (int i =0; i<4; i++)
  {
    vector <string> studentList;
    cout << "What would you like the name of class #" << i+1 <<" to be?" << endl;
    getline(cin, className);
    cout << "What day would you like this class to be on?" << endl;
    getline(cin, dayOfWeek);
    cout << "What time would you like this class to be?" << endl;
    getline(cin, Time);
    cout << "What is the name of your teacher for this class?" << endl;
    getline(cin, Teacher);
    cout << "What is the ID# of your class?" << endl;
    cin >> classID;
    cout << "How many Students are in the class?" << endl;
    int size;
    cin >> size;
    int count = 1;
    for (int k = 0; k < size; k++)
      {
        string studentName;
        cout << "What is the name of Student " << count << " ?" << endl;
        cin >> studentName;
        studentList.push_back(studentName);
        count++;
      }

    myClass _Class(className, dayOfWeek, Time, Teacher, classID, studentList);

    classes.push_back(_Class);


    if (outFile.is_open()) 
      {
          classes[i].saveToFile(outFile);
          cout << "Class information has been saved to class_info.txt." << endl;
      } 
    else 
      {
         cerr << "Error opening file for writing!" << endl;
      }

  }
  outFile.close();
}

void classStorer()
{
  vector <myClass> classes;

    ifstream inputFile("class_info.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        //return 1;
    }



    string line;
    while (getline(inputFile, line)) 
    {
        vector<string> data;
        vector<string> dataNames;

        istringstream iss(line);
        string token;
        while (iss >> token) 
        {
            // Store each token in the vector
            data.push_back(token);
        }

      for (int i = 5; i < data.size(); i++)
      {
        dataNames.push_back(data.at(i));
      }

      myClass Class(data.at(0), data.at(1), data.at(2), data.at(3), stoi(data.at(4)), dataNames);
      classes.push_back(Class);

    }

  string hello = classes.at(1).getClassName();
  cout << hello;
  inputFile.close();
}

void studentCreator()
{
  int IDnum;
  string Name, Email;
  vector <Student> students;
  ofstream outFile("student_info.txt");
  cout << "Hey lets begin with creating your students! How many students would you like to create?" << endl;
  int numStudents;
  cin >> numStudents;
  for (int i =0; i<numStudents; i++)
  {
    cout << "What is the Name of Student " << i+1 << endl;
    // cin.ignore('\n');
    // getline(cin, Name);
    cin >> Name;
    cout << "What is their Email" << endl;
    // getline(cin, Email);
    cin >> Email;
    cout << "What is the ID# of the Student" << endl;
    cin >> IDnum;

    Student _Student(IDnum, Name, Email);

    students.push_back(_Student);
    if (outFile.is_open()) 
      {
          students[i].saveFile(outFile);
          cout << "Class information has been saved to student_info.txt." << endl;
      } 
    else 
      {
         cerr << "Error opening file for writing!" << endl;
      }

  }
  outFile.close();
}

vector <Student> studentStorer()
{
  vector <Student> students;

    ifstream inputFile("student_info.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        //return 1;
    }


    string line;
    while (getline(inputFile, line)) 
    {
        vector<string> data;
        // vector<string> dataNames;

        istringstream iss(line);
        string token;
        while (iss >> token) 
        {
            // Store each token in the vector
            data.push_back(token);
        }

      Student myStudent(stoi(data.at(0)), data.at(1), data.at(2));
      students.push_back(myStudent);

    }
  inputFile.close();
  return students;
} // take this away if you decie to merge funcion again

//   cout << "Now lets create a schedule for each student!" << endl;
//   for (int i = 0; i < students.size(); i++)
//     {
//       cout << "Create schedule for student " << i+1 << endl;
//       students.at(i).createSchedule();
//     }

//   cout << "Would you like to update the schedule of a student? Y (yes) or N (no)" << endl;
//   char answer;
//   cin >> answer;
//   if (answer == 'Y')
//   {
//     cout << "Which student would you like to update?" << endl;
//     cout << "Enter the ID# of the student" << endl;
//     int IDnumber;
//     cin >> IDnumber;
//     for (int i = 0; i < students.size(); i++)
//       {
//         if (students.at(i).getIDnum() == IDnumber)
//         {
//           auto studentSchedule = students.at(i).getSchedule();
//           students.at(i).updateSchedule(studentSchedule);
//         }
//       }
//   }

//   string hello = students.at(0).getName();
//   cout << hello;
//   inputFile.close();
// }

void teacherCreator()
{
  int IDnum;
  string Name, Email;
  vector <Teacher> teachers;
  ofstream outFile("teacher_info.txt");
  cout << "Hey lets begin with creating your students! How many Teachers would you like to create?" << endl;
  int numTeachers;
  cin >> numTeachers;
  for (int i =0; i<numTeachers; i++)
  {
    cout << "What is the Name of Teacher " << i+1 << endl;
    // cin.ignore('\n');
    // getline(cin, Name);
    cin >> Name;
    cout << "What is their Email" << endl;
    // getline(cin, Email);
    cin >> Email;
    cout << "What is the ID# of the Teacher" << endl;
    cin >> IDnum;

    Teacher _Teacher(IDnum, Name, Email);

    teachers.push_back(_Teacher);
    if (outFile.is_open()) 
      {
          teachers[i].saveToFile(outFile);
          cout << "Class information has been saved to teacher_info.txt." << endl;
      } 
    else 
      {
         cerr << "Error opening file for writing!" << endl;
      }

  }
  outFile.close();
}

vector <Teacher> teacherStorer()
{
  vector <Teacher> teachers;

    ifstream inputFile("teacher_info.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        //return 1;
    }


    string line;
    while (getline(inputFile, line)) 
    {
        vector<string> data;

        istringstream iss(line);
        string token;
        while (iss >> token) 
        {
            // Store each token in the vector
            data.push_back(token);
        }

      Teacher myTeacher(stoi(data.at(0)), data.at(1), data.at(2));
      teachers.push_back(myTeacher);

    }
  inputFile.close();
  return teachers;
}
  // cout << "Now lets input the subjects the teacher teaches" << endl;
  // for (int i = 0; i < teachers.size(); i++)
  //   {
  //     cout << "Create subjects for Teacher" << i+1 << endl;
  //     cout << "How many subjects would you like to add?" << endl;
  //     int numSubjects;
  //     cin >> numSubjects;
  //     teachers.at(i).createSubjects(numSubjects);
  //   }

//   cout << "Would you like to update the subjects of a Teacher? Y (yes) or N (no)" << endl;
//   char answer;
//   cin >> answer;
//   if (answer == 'Y')
//   {
//     cout << "Which Teacher would you like to update?" << endl;
//     cout << "Enter the ID# of the Teacher" << endl;
//     int IDnumber;
//     cin >> IDnumber;
//     for (int i = 0; i < teachers.size(); i++)
//       {
//         if (teachers.at(i).getIDnum() == IDnumber)
//         {
//           auto studentSchedule = teachers.at(i).getSubjects();
//           teachers.at(i).updateSubjects(studentSchedule);
//         }
//       }
//   }

//   string hello = teachers.at(0).getName();
//   cout << hello;
//   inputFile.close();
// }

void createStudentSchedule(vector <Student> &students)
{
  cout << "Now lets create a schedule for each student!" << endl;
  for (int i = 0; i < students.size(); i++)
    {
      cout << "Create schedule for student " << i+1 << endl;
      students.at(i).createSchedule();
    }
}

void updateStudentSchedule(vector <Student> &students)
{
  cout << "Would you like to update the schedule of a student? Y (yes) or N (no)" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y')
    {
      cout << "Which student would you like to update?" << endl;
      cout << "Enter the ID# of the student" << endl;
      int IDnumber;
      cin >> IDnumber;
      for (int i = 0; i < students.size(); i++)
        {
          if (students.at(i).getIDnum() == IDnumber)
          {
            auto studentSchedule = students.at(i).getSchedule();
            students.at(i).updateSchedule(studentSchedule);
          }
        }
    }
}

void createTeacherSchedule(vector <Teacher> &teachers)
{
  cout << "Now lets input the subjects the teacher teaches" << endl;
  for (int i = 0; i < teachers.size(); i++)
    {
      cout << "Create subjects for Teacher" << i+1 << endl;
      cout << "How many subjects would you like to add?" << endl;
      int numSubjects;
      cin >> numSubjects;
      teachers.at(i).createSubjects(numSubjects);
    }

}

void updateTeacherSchedule(vector <Teacher> &teachers)
{
  cout << "Would you like to update the subjects of a Teacher? Y (yes) or N (no)" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y')
    {
      cout << "Which Teacher would you like to update?" << endl;
      cout << "Enter the ID# of the Teacher" << endl;
      int IDnumber;
      cin >> IDnumber;
      for (int i = 0; i < teachers.size(); i++)
        {
          if (teachers.at(i).getIDnum() == IDnumber)
          {
            auto studentSchedule = teachers.at(i).getSubjects();
            teachers.at(i).updateSubjects(studentSchedule);
          }
        }
    }

}



int main ()
{
  // classCreator();
  // classStorer();
  // studentCreator();
  // studentStorer();
  // teacherCreator();
  // teacherStorer();
    // vector <Student> students = studentStorer();
    // vector <Teacher> teachers = teacherStorer();

    // createStudentSchedule(students);
    // updateStudentSchedule(students);
    // createTeacherSchedule(teachers);
    // updateTeacherSchedule(teachers);

  Student student1(1, "Jim", "ztejd@example.com");
  string date = "1/1/2023";
  char status = 'P';
  student1.markAttendance(date, status);
}

