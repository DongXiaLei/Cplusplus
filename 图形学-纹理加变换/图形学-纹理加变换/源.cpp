#include "pch.h"
#include <gl/glut.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>


// 图形学-三变换-第三次作业.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
// 图形学-变换移动.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#define GLUT_DISABLE_ATEXIT_HACK

// ASCII字符总共只有0到127，一共128种字符
#define MAX_CHAR       128
#define GLUT_DISABLE_ATEXIT_HACK
//显示字符串，不能显示中文只能显示ASC码
void drawString(const char* str) {
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall) { // 如果是第一次调用，执行初始化
						// 为每一个ASCII字符产生一个显示列表
		isFirstCall = 0;

		// 申请MAX_CHAR个连续的显示列表编号
		lists = glGenLists(MAX_CHAR);

		// 把每个字符的绘制命令都装到对应的显示列表中
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// 调用每个字符对应的显示列表，绘制每个字符
	for (; *str != '\0'; ++str)
		glCallList(lists + *str);
}


GLfloat AngleX;
GLfloat AngleY;
GLfloat sca[3] = { 1.5,1.5,1.5 };
GLfloat tra[3] = { 0,0,0 };

//自己定义的小桌子，比较丑，故用预定义的
void Draw_Cube(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, GLfloat z1, GLfloat z2)
{	//桌子由立方体组成，已知六个参数即可构造八个顶点
	int i, j;
	GLfloat vertex[8][3] = {
		//八个顶点，从v1-v8
		x1,y1,z2,
		x2,y1,z2,
		x1,y2,z2,
		x2,y2,z2,
		x1,y1,z1,
		x2,y1,z1,
		x1,y2,z1,
		x2,y2,z1
	};
	GLint surface[6][4] = {
		//v1对应0,以此类推
		0,1,3,2,
		4,5,7,6,
		2,3,7,6,
		0,1,5,4,
		0,2,6,4,
		1,3,7,5
	};

	glBegin(GL_QUADS);//指定绘制方式
	//将每个立方体分成六个面绘制
	for (i = 0; i < 6; i++)
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	glEnd();
}
void Draw_Table()
{

	//将桌子拆分成5个立方体绘制
	Draw_Cube(0.0, 50.0, 0.0, 40, 30, 40);//桌面
	Draw_Cube(5, 15, 5, 15, 0.0, 30);//四条腿
	Draw_Cube(35, 45, 5, 15, 0, 30);
	Draw_Cube(5, 15, 25, 35, 0, 30);
	Draw_Cube(35, 45, 25, 35, 0, 30);
}



void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//恢复单位矩阵

	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(-30.0f, 65.0f);//位置中心点为（0，0）
	drawString("2016301500159_DongXiaLei");

	glPushMatrix();
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glRotatef(AngleX, 1.0f, 0.0f, 0.0f);//按照三个坐标轴旋转
		glRotated(AngleY, 0.0f, 1.0f, 0.0f);
		
		
		glColor3f(1.0f, 1.0f, 1.0f);
		Draw_Cube(0.0, 50.0, 0.0, 50, 0, 50);//桌面

	}
	glPopMatrix();

	glutSwapBuffers();
}
void DrawGLScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 清除屏幕和深度缓存
	glLoadIdentity();	// 重置当前的模型观察矩阵
	//添加绘图代码
	glTranslatef(-1.5f, 0.0f, -6.0f);	// 左移 1.5 单位，并移入屏幕 6.0
	glRotatef(30.0f, 0.0f, 1.0f, 0.0f);	// 绕Y轴旋转金字塔
	glBegin(GL_TRIANGLES);	// 绘制三角形
		//开启平滑着色模式
	glColor3f(1.0f, 0.0f, 0.0f);		// 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	// 三角形的上顶点 (前侧面)
	glColor3f(0.0f, 1.0f, 0.0f);		// 绿色
	glVertex3f(-1.0f, -1.0f, 1.0f);	// 三角形的左下顶点 (前侧面)
	glColor3f(0.0f, 0.0f, 1.0f);		// 蓝色
	glVertex3f(1.0f, -1.0f, 1.0f);	// 三角形的右下顶点 (前侧面)

	glColor3f(1.0f, 0.0f, 0.0f);		// 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	// 三角形的上顶点 (右侧面)
	glColor3f(0.0f, 0.0f, 1.0f);		// 蓝色
	glVertex3f(1.0f, -1.0f, 1.0f);	// 三角形的左下顶点 (右侧面)
	glColor3f(0.0f, 1.0f, 0.0f);		// 绿色
	glVertex3f(1.0f, -1.0f, -1.0f);	// 三角形的右下顶点 (右侧面)

	glColor3f(1.0f, 0.0f, 0.0f);		// 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	// 三角形的上顶点 (后侧面)
	glColor3f(0.0f, 1.0f, 0.0f);		// 绿色
	glVertex3f(1.0f, -1.0f, -1.0f);	// 三角形的左下顶点 (后侧面)
	glColor3f(0.0f, 0.0f, 1.0f);		// 蓝色
	glVertex3f(-1.0f, -1.0f, -1.0f);	// 三角形的右下顶点 (后侧面)

	glColor3f(1.0f, 0.0f, 0.0f);		// 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	// 三角形的上顶点 (左侧面)
	glColor3f(0.0f, 0.0f, 1.0f);		// 蓝色
	glVertex3f(-1.0f, -1.0f, -1.0f);	// 三角形的左下顶点 (左侧面)
	glColor3f(0.0f, 1.0f, 0.0f);		// 绿色
	glVertex3f(-1.0f, -1.0f, 1.0f);	// 三角形的右下顶点 (左侧面)
	glEnd();

	glLoadIdentity();	// 重置当前的模型观察矩阵
	glTranslatef(1.50f, 0.0f, -7.0f);	// 右移1.5单位，并移入屏幕6个单位
	glRotatef(30.0f, 1.0f, 1.0f, 1.0f);	// 绕XYZ轴旋转立方体
	glBegin(GL_QUADS);		//  绘制立方体
		//开启单调着色模式，保证立方体的每个面的颜色都不同
	glColor3f(0.0f, 1.0f, 0.0f);		// 一次性将当前色设置为绿色
	glVertex3f(1.0f, 1.0f, -1.0f);	// 四边形的右上顶点 (顶面)
	glVertex3f(-1.0f, 1.0f, -1.0f);	// 四边形的左上顶点 (顶面)
	glVertex3f(-1.0f, 1.0f, 1.0f);	// 四边形的左下顶点 (顶面)
	glVertex3f(1.0f, 1.0f, 1.0f);	// 四边形的右下顶点 (顶面)

	glColor3f(1.0f, 0.5f, 0.0f);		// 颜色改成橙色
	glVertex3f(1.0f, -1.0f, 1.0f);	// 四边形的右上顶点(底面)
	glVertex3f(-1.0f, -1.0f, 1.0f);	// 四边形的左上顶点(底面)
	glVertex3f(-1.0f, -1.0f, -1.0f);	// 四边形的左下顶点(底面)
	glVertex3f(1.0f, -1.0f, -1.0f);	// 四边形的右下顶点(底面)

	glColor3f(1.0f, 0.0f, 0.0f);		// 颜色改成红色
	glVertex3f(1.0f, 1.0f, 1.0f);	// 四边形的右上顶点(前面)
	glVertex3f(-1.0f, 1.0f, 1.0f);	// 四边形的左上顶点(前面)
	glVertex3f(-1.0f, -1.0f, 1.0f);	// 四边形的左下顶点(前面)
	glVertex3f(1.0f, -1.0f, 1.0f);	// 四边形的右下顶点(前面)

	glColor3f(1.0f, 1.0f, 0.0f);		// 颜色改成黄色
	glVertex3f(1.0f, -1.0f, -1.0f);	// 四边形的右上顶点(后面)
	glVertex3f(-1.0f, -1.0f, -1.0f);	// 四边形的左上顶点(后面)
	glVertex3f(-1.0f, 1.0f, -1.0f);	// 四边形的左下顶点(后面)
	glVertex3f(1.0f, 1.0f, -1.0f);	// 四边形的右下顶点(后面)

	glColor3f(0.0f, 0.0f, 1.0f);		// 颜色改成蓝色
	glVertex3f(-1.0f, 1.0f, 1.0f);	// 四边形的右上顶点(左面)
	glVertex3f(-1.0f, 1.0f, -1.0f);	// 四边形的左上顶点(左面)
	glVertex3f(-1.0f, -1.0f, -1.0f);	// 四边形的左下顶点(左面)
	glVertex3f(-1.0f, -1.0f, 1.0f);	// 四边形的右下顶点(左面)

	glColor3f(1.0f, 0.0f, 1.0f);		// 颜色改成紫罗兰色
	glVertex3f(1.0f, 1.0f, -1.0f);	// 四边形的右上顶点(右面)
	glVertex3f(1.0f, 1.0f, 1.0f);	// 四边形的左上顶点(右面)
	glVertex3f(1.0f, -1.0f, 1.0f);	// 四边形的左下顶点(右面)
	glVertex3f(1.0f, -1.0f, -1.0f);	// 四边形的右下顶点(右面)
	glEnd();	// 立方体绘制结束

	return ;	//  一切 OK
}

void reshape(int w, int h) {
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	GLfloat nRange = 100.0f;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h) {
		glOrtho(-nRange, nRange, -nRange * aspect, nRange*aspect, -nRange, nRange);//确定图形不会变形
	}
	else
		glOrtho(-nRange, nRange, -nRange / aspect, nRange / aspect, -nRange, nRange);
}


void init() {
	AngleX = 45.0f;
	AngleY = 315.f;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//设置背景为黑

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DITHER);
	glShadeModel(GL_SMOOTH);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);//对glut函数库进行初始化 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);;//指定glutCreateWindow函数将要创建的窗口显示模式 RGB 双缓冲
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("图形学");//打开设置好的窗口，进入glutMainLoop之前这个窗口不会显示
	glEnable(GL_TEXTURE_2D);    // 启用纹理
	glutReshapeFunc(reshape);//重绘   注册窗口大小改变时，回调函数，必须要
	glutDisplayFunc(DrawGLScene);//显示  指定当前窗口需要重绘时调用的函数

	init();
	glutMainLoop();//进入glut事件处理循环，永远不会返回
	return 0;
}


