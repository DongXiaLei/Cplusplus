// C++程序设计5-多态虚函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
	double radius;
	double   PI = 3.1415926;
	static double count_all;
	Shape(double r=0)
	{
		radius = r;
	}
	~Shape() {}
	virtual double Area()
	{
		cout << "Shape Area=" << count_all;
		return 0;
	}
};
double Shape::count_all = 0;
class Circle :public Shape
{
private:
	double temp;
public:
	Circle(double r) :Shape(r) 
	{
		temp = Area();
		count_all += temp;
	}
	double Area()
	{
		double temp = 0;
		temp = radius * radius*PI;
		return temp;
	}
};
class Square :public Shape
{
private:
	double temp;
public:
	Square(double r) :Shape(r)
	{
		temp = Area();
		count_all += temp;
	}
	double Area()
	{
		double temp = 0;
		temp = radius * radius;
		return temp;
	}
};
class Rectangle :public Shape
{
private:
	double height;
	double temp;
public:
	Rectangle(double r,double h) :Shape(r)
	{
		height = h;
		temp = Area();
		count_all += temp;
	}
	double Area()
	{
		double temp = 0;
		temp = radius * height;
		return temp;
	}
};
class Trapezoid :public Shape
{
private:
	double weight;
	double height;
	double temp;
public:
	Trapezoid(double r, double w,double h) :Shape(r)
	{
		height = h;
		weight = w;
		temp = Area();
		count_all += temp;
	}
	double Area()
	{
		double temp = 0;
		temp = (weight+radius)*height/2.0;
		return temp;
	}
};
class Trangle :public Shape
{
private:
	double weight;
	double height;
	double temp;
public:
	Trangle(double r, double w, double h) :Shape(r)
	{
		height = h;
		weight = w;
		temp = Area();
		count_all += temp;
	}
	double Area()
	{
		double temp = (weight + height + radius)/2.0;
		temp = sqrt(temp* (temp - height)*(temp - weight)*(temp - radius));
		return temp;
	}
};
int main()
{
	Circle circle(10);
	Square square(10); 
	Rectangle rec(10, 5);
	Trapezoid trap(10, 20, 10);
	Trangle trangle(15, 20, 25);
	Shape *s[5];
	s[0] = &circle;
	s[1] = &square;
	s[2] = &rec;
	s[3] = &trap;
	s[4] = &trangle;
	cout << "圆形面积：" << s[0]->Area() << endl;
	cout << "正方形面积：" << s[1]->Area() << endl;
	cout << "长方形面积：" << s[2]->Area() << endl;
	cout << "梯形面积：" << s[3]->Area() << endl;
	cout << "三角形面积：" << s[4]->Area() << endl;
	cout << "总面积："<<Shape::count_all << endl;

	system("pause");
	return 0;
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
