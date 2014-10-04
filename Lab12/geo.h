#ifndef GEO_H
#define GEO_H
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
Shape(const char* const token[]):dimension1(token[1]==0?0:atof(token[1])),dimension2(token[2]==0?0:atof(token[2])), dimension3(token[3]==0?0:atof(token[3])){}
  virtual void print(ostream&) const = 0;
  virtual ~Shape() {};
};


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

ostream& operator<<(ostream&, const Shape*);
//const values
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159265;

///////////////
//Main Method//
///////////////
#endif