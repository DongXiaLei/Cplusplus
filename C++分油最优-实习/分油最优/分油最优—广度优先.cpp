#include "pch.h"
#include <iostream>
#define N 200
using namespace std;
/*
	�������� ���
	�ඨ�壺
	    ������Ͱ��С V30��V17��V13
		��ǰ״̬����������λ��location
		��һ��״̬��������λ��pre_location

	��ʼ״̬��������Ͱ�����ֱַ�Ϊ V30 V17 V13�������� 30 0 0
	ѭ���ݹ飺
	  ����Find��int i��int count ��int count_��Queue q��i��ȣ�count��ǰλ�ã�count_ǰһ��λ�ã�qΪ��ǰ����״̬
	    ����ÿһ��״̬����6�ֲ���V30->V17 V30->V13 V17->V13,���Ϸ�����
		ÿ�β������ֽ������ÿ�ֽ�����أ�����Findsame�������ȫ�ֱ���ArrayQueue������
		ȫ������ֱ��¼��Ͱ��������ǰλ�ã�ǰһ��λ��
	�����ݹ飺
	    ֱ���ҵ�V30=15��V17=15ʱ��
		��¼ȫ�����鳤�ȵ�ȫ�ֱ���ture_loc
		�����ݹ�
	Ѱ���·��
	  ����Reverse����
	    ͨ��ture_loc�ҵ�ȫ��״̬��һ���ҵ���ȷ�����λ��
		������Դ��ÿ��ͨ����ǰλ��locaton��ǰһ��λ��pre_location
		���ҵ��Ľ����¼���µĶ�������ArrayTrue������¼���·������count_num
    ѭ�������
	    �����·����������ArrayTrue����������

*/
//�������
class Queue
{
public:
	int V30;
	int V17;
	int V13;
	int locaiton=0;//��ǰλ��
	int pre_location=0;//��һ��λ��
	Queue();
	Queue(int a, int b, int c, int loc);//���ع��캯��
	Queue(const Queue& q);//���ƹ��캯��
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

Queue ArrayQueue[N] = { Queue(30,0,0,0) };//��ʼ��
//���غ���
int FindSame(Queue item)
{
	for (int i = 0; i < N; i++)
	{
		if (item.V30 == ArrayQueue[i].V30&&item.V17 == ArrayQueue[i].V17&&item.V13 == ArrayQueue[i].V13)
			return 1;
	}
	return 0;
}
//�ݹ麯��
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
//Ѱ���·����
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
	//��ȱ������
	cout << "��ȱ������:"<<ture_loc<<endl;
	for (int i = 0; i < ture_loc+1; i++)
	{
			cout << i << " " << "����Ͱ��" << ArrayQueue[i].V30 << " " << ArrayQueue[i].V17 << " " << ArrayQueue[i].V13 << " "<<"��ǰ�ڵ�"<<ArrayQueue[i].locaiton<< " " << "��һ���ڵ�λ�ã�" << " " << ArrayQueue[i].pre_location << endl;
	}
	for (int j= count_num-1,k=0; j >=0; j--,k++)
	{
		    cout <<"��"<< k+1 << "�� ��" << "����Ͱ��" << que[j].V30 << " " << que[j].V17 << " " << que[j].V13 << " "  << endl;
	}


	system("pause");
	return 0;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
