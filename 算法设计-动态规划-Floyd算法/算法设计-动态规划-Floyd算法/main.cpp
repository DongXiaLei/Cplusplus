#include "pch.h"


#include"Floyd.h"


//������������Ͷ�������ֵ�Ƿ���Ч�������Լ�����Ϊɶ��
//�������ͱ����Ĺ�ϵ�ǣ�((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}
int main() {
	int vexnum; int edge;
	cout << "����ͼ�����ࣺ1��������ͼ��2��������ͼ" << endl;
	int kind;
	cin >> kind;
	//�ж������kind�Ƿ�Ϸ�
	while (1) {
		if (kind == 1 || kind == 2) {
			break;
		}
		else {
			cout << "�����ͼ�������Ų��Ϸ������������룺1��������ͼ��2��������ͼ" << endl;
			cin >> kind;
		}
	}

	cout << "����ͼ�Ķ�������ͱߵ�������" << endl;
	cin >> vexnum >> edge;
	while (!check(vexnum, edge)) {
		cout << "�������ֵ���Ϸ�������������" << endl;
		cin >> vexnum >> edge;
	}
	Graph_DG graph(vexnum, edge);
	graph.createGraph(kind);
	graph.print();
	graph.Floyd();
	graph.print_path();

	system("pause");
	return 0;
}
