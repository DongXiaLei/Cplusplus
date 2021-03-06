#				// C++程旭设计-模板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
	int a[5] = {1,2,3,4,5};
	vector<int> v1, v2(a, a + 5);
	vector<int >::iterator itv;
	v1.insert(v1.begin(), 2);
	v1.insert(v1.begin(), 4);
	v1.insert(v1.end(), 6);
	cout << v1.size()<<" "<<v1.empty()<<endl;
	v2.erase(v2.begin());
	for (itv = v2.begin(); itv != v2.end(); itv++)
	{
		cout << *itv << " ";
	}
	cout << endl;

	list<int >l1, l2(v2.begin(), v2.end());
	list<int>::iterator itl;
	l2.insert(l2.begin(), 1);
	//l2.erase(l2.begin());
	l2.push_back(6);
	l2.pop_back();
	for (itl = l2.begin(); itl != l2.end(); itl++)
	{
		cout << *itl << " ";
	}
	cout << endl;
	cout << l2.back() << " " << l2.front() << " " << endl;

	vector<string> vs;
	string s1("we");
	vs.push_back(s1);
	vs.push_back("like");
	vs.push_back("rourou");
	for (size_t i = 0; i < vs.size(); i++)
	{
		cout << vs[i]<<" ";
	}
	

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
