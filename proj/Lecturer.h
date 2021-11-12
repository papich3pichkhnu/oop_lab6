#pragma once
#include "Discipline.h"
#include "Department.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Department;
class Discipline;
class Student;
class Person;
class Lecturer : virtual public Person
{
protected:		
	Department* d;
public:	
	void setDepartment(Department* d);
	Lecturer();
	virtual ~Lecturer();
	Lecturer(string _lName, string _fName, string _mName);		
	Lecturer(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh);
	static Lecturer readFromFile();
	void printToFile();
	void selfDescribe();
};

