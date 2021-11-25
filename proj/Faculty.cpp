#include "Faculty.h"
#include <iostream>
#include <fstream>
#include <string>
int Faculty::count = 0;
Faculty::Faculty() :Faculty("Faculty"+std::to_string(this->count+1),"F","Decane",
	2021,10,5,"3802123456","faculty@khnu.km.ua"){
	
	cout << "Faculty \"" << this->facultyName << "\" was created" <<endl;
}
Faculty::~Faculty()
{	
	this->students.clear();
	
	cout << "Faculty \"" << this->facultyName << "\" was destroyed"<<endl;
}
Faculty::Faculty(string _fName, string _a, string _d, int _yc, int _nc, int _ns, string _tn, string _e) :
	facultyName(_fName), abbreviature(_a), decane(_d), yearOfCreating(_yc),
	numOfSpecs(_ns), telephoneNumber(_tn), email(_e)
{
	
	cout << "Faculty \"" << this->facultyName << "\" was created"<<endl;
}
void Faculty::setFaculty(string _facultyName) { this->facultyName = _facultyName; }
void Faculty::setFaculty(string _facultyName, string _abbreviature) { this->facultyName = _facultyName; this->abbreviature = _abbreviature; }
void Faculty::setNumericData(int _numOfSpecs) { this->numOfSpecs = _numOfSpecs; }
void Faculty::setInfo(string _decane, int _yearOfCreating, string _telephoneNumber, string _email) {
	this->decane = _decane; this->yearOfCreating = _yearOfCreating; this->telephoneNumber = _telephoneNumber;
	this->email = _email;
}
int Faculty::getNumOfDepartments() {
	return this->departments.size();
}
void Faculty::modifyData(Faculty* faculty) { faculty->abbreviature += "_New"; }
Faculty Faculty::returnWithModifiedData() { this->abbreviature += "New"; return *this; }
void Faculty::printToFile() {
	ofstream out("facfile.txt", ios::out);
	out << this->abbreviature << endl;
	out << this->decane << endl;
	out << this->email << endl;
	out << this->facultyName << endl;
	out << this->numOfSpecs << endl;
	out << this->telephoneNumber << endl;
	out << this->yearOfCreating << endl;
	out.close();
}
void Faculty::show() {
	
	cout << "Abbreviature: "; cout << this->abbreviature << endl;
	cout << "Decane: ";cout << this->decane << endl;
	cout << "Email: ";cout << this->email << endl;
	cout << "Faculty name: ";cout << this->facultyName << endl;
	cout << "Num of majors: ";cout << this->numOfSpecs << endl;
	cout << "Telephone number: ";cout << this->telephoneNumber << endl;
	cout << "Year of creating: ";cout << this->yearOfCreating << endl;
	cout << endl;
}
Faculty Faculty::readFromFile() {
	Faculty obj;
	ifstream in("facfile.txt", ios::in);
	in >> obj.abbreviature;
	in >> obj.decane;
	in >> obj.email;
	in >> obj.facultyName;
	in >> obj.numOfSpecs;
	in >> obj.telephoneNumber;
	in >> obj.yearOfCreating;
	in.close();
	return obj;
}
int* Faculty::myAlloc()
{
	int r = rand() % 4 + 2;
	int* arr{ new int[r] {0} };
	return arr;
}
void Faculty::enrollStudent(Student* s)
{		
	if (s->getFaculty() != nullptr)
	{
		cout << "Student " << s->getFullName() << " is already enroled on the faculty " << s->getFaculty()->abbreviature << endl;
		return;
	}
	this->students.push_back(s);
	s->setFaculty(this);
	cout << "Student " << s->getFullName()<< " was enroled on the faculty " << this->abbreviature<<endl;

}
void Faculty::deductStudent(Student* s)
{
	bool f = false;
	for (auto it=this->students.begin();it!=this->students.end();it++)
	{
		if (s->getFullName() == (*it)->getFullName())
		{
			this->students.erase(it);
			cout << "Student " << s->getFullName()<<" was deducted from the faculty " << this->abbreviature << endl;
			f = true;
			s->setFaculty(NULL);
			break;
		}
	}
	if (!f)
	{
		cout << "Student " << s->getFullName() << " isn't studiyng on this faculty " << this->abbreviature << endl;
	}
}

void Faculty::addDepartment(Department* s)
{
	if (s->getFaculty() != nullptr)
	{
		cout << "Department " << s->name << " is already in list of the faculty " << s->getFaculty()->abbreviature << endl;
		return;
	}
	this->departments.push_back(s);
	s->setFaculty(this);
	cout << "Department " << s->name << " was added in list of departments of the faculty " << this->abbreviature << endl;
}

void Faculty::deleteDepartment(Department* s)
{
	bool f = false;
	for (auto it = this->departments.begin(); it != this->departments.end(); it++)
	{
		if (s->name == (*it)->name)
		{
			this->departments.erase(it);
			cout << "Department " << s->name << " was deleted from the faculty " << this->abbreviature << endl;
			f = true;
			s->setFaculty(NULL);
			break;
		}
	}
	if (!f)
	{
		cout << "Department " << s->name << " isn't in list of departments on this faculty " << this->abbreviature << endl;
	}
}

Student* findStudent(string _ln, string _fn, string _mn)
{
	return nullptr;
}
vector<Student*> Faculty::getStudents() { return (this->students); }
Faculty& Faculty::operator++()
{
	++numOfSpecs;
	return *this;
}
Faculty Faculty::operator++(int)
{
	Faculty* temp = this;
	++(*(this));
	return *temp;
	
}
Faculty& Faculty::operator--()
{
	--numOfSpecs;
	return *this;
	
}
Faculty Faculty::operator--(int)
{
	Faculty* temp = this;
	--(*(this));
	return *temp;
}

Faculty Faculty::operator+(Student *s)
{
	Faculty* fac=this;	
	fac->enrollStudent(s);
	return *fac;
}

Faculty Faculty::operator-(Student* s)
{
	Faculty* fac =this;
	fac->deductStudent(s);
	return *fac;
}

Faculty Faculty::operator+(Department* d)
{
	Faculty* fac = this;
	fac->addDepartment(d);
	return *fac;
}

Faculty Faculty::operator-(Department* d)
{
	Faculty* fac = this;
	fac->deleteDepartment(d);
	return *fac;
}

Faculty Faculty::operator*(int a)
{
	Faculty fac = *this;
	fac.numOfSpecs *= a;
	return fac;
}

Faculty& Faculty::operator+=(Student* s)
{
	*(this) = *(this) + s;
	return *(this);
}

Faculty& Faculty::operator-=(Student* s)
{
	*(this) = *(this) - s;
	return *(this);
}

Faculty& Faculty::operator+=(Department* s)
{
	*(this) = *(this) + s;
	return *(this);
}

Faculty& Faculty::operator-=(Department* s)
{
	*(this) = *(this) - s;
	return *(this);
}


Faculty& Faculty::operator*=(int s)
{
	*(this) = *(this) * s;
	return *(this);
}

Department* Faculty::operator[](int index)
{
	if (index >= this->departments.size())
	{
		throw runtime_error("Array index out of bound, exiting ");
	}
	else return this->departments[index];
}


