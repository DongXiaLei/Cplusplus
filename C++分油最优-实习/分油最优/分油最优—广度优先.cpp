#include "pch.h"
#include <iostream>
#define N 200
using namespace std;
/*
	分油问题 求解
	类定义：
	    三个油桶大小 V30，V17，V13
		当前状态储存在数组位置location
		上一个状态储存数组位置pre_location

	初始状态：三个油桶容量分分别为 V30 V17 V13，初油量 30 0 0
	循环递归：
	  函数Find（int i，int count ，int count_，Queue q）i深度，count当前位置，count_前一个位置，q为当前对象状态
	    对以每一个状态，有6种操作V30->V17 V30->V13 V17->V13,加上翻过来
		每次产生六种结果，将每种结果查重（函数Findsame）后放在全局变量ArrayQueue数组中
		全局数组分别记录油桶油量，当前位置，前一个位置
	结束递归：
	    直到找到V30=15，V17=15时，
		记录全局数组长度的全局变量ture_loc
		结束递归
	寻最短路：
	  函数Reverse（）
	    通过ture_loc找到全部状态第一个找到正确结果的位置
		反向溯源，每层通过当前位置locaton，前一个位置pre_location
		将找到的结果记录到新的对象数组ArrayTrue，并记录最短路径长度count_num
    循环输出：
	    将最短路径对象数组ArrayTrue反向遍历输出

*/
//定义对象
class Queue
{
public:
	int V30;
	int V17;
	int V13;
	int locaiton=0;//当前位置
	int pre_location=0;//上一个位置
	Queue();
	Queue(int a, int b, int c, int loc);//重载构造函数
	Queue(const Queue& q);//复制构造函数
};
Queue::Queue() {}
Queue::Queue(int a, int b, int c, int loc)
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
	locaiton = q.locaiton;
	pre_location = q.pre_location;
}

Queue ArrayQueue[N] = { Queue(30,0,0,0) };//初始化
//查重函数
int FindSame(Queue item)
{
	for (int i = 0; i < N; i++)
	{
		if (item.V30 == ArrayQueue[i].V30&&item.V17 == ArrayQueue[i].V17&&item.V13 == ArrayQueue[i].V13)
			return 1;
	}
	return 0;
}
//递归函数
int ture_loc = 0;
void Find(int i, int count,int count_, Queue t)
{
	if (t.V30 == 15 && t.V17 == 15)
	{
		ture_loc = count_;
		return;
	}
	else
	{
		//1->2 1
		Queue temp1 = t;
		int tem = 0;
		tem = 17 - temp1.V17;
		temp1.V30 -= tem;
		temp1.V17 = 17;
		temp1.locaiton = count;
		temp1.pre_location = count_;
		if (!(FindSame(temp1)))
		{
			ArrayQueue[count++] = temp1;
		}
		//1->3 2
		Queue temp2 = t;
		tem = 13 - temp2.V13;
		temp2.V30 -= tem;
		temp2.V13 = 13;
		temp2.locaiton = count;
		temp2.pre_location = count_;
		if (!(FindSame(temp2)))
		{
			ArrayQueue[count++] = temp2;
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
		temp3.locaiton = count;
		temp3.pre_location = count_;
		if (!(FindSame(temp3)))
		{
			ArrayQueue[count++] = temp3;
		}
		//2->1 4
		Queue temp4 = t;
		temp4.V30 += temp4.V17;
		temp4.V17 = 0;
		temp4.locaiton = count;
		temp4.pre_location = count_;
		if (!(FindSame(temp4)))
		{
			ArrayQueue[count++] = temp4;
		}
		//3->1 5 
		Queue temp5 = t;
		temp5.V30 += temp5.V13;
		temp5.V13 = 0;
		temp5.locaiton = count;
		temp5.pre_location = count_;
		if (!(FindSame(temp5)))
		{
			ArrayQueue[count++] = temp5;
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
		temp6.locaiton = count;
		temp6.pre_location = count_;
		if (!(FindSame(temp6)))
		{
			ArrayQueue[count++] = temp6;
		}
		count_++;
		Find(i + 1, count,count_, ArrayQueue[count_]);
	}
}
//寻最短路函数
int count_num = 0;
Queue* Reverse()
{
	Queue ArrayTrue[200] = { Queue(0,0,0,0) };
	ArrayTrue[0].V30 = ArrayQueue[ture_loc].V30;
	ArrayTrue[0].V17 = ArrayQueue[ture_loc].V17;
	ArrayTrue[0].V13 = ArrayQueue[ture_loc].V13;
	int i = ArrayQueue[ture_loc].pre_location,j=1;
	while (ArrayQueue[i].locaiton != 0)
	{
		ArrayTrue[j].V30 = ArrayQueue[ArrayQueue[i].locaiton].V30;
		ArrayTrue[j].V17 = ArrayQueue[ArrayQueue[i].locaiton].V17;
		ArrayTrue[j].V13 = ArrayQueue[ArrayQueue[i].locaiton].V13;

		j++;
		i = ArrayQueue[ArrayQueue[i].locaiton].pre_location;

	}
	count_num = j;



	return ArrayTrue;
}
int main()
{
	Find(1, 1,0, ArrayQueue[0]);
	Queue* que = Reverse();
	//广度遍历结果
	cout << "广度遍历结果:"<<ture_loc<<endl;
	for (int i = 0; i < ture_loc+1; i++)
	{
			cout << i << " " << "三个桶：" << ArrayQueue[i].V30 << " " << ArrayQueue[i].V17 << " " << ArrayQueue[i].V13 << " "<<"当前节点"<<ArrayQueue[i].locaiton<< " " << "上一个节点位置：" << " " << ArrayQueue[i].pre_location << endl;
	}
	for (int j= count_num-1,k=0; j >=0; j--,k++)
	{
		    cout <<"第"<< k+1 << "步 ：" << "三个桶：" << que[j].V30 << " " << que[j].V17 << " " << que[j].V13 << " "  << endl;
	}


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
