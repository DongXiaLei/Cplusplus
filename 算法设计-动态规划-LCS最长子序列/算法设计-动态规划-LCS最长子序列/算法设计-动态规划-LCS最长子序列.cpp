// 算法设计-动态规划-LCS最长子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
•若给定序列X={x1,x2,…,xm}，则另一序列Z={z1,z2,…,zk}，是X的子序列是指存在一个严格递增下标序列{i1,i2,…,ik}使得对于所有j=1,2,…,k有：zj=xij。
•例如，序列Z={B，C，D，B}是序列X={A，B，C，B，D，A，B}的子序列，相应的递增下标序列为{2，3，5，7}。
 
分析：
用动态规划做
 

1.最长公共子序列的结构
事实上，最长公共子序列问题具有最优子结构性质。
设序列X={x1,x2,…,xm}和Y={y1,y2,…,yn}的最长公共子序列为Z={z1,z2,…,zk}则
(1)若xm=yn，则zk=xm=yn，且Zk-1是Xm-1和Yn-1的最长公共子序列。
(2)若xm≠yn且zk≠xm，则Z是Xm-1和Y的最长公共子序列。
(3)若xm≠yn且zk≠yn，则Z是X和yn-1的最长公共子序列。
测试数据 QWERTYUIOP
		QRTYQRUIOP
*/

#include "pch.h"

#include<iostream>
#include<cstring>
#include<String>
#include<algorithm>
using namespace std;

#define N 100
char X[N];
char Y[N];
int b[N][N];
int c[N][N];
int lcslength(char x[], char y[], int m, int n)
{//计算最优子序列的长度
	int i, j;

	for (i = 1; i <= m; i++)
		c[i][0] = 0;
	for (i = 1; i <= n; i++)
		c[0][i] = 0;
	c[0][0] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] > c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
	return c[m][n];
}

void showLCS(int i, int j, char x[])
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1)
	{
		showLCS(i - 1, j - 1, x);
		cout << x[i - 1];
	}
	else if (b[i][j] == 2)
	{
		showLCS(i - 1, j, x);
	}
	else
		showLCS(i, j - 1, x);
}

int main()
{
	int lenx, leny, len;
	printf("请输入两行字符串\n");
	cin >> X >> Y;
	lenx = strlen(X);
	leny = strlen(Y);
	len = lcslength(X, Y, lenx, leny);
	cout << "最大公共子序列的长度是：" << len << endl;
	
	showLCS(lenx, leny, X);
	cout << endl;
	for (int i=0; i < lenx + 1; i++)
	{
		for (int j=0; j < leny + 1; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i=0; i < lenx + 1; i++)
	{
		for (int j=0; j < leny + 1; j++)
			cout << b[i][j]<<" ";
		cout << endl;
	}
	cout << endl;

	return 0;
}