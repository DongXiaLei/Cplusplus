// C++-程序设计-链表模板实现.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#define N 10
using namespace std;

template <class T>
class LinkNode
{
public:
	LinkNode(T v) { value = v; }
	T value;
	LinkNode<T>* next;
};
template <class T>
class LinkList
{
private:
	LinkNode<T>* head;
public:
	LinkList();
	LinkList(const LinkList& list);
	virtual ~LinkList();
	void clear();
	int length() const;
	bool is_empty() const;
	void output() const;

	LinkNode<T>* push_back(T value);
	LinkNode<T>* insert(T value, int pos);
	LinkNode<T>* remove(T value);

	LinkNode<T>* find(T value) const;
	//查找链表的中间节点
	LinkNode<T>* find_middle() const;
	//查找链表的倒数第N个节点
	LinkNode<T>* find_reverse_nth(int n) const;

	//链表反转
	LinkList<T>& reverse();
	LinkNode<T>* _reverse(LinkNode<T>* pNode);
	//在链表中创建环，n表示交点相对于头节点的位置
	LinkNode<T>* make_cycle(int n);
	//在链表中解除环，cycle_entry表示环的入口点
	void LinkList<T>::clear_cycle(LinkNode<T>* cycle_entry);
	//检查链表是否有环
	LinkNode<T>* check_cycle() const;
	//检查链表环的入口节点
	LinkNode<T>* find_cycle_entry() const;
	//合并两个链表，假设两个链表都已经排序
	template<class U> //这里这样定义才能编译通过，具体问题参见http://blog.csdn.net/dongzhongshu/article/details/6200466
	friend LinkList<U>& mergelist(const LinkList<U>& list1, const LinkList<U>& list2);
	//链表冒泡排序
	LinkList<T>& bubble_sort();
	//链表选择排序
	LinkList<T>& select_sort();
};
template <class T>
LinkList<T>::LinkList()
{
	this->head = NULL;
	T tmp;
	LinkNode<T> *r, *p = this->head;
	cin >> tmp;
	while (tmp != MIN_INT) //此处先争对int型，以后再修改
	{
		r = new LinkNode<T>(tmp);
		r->next = NULL;
		if (head == NULL)
			head = r;
		else
			p->next = r;
		p = r;
		cin >> tmp;
	}
}

template <class T>
LinkList<T>::LinkList(const LinkList& list)
{
	LinkNode<T> *p = list.head;
	LinkNode<T> *q = NULL, *r = NULL;
	head = NULL;
	while (p != NULL)
	{
		r = new LinkNode<T>(p->value);
		r->next = NULL;
		if (head == NULL)
		{
			head = r;
		}
		if (q != NULL)
		{
			q->next = r;
		}
		q = r;
		p = p->next;
	}
}

template <class T>
void LinkList<T>::clear()
{
	LinkNode<T>* p = this->head;
	while (head != NULL)
	{
		head = head->next;
		p->next = NULL;
		delete p;
		p = head;
	}
}
template <class T>
LinkList<T>::~LinkList()
{
	clear();
}
template <class T>
bool LinkList<T>::is_empty() const
{
	return head == NULL;
}

template <class T>
int LinkList<T>::length() const
{
	int size = 0;
	LinkNode<T>* p = head;
	while (p != NULL)
	{
		size++;
		p = p->next;
	}

	return size;
}
template <class T>
LinkNode<T>* LinkList<T>::push_back(T value)
{
	LinkNode<T>* p = head, q;
	while (p != NULL && p->next != NULL)
		p = p->next;

	q = new LinkNode<T>(value);
	q->next = NULL;
	if (p != NULL)
		p->next = q;
	else
		head = q;

	return q;
}

template <class T>
LinkNode<T>* LinkList<T>::insert(T value, int pos)
{
	LinkNode<T>* p = head, q = p, r;
	for (int i = 0; i < pos && p != NULL; i++)
	{
		q = p;
		p = p->next;
	}

	r = new LinkNode<T>(value);
	if (!q)
		head = r;
	else
		q->next = r;
	r->next = p;

	return r;
}

template <class T>
LinkNode<T>* LinkList<T>::remove(T value)
{
	LinkNode<T>* p = head, *q;
	while (p)
	{
		if (p->value == value)
		{
			if (q)
			{
				q->next = p->next;
			}
			p->next = NULL;
			delete p;
		}
		q = p;
		p = p->next;
	}
}
template <class T>
LinkNode<T>* LinkList<T>::find(T value) const
{
	LinkNode<T>* p = head;
	while (p)
	{
		if (p->value == value)
			return p;
		p = p->next;
	}

	return NULL;
}

template <class T>
LinkNode<T>* LinkList<T>::find_middle() const
{
	LinkNode<T>* p = head, *q = head;
	while (q != NULL)
	{
		if (q->next != NULL)
			q = q->next->next;
		else
			break;

		p = p->next;
	}

	return p;
}

template <class T>
LinkNode<T>* LinkList<T>::find_reverse_nth(int n) const
{
	if (n > length())
		return NULL;

	LinkNode<T> *p = head, *q = head;
	for (int i = 0; i < n; i++)
	{
		if (p != NULL)
			p = p->next;
		else
			return NULL;
	}

	while (p != NULL)
	{
		p = p->next;
		q = q->next;
	}

	return q;
}
template <class T>
LinkList<T>& LinkList<T>::reverse()
{
	LinkNode<T> *p = head, *q = NULL, *r = NULL;
	if (p != NULL)
		q = p->next;

	while (q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	head->next = NULL;
	head = p;

	return *this;
}

template <class T>
LinkNode<T>* LinkList<T>::_reverse(LinkNode<T>* pNode)
{
	if (pNode == NULL)
		return NULL;
	else if (pNode->next == NULL)
	{ }
}
template <class T>
void LinkList<T>::clear_cycle(LinkNode<T>* cycle_entry)
{
	LinkNode<T>*q = cycle_entry;
	while (q->next != cycle_entry)
		q = q->next;

	q->next = NULL;
}
template <class T>
LinkNode<T>* LinkList<T>::check_cycle() const
{
	LinkNode<T> *p = head, *q = (head == NULL) ? NULL : p->next;
	while (p != q)
	{
		if (p)
			p = p->next;
		else
			break;

		if (q)
			q = q->next;
		else
			break;

		if (q)
			q = q->next;
		else
			break;
	}

	if (!p || !q) return NULL;
	return p;
}
template <class T>
LinkNode<T>* LinkList<T>::find_cycle_entry() const
{
	LinkNode<T>* jointNode = check_cycle();
	if (jointNode == NULL)
		return NULL;

	LinkNode<T>* p = jointNode->next;
	LinkNode<T>* q = head;
	while (p != q)
	{
		p = p->next;
		q = q->next;
	}

	return p;
}
template <class T>
LinkList<T>& mergelist(const LinkList<T>& list1, const LinkList<T>& list2)
{
	LinkList<T>* pNewList;
	if (list1.is_empty())
	{
		pNewList = new LinkList<T>(list2);
		return *pNewList;
	}

	pNewList = new LinkList<T>(list1);
	if (list2.is_empty())
		return *pNewList;

	LinkNode<T> *p = pNewList->head, *q, *r = list2.head, *s;
	while (r)
	{
		if (p && p->value <= r->value)
		{
			q = p;
			p = p->next;
		}
		else
		{
			s = new LinkNode<T>(r->value);
			q->next = s;
			s->next = p;
			q = s;
			r = r->next;
		}
	}


	return *pNewList;
}
template <class T>
LinkList<T>& LinkList<T>::bubble_sort()
{
	LinkNode<T> *p, *q;
	for (p = head; p; p = p->next) //这个循环只是为了让循环达到和链表中节点相等的个数，p不会被实际用到
		for (q = head; q->next; q = q->next)
		{
			if (q->value > q->next->value)
			{
				T tmp = q->value;
				q->value = q->next->value;
				q->next->value = tmp;
			}
		}
}

template <class T>
LinkList<T>& LinkList<T>::select_sort()
{
	LinkNode<T> *p = head, *q, *smallest;
	for (; p; p = p->next)
	{
		smallest = p;
		for (q = p->next; q; q = q->next)
		{
			if (q->value < smallest->value)
				smallest = q;
		}
		if (smallest != p)
		{
			T tmp = smallest->value;
			smallest->value = p->value;
			p->value = tmp;
		}
	}

	return *this;
}
template <class T>
void LinkList<T>::output() const
{
	LinkNode<T>* p = head;
	while (p)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
    return 0;
}

