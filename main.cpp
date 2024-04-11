#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Functions.h"

using namespace std;


int main ()
{
  cout << "PLEASE NOTE WHEN USING THIS PROGRAM, WHENEVER YOU MUST INPUT A PROPER NOUN SUCH AS A NAME FOR ANYTHING LIKE A STUDENT, TEACHER, CLASS, OR EVEN DAY OF THE WEEK, PLEASE INTIATE THE NAME WITH A CAPITAL LETTER AS NEEDED." << endl << endl;
  
  cout << "Welcome to the School Management System! Please begin with creating your classes" << endl;
  
  Functions F; // creating a Function object A lot of the program is hidden in the functions class, which basicallly give you access to all other function.
  F.classCreator(); // calls the classCreator function in the functions.h file, which creates a class with the given name and number of students
  F.classLoader(); // calls the classLoader function in the functions.h file, which loads the classes from the classes.txt file
  F.classPrinter(F.classLoader()); // calls the classPrinter function in the functions.h file, which prints the classes from the classes.txt file

  
  F.studentCreator(); // calls the studentCreator function in the functions.h file, which creates a student with the given name, ID, and email
  vector <Student> students = F.studentLoader(); // calls the studentLoader function in the functions.h file, which loads the students from the students.txt file
  F.studentPrinter(F.studentLoader()); // calls the studentPrinter function in the functions.h file, which prints the students from the students.txt file

  F.teacherCreator(); // calls the teacherCreator function in the functions.h file, which creates a teacher with the given name, ID, and
  vector <Teacher> teachers = F.teacherLoader();// calls the teacherLoader function in the functions.h file, which loads the teachers from the teachers.txt file
  F.teacherPrinter(F.teacherLoader()); // calls the teacherPrinter function in the functions.h file, which prints the teachers from the teachers.txt file
  

    F.createStudentSchedule(students); // calls the createStudentSchedule function in the functions.h file, which creates a schedule for a student
    F.updateStudentSchedule(students); // calls the updateStudentSchedule function in the functions.h file, which updates a student's schedule
    F.studentSchedulePrinter(students); // calls the studentSchedulePrinter function in the functions.h file, which prints a student's schedule


    F.createTeacherSchedule(teachers); // calls the createTeacherSchedule function in the functions.h file, which creates a schedule for a teacher
    F.updateTeacherSchedule(teachers);// calls the updateTeacherSchedule function in the functions.h file, which updates a teacher's schedule
    F.teacherSchedulePrinter(teachers);// calls the teacherSchedulePrinter function in the functions.h file, which prints a teacher's schedule

  // //Now the following bits of code that arent hidden because these bits of code arent doing anything spectacular, just calling on other functions that actually do the work. So i didnt beileve it was necessary to hide them.

  // //anyways this will prompt you to mark the attendance of students which you can choose to do or not
  cout << "Would you like to mark the attendance of any students? Y (yes) or N (no)" << endl;
  char answer;
  cin >> answer;
  if (answer == 'Y')
  {
    cout << "How many students would you like to mark?" << endl;
    int numStudents;
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
      cout << "What is the name of student#" << i+1 << " you would like to mark?" << endl;
      string name;
      cin >> name;
      
      cout << "What is their ID#?" << endl;
      int IDnum;
      cin >> IDnum;
      
      cout << "What is their E-mail?" << endl;
      string email;
      cin >> email;
      
      Student student1(IDnum, name, email);
  
      cout << "What is the date of the attendance? (input in this format: MM/DD/YYYY)" << endl;
      string date;
      cin >> date;
  
      cout << "What was the status of the attendance? Please input one of the following character: P = Present, A = Absent, T = Tardy " << endl;
      char status;
      cin >> status;
      student1.markAttendance(date, status); // this is the function actually doing the work
    }
  }


  //this will prompt you to create an attendance report which you may choose to do or not
  cout << "Would you like to generate an attendance report? Y (yes) or N (no)" << endl;
  char answer2;
  cin >> answer2;
  if (answer2 == 'Y')
  {
    myClass class1;
    cout << "What date will the report be generated for? (input in this format: MM/DD/YYYY)" << endl;
    string date;
    cin >> date;
    class1.generateAttendanceReport(date);// this is the function actually doing the work
  }

  //this will prompt you to sumbit grades for a student which you may choose to do or not
  cout << "Would you like to submit a student's grade for an assignment? Y (yes) or N (no)" << endl;
  char answer3;
  cin >> answer3;
    if (answer3 == 'Y')
      {
        cout << "How many students would you like to sumbit an assignment for?" << endl;
        int numStudents;
        cin >> numStudents;

        for (int i = 0; i < numStudents; i++)
        {
          cout << "What is the name of student#" << i+1 << " you would like to sumbit for?" << endl;
          string name;
          cin >> name;

          cout << "What is their ID#?" << endl;
          int IDnum;
          cin >> IDnum;

          cout << "What is their E-mail?" << endl;
          string email;
          cin >> email;

          Student student1(IDnum, name, email);

          cout << "What is the name of the assignment?" << endl;
          string assignmentName;
          cin >> assignmentName;

          cout << "What is the subject of the assignment?" << endl;
          string subject;
          cin >> subject;

          cout << "What is the grade of the assignment?" << endl;
          int grade;
          cin >> grade;
          
    student1.submitAssignment(assignmentName , subject, grade);// this is the function actually doing the work
        }
      }

//this will prompt you to create a grade report for a student which you may choose to do or not
  cout << "Would you like to calculate the class grade of a student? Y (yes) or N (no)" << endl;
    char answer4;
    cin >> answer4;
    if (answer4 == 'Y')
    {
      Student student;
      cout << "What is the name of the student?" << endl;
      string name;
      cin >> name;

      cout << "What is the class" << endl;
      string className;
      cin >> className;
    int num = student.calculateClassGrade(name, className);// this is the function actually doing the work
    cout << name<< "\'s " << className << " class grade: " << num << endl;
        }
  
//this will prompt you to enter exam grades for students which you may choose to do or not
  cout << "Would you like to enter the any exam grades? Y (yes) or N (no)" << endl;
    char answer5;
    cin >> answer5;
    if (answer5 == 'Y')
    {
      cout << "How many exam grades would you like to enter?" << endl;
      int numExams;
      cin >> numExams;
      for (int i = 0; i < numExams; i++)
        {
          myClass class1;
          cout << "What is the name of student"<< i+1 <<" whose grade you are entering?" << endl;
          string studentName;
          cin >> studentName;

          cout << "What is the name of the exam?" << endl;
          string examName;
          cin >> examName;

          cout << "What is the grade of the exam?" << endl;
          int grade;
          cin >> grade;
          class1.enterExamGrades(studentName, examName, grade);// this is the function actually doing the work
        }
    }

  F.examGradesReport(); // finally i hid this one since its implemenation isnt so basic, but this one will essentially print out the exam grades report for all exams
}
