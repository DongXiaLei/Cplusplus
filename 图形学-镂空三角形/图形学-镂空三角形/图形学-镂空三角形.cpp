// 图形学-镂空三角形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <time.h>
#include <math.h>

void init()
{
	glClearColor(1, 1, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 50, 0, 50, -1, 1);
}

void display()
{
	//三个增向量
	GLfloat vertices[3][3] = { {0.0,0.0,0.0}, {25.0, 50.0, 0.0}, {50.0, 0.0, 0.0} };
	GLfloat p[3] = { 0,0,0 };

	glBegin(GL_POINTS);
	glPointSize(3);

	for (int i = 0; i < 5000; ++i) {
		int x = rand() % 3;

		p[0] = (p[0] + vertices[x][0]) / 2;
		p[1] = (p[1] + vertices[x][1]) / 2;

		glVertex3fv(p);
	}
	glEnd();
	glutSwapBuffers();
}

int main1(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Sierpinski");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

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
