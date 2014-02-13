//Assignment 2B Geometry Homework
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
struct Square{
  double side;
};

struct Rectangle{
  double length;
  double width;
};

struct Circle{
  double radius;
};

struct Cube
{
  double side;
};

struct Prism
{
  double length;
  double width;
  double height;
};

struct Cylinder
{
  double radius;
  double height;
};

//function prototype
void printSquare(Square* square);
void printRectangle(Rectangle* rectangle);
void printCircle(Circle* circle);
void printCube(Cube* cube);
void printPrism(Prism* prism);
void printCylinder(Cylinder* cylinder);

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
  cout<<"Assignment 2B GeometryHomework2"<<endl;
  cout<<"Programmer: Ashkon Honardoost"<<endl;
  cout<<"Class: Comsc 200"<<endl;
  cout<<"Editor used: Sublime Text 2"<<endl;
  cout<<"Compiler used: G++ via Terminal"<<endl<<endl; 

  // create a file-reading object
  ifstream fin;
  void *shape[100];
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
    for(int a = 0;a<n; a++){
    //Sets square side values and calculates
    if(strcmp(token[0],"SQUARE")==0){
      Square* s = new Square;
      s->side = nums[0];
      shape[objectIndex] =s;
      objectId[objectIndex] = 1;
      break;
    }
    //sets length and width then does math
    else if(strcmp(token[0],"RECTANGLE") == 0){
      Rectangle* r = new Rectangle;
      r->length = nums[0];
      r->width = nums[0];
      shape[objectIndex] = r;
      objectId[objectIndex] = 2;
      break;
    }
    //sets radius adn does calculations
    else if(strcmp(token[0],"CIRCLE") == 0){
      Circle* c = new Circle;
      c->radius = nums[0];
      shape[objectIndex] = c;
      objectId[objectIndex] =3;
      break;
    }
    //sets sides and does calculations
    else if(strcmp(token[0],"CUBE") == 0){
      Cube* cb = new Cube;
      cb->side = nums[0];
      shape[objectIndex] = cb;
      objectId[objectIndex] = 4;
      break;
    }
    //Sets length/width/height and does calculations
    else if(strcmp(token[0],"PRISM")==0){
      Prism* p = new Prism;
      p->length = nums[0];
      p->width = nums[1];
      p->height = nums[2];
      shape[objectIndex] = p;
      objectId[objectIndex] = 5;
      break;
    }
    //Sets radius and height and then does calculations
    else if(strcmp(token[0],"CYLINDER") == 0){
      Cylinder* cy = new Cylinder;
      cy->radius = nums[0];
      cy->height = nums[1];
      shape[objectIndex] = cy;
      objectId[objectIndex] = 6;
      break;
    }
    //if not any of the objects it prints an error message
    else{ 
      cout<< token[0] << " INVALID OBJECT" << endl;
      objectIndex--;
      break;
    }
  }
  }
    objectIndex++;
}
  fin.close(); //closes the documents

  //Prints out the values of the object
  for(int z=0; z<objectIndex; z++){
    if(objectId[z] == 1) printSquare((Square*)shape[z]);
    else if(objectId[z] == 2) printRectangle((Rectangle*)shape[z]);
    else if(objectId[z] == 3) printCircle((Circle*)shape[z]);
    else if(objectId[z] == 4) printCube((Cube*)shape[z]);
    else if(objectId[z] == 5) printPrism((Prism*)shape[z]);
    else if(objectId[z] == 6) printCylinder((Cylinder*)shape[z]);
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
void printSquare(Square* s){
  double side = s->side;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout<<setprecision(6)<<"SQUARE side="<< side;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" area = " << side*side << " Perimeter = " << side*4 <<endl;
}

void printRectangle(Rectangle* r){
  double length = r->length;
  double width = r->width;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<< "RECTANGLE length =" <<length<<" width = " << width;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" area = " << length*width << " Perimeter = " << (2*length) + (2*width) << endl;
}

void printCircle(Circle* c){
  double radius = c->radius;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"CIRCLE radius = " << radius;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<"area = " << (PI)*(radius)*(radius) << " Circumferance = " << 2*PI*radius <<endl; 
}

void printCube(Cube* cb){
  double side = cb->side;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"CUBE side = " << side;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" surface area = " << 6*(side*side) << " volume = " << side*side*side <<endl;
}

void printPrism(Prism* p){
  double length = p->length;
  double width = p->width;
  double height = p->height;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"PRISM length = "<<length << " width = " << width << " height = " << height;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" Surface Area = " << 2*length*width + 2*width*height + 2*length*height << " Volume = " << length*width*height <<endl;
}

void printCylinder(Cylinder* cy){
  double radius = cy->radius;
  double height = cy->height;
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6)<<"CYLINDER radius = " << radius << " height = " << height;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2)<<" surface area = " << 2*(3.14)*radius*radius + 2*(3.14)*radius*height << " volume = " << (3.14)*radius*radius*height << endl; 
}