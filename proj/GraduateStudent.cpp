#include "GraduateStudent.h"
GraduateStudent::GraduateStudent():Student(),Lecturer(){
	
}
GraduateStudent::~GraduateStudent()
{
	cout << "GraduateStudent \"" << this->getFullName() << "\" was destroyed" << endl;
}
void GraduateStudent::selfDescribe()
{
	cout << "I am graduate student " << this->getFullName() << endl;
}
GraduateStudent::GraduateStudent(string _lName, string _fName, string _mName) :GraduateStudent(_lName, _fName, _mName, 30, 180, "Green", "Black") {}

GraduateStudent::GraduateStudent(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh) :
	Lecturer(_ln,_fn,_mn,_a,_h,_coe,_coh)
{
	setFaculty(nullptr);
	cout << "Graduate student \"" << this->getFullName() << "\" was created" << endl;

}
