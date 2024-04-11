#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Personnel.h"
#include "myClass.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Functions
{
  private:
  
  public:
  
  void classCreator(); //prompts the user to input class information and basically stores all the information in a file
  vector <myClass> classLoader(); //loads the information from the file into a vector of myClass objects
  void classPrinter(vector <myClass> classes); //this takes that vector and prints it out to the console

//these are essentially the same as the classcreator, loader, and printer functions, but for the student and teacher classes. 
  void studentCreator(); 
  vector <Student> studentLoader();
  void studentPrinter(vector <Student> students);

  void teacherCreator();
  vector <Teacher> teacherLoader();
  void teacherPrinter(vector <Teacher> teachers);

  void createStudentSchedule(vector <Student> &students); //this function takes the student vector and creates a schedule for each student
  void updateStudentSchedule(vector <Student> &students); //this function allows  you to update the schedule of a student if youd like
  void studentSchedulePrinter(const vector <Student> &students); // this just prints it.
//these are just the teacher counterparts of the student scheduling functions.
  void createTeacherSchedule(vector <Teacher> &teachers); 
  void updateTeacherSchedule(vector <Teacher> &teachers);
  void teacherSchedulePrinter(const vector <Teacher> &teachers);
//just accesses the exam_grades.txt file and prints it out to the console.
  void examGradesReport();
};

#endif