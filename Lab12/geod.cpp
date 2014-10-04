#include "geo.h"
#include "geo.h"
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