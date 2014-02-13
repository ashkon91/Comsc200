//Lab 1A, My Grade Program
//Programmer: Ashkon Honardoost 
// Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
//includes iostream and string functions we need
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;
using std::getline;

int main(){
  int total;
  int gradeCounter;
  int grade;
  int average;
  string buf;

  //initialize the values
  total = 0;
  gradeCounter = 0;
  buf = "";

  //loop to get 10 grade values and buffers from string to int for each value
  while(gradeCounter <= 9)
  {
    cout << "Enter Grade: ";
    cin >> buf;
    grade = atoi(buf.c_str());
    cin.ignore(1000,10);
    total += grade; //adds the grade to the total value
    gradeCounter++; // increments the counter
  }
  //Calculates the average
  average = total/gradeCounter;

  //display the results
  cout << "\nThe total of the grades is: " << total << endl;
  cout << " The average of the scores is:" << average << endl;

}