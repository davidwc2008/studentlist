/*
David Chen
2017
Student List Program in C++
*/

//include libraries
#include <iostream>
#include <vector>

using namespace std;

//struct declaration
struct Student
{
  char firstname [20];
  char lastname [20];
  int studentid;
  float gpa;
};

//function declaration
void add(vector<Student> *pstudents);
void print(vector<Student> *pstudents);
void remove(vector<Student> *pstudents);
  
int main()
{
  cout << "Welcome to Student List.  Type a to add students, p to print student information, and r to remove a student's information.  Press y to quit." << endl;

  char invalid = 'y';
  char input = ' ';
  vector<Student> students;
  vector<Student> *pstudents = &students;

  while (invalid == 'y'){
    cin >> input;
    if (input == 'a'){
      add(pstudents);
    }else if (input == 'p'){
      print(pstudents);
    }else if (input == 'r'){
      remove(pstudents);   
    }else if (input == 'y'){
      break;
    }else {
      cout << "Invalid input.  Would you like to try again?  Press y for yes and n for no. ";
      cin >> invalid;
    }
  }
  return 0;
}

void add(vector<Student> *pstudents)
{
  Student random;
  cout << "Enter first name: ";
  cin >> random.firstname;
  cout << "Enter last name: ";
  cin >> random.lastname;
  cout << "Enter student id: ";
  cin >> random.studentid;
  cout << "Enter GPA: ";
  cin >> random.gpa;
  pstudents->push_back(random);
  cout << "You have successfully stored information.  Press a to add students, p to print student information, and r to remove a student's information.  Press y to quit." << endl;
}

void print(vector<Student> *pstudents)
{
  for (vector<Student>::iterator it = pstudents->begin(); it != pstudents->end(); ++it){
    Student random = *it;
    cout << random.firstname << " " << random.lastname << " | ID: " << random.studentid << " | GPA: " << random.gpa << endl;
  }
  cout << "The program has finished printing.  Press a to add students, p to print student information, and r to remove a student's information.  Press y to quit." << endl;
}

void remove(vector<Student> *pstudents)
{
  char number;
  cout << "Enter the student id number for student's information to be deleted." << endl;
  cin >> number;
}






