// C++学习之继承.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;
class UGStudent :public Student
{
private:
	int age;
	int grade;
public:
	UGStudent();
	UGStudent(int n, char* s, int a, int g);
	void printExtra();

};
UGStudent::UGStudent()
{
	Setvalue(0, " ");
	age = 0; grade = 0;
}
UGStudent::UGStudent(int n, char *s, int a, int g)
{
	Setvalue(n, s);
	age = a; grade = g;
}
void UGStudent::printExtra()
{
	cout << "age:"<< age << endl;
	cout << "grade:"<< grade;
}
int main()
{
	char str[] = "wang";
	UGStudent st(100, str, 18, 1);
	st.print();
	st.printExtra();
	
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
