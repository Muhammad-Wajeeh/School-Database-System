#include "Functions.h"
// all these functions were explained in the functions.h file, but i will dig a bit deeper into them here, i will explain the slightly more complicated parts of these functions. most of it should be self explantory though if you look at the functions.h file. 
void Functions::classCreator()
{
  string className, dayOfWeek, Time, Teacher;
  int classID;
  vector <myClass> classes;
  ofstream outFile("class_info.txt");
  cout << "How many classes would you like to create?" << endl;
  int numClasses;
  cin >> numClasses;
  for (int i =0; i<numClasses; i++)
  {
    vector <string> studentList;
    cout << "What would you like the name of class #" << i+1 <<" to be?" << endl;
    cin >> className;
    cout << "What day would you like this class to be on?" << endl;
    cin >> dayOfWeek;
    cout << "What time would you like this class to be? (Do not input space)" << endl;
    cin >> Time;
    cout << "What is the name of your teacher for this class? (If you'd like to write a lastname write it in the format shown: firstname.lastname)" << endl;
    cin >> Teacher;
    cout << "What is the ID# of your class? (please enter a number)" << endl;
    cin >> classID;
    cout << "How many Students are in the class?" << endl;
    int size;
    cin >> size;
    int count = 1;
    for (int k = 0; k < size; k++)
      {
        string studentName;
        cout << "What is the name of Student " << count << " ?" << " (If you'd like to write a lastname write it in the format shown: firstname.lastname)" << endl;
        cin >> studentName;
        studentList.push_back(studentName);
        count++;
      }

    myClass _Class(className, dayOfWeek, Time, Teacher, classID, studentList);

    classes.push_back(_Class); //here you are creating a vector of myClass objects


    if (outFile.is_open()) 
      {
          classes[i].saveToFile(outFile); // the vector is then used here to store the information of the class into the file
          cout << "Class information has been saved to class_info.txt." << endl;
      } 
    else 
      {
         cout<< "Error opening file for writing!" << endl;
      }

  }
  outFile.close(); 
}

//---------------------- just seperator for tidyness and readablity ----------------------

vector <myClass> Functions::classLoader()
{
  
  vector <myClass> classes;

    ifstream inputFile("class_info.txt");
    if (!inputFile.is_open()) 
    {
        cout << "Error opening file." << endl;
        //return 1;
    }


    else
    {
        string line;
        while (getline(inputFile, line)) 
        {
            vector<string> data;
            vector<string> dataNames;
    
            istringstream iss(line);
            string string;
            while (iss >> string) 
            {
                // Store each token in the vector
                data.push_back(string);
            }
    
          for (int i = 5; i < data.size(); i++) // this for loop is used to store the names of the students into a vector, since its a vector and im attempting to store a vector int my other vector i needed to create its own for loop.
          {
            dataNames.push_back(data.at(i));
          }
    
          myClass Class(data.at(0), data.at(1), data.at(2), data.at(3), stoi(data.at(4)), dataNames);
          classes.push_back(Class);
        }
      cout << "Classes have been loaded from class_info.txt into classes vector" << endl;
    }

  // string hello = classes.at(1).getClassName();
  // cout << hello;
  inputFile.close();
  return classes;
}

//---------------------------------------------------------
//just prints the stuff int the vector of myClass objects out.
void Functions::classPrinter(vector <myClass> classes)
{
  for (int i = 0; i < classes.size(); i++)
    {
      cout << "Class #" << i+1 << ": " << endl;
      classes.at(i).printClass(); // this is the function that prints out the class info. and its explanation will be in the myClass.h file.
    }
}

//-----------------------------------------------------------

void Functions::studentCreator()
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
    cout << "What is the Name of Student" << i+1 << "(If you'd like to write a lastname write it in the format shown: firstname.lastname)" << endl;
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

//-----------------------------------------------

vector <Student> Functions::studentLoader()
{
  vector <Student> students;

    ifstream inputFile("student_info.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        //return 1;
    }

else{
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
  cout << "Students have been loaded from student_info.txt into students vector" << endl;
}
  inputFile.close();
  return students;
}
//-----------------------------------------------

void Functions::studentPrinter(vector <Student> students)
{
  for (int i = 0; i < students.size(); i++)
    {
      cout << "Student #" << i+1 << ": " << endl;
      students.at(i).printStudent();
    }
}

//-----------------------------------------------

void Functions::teacherCreator()
{
  int IDnum;
  string Name, Email;
  vector <Teacher> teachers;
  ofstream outFile("teacher_info.txt");
  cout << "Hey lets begin with creating your Teachers! How many Teachers would you like to create?" << endl;
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

//-----------------------------------------------

vector <Teacher> Functions::teacherLoader()
{
  vector <Teacher> teachers;

    ifstream inputFile("teacher_info.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        //return 1;
    }

else
  {
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
  cout << "Teachers have been loaded from teacher_info.txt into teachers vector" << endl;
  }
  inputFile.close();
  return teachers;
}

//-----------------------------------------------

void Functions::teacherPrinter(vector <Teacher> teachers)
{
  for (int i = 0; i < teachers.size(); i++)
    {
      cout << "Teacher #" << i+1 << ": " << endl;
      teachers.at(i).printTeacher();
      cout << endl;
    }
  
}

//-----------------------------------------------

void Functions::createStudentSchedule(vector <Student> &students)
{
  cout << "Now lets create a schedule for each student!" << endl;
  for (int i = 0; i < students.size(); i++)
    {
      cout << "Create schedule for student " << i+1 << endl;
      students.at(i).createSchedule();
    }
}

//-----------------------------------------------

void Functions::updateStudentSchedule(vector <Student> &students)
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
            // auto studentSchedule = students.at(i).getSchedule();
            // students.at(i).updateSchedule(studentSchedule);
            students.at(i).updateSchedule(students.at(i));
          }
        }
    }
}

//-----------------------------------------------

void Functions::studentSchedulePrinter(const vector <Student> &students)
{
  for (int i = 0; i < students.size(); i++)
    {
      cout << "Student #" << i+1 << ": " << endl;
      students.at(i).printStudentSchedule();
      cout << endl;
    }
}

//-----------------------------------------------

void Functions::createTeacherSchedule(vector <Teacher> &teachers)
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

//-----------------------------------------------

void Functions::updateTeacherSchedule(vector <Teacher> &teachers)
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
            // vector <string> studentSchedule = teachers.at(i).getSubjects();
            // teachers.at(i).updateSubjects(studentSchedule);
            teachers.at(i).updateSubjects(teachers.at(i));
          }
        }
    }

}

//-----------------------------------------------

void Functions::teacherSchedulePrinter(const vector <Teacher> &teachers)
{
  for (int i = 0; i < teachers.size(); i++)
    {
      cout << "Teacher #" << i+1 << ": " << endl;
      teachers.at(i).printTeacherSchedule();
      cout << endl << endl;
    }
}

//-----------------------------------------------
void Functions::examGradesReport()
{
  cout << "Would you like to produce an examGradesReport? Y (yes) or N (no)" << endl;
  char answer6;
  cin >> answer6;
  cout << "How many of the Exam grades would you like create a report for right now?" << endl;
  int numGrades;
  cin >> numGrades;
  string *arrayOfGrades = new string[numGrades];
  if (answer6 == 'Y')
  {
    ifstream inputFile("exam_grades.txt");
          if (!inputFile.is_open()) 
          {
              cerr << "Error opening file." << endl;
              //return 1;
          }

      else
          {
            string line;
            for (int i = 0; i < numGrades; i++)
              {
                 getline(inputFile, line);
                 *arrayOfGrades = line;
              }

            for (int i = 0; i < numGrades; i++)
              {
                cout << arrayOfGrades[i] << endl;
              }

            cout << "Exam grades report created!" << endl;
          }
    delete [] arrayOfGrades; // Free dynamically allocated memory
    inputFile.close();
  }
}