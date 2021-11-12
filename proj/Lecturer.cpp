#include "Lecturer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

Lecturer::Lecturer() :Lecturer("Last name", "First name", "Middle name") { }
Lecturer::~Lecturer()
{
	this->d = nullptr;	
	cout << "Lecturer \"" << this->getFullName() << "\" was destroyed" << endl;	
}
Lecturer::Lecturer(string _lName, string _fName, string _mName) :Lecturer(_lName, _fName, _mName, 30, 180, "Green", "Black") {}

Lecturer::Lecturer(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh) :
	Person(_ln, _fn, _mn, _a, _h, _coe, _coh),d(nullptr)
{
	
	cout << "Lecturer \"" << this->getFullName() << "\" was created" << endl;
	
}
void Lecturer::setDepartment(Department* d)
{
	this->d = d;
}

/*void Lecturer::teaching()
{
	srand(time(NULL));
	vector<Student*> students=this->f->getStudents();
	int cnt = this->disciplines.size();	
	int r = rand() % cnt;
	cout << "" << endl;
	cout << "Teaching discipline " << this->disciplines[r]->getName() << "...." << endl;
	for (Student* st : students)
	{
		int mark = rand() % 5 + 1;
		cout << "Student " << st->getFullName()<<" got mark " << mark << endl;
		if (mark < 3)this->f->deductStudent(st);
	}
	cout << "" << endl;
}
void Lecturer::addDiscipline(Discipline* d)
{
	this->disciplines.push_back(d);
}*/
void Lecturer::printToFile()
{
	ofstream out("lecturerfile.txt", ios::out);
	out << this->lastName << endl;
	out << this->firstName << endl;
	out << this->middleName << endl;	
	out.close();
}
void Lecturer::selfDescribe()
{
	cout << "I am lecturer " << this->getFullName()<<endl;
}
Lecturer Lecturer::readFromFile()
{
	Lecturer obj;
	ifstream in("lecturerfile.txt", ios::in);
	in >> obj.lastName;
	in >> obj.firstName;
	in >> obj.middleName;	
	return obj;
}