// 图形学-变换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>

// 太阳、地球和月亮
// 假设每个月都是12天
// 一年12个月，共是360天
static int day = 200; // day的变化：从0到359

double CalFrequency()
{
	static int count;
	static double save;
	static clock_t last, current;
	double timegap;

	++count;
	if (count <= 50)
		return save;
	count = 0;
	last = current;
	current = clock();
	timegap = (current - last) / (double)CLK_TCK;
	save = 50.0 / timegap;
	return save;
}

void myDisplay(void)
{
	double FPS = CalFrequency();
	printf("FPS = %f\n", FPS);

	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 400000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

	// 绘制红色的“太阳”
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600000, 20, 20);
	// 绘制蓝色的“地球”
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(150000000, 0.0f, 0.0f);
	glutSolidSphere(15945000, 20, 20);
	// 绘制黄色的“月亮”
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day / 30.0*360.0 - day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000000, 0.0f, 0.0f);
	glutSolidSphere(4345000, 20, 20);

	glFlush();
	glutSwapBuffers();
}

void myIdle(void)
{
	++day;
	if (day >= 360)
		day = 0;
	myDisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("太阳，地球和月亮");
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);
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
