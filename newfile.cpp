/*
David Chen
2017
Student List Program in C++
*/

//include libraries
#include <iostream>
#include <vector>
#include <cstring>

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
void add(vector<Student*> *pstudents);
void print(vector<Student*> *pstudents);
void remove(vector<Student*> *pstudents);

//main function
int main()
{
  cout << "Welcome to Student List.  Type ADD to add students, PRINT to print student information, and DELETE to remove a student's information.  Type QUIT to quit." << endl;

  char invalid = 'y';
  char input[20] = " ";
  vector<Student*> students;
  vector<Student*> *pstudents = &students;

  while (invalid == 'y'){
    cin >> input;
    if (!strcmp(input, "ADD")){
      add(pstudents);
    }else if (!strcmp(input, "PRINT")){
      print(pstudents);
    }else if (!strcmp(input, "DELETE")){
      remove(pstudents);   
    }else if (!strcmp(input, "QUIT")){
      break;
    }else {
      cout << "Invalid input.  Would you like to try again?  Press y for yes and n for no. ";
      cin >> invalid;
    }
  }
  return 0;
}

//add function
void add(vector<Student*> *pstudents)
{
  Student* random = new Student();
  cout << "Enter first name: " << endl;
  cin >> random->firstname;
  cout << "Enter last name: " << endl;
  cin >> random->lastname;
  cout << "Enter student id: " << endl;
  cin >> random->studentid;
  cout << "Enter GPA: " << endl;
  cin >> random->gpa;
  pstudents->push_back(random);
  cout << "You have successfully stored information.  Type ADD to add students, PRINT to print student information, and DELETE to remove a student's information.  Type QUIT to quit." << endl;
}

//print function
void print(vector<Student*> *pstudents)
{
  for (vector<Student*>::iterator it = pstudents->begin(); it != pstudents->end(); it++){
    Student* random = *it;
    cout << random->firstname << " " << random->lastname << " | ID: " << random->studentid << " | GPA: " << random->gpa << endl;
  }
  cout << "The program has finished printing.  Type ADD to add students, PRINT to print student information, and DELETE to remove a student's information.  Type QUIT to quit." << endl;
}

//remove function
void remove(vector<Student*> *pstudents)
{
  int number;
  int count = -1;
  cout << "Enter the student id number for student's information to be deleted." << endl;
  cin >> number;
  for (vector<Student*>::iterator it = pstudents->begin(); it != pstudents->end(); it++){
    Student random = **it;
      if (random.studentid == number){
	delete *it;
	count++;
        pstudents->erase(pstudents->begin() + count);
	cout << "You have successfully removed the student's information." << endl;
	break;
      } else if (random.studentid != number) {
	count++;
      }
  }
  cout << "Type ADD to add students, PRINT to print student information, and DELETE to remove a student's information.  Type QUITto quit." << endl;
}






