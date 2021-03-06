// 分油最优.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
/*

#include <iostream>
#define N 200
using namespace std;

class Queue
{
public:
int V30;
int V17;
int V13;
int deepth;
int locaiton;
int pre_location;
Queue();
Queue(int a,int b, int c,int loc);
Queue(const Queue& q);
};
Queue::Queue() {}
Queue::Queue(int a,int b,int c ,int loc)
{
V30 = a;
V17 = b;
V13 = c;
pre_location = loc;
}
Queue::Queue(const Queue& q)
{
V30 = q.V30;
V17 = q.V17;
V13 = q.V13;
deepth = q.deepth;
locaiton = q.locaiton;
pre_location = q.pre_location;
}

Queue ArrayQueue[N] = { Queue(30,0,0,0) };
int FindSame(Queue item)
{
for (int i = 0; i < N; i++)
{
if (item.V30 == ArrayQueue[i].V30&&item.V17 == ArrayQueue[i].V17&&item.V13 == ArrayQueue[i].V13)
return 1;
}
return 0;
}
void Find(int i,int count,Queue t)
{
if(t.V30==15||t.V17==15)
{
return ;
}
else
{
//1->2 1
Queue temp1 = t;
int tem = 0;
tem = 17 - temp1.V17;
temp1.V30 -= tem;
temp1.V17 = 17;
temp1.deepth = i;
temp1.locaiton = 1;
temp1.pre_location = temp1.locaiton;
if (!(FindSame(temp1)))
{
ArrayQueue[count++] = temp1;
Find(i + 1, count, temp1);
}
//1->3 2
Queue temp2 = t;
tem = 13 - temp2.V13;
temp2.V30 -= tem;
temp2.V13 = 13;
temp2.deepth = i;
temp2.locaiton = 2;
temp2.pre_location = temp2.locaiton;
if (!(FindSame(temp2)))
{
ArrayQueue[count++] = temp2;
Find(i + 1, count, temp2);
}
//2->3 3
Queue temp3 = t;
if ((temp3.V17 + temp3.V13) >= 13)
{
tem = temp3.V17 + temp3.V13 - 13;
temp3.V17 = tem;
temp3.V13 = 13;
}
else
{
temp3.V13 = temp3.V13 + temp3.V17;
temp3.V17 = 0;
}
temp3.deepth = i;
temp3.locaiton = 3;
temp3.pre_location = temp3.locaiton;
if (!(FindSame(temp3)))
{
ArrayQueue[count++] = temp3;
Find(i + 1, count, temp3);
}
//2->1 4
Queue temp4 = t;
temp4.V30 += temp4.V17;
temp4.V17 = 0;
temp4.deepth = i;
temp4.locaiton = 4;
temp4.pre_location = temp4.locaiton;
if (!(FindSame(temp4)))
{
ArrayQueue[count++] = temp4;
Find(i + 1, count, temp4);
}
//3->1 5
Queue temp5 = t;
temp5.V30 += temp5.V13;
temp5.V13 = 0;
temp5.deepth = i;
temp5.locaiton = 5;
temp5.pre_location = temp5.locaiton;
if (!(FindSame(temp5)))
{
ArrayQueue[count++] = temp5;
Find(i + 1, count, temp5);
}
//3->2 6
Queue temp6 = t;
if ((temp6.V17 + temp6.V13) >= 17)
{
tem = temp6.V17 + temp6.V13 - 17;
temp6.V17 = 17;
temp6.V13 = tem;
}
else
{
temp6.V17 = temp6.V13 + temp6.V17;
temp6.V13 = 0;
}
temp6.deepth = i;
temp6.locaiton = 6;
temp6.pre_location = temp6.locaiton;
if (!(FindSame(temp6)))
{
ArrayQueue[count++] = temp6;
Find(i + 1, count, temp6);
}
}
}
int main()
{
Find(1, 1, ArrayQueue[0]);
for (int i = 0; i < N; i++)
{
if (!(ArrayQueue[i].V30 == 0 && ArrayQueue[i].V17 == 0 && ArrayQueue[i].V13 == 0))
cout << i + 1 << " " <<"三个桶："<< ArrayQueue[i].V30 << " " << ArrayQueue[i].V17 << " " << ArrayQueue[i].V13 <<" "<<"搜索深度："<< ArrayQueue[i].deepth << " " <<"上一个节点位置："<< ArrayQueue[i].pre_location << endl;
}

system("pause")
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

*/
