// C++程序设计-文件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*

#include "pch.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	char ch;
	char s[15];
	FILE* fp;
	if ((fp = fopen("file", "a+")) == NULL)
		cout << "open error!";
	//fputs("hqhdqhq", fp);
	ch = fgetc(fp);
	while (ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	cout << ch<<endl;
	fgets(s, 15, fp);
	cout << s;
	std::cout << "Hello World!\n";


}
*/
#include "pch.h"
#include<iostream>
#include<fstream>
using namespace std;

int main() 
{
	ofstream file;
	file.open("input.txt");//无则新建
	file << "aaaaaaaa\nbbbbbbbb\ncccccccc";//输入内容
	file.close();

	ifstream filei("input.txt");
	ofstream fileo;
	fileo.open("output.txt");

	char c;
	filei >> noskipws;//不忽略换行符
	int i = 1;
	fileo << i << " ";
	cout << i << " ";
	while (filei >> c) {//从文件中读取到输入流
		if (c == '\n') {
			i++;
			fileo << "\n";
			cout << "\n";
			fileo << i << " ";
			cout << i << " ";
		}
		else {
			fileo << c;//输出流写入文件
			cout << c;
		}
	}
	filei.close();
	fileo.close();

	return 0;
}

