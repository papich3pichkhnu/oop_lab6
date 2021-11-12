#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
using namespace std;
Person::Person() : Person("Last name", "First name", "Middle name") {
	
}
Person::~Person()
{
	cout << "Person \"" << this->getFullName() << "\" was destroyed" << endl;
}
Person::Person(string _lName, string _fName, string _mName) : Person(_lName, _fName,_mName,18,170,"Brown","Black")
{
	
}
Person::Person(string _ln, string _fn, string _mn, int _a, int _h, string _coe, string _coh)
{
	setName(_ln, _fn, _mn);
	setData(_a, _h); setEyesHair(_coe, _coh);
	cout << "Person \"" << this->getFullName() << "\" was created" << endl;

}
string Person::getFullName() {
	return this->lastName + " " + this->firstName + " " + this->middleName;
}
void Person::setName(string _name) { this->firstName = _name; }
void Person::setName(string _lName, string _fName, string _mName) { this->lastName = _lName; this->firstName = _fName; this->middleName = _mName; }
void Person::setData(int _age) { this->age = _age; }
void Person::setData(int _age, int _height) { this->age = _age; this->height = _height; }
void Person::setEyesHair(string _colorOfEyes, string _colorOfHair) { this->colorOfEyes = _colorOfEyes; this->colorOfHair = _colorOfHair; }
int Person::getAge() { return this->age;}
int Person::getHeight() { return this->height;}
string Person::getColorOfEyes() { return this->colorOfEyes; }
string Person::getColorOfHair() { return this->colorOfHair; }
