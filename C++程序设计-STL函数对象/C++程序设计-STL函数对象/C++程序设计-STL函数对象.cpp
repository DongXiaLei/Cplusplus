// C++程序设计-STL函数对象.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
class Student //默认为protected
{
public:
	int number;
	string name;
	Student(int i, string s) { number = i; name = s; }
	bool operator < (Student & b) 
	{
		return number < b.number;
	}
	
	friend void print(Student s1);
	
};
void print(Student s1)
{
	cout << "number:" << s1.number << "name:" << s1.name << endl;
}
struct numbercmp//默认为public
{
public:
	bool operator()(Student &s1, Student &s2)
	{
		return s1.number < s2.number;
	}
	
};

int main()
{
	Student st1(2011, "dong"), st2(2012, "xia"), st3(2013, "lei"), st4(2012, "peng");
	list<Student> v1;
	//vector<Student> v1;
	v1.push_back(st1);
	v1.push_back(st2);
	v1.push_back(st3);
	v1.push_back(st4);
	v1.sort();
	//sort(v1.begin(), v1.end(),numbercmp() );
	for_each(v1.begin(), v1. end(), print);
	
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
