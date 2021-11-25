#pragma once
#include "Lecturer.h"
#include "Discipline.h"
#include "Faculty.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Lecturer;
class Faculty;
class Discipline;
class Department
{
private:
	Faculty* f;
public:
	static int count;
	string name;
	vector<Lecturer*> lecturers;
	Lecturer* headOfDepartment;	
	Department(string _n);
	~Department();
	Department();
	void enrollLecturer(Lecturer* l);
	void deductLecturer(Lecturer* l);
	void setHeadOfDepartment(Lecturer* l);
	void setFaculty(Faculty* f);
	Faculty* getFaculty();
	void show();
	friend ostream& operator<<(std::ostream& out, Department& d);
};

