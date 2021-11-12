#pragma once
#include "Lecturer.h"
#include "Student.h"
class GraduateStudent :
    public Student, public Lecturer
{
public:
	GraduateStudent();
	~GraduateStudent();
	GraduateStudent(string _lName, string _fName, string _mName);
	GraduateStudent(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh);
	void selfDescribe();
};

