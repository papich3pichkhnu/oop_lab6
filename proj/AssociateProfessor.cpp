#include "AssociateProfessor.h"
#include<string>
#include<iostream>
using namespace std;
AssociateProfessor::AssociateProfessor() :AssociateProfessor("Last name", "First name", "Middle name") {}
AssociateProfessor::~AssociateProfessor()
{
	this->d = nullptr;
	cout << "Associate professor \"" << this->getFullName() << "\" was destroyed" << endl;
}
AssociateProfessor::AssociateProfessor(string _lName, string _fName, string _mName) : AssociateProfessor(_lName, _fName, _mName, 30, 180, "Green", "Black") {}

AssociateProfessor::AssociateProfessor(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh) :
	Person(_ln, _fn, _mn, _a, _h, _coe, _coh), SeniorLecturer(_ln, _fn, _mn, _a, _h, _coe, _coh) {
	
	cout << "Associate professor \"" << this->getFullName() << "\" was created" << endl;
}
void AssociateProfessor::mentorCourseProject(Student* s)
{
	cout << "Associate professor "<<this->getFullName()<<" is mentoring course project of student "<<s->getFullName()<<endl;

}
void AssociateProfessor::selfDescribe()
{
	cout << "I am associate professor " << this->getFullName() << endl;
}