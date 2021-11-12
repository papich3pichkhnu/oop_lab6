#pragma once
#include "Lecturer.h"
#include "Exam.h"
class Exam;
class Lecturer;
class SeniorLecturer :
    public Lecturer
{
public:
    SeniorLecturer();
    virtual ~SeniorLecturer();
    SeniorLecturer(string _lName, string _fName, string _mName);
    SeniorLecturer(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh);    
    void setExamSign(Exam*);
    void selfDescribe();
};

