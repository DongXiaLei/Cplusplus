// C++-程序设计-模板-链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template <class T>
struct Node//链表节点定义
{
	T _data;
	Node* next;
	Node(const T& d)
		:_data(d)
		, next(NULL)
	{}
};

template <class T>
class LinkList
{
private:
	Node<T>* _head;
	Node<T>* _tail;//链表的头尾节点
public:
	LinkList()
		:_head(NULL)
		, _tail(NULL)
	{}

	~LinkList()
	{
		if (_head == NULL)
		{
		}
		else if ((_head == _tail) && (_head != NULL))
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			Node<T>* cur = _head;
			Node<T>* del = _head;
			while (cur)
			{
				del = cur;
				cur = cur->next;
				delete del;
			}
		}
	}
public:
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();//尾插，头插，头删，尾删
	void Display();//显示链表内容
	int ListLen();//求链表长度
	void Insert(const int& pos, const T& d);//指定位置插入
	void Del_Insert(const int& pos);//指定位置删除
    void contact(const LinkList<T> &ls);//两个链表的结合

};
template <class T>
void LinkList<T>::contact(const LinkList<T> &ls)
{
	if (_head == NULL)
	{
		_head = ls._head;	
	}
	else
	{
		_tail->next = ls._head;
	}
	Node<T>* tmp = ls._head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	_tail = tmp;
}
template <class T>
void LinkList<T>::PushBack(const T& d)
{
	if (_head == NULL)
	{
		Node<T>* cur = new Node<T>(d);
		_head = cur;
		_tail = cur;
	}
	else
	{
		Node<T>* cur = new Node<T>(d);
		Node<T>* tmp = _head;

		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = cur;
		_tail = cur;
	}

}


template <class T>
void LinkList<T>::PopBack()
{
	if (_head == NULL)
	{
		return;
	}
	else if ((_head == _tail) && (_head != NULL))
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		/*delete _tail;
		_tail = NULL;    //只是转移了_tail的指向，使其指向了NULL，并没有改变链表最后一个节点为NULL
		Node<T>* cur = _head;
		while(cur->next)
		{
		cur = cur->next;
		}
		_tail = cur;*/
		Node<T>* cur = _head;
		while (cur->next)
		{
			_tail = cur;
			cur = cur->next;
		}
		delete cur;
		_tail->next = NULL;

	}
}

template <class T>
void LinkList<T>::PushFront(const T& d)
{
	if (_head == NULL)
	{
		Node<T>* cur = new Node<T>(d);
		_head = cur;
		_tail = cur;
	}
	else
	{
		Node<T>* cur = new Node<T>(d);
		cur->next = _head;
		_head = cur;
	}
}

template <class T>
void LinkList<T>::PopFront()
{
	if (_head == NULL)
	{
		return;
	}
	else if ((_head == _tail) && (_head != NULL))
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node<T>* cur = _head;
		_head = _head->next;
		delete cur;
	}
}

template <class T>
void LinkList<T>::Display()
{
	Node<T>* cur = _head;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->next;
	}
	cout << endl;
}
template <class T>
int LinkList<T>::ListLen()
{
	int count = 0;
	Node<T>* cur = _head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}


template <class T>
void LinkList<T>::Insert(const int& pos, const T& d)
{
	int num = pos;
	if (num > ListLen() + 1)
	{
		cout << "NULL 链表" << endl;
		return;
	}
	else
	{
		Node<T>* cur = new Node<T>(d);
		if (num == 1)
		{
			cur->next = _head;
			_head = cur;
		}
		else
		{
			Node<T>* tmp1 = _head;
			Node<T>* tmp2 = _head;
			while (--num)
			{
				tmp2 = tmp1;
				tmp1 = tmp1->next;

			}
			cur->next = tmp1;
			tmp2->next = cur;
			//_head->next = cur;  应该是tmp的上一个节点指向cur
		}
	}

}
template <class T>
void LinkList<T>::Del_Insert(const int& pos)
{
	int num = pos;
	if (_head == NULL)
	{
		cout << "NULL 链表" << endl;
		return;
	}
	else if ((_head == _tail) && (_head != NULL))
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node<T>*  cur = _head;
		if (num == 1)
		{
			_head = _head->next;
			delete cur;
		}
		else
		{
			Node<T>* tmp1 = _head;
			Node<T>* tmp2 = _head;
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

void test()
{
	LinkList<int> l1;
	LinkList<int> l2;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.PushBack(5);
	l1.Display();
	cout << "Listlen:" << l1.ListLen() << endl;
	l2.PushBack(1);
	l2.PushBack(2);
	l2.PushBack(3);
	l2.PushBack(4);
	l2.PushBack(5);
	l2.Display();
	cout << "Listlen:" << l2.ListLen() << endl;
	LinkList<int> *p1 = &l1;
	LinkList<int> *p2 = &l2;
	p1->contact(*p2);
	cout << "after_contact" << endl;
	l1.Display();
	cout << "Listlen:" << l1.ListLen() << endl;
	cout << endl;
	l1.PopBack();
	l1.PushFront(0);
	l1.PopFront();
	l1.Display();
	l1.PushFront(5);
	l1.Display();
	cout << "Listlen:" << l1.ListLen() << endl;
	l1.Insert(1, 6);
	l1.Display();
	l1.Insert(2, 7);
	l1.Display();
	l1.Insert(8, 8);
	l1.Display();
	cout << "Listlen:" << l1.ListLen() << endl;

	l1.Del_Insert(1);
	l1.Display();
	cout << "Listlen:" << l1.ListLen() << endl;

}

int main()
{

	test();

	system("pause");
	return 0;

}
/*

#include <iostream>
using namespace std;
#define N 5


template<typename T>
class List
{
public:
T elem;
List* next;
List()
{
elem=0;
next = NULL;
}
~List()
{

}
void intit();
void insert_elem(T t, int n);
T* delet_elem(int n);
T* contate(List* h);
void print(List* h);



};
template<typename T>
void List<T>::intit()
{
T temp;
List* head = new List;
List* p = new List;
cin >> temp;
p->elem = temp;
p->next = NULL;
head->next = p;
while (temp!=-1)
{
cin >> temp;
List* tem = new List;
tem->elem = temp;
tem->next = NULL;
p->next = tem;
p = tem;
delete tem;
}
delete p;
}
template<typename T>
void List<T>::insert_elem(T t, int n)
{

}
template<typename T>
T*  List<T>::delet_elem(int n)
{

}
template<typename T>
T* List<T>::contate(List* h)
{

}
template<typename T>
void List<T>::print(List* h)
{
if(h->next == NULL)
{
cout<<"empty"；
}
else
{
List* p = head->next;
while (p != NULL)
cout << p->elem << " ";
}
}
int main()
{
List<int> ls;
ls.intit();
return 0;
}


*/