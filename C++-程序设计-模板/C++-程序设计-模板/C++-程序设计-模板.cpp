// C++-程序设计-模板.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#define N 10
using namespace std;
template<class T>
T* sort_bubble(T array[],int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		for (int j =0; j<n-i-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	return array;
}
class Student
{
public:
	int number;
	int ID;
	char name[20];
	Student(){}
	Student(int a, int b,const char *s)
	{
		number = a;
		ID = b;
		strcpy(name, s);
	}
	~Student(){}
	//重载>号，实现对名字字符串排序
	bool operator>(Student &stu)
	{
		return strcmp(name, stu.name)>0?1:0;
	}
};

int main()
{
	//对基本数据类型的排序
	int arr_i[N] = { 2,6,1,7,4,8,2,3,9,3};
	double arr_d[N] = { 2.2,6.6,4.4,3,2.3,1.7,8.9,7.6,1.2,4.6 };
	char arr_c[N] ="qwertyufA" ;
	int* p_i;
	double* p_d;
	char* p_c;
	p_i=sort_bubble(arr_i, 10);
	p_d = sort_bubble(arr_d, 10);
	p_c = sort_bubble(arr_c, 10);
	cout << "对int、float、等基本数据类型的排序：" << endl;
	for (int i = 0; i < N; i++)
	{
		cout<<p_i[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << p_d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << p_c[i] << " ";
	}
	cout << endl;
	//对类对象根据名字字符串的排序
	Student st1(11, 1, "dong"), st2(22, 2, "xia"), st3(33, 3, "lei");
	Student st[3] = { { 11, 1, "dong" },{ 44, 2, "dia" },{ 33, 3, "lei" } };
	sort_bubble(st, 3);
	cout << "对类对象的排序：" << endl;
	for (int i = 0; i < 3; i++)
	{

		cout << st[i].name << " ";
	}

	system("pause");
	return 0;
}

/*
#include "stdafx.h"
#include<iostream>
using namespace std;
template<class T>
void Sort(T set[], int n)
{
int i, j;
T temp;
for (i = 1; i<n; i++)
for (j = n - 1; j >= i; j--)
if (set[j - 1]>set[j])
{
temp = set[j - 1];
set[j - 1] = set[j];
set[j] = temp;
}
}
int main()
{
int i;
int a[] = { 4,5,2,8,9,3 };
double b[] = { 3.5, 6.7, 2, 5.2, 9.2, 10.3 };
Sort(a, 6);
Sort(b, 6);
for (i = 0; i<6; i++)
cout << a[i] << "  ";
cout << endl;
for (i = 0; i<6; i++)
cout << b[i] << "  ";
cout << endl;

system("pause");
return 0;
}
*/


