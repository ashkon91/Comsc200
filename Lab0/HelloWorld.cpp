//Lab 0b, The "Hello, World" Program
//Programmer: Ashkon Honardoost 
// Class: Comsc200
//Editor used: TextWrangler
//Compiler used: G++

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  //This will print my name and the assignment's title.
  cout << "Lab 0b, The \"Hello, World\" Program \n";
  cout << "Programmer: Ashkon Honardoost\n";
  cout << "Editor used: TextWrangler \n";
  cout << "Compiler used: G++ \n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}