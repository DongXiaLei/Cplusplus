// 算法设计-动态规划-背包问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
测试数据
5 11
2 3
2 5
6 5
4 4
4 11
*/
#include "pch.h"
#include <cmath>
#include<iostream>
#include <algorithm>
using namespace std;

int a[50001], b[50001];
int f2[5001][5001], f1[5001];

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
01背包
有n件物品和容量为m的背包 给出i件物品的重量以及价值 求解让装入背包的物品重量不超过背包容量 且价值最大
特点 这是最简单的背包问题 特点是每个物品只有一件供你选择放还是不放

设f[i][j]表示前i件物品 总重量不超过j的最大价值 可得出状态转移方程
f[i][j]=max{f[i-1][j-a[i]]+b[i],f[i-1][j]}
*/
//二维解
int fun1(int n, int m)
{
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
		{
			if (a[i] <= j)
				f2[i][j] = max(f2[i - 1][j], f2[i - 1][j - a[i]] + b[i]);
			//第一种情况是不考虑放入a只考虑放入bcde承重为C时的最大价值f[4][C],第二种情况是考虑放入a时的最大价值，即value[a]+f[4][10-weight[a]]
			else f2[i][j] = f2[i - 1][j];
		}
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
			cout << f2[i][j] << " ";
		cout << endl;
	}
	return f2[n][m];
}
int fun2(int n,int m)
{
	int f[50001] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		//01背包
		
		/*
		for (int j = m; j >= a[i]; j--)
		{
			if (f[j - a[i]] + b[i] > f[j])
				f[j] = f[j - a[i]] + b[i];
		}
		*/
	    //完全背包
		for (int j = a[i]; j <= m; j++) 
		{
			if (f[j - a[i]] + b[i] > f[j])
				f[j] = f[j - a[i]] + b[i];
		}
		for(int k=0;k<m+1;k++)
			cout << f[k] << " ";
		cout << endl;


	}
	return f[m]; //最优解
}
int main()
{
	int m, n;
	cin >> n >> m;
	max(n, m);
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	cout <<fun2(n,m) << endl; //最优解
	//COYG
}
/*
#include<iostream>
#include<algrithm>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int a[10001],b[10001],c[10001];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int f[10001];
	for(int i=1;i<=n;i++)
	for(int j=m;j>=0;j--)
	for(int k=0;k<=c[i];k++){
		if(j-k*a[i]<0)break;
		f[j]=max(f[j],f[j-k*a[i]]+k*b[i]);
	}
	cout<<f[m]<<endl;//最优解
}

*/

