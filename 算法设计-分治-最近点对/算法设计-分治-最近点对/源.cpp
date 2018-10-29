#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int result[100];
int tot;
int n = 20;


void print()
{
	cout << tot<<" ";
	cout << n << " = ";
	for (int i = 0; i < tot; ++i)
	{
		cout << result[i];
		if (i != tot - 1)
			cout << "+";
	}
	cout << endl;
}
void partition(int cur, int limit)
{
	if (cur == 0)
	{
		print();
		return;
	}
	for (int i = min(limit, cur); i >= 1; --i)
	{
		result[tot++] = i;
		partition(cur - i, i);
		result[--tot] = 0;
	}
}
int main()
{
	cin >> n;
	partition(n, n);
}