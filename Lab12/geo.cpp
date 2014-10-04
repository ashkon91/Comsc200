#include "geo.h"
#include "geo.h"

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
ostream& operator<<(ostream& out, const Shape* s)
{
  s->print(out);
  return out;
}