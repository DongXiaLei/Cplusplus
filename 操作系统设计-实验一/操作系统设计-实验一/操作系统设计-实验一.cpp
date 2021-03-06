// 操作系统设计-实验一.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
操作系统设计实验一

定义五个进程，有优先级和时间数，按优先级依次运行，时间数用完则删除


测试数据
A 1 3
B 2 6
C 4 6
D 3 7
E 1 8

*/

static 
class Process//进程节点
{
public:
	char name;//进程名字
	Process* next;//下一个进程指针
	int time;
	int privileg;
	char Pos;
	Process();
	Process(const Process & p);//复制构造函数
	~Process() {}
	bool operator>(const Process &p);//重载>

};
Process::Process()
{
	cin >> name;
	cin >> time;
	cin >> privileg;
	Pos = 'R';
	next = NULL;
}
Process::Process(const Process &p)
{
name = p.name;
time = p.time;
privileg = p.privileg;
Pos = p.Pos;
}

class Pro//进程队列
{
public:
	Process * head;
	int count = 1;
	Pro()
	{
		head = NULL;
	}
	~Pro(){}
	void CreateQueue();
	void SortQueue();
	void DispalyQueue();
	void Run();
};
bool Process::operator>(const Process & p)
{
	return privileg > p.privileg;
}
void Pro::CreateQueue()
{

	for (int i = 0;i < 5; i++)
	{
		Process* pro = new Process();
		if (head == NULL)
		{
			head = pro;
		}
		else
		{
			Process * tmp = head;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = pro;
		}
	}
}
void Pro::SortQueue()
{
	Process* pro1,*pro2;
	for (pro1 = head; pro1; pro1 = pro1->next)
	{
		for (pro2 = head; pro2->next; pro2 = pro2->next)
		{
			if (pro2->privileg < pro2->next->privileg)
			{
				char temp_name = pro2->name;
				pro2->name = pro2->next->name;
				pro2->next->name = temp_name;

				int temp_time = pro2->time;
				pro2->time = pro2->next->time;
				pro2->next->time = temp_time;

				char temp_pos = pro2->Pos;
				pro2->Pos = pro2->next->Pos;
				pro2->next->Pos = temp_pos;

				int temp_privileg = pro2->privileg;
				pro2->privileg = pro2->next->privileg;
				pro2->next->privileg = temp_privileg;
			}
		}
	}
}

void Pro::DispalyQueue()
{
	Process* pro = head;
	cout<<"第" << count++ << "次："<<endl;
	while (pro)
	{
		cout << "进程："<<pro->name<<"时间数："<<pro->time<<"优先级："<<pro->privileg<< endl ;
		pro = pro->next; 
	}
}
void Pro::Run()
{
	SortQueue();
	DispalyQueue();
	cout << endl;
	while (head != NULL&&head->time > 0)
	{
		
		head->time -= 1;
		head->privileg -= 1;
		if (head->time == 0)
		{
			head->Pos = 'E';
		}
		if (head->Pos == 'E')
		{
			Process* del = head;
			head = head->next;
			delete del;
		}
		SortQueue();
		DispalyQueue();
		cout << endl;
	}
	
}
int main()
{
	Pro pro;
	pro.CreateQueue();
	pro.Run();

	system("pause");
    return 0;
}

