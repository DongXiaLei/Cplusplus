// C++程序设计3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//适用对象指针做函数参数是指针操控内存，引用是别名直接操控内存（实质还是直接操控内存）
#include "pch.h"
#include <iostream>
using namespace std;

class Student
{
private:
	double score;
	const char * name;
public:
	Student();
	Student( const char *name,double score);//构造函数
	Student(const Student& stu);//拷贝构造函数 是不改变源的值，生成一个新的
	~Student();//析构函数

	friend Student* Compare(Student &stu1, Student &stu2,int flag);//友元函数 若flag等于1 返回高成绩 否则相反
	void display();
};
Student::Student(){}
Student::Student( const char* p,double s)
{
	name = p;
	score = s;
}
Student::Student(const Student &stu)
{
	name = stu.name;
	score = stu.score;
}
Student::~Student() {}
Student* Compare(Student &stu1, Student &stu2,int flag)//若flag等于1 返回高成绩 否则相反
{
	Student *p1, *p2;
	p1 = &stu1; p2 = &stu2;

	if (flag == 1)
	{
		if (p1->score >= p2->score)//用stu1.name>=stu2.score也是可以的
			return p1;
		else return p2;
	}
	else
	{
		if (p1->score >= p2->score)//用stu1.name>=stu2.score也是可以的
			return p2;
		else return p1;
	}
}
void Student::display()
{
	cout << name << " " << score<<endl;
}

int main()
{
	Student *max_stu, *min_stu,*temp;//Student * p = new Student();
	Student tem;
	Student stu[5] = { Student("zhang",78),Student("wang",80) ,Student("zhao",92), Student("li",65),Student("chen",50) };
	tem = stu[0];//使用复制构造函数
	for (int i = 0; i < 4; i++)
	{
		temp = Compare(tem, stu[i + 1], 1);
		tem = *temp;
	}
	max_stu = temp;
	cout << "最高分：";
	max_stu->display();

	for (int i = 0; i < 4; i++)
	{
		temp = Compare(tem, stu[i + 1], 0);
		tem = *temp;
	}
	min_stu = temp;
	cout << "最低分：";
	min_stu->display();

	system("pause");
	return 0;
}

