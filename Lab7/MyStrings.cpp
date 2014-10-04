//Lab 7b: MYSTrings.cpp
//Programmer : Ashkon Honardoost
//Comsc 200
//Editor : Sublime Text 2
//Compiler : G++
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;


int main()
{
	//prints info
	cout << "Lab 6a: MyStrings.cpp\n" << "Ashkon Honardoost\n" << "Comsc 200 \n" << "Editor:Sublime Text 2\n" << "Compiler:G++\n\n";

	string string1("noon is 12pm; midnight is not.");
	int location;

	//finding "is" at location 5 and 24
	cout << "Original string: \n" << string1 << "\n\n(find) \"is\" was found at: "<<string1.find("is");
	cout << "\n(rfind) \"is\" was found at: " << string1.rfind("is");

	//find 'o' at locatipn 1
	location = string1.find_first_of("misop");
	cout << "\n\n(find_first_of) found" << string1[location] << "'from the group \"misop\" at "<< location;

	//finds 'o' at location 29
	location = string1.find_last_of("misop");
	cout << "\n\n(find_last_of) found " << string1[location] << "'from the group \"misop\" at : " << location;

	//find '1' at location 8
	location = string1.find_first_not_of( "noi spm");
	cout << "\n\n(find_first_not_of) '" << string1[ location] << "' is not contained in \"noi spm\" and was found at : " << location;

	//find '.' at location 12
	location = string1.find_first_not_of("12 noi spm");
	cout << "\n\n(find_first_not_of)'" << string1[location] << "' is not contained in \"noi spm\" and was " << "found at: " << location << endl;

	//search for characters not in string1
	location = string1.find_first_not_of("noon is 12pm: midnight is not.");
	cout << "\nfind_first_not_of(\"noon is 12pm; midnight is not.\")" << " returned: " << location << endl;

	//search for noon
	cout << "Original string: \n" << string1 << "\n\n(find) \"noon\" was found at: "<<string1.find("noon");
	cout << "\n(rfind) \"noon\" was found at: " << string1.rfind("noon")<<endl;
}
