//Assignment 1B Geometry Homework
//Programmer: Ashkon Honardoost
//Class: Comsc 200
//Editor used: Sublime Text 2
//Compiler used: G++ via Terminal 

#include <fstream>
using std::ifstream;

#include <iostream>
using std::ios;
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;

#include <cstring>

#include <cstdlib>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

int main()
{
  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a file
  if (!fin.good()) 
    return 1; // exit if file not found
  
  // read each line of the file
  while (!fin.eof())
  {
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);
    
    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index
    
    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
    
    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }
    //converts all tokens 1 and after to doubles
    double nums[MAX_TOKENS_PER_LINE-1];
    for(int i = 1; i < MAX_TOKENS_PER_LINE; i++){
      if(token[i] != NULL)
        nums[i-1] = atof(token[i]);
      else
        nums[i-1] = 0;
    }

    //prints the values.

    //Sets square side values and calculates
    if(strcmp(token[0],"SQUARE")==0){
      double side = nums[0];
      cout.unsetf(ios::fixed|ios::showpoint);
      cout<<setprecision(6)<<"SQUARE side="<< side;
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2)<<" area = " << side*side << " Perimeter = " << side*4 <<endl;
      
    }
    //sets length and width then does math
    else if(strcmp(token[0],"RECTANGLE") == 0){
      double length = nums[0];
      double width = nums[1];
      cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
      cout << setprecision(6)<< "RECTANGLE length =" <<length<<" width = " << width;
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2)<<" area = " << length*width << " Perimeter = " << (2*length) + (2*width) << endl;
    }
    //sets radius adn does calculations
    else if(strcmp(token[0],"CIRCLE") == 0){
      double radius = nums[0];
      cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
      cout << setprecision(6)<<" CIRCLE radius = " << radius;
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2)<<"area = " << (3.14)*(radius)*(radius) << " Circumferance = " << 2*3.14*radius <<endl; 
    }
    //sets sides and does calculations
    else if(strcmp(token[0],"CUBE") == 0){
      double side = nums[0];
      cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
      cout << setprecision(6)<<"CUBE side = " << side;
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2)<<" surface area = " << 6*(side*side) << " volume = " << side*side*side <<endl;
    }
    //Sets length/width/height and does calculations
    else if(strcmp(token[0],"PRISM")==0){
      double length = nums[0];
      double width = nums[1];
      double height = nums[2];
      cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
      cout << setprecision(6)<<"PRISM length = "<<length << " width = " << width << " height = " << height;
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2)<<" Surface Area = " << 2*length*width + 2*width*height + 2*length*height << " Volume = " << length*width*height <<endl;
    }
    //Sets radius and height and then does calculations
    else if(strcmp(token[0],"CYLINDER") == 0){
      double radius = nums[0];
      double height = nums[1];
      cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
      cout << setprecision(6)<<"CYLINDER radius = " << radius << " height = " << height;
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2)<<" surface area = " << 2*(3.14)*radius*radius + 2*(3.14)*radius*height << " volume = " << (3.14)*radius*radius*height << endl; 
    }
    //if not any of the objects it prints an error message
    else 
      cout<< token[0] << " INVALID OBJECT" << endl;
    }
  }
}
