// C++程序设计-重载.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int x = 0, int y = 0);
	~Point();
	void show();
	friend Point operator-(const Point &p1);
	friend bool operator!(const Point &p1);
};
Point::Point(int xm, int ym)
{
	x = xm; y = ym;
}
Point::~Point(){}
void Point::show()
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
}
Point operator-(const Point &p1)
{
	Point tmep(-p1.x, p1.y);
	return tmep;
}
bool operator!(const Point &p1)
{
	return (p1.x == 0 && p1.y == 0);
}
int main()
{
	Point p1(20),p2;
	p1.show();
	p2.show();
	p2 = -p1;
	p2.show();
	cout << !p2 << endl;
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
