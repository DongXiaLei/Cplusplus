// C++-程序设计-实习二.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define minN 1e-9
#define N 100
using namespace std;
template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node()
	{
		data = minN;
		next = NULL;
	}
	Node(T d)
	{
		data = d;
		next = NULL;
	}
};
template<typename T>
class List
{
public:
	Node<T>* head;
	List()
	{
		head = NULL;
	}
	List(T& dat)
	{
		head->data = dat;
	}
	~List(){}

	void CreateList(T* arr,int num);
	void DestoryList();
	void PushBackList(const T& dat);
	T   PopBackList();
	void InsertList(int pos,const T& dat);
	T   DeleteList(int pos);
	void MergeList(List<T> &ls);

	int LengthOfList();
	void SortList();
	void DispalyList();

};
template<typename T>
void List<T>::CreateList(T* arr,int num)
{
	Node<T>* p;
	p = head;
	for (int i = 0; i < num; i++)
	{
		Node<T>* temp = new Node<T>(arr[i]);
		//temp->data = arr[i];
		temp->next = NULL;
		if (p==NULL)
		{
			head = temp;
		}
		else
		{
			p->next = temp;
		}
		p = temp;
	}

}
template<typename T>
void List<T>::DestoryList()
{
	
	if (head == NULL)
		return;
	else
	{
		Node<T>* cur = head;
		Node<T>* del = head;
		while (cur)
		{
			del = cur;
			cur = cur->next;
			delete del;
		}
		head = NULL;

	}
}
template<typename T>
void List<T>::PushBackList(const T& dat)
{
	if (head == NULL)
	{
		Node<T>* temp = new Node<T>(dat);
		head = temp;
	}
	else
	{
		Node<T>* cur = new Node<T>(dat);
		Node<T>* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = cur;
	}
	

}
template<typename T>
T List<T>::PopBackList()
{
	if (head == NULL)
	{
		cout << "无数据可删除";
		return NULL;
	}
	else
	{
		Node < T>* temp = head,*p=NULL;
		while (temp->next!= NULL)
		{
			if (temp->next->next == NULL)
				p = temp;
			temp = temp->next;
		}
		T tem = temp->data;
		delete temp;
		p->next = NULL;
		return tem;
	}
}
template<typename T>
void List<T>::InsertList(int pos,const T& dat)
{
	int num = pos;
	if (num >LengthOfList() + 1)
	{
		cout << "错误，超出链表范围" << endl;
		return;
	}
	else
	{
		Node<T>* cur = new Node<T>(dat);
		if (num == 1)
		{
			cur->next = head;
			head = cur;
		}
		else
		{
			Node<T>* tmp1 = head;
			Node<T>* tmp2 = head;
			while (--num)
			{
				tmp2 = tmp1;
				tmp1 = tmp1->next;

			}
			cur->next = tmp1;
			tmp2->next = cur;
			//head->next = cur;  应该是tmp的上一个节点指向cur
		}
	}

}
template<typename T>
T List<T>::DeleteList(int pos)
{
	int num = pos;
	if (num > LengthOfList() || num <= 0)
	{
		cout << "超出链表范围链表" << endl;
		return NULL;
	}
	else if (head == NULL)
	{
		cout << "空链表" << endl;
		return NULL;
	}
	else
	{
		Node<T>*  cur = head;
		if (num == 1)
		{
			head = head->next;
			delete cur;
		}
		else
		{
			Node<T>* tmp1 = head;
			Node<T>* tmp2 = head;
			while (--num)
			{
				tmp2 = tmp1;
				tmp1 = tmp1->next;
			}
			tmp2->next = tmp1->next;
			delete tmp1;

		}

	}

}
template<typename T>
void List<T>::MergeList(List<T> &ls)
{
	if (head == NULL)
	{
		head = ls.head;
	}
	else
	{
		Node<T>* tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next= ls.head;
	}
}
template<typename T>
int List<T>::LengthOfList()
{
	Node<T>* p = head;
	if (p->next == NULL && p->data != minN)
		return 1;
	if (p->next == NULL)
		return 0;
	else
	{
		int count = 1;
		while (p->next != NULL)
		{
			count++;
			p = p->next;
		}
		return count;
	}
}
template<typename T>
void List<T>::SortList()
{
	Node<T>*p, *q;
	for (p = head; p; p = p->next) //这个循环只是为了让循环达到和链表中节点相等的个数，p不会被实际用到
		for (q = head; q->next; q = q->next)
		{
			if (q->data > q->next->data)
			{
				T tmp = q->data;
				q->data = q->next->data;
				q->next->data = tmp;
			}
		}
}
template<typename T>
void List<T>::DispalyList()
{
	Node<T>* p = head;
	if (p == NULL)
		cout << "链表为空！";
	while (p != NULL)
	{
		if (p->data != minN)
			cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}
void test()
{
	int array[N] = { 5,2,1,2,3,4,5 };
	List<int> ls;
	int num = sizeof(array) / sizeof(int);
	cout << "ls1初始化";
	ls.CreateList(array, 7);
	ls.DispalyList();
	cout<<"ls1长度：" << ls.LengthOfList() << endl;
	cout << "ls1排序后输出";
	ls.SortList();
	ls.DispalyList();
	//ls.DestoryList();
	cout << "尾插7后";
	ls.PushBackList(7);
	ls.DispalyList();
	cout << "删除尾部数";
	ls.PopBackList();
	ls.DispalyList();
	cout << "在第4个位置插入9";
	ls.InsertList(4, 9);
	ls.DispalyList();
	cout << "删除第4个位置的数";
	ls.DeleteList(4);
	ls.DispalyList();

	List<int> ls2;
	ls2.CreateList(array, 7);
	cout << "ls2初始化";
	ls2.DispalyList();
	ls2.MergeList(ls);
	cout << "ls1链接到ls2后结果";
	ls2.DispalyList();
	
}
int main()
{
	
	test();
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
