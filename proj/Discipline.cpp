#include "Discipline.h"
#include <iostream>
#include <fstream>
#include <string>

Discipline::Discipline(string _n, Department* _d, string _t, int _cr, int _nh, int _ncw) :
	name(_n), department(_d), typeOfControl(_t), credits(_cr), numberOfHours(_nh), numberOfControlWorks(_ncw)
{
	cout << "Discipline \"" << _n << "\" was created" << endl;
}
Discipline::Discipline() : Discipline("Discipline",new Department("Department"),"Exam",60,20,5)
{
	
}
Discipline::~Discipline()
{
	cout << "Discipline \"" << this->name << "\" was destroyed" << endl;
}
Discipline::Discipline(const Discipline& _d) : Discipline(_d.name,_d.department,_d.typeOfControl,_d.credits,
	_d.numberOfHours, _d.numberOfControlWorks)
{
	
}
string Discipline::getName() {
	return this->name;
}
Department* Discipline::getDepartment() {
	return this->department;
}
string Discipline::getTypeOfControl() {
	return this->typeOfControl;
}
int Discipline::getCredits() {
	return this->credits;
}
int Discipline::getNumberOfControlWorks() {
	return this->numberOfControlWorks;
}
int Discipline::getNumberOfHours() {
	return this->numberOfHours;
}
void Discipline::printToFile()
{
	ofstream out("discfile.txt", ios::out);
	out << this->name << endl;
	out << this->department->name << endl;
	out << this->credits << endl;
	out << this->numberOfControlWorks << endl;
	out << this->numberOfHours << endl;
	out << this->typeOfControl << endl;
	out.close();
}
Discipline Discipline::readFromFile()
{
	Discipline obj;
	ifstream in("discfile.txt", ios::in);
	in >> obj.name;
	in >> obj.department->name;
	in >> obj.credits;
	in >> obj.numberOfControlWorks;
	in >> obj.numberOfHours;
	in >> obj.typeOfControl;
	in.close();
	return obj;
}