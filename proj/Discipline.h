#pragma once
#include "Department.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Department;
class Discipline
{
private:	
	int credits;
	int numberOfHours;
	int numberOfControlWorks;
public:
	string name;
	Department* department;
	string typeOfControl;
	Discipline(string _n, Department* _d, string _t, int _cr, int _nh, int _ncw);
	Discipline();
	~Discipline();
	Discipline(const Discipline &_d);
	string getName();
	Department* getDepartment();
	string getTypeOfControl();	
	int getCredits();
	int getNumberOfHours();
	int getNumberOfControlWorks();
	void printToFile();
	static Discipline readFromFile();
	
};

