//Lab 0b, Console Programming Basics
//Programmer: Ashkon Honardoost
//Class: Comsc 200
//Editor used: TextWrangler
//Compiler used: ideone.com

#include <iostream>
using std::ios;
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::getline;
using std::string;

#include <iomanip>
using std::setprecision;

#include <cstdlib>

int main()
{
  //Declares the variables needed for the program
  int age = 0;
  double tempF = 0;
  double tempC = 0;
  string buf = "";
  string city = "";
  
  //Prompts the use for their age
  string name = "";
  cout << "Enter your age: ";
  cin >> buf;
  age = atoi(buf.c_str());
  cin.ignore(1000, 10);
  
  //Prompts user for their name
  cout << "\nEnter your name: ";
  getline(cin, name);
  
  //Prompts the user for the temperature outside and calculates C tempt
  cout << "\nEnter the temperature outside right now(Degrees F): ";
  cin>> buf;
  tempF = atof(buf.c_str());
  cin.ignore(1000, 10);
  tempC = (double)(tempF-32) * 5 / 9;
  
  //Prompts the user for their location
  cout << "\nWhat city are you in right now? ";
  getline(cin, city); 
   
  //Prints out the information about the user
  cout << "\n"<<name<< " is " << age << " years old now, and will be " << age+1 << "a year from now." <<endl;
  
  //Prints the information about the weather 
  
  cout <<"It is " << tempF << " in " << city << " -- that's ";
  cout.setf(ios::fixed|ios::showpoint);
  cout <<setprecision(1)<<tempC << " degrees C" << endl;
  
}
  