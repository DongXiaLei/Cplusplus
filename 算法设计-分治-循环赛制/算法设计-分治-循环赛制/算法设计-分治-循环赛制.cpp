// 算法设计-分治-循环赛制.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include<iostream>
#include<vector>
using namespace std;

void GameTable(vector<vector<int> > &vec,int lk) {
	if (vec.size() == 0) {
		return;
	}
	size_t s = vec.size();
	int k=0;
	while (s = s >> 1) {
		//s = s >> 1;
		k++;
	}
	k = lk;
	//初始化
	vec[0][0] = 1;
	vec[0][1] = 2;
	vec[1][0] = 2;
	vec[1][1] = 1;

	for (int i = 2; i <= k; i++) 
	{
		int length = 0x1 << i;
		int half = length >> 1;

		//左下角的子表中项为左上角子表对应项加half=2^(i-1)
		for (int row = 0; row < half; row++) 
		{
			for (int col = 0; col < half; col++) 
			{
				vec[row + half][col] = vec[row][col] + half;
			}
		}
		//右上角的子表等于左下角子表
		for (int row = 0; row < half; row++) 
		{
			for (int col = 0; col < half; col++) 
			{
				vec[row][col + half] = vec[row + half][col];
			}
		}
		//右下角的子表等于左上角子表
		for (int row = 0; row < half; row++) 
		{
			for (int col = 0; col < half; col++) 
			{
				vec[row + half][col + half] = vec[row][col];
			}
		}
	}
}

int main(void) {
	cout << "共有2^k个选手参加比赛，输入k（k>0）：" << endl;
	int k;
	do {
		cin >> k;
	} while (k < 0 || k > 31);

	int s = 0x1 << k;
	vector<vector<int> > vec(s, vector<int>(s, 0));

	GameTable(vec,k);

	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
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
