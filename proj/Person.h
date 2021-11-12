#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Person
{
protected:
	int age;
	int height;
	string colorOfEyes;
	string colorOfHair;
public:
	Person(string, string, string);
	Person();
	Person(string, string, string , int, int , string , string);
	virtual ~Person();
	string lastName;
	string firstName;
	string middleName;
	void setName(string _lName);
	void setName(string _lName, string _fName, string _mName);
	string getFullName();
	void setData(int _age);
	void setData(int _age, int _height);
	void setEyesHair(string _colorOfEyes, string _colorOfHair);
	int getAge();
	int getHeight();
	string getColorOfEyes();
	string getColorOfHair();
	virtual void selfDescribe()=0;
};

