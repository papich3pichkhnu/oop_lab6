#include "SeniorLecturer.h"
#include "Exam.h"
#include<iostream>
#include <string>
using namespace std;
class Exam;
class Lecturer;
SeniorLecturer::SeniorLecturer() :SeniorLecturer("Last name", "First name", "Middle name") { }
SeniorLecturer::~SeniorLecturer()
{
	this->d = nullptr; 
	cout << "Senior lecturer \"" << this->getFullName() << "\" was destroyed" << endl;
}
SeniorLecturer::SeniorLecturer(string _lName, string _fName, string _mName) : SeniorLecturer(_lName, _fName, _mName, 30, 180, "Green", "Black") { }

SeniorLecturer::SeniorLecturer(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh) :
	Person(_ln, _fn, _mn, _a, _h, _coe, _coh), 
	Lecturer(_ln, _fn, _mn, _a, _h, _coe, _coh)
{
	
	cout << "Senior lecturer \"" << this->getFullName() << "\" was created" << endl;
}
void SeniorLecturer::setExamSign(Exam* e)
{
	
	cout << "Exam on " << e->discipline->getName() << " is signed by " << this->getFullName()<<endl;
}
void SeniorLecturer::selfDescribe()
{
	cout << "I am senior lecturer " << this->getFullName() << endl;
}