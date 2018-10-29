#pragma once
class Student
{
private:
	int number;
	char name[20];
public:
	Student();
	~Student();

	void Setvalue(int n, const char *p);
	void print();
};

