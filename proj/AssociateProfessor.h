#pragma once
#include "SeniorLecturer.h"
#include "Student.h"
class Student;
class SeniorLecturer;
class AssociateProfessor :
    public SeniorLecturer
{
public:
    AssociateProfessor();
    virtual ~AssociateProfessor();
    AssociateProfessor(string _lName, string _fName, string _mName);
    AssociateProfessor(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh);
    void mentorCourseProject(Student* s);
    void selfDescribe();
};

