
//Assignment 4B Geometry Homework
//Programmer: Ashkon Honardoost
//Class: Comsc 200
//Editor used: Sublime Text 2
//Compiler used: G++ via Terminal 

#include <fstream>
using std::ifstream;

#include <iostream>
using std::ios;
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;

#include <cstring>

#include <cstdlib>

//Creates the structures and their memebrs
class Square{
private:
  const double side;
public:
  Square(const char* const token[4]):side(token[1]==0?0:atof(token[1]))
  {

  }
  void print() const;
};

class Rectangle{
private:
  const double length;
  const double width;
public:
  Rectangle(const char* const token[4]):length(token[1] == 0?0:atof(token[1])), width(token[2] == 0?0:atof(token[2]))
  {
  
  }  
  void print() const;
};

class Circle{
private:
  const double radius;
public:
  Circle(const char* const token[4]):radius(token[1] == 0?0:atof(token[1]))
  {

  }
  void print() const;
};

class Cube
{
private:
  const double side;
public:
  Cube(const char* const token[4]):side(token[1] == 0?0:atof(token[1]))
  {

  }
  void print() const;
};

class Prism
{
private:
  const double length;
  const double width;
  const double height;
public:
  Prism(const char* const token[4]):length(token[1] == 0?0:atof(token[1])),width(token[2] == 0?0:atof(token[2])), height(token[3] == 0?0:atof(token[3]))
  {
    
  }
  void print() const;
};

class Cylinder
{
private:
  const double radius;
  const double height;
public:
  Cylinder(const char* const token[4]):radius(token[1] == 0?0:atof(token[1])),height(token[2] == 0?0:atof(token[2])){
    
  }
  void print() const;
};


//const values
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159265;

///////////////
//Main Method//
///////////////

int main()
{
  //Prints out assignment info
  cout<<"Assignment 4B GeometryHomework2"<<endl;
  cout<<"Programmer: Ashkon Honardoost"<<endl;
  cout<<"Class: Comsc 200"<<endl;
  cout<<"Editor used: Sublime Text 2"<<endl;
  cout<<"Compiler used: G++ via Terminal"<<endl<<endl; 

  // create a file-reading object
  ifstream fin;
  const void *shape[100];
  int objectId[100];
  int objectIndex = 0;
  
  fin.open("geo.txt"); // open a file
  if (!fin.good()){ 
    cout<<"File is no good"<<endl;
    return 1; // exit if file not found
  }
  // read each line of the file
  while (!fin.eof())
  {
    
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);
    
    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index
    
    // array to store memory addresses of the tokens in buf
    const char * token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
    
    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }
    //Sets square side values and calculates
    if(strcmp(token[0],"SQUARE")==0){
      const Square* const s = new Square(token);
      shape[objectIndex] =s;
      objectId[objectIndex] = 1;
      
    }
    //sets length and width then does math
    else if(strcmp(token[0],"RECTANGLE") == 0){
      const Rectangle* const r = new Rectangle(token);
      shape[objectIndex] = r;
      objectId[objectIndex] = 2;
      
    }
    //sets radius adn does calculations
    else if(strcmp(token[0],"CIRCLE") == 0){
      const Circle* const c = new Circle(token);
      shape[objectIndex] = c;
      objectId[objectIndex] =3;
      
    }
    //sets sides and does calculations
    else if(strcmp(token[0],"CUBE") == 0){
      const Cube* const cb = new Cube(token);
      shape[objectIndex] = cb;
      objectId[objectIndex] = 4;
      
    }
    //Sets length/width/height and does calculations
    else if(strcmp(token[0],"PRISM")==0){
      const Prism* const p = new Prism(token);
      shape[objectIndex] = p;
      objectId[objectIndex] = 5;
    
    }
    //Sets radius and height and then does calculations
    else if(strcmp(token[0],"CYLINDER") == 0){
      const Cylinder* const cy = new Cylinder(token);
      shape[objectIndex] = cy;
      objectId[objectIndex] = 6;
      
    }
    //if not any of the objects it prints an error message
    else{
      cout<< token[0] << " INVALID OBJECT" << endl;
      objectIndex--;
    }
    objectIndex++;
    }    
  }

  fin.close(); //closes the documents
  
  //Prints out the values of the object
  for(int z=0; z<objectIndex; z++){
    if(objectId[z] == 1) ((Square*)shape[z])->print();
    else if(objectId[z] == 2) ((Rectangle*)shape[z])->print();
    else if(objectId[z] == 3) ((Circle*)shape[z])->print();
    else if(objectId[z] == 4) ((Cube*)shape[z])->print();
    else if(objectId[z] == 5) ((Prism*)shape[z])->print();
    else if(objectId[z] == 6) ((Cylinder*)shape[z])->print();
  }

  //deletes the dynamic array.
  for(int d=0; d<objectIndex; d++){
    if(objectId[d] == 1) delete ((Square*)shape[d]);
    else if(objectId[d] == 2) delete((Rectangle*)shape[d]);
    else if(objectId[d] == 3) delete((Circle*)shape[d]);
    else if(objectId[d] == 4) delete((Cube*)shape[d]);
    else if(objectId[d] == 5) delete((Prism*)shape[d]);
    else if(objectId[d] == 6) delete((Cylinder*)shape[d]);
  }

  cout<<"All objects have been deleted"<<endl;
  }
///////////////////////////////
//Functions to print out data//
///////////////////////////////
void Square::print() const{
  double s = side;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout<<setprecision(6)<<"SQUARE side="<< s;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" area = " << s*s << " Perimeter = " << s*4 <<endl;
}

void Rectangle::print() const{
  double area = length*width;
  double perim = 2*width+2*length;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<< "RECTANGLE length =" <<length<<" width = " << width;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" area = " << area << " Perimeter = " << perim << endl;
}

void Circle::print() const{
  double area = radius*PI*PI;
  double circum = 2*PI*radius;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"CIRCLE radius = " << radius;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<"area = " << area << " Circumferance = " << circum <<endl; 
}

void Cube::print() const{
  double sa = (side*side)*6;
  double v = side*side*side;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"CUBE side = " << side;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" surface area = " << sa << " volume = " << v <<endl;
}

void Prism::print() const{
  double sa = 2*length*width + 2*width*height + 2*length*height;
  double v = length*width*height;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"PRISM length = "<<length << " width = " << width << " height = " << height;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" Surface Area = " << sa << " Volume = " << v <<endl;
}

void Cylinder::print() const{
  double sa = 2*(PI)*radius*radius + 2*(PI)*radius*height ;
  double v = (PI)*radius*radius*height;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"CYLINDER radius = " << radius << " height = " << height;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" surface area = " << 2*(3.14)*radius*radius + 2*(3.14)*radius*height << " volume = " << (3.14)*radius*radius*height << endl; 
}