
//Assignment 12 Geometry Homework6
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
using std::ostream;

#include <iomanip>
using std::setprecision;

#include <cstring>

#include <cstdlib>

#include <vector>
using std::vector;
//Creates the classes and their memebrs
class Shape{
protected:
  double const dimension1;
  double const dimension2;
  double const dimension3;
public:
  Shape(const char* const[]);
  virtual void print(ostream&) const = 0;
  virtual ~Shape() {};
};

Shape::Shape(const char* const token[])
:dimension1(token[1]==0?0:atof(token[1])),dimension2(token[2]==0?0:atof(token[2])), dimension3(token[3]==0?0:atof(token[3])){}

struct Square:public Shape{
  Square(const char* const token[]):Shape(token){}
  void print(ostream&) const;
};

struct Rectangle:public Shape{
  Rectangle(const char* const token[]):Shape(token){}
  void print(ostream&) const;
};

struct Circle:public Shape{
  Circle(const char* const token[]):Shape(token){}
  void print(ostream&) const;
};

struct Cube:public Square
{
  Cube(const char* const token[]):Square(token){}
  void print(ostream&) const;
};

struct Prism:public Rectangle
{
    Prism(const char* const token[]):Rectangle(token){}
  void print(ostream&) const;
};

struct Cylinder:public Circle
{
  Cylinder(const char* const token[]):Circle(token){}
  void print(ostream&) const;
};
ostream& reset(ostream& );
ostream& set(ostream& );

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
  cout<<"Assignment 12 GeometryHomework6"<<endl;
  cout<<"Programmer: Ashkon Honardoost"<<endl;
  cout<<"Class: Comsc 200"<<endl;
  cout<<"Editor used: Sublime Text 2"<<endl;
  cout<<"Compiler used: G++ via Terminal"<<endl<<endl; 

  double Dim[MAX_TOKENS_PER_LINE] = {};
  vector <Shape*> shapes;
  // create a file-reading object
  ifstream fin;

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
      shapes.push_back(new Square(token));
      
    }
    //sets length and width then does math
    else if(strcmp(token[0],"RECTANGLE") == 0){
      shapes.push_back(new Rectangle(token));

      
    }
    //sets radius adn does calculations
    else if(strcmp(token[0],"CIRCLE") == 0){
      shapes.push_back(new Circle(token));

      
    }
    //sets sides and does calculations
    else if(strcmp(token[0],"CUBE") == 0){
      shapes.push_back(new Cube(token));
    }
    //Sets length/width/height and does calculations
    else if(strcmp(token[0],"PRISM")==0){
      shapes.push_back(new Prism(token));
    }
    //Sets radius and height and then does calculations
    else if(strcmp(token[0],"CYLINDER") == 0){
      shapes.push_back(new Cylinder(token));

      
    }
    //if not any of the objects it prints an error message
    else{
      cout<< token[0] << " INVALID OBJECT" << endl;
    }
    }    
  }

  fin.close(); //closes the documents
  
  //Prints out the values of the object
  for(vector <Shape*>::const_iterator i = shapes.begin(); i != shapes.end(); i++){
    (*i)->print(cout);
  }
  //deletes the dynamic array.
  for(vector<Shape*>::const_iterator i = shapes.begin(); i != shapes.end(); i++){
    delete *i;
  }

  cout<<"All objects have been deleted"<<endl;
  }
///////////////////////////////
//Functions to print out data//
///////////////////////////////
void Square::print(ostream& out) const{
  double Area = dimension1*dimension1;
  double Perim = dimension1*4;
  cout<<reset;
  out<<"SQUARE side="<< dimension1;
  cout<<set;
  out <<" area = " << Area << " Perimeter = " << Perim <<endl;
}

void Rectangle::print(ostream& out) const{
  double area = dimension1*dimension2;
  double perim = 2*dimension1+2*dimension2;
  out<<reset;
  out << "RECTANGLE length =" <<dimension1<<" width = " << dimension2;
  cout<<set;
  out <<" area = " << area << " Perimeter = " << perim << endl;
}

void Circle::print(ostream& out) const{
  double area = dimension1*PI*PI;
  double circum = 2*PI*dimension1;
  out<<reset;
  out<<"CIRCLE radius = " << dimension1;
  cout<<set;
  out <<"area = " << area << " Circumferance = " << circum <<endl; 
}

void Cube::print(ostream& out) const{
  double sa = (dimension1*dimension1)*6;
  double v = dimension1*dimension1*dimension1;
  cout<<reset;
  out <<"CUBE side = " << dimension1;
  cout<<set;
  out <<" surface area = " << sa << " volume = " << v <<endl;
}

void Prism::print(ostream& out) const{
  double sa = 2*dimension1*dimension2 + 2*dimension2*dimension3 + 2*dimension1*dimension3;
  double v = dimension1*dimension2*dimension3;
  cout<<reset;
  out <<"PRISM length = "<<dimension1 << " width = " << dimension2 << " height = " << dimension3;
  cout<<set;
  out <<" Surface Area = " << sa << " Volume = " << v <<endl;
}

void Cylinder::print(ostream& out) const{
  double sa = 2*(PI)*dimension1*dimension1 + 2*(PI)*dimension1*dimension2 ;
  double v = (PI)*dimension1*dimension1*dimension2;
  cout<<reset;
  out <<"CYLINDER radius = " << dimension1 << " height = " << dimension2;
  cout<<set;
  out <<" surface area = " << 2*(3.14)*dimension1*dimension1 + 2*(3.14)*dimension1*dimension2 << " volume = " << (3.14)*dimension1*dimension1*dimension2 << endl; 
}
ostream& reset(ostream& out) // requires iostream, using ostream
{
  out.unsetf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(6); // requires iostream and iomanip, using setprecision
  return out;
}

ostream& set(ostream& out) // requires iostream, using ostream
{
  out.setf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(2); // requires iostream and iomanip, using setprecision
  return out;
}