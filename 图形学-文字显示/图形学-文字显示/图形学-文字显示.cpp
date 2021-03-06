// 图形学-文字显示.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
/////////////////////////////////////////////
//main.cpp
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

//声明函数原型
void Drawing();
void DrawPolygon(int, int);
void OnMouse(int, int, int, int);
void OnKeyboard(unsigned char, int, int);

void Initialization();
void OnDisplay();
void OnReshape(int, int);

void drawString(const char* str);

//全局变量
int winWidth(500), winHeight(500);

#define MAX_CHAR 128


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);			//初始化opengl
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(110, 110);	//窗口位置
	glutInitWindowSize(500, 500);	//窗口大小
	glutCreateWindow("Demo");	//创建并显示窗口

	Initialization();
	glutDisplayFunc(OnDisplay);		//设置回调函数
	glutReshapeFunc(OnReshape);		//重绘函数

	glutMainLoop();					//opengl主循环
	return 0;
}

//绘图函数
void Drawing()
{
}

//显示回调函数
void OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Drawing();

	glColor3f(0.0f, 0.0f, 0.0f);	 //设置字体颜色
	glRasterPos2i(0, winHeight - 15);  //起始位置
	drawString("  Hello，OpenGL.");	 //输出的字符串

	glutSwapBuffers();			  //交换前后缓存区
}

void Initialization()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //设置背景色为白色
}

//重绘回调函数
void OnReshape(int w, int h)
{
	winWidth = w;
	winHeight = h;

	glViewport(0, 0, w, h);			//设置视区大小

	glMatrixMode(GL_PROJECTION);	//投影模式
	glLoadIdentity();				//载入单位矩阵以初始化当前矩阵

	gluOrtho2D(0, w, 0, h);	//将当前绘图区域设置为二维正交投影

	glMatrixMode(GL_MODELVIEW);		//模型视图模式
	glLoadIdentity();				//初始化当前矩阵
}

void drawString(const char* str) //屏幕显示字体
{
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall) {
		isFirstCall = 0;
		// 申请MAX_CHAR个连续的显示列表编号
		lists = glGenLists(MAX_CHAR);
		// 把每个字符的绘制命令都装到对应的显示列表中
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// 调用每个字符对应的显示列表，绘制每个字符
	for (; *str != '\0'; ++str) {
		glCallList(lists + *str);
	}
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
