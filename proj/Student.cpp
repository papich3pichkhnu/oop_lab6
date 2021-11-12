#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
Student::~Student()
{
	cout << "Student \"" << this->getFullName() << "\" was destroyed"<<endl;
	this->sFaculty = nullptr;

}
Student::Student(string _lName, string _fName, string _mName) :Student(_lName, _fName, _mName, 30, 180, "Green", "Black") {}

Student::Student(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh) :
	Person(_ln,_fn,_mn,_a,_h,_coe,_coh),sFaculty(nullptr){

	cout << "Student \"" << this->getFullName() << "\" was created"<<endl;	

}
Student::Student() :Student("Last name","First name","Middle name",
18,170,"Brown","Black")
{	
	
}

void Student::setFaculty(Faculty* _sFaculty) { this->sFaculty = _sFaculty; }

void Student::printToFile()
{
	ofstream out("studfile.txt", ios::out);
	out << this->lastName<<endl;
	out << this->firstName << endl;
	out << this->middleName << endl;
	out << this->age << endl;
	out << this->height << endl;
	out << this->colorOfEyes << endl;
	out << this->colorOfHair << endl;
	out.close();
}
void Student::show()
{
	cout << "Student ";
	cout << "Last name: "; cout << this->lastName << endl;
	cout << "First name: "; cout << this->firstName << endl;
	cout << "Middle name: "; cout << this->middleName << endl;
	cout << "Age: "; cout << this->age << " years" << endl;
	cout << "Height: "; cout << this->height << " cm" << endl;
	cout << "Color of eyes: ";  cout << this->colorOfEyes << endl;
	cout << "Color of hair: "; cout << this->colorOfHair << endl;
	cout << "Faculty of the student: "<<endl; this->showFaculty();
	cout << endl;
}
void Student::showFaculty() {
	string s = "This student " + this->getFullName() + " isn't enrolled on any faculty";
	if (this->sFaculty != NULL)
	{
		this->sFaculty->show();

	}
	else throw runtime_error(s.c_str());
}
Student* Student::generate() {
	srand(time(NULL));
	Student* s = new Student();
	s->age = rand() % 20 + 18;
	string colorOfEyes[] = { "brown","green","blue" };
	s->colorOfEyes = colorOfEyes[rand() % 3];
	string colorOfHair[] = { "black","blonde","red" };
	s->colorOfHair = colorOfHair[rand() % 3];
	string firstName[] = { "John","Billy","Daniel" };
	s->firstName = firstName[rand() % 3];
	s->height = rand() % 50 + 110;
	s->firstName = "None";
	s->lastName = "None";
	s->sFaculty = NULL;
	return s;
}
Student Student::readFromFile()
{
	Student obj;
	ifstream in("studfile.txt", ios::in);
	in >> obj.lastName;
	in >> obj.firstName;
	in >> obj.middleName;
	in >> obj.age;
	in >> obj.height;
	in >> obj.colorOfEyes;
	in >> obj.colorOfHair;
	in.close();
	return obj;
}

void Student::selfDescribe()
{
	cout << "I am student " << this->getFullName() << endl;
}
