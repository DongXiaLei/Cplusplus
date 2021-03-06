// 算法设计-递归-自然数划分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
思路：用temp[i][j] 表示i 划分成最大数为j的数相加的组合数， 求temp[i][j] 可分为三种情况：
1， i = 1或j = 1 时 temp[i][j] = 1 (将1分成n份或将n分成1份只有一种情况)
2，当i < j 时， temp[i][j]和temp[i][i]相同
3， 当i = j 时， temp[i][j] 比 temp[i][j-1] 多了 j 这一种组合
4， 当i > j 时， tmep[i][j] = temp[i][j-1](不含j的组合) + temp[i-j][j]（含j的组合）
*/
/*
  递归实现
int intPart( int n , int m )
{

	if( ( n < 1 ) ||( m < 1 ) ) return 0 ;


	if( ( n == 1 )||( m == 1 ) ) return 1 ;


	if( n < m ) return intPart( n , n ) ;


	if( n == m ) return intPart( n , m-1 ) + 1 ;


	return intPart( n , m-1 ) + intPart( n - m , m ) ;
}
*/
#include "pch.h"

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define MAX 500

int temp[MAX][MAX];
//500以内 temp[i][j] 表示i 划分成最大数为j的数相加的组合数
void fun()
{
	int i, j;
	for (i = 1; i < MAX; i++)
	{
		for (j = 1; j < MAX; j++)
		{
			if (i == 1 || j == 1)
			{
				temp[i][j] = 1;
			}
			else if (i < j)
			{
				temp[i][j] = temp[i][i];
			}
			else if (i == j)
			{
				temp[i][j] = temp[i][j - 1] + 1;
			}
			else if (i > j)
			{
				temp[i][j] = temp[i][j - 1] + temp[i - j][j];
			}
		}
	}
}
int intPart(int n, int m)
{

	if ((n < 1) || (m < 1)) return 0;


	if ((n == 1) || (m == 1)) return 1;


	if (n < m) return intPart(n, n);


	if (n == m) return intPart(n, m - 1) + 1;


	return intPart(n, m - 1) + intPart(n - m, m);
}
int main()
{
	fun();
	int n, m;
	cout << "请输入化分数n和最大划分子序列的值：";
	cin >> n >> m;
	printf("%d\n", intPart(n,m));
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
