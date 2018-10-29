#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

/*
char  *p ="name";  == const char * p="name"
两p内容不可修改的，即*p 不可以修改 但是 p可以再被赋值，只可以赋值常量
调用时间参数必须为const char* ，赋值对象也必须为const char* p
p = const char * 类型是合法的
p = char * 不合法 
char * name = "name";字符串均为常量
name = "string";合法，常量之间赋值

char p[] = "name"； == char *p=“name”; p是变量 内容和指向内容的值都可以改变
char *name；
name = new char(n);
strcpy(name,p);

*/

/*

class Stu
{
private:
	int score;
	char * name;
public:
	Stu();
	Stu( char *p, int s = 11);
	~Stu();
	Stu(const Stu &st);

	void dispaly();
};

Stu::Stu(){}
Stu::Stu(char * p,int s)
{
	score = s;
	name = new char[strlen(p) + 1];
	strcpy(name, p);

}
Stu::~Stu(){}
Stu::Stu(const Stu & st)
{
	name = st.name;
	score = st.score;
}
Stu::Stu(const Stu & st)
{
	name = st.name;
	score = st.score;
}
void Stu::dispaly()
{
	cout << name;
}
int main()
{
	char str[]= "name";
	Stu s1(str);
	s1.dispaly();
	system("pause");
	return 0;
}

*/


