// C++课堂作业2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	int getAge();
	float getGrade();
	string getName();

	void setName();
	void setGrade();
	void setAge();

	float CheckAgeScore();
private:
	string name;
	int age;
	float grade;

};
void Student::setName()
{
	string name;
	cout << "请输入该同学名字：" << endl;
	cin >> name;
	this->name = name;
}
void Student::setAge()
{
	int age;
	cout << "请输入该同学年龄：" << endl;
	cin >> age;
	this->age = age;
}
void Student::setGrade()
{
	float grade;
	cout << "请输入该同学成绩：" << endl;
	cin >> grade;
	this->grade = grade;
}
string Student::getName()
{
	return name;
}
int Student::getAge()
{
	return age;
}
float Student::getGrade()
{
	return grade;
}
float Student::CheckAgeScore()
{
	if (age < 15 || age>25)
	{
		throw "错误！：年龄不在15~25之间";
	}
	if (!(grade >= 0 && grade <= 5))
	{
		throw "错误！：成绩不在0~5之间";
	}
	else return grade;
}
int main()
{
	float grade;
	int age;
	string name;
	Student stu;

	stu.setAge();
	stu.setGrade();
	stu.setName();
	try
	{
		grade = stu.CheckAgeScore();
		age = stu.getAge();
		name = stu.getName();
		cout << "Name:" << name <<endl<< "Age:" << age << endl << "Grade:" << grade * 20;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
