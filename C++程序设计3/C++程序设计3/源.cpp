#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

/*
char  *p ="name";  == const char * p="name"
��p���ݲ����޸ĵģ���*p �������޸� ���� p�����ٱ���ֵ��ֻ���Ը�ֵ����
����ʱ���������Ϊconst char* ����ֵ����Ҳ����Ϊconst char* p
p = const char * �����ǺϷ���
p = char * ���Ϸ� 
char * name = "name";�ַ�����Ϊ����
name = "string";�Ϸ�������֮�丳ֵ

char p[] = "name"�� == char *p=��name��; p�Ǳ��� ���ݺ�ָ�����ݵ�ֵ�����Ըı�
char *name��
name = new char(n);
strcpy(name,p);

*/

/*

class Stu
{
private:
	int score;
	char * name;
public:
	Stu();
	Stu( char *p, int s = 11);
	~Stu();
	Stu(const Stu &st);

	void dispaly();
};

Stu::Stu(){}
Stu::Stu(char * p,int s)
{
	score = s;
	name = new char[strlen(p) + 1];
	strcpy(name, p);

}
Stu::~Stu(){}
Stu::Stu(const Stu & st)
{
	name = st.name;
	score = st.score;
}
Stu::Stu(const Stu & st)
{
	name = st.name;
	score = st.score;
}
void Stu::dispaly()
{
	cout << name;
}
int main()
{
	char str[]= "name";
	Stu s1(str);
	s1.dispaly();
	system("pause");
	return 0;
}

*/


