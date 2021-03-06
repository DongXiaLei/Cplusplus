// 算法设计-递归-汉姆塔.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int num = 0;//统计步数
void move(char x, char y, int n)
{
	num++;
	cout << "第" << num << "步：" << "将标号为" << n << "的盘子" << "从" << x << "移到" << y << "柱子上" << endl;
}
//将n个盘子从x借助y移到z
void hanio(int n,char x,char y,char z)
{
	if (n == 1)//递归出口
		move(x, z, 1);
	else
	{
		hanio(n - 1, x, z, y);//将n-1个盘子从x借助z移到y
		move(x, z, n);//将n个盘子移到z
		hanio(n - 1, y, x, z);//将n-1个盘子从y借助x移到z
	}
}
int main()
{
	char x = 'X';
	char y = 'Y';
	char z = 'Z';
	int n;
	cin >> n;
	hanio(n, x, y, z);
  
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
