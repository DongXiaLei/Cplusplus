#include "pch.h"
#include "Student.h"
#include <iostream>
#include <string>

Student::Student()
{
	number = 0;
	name[0] = '\0';
}
Student::~Student()
{
}
void Student::Setvalue(int s, const char * p)
{
	number = s;
	strcpy(name, p);
}
void Student::print()
{
	std::cout <<"number:"<< number << std::endl;
	std::cout << "name:"<< name<<std::endl;
}
