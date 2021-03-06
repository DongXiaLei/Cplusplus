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
GLfloat AngleZ;
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
		glRotatef(AngleX, 1.0f, 0.0f, 0.0f);//按照三个坐标轴旋转
		glRotated(AngleY, 0.0f, 1.0f, 0.0f);
		glScalef(sca[0], sca[1], sca[2]);//放大
		glTranslatef(tra[0], tra[1], tra[2]);//平移三个坐标轴方向上

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f, 1.0f, 1.0f);
		glutWireSphere(18, 14, 14);
		glutWireCone(30, 40, 30, 30);
		glEnd();
	}
	glPopMatrix();

	glutSwapBuffers();
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

void Skeyboard(GLint key, GLint x, GLint y) {
	if (key == GLUT_KEY_UP)
		AngleX -= 5.0f;
	if (key == GLUT_KEY_DOWN)
		AngleX += 5.0f;
	if (key == GLUT_KEY_LEFT)
		AngleY -= 5.0f;
	if (key == GLUT_KEY_RIGHT)
		AngleY += 5.0f;


	if (AngleX > 355.0f)//缩小到一定程度之后变回原来大小
		AngleX = 0.0f;
	if (AngleX < 0.0f)
		AngleX = 355.0f;


	glutPostRedisplay();
}


void Nkeyboard(unsigned char key, int x, int y) {
	if (key == 'j') {
		for (int i = 0; i < 3; i++)
			sca[i] += 0.1;
	}
	if (key == 'k') {
		for (int i = 0; i < 3; i++)
			sca[i] -= 0.1;
	}
	if (key == 'w') {
		tra[1]++;
	}
	if (key == 's') {
		tra[1]--;
	}
	if (key == 'a') {
		tra[0]--;
	}
	if (key == 'd') {
		tra[0]++;
	}
	if (key = 'q') {
		tra[2]++;
	}
	if (key = 'e') {
		tra[2]--;
	}

	glutPostRedisplay();//回显函数
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

	glutReshapeFunc(reshape);//重绘   注册窗口大小改变时，回调函数，必须要
	glutDisplayFunc(display);//显示  指定当前窗口需要重绘时调用的函数
	glutSpecialFunc(Skeyboard);
	glutKeyboardFunc(Nkeyboard);

	init();
	glutMainLoop();//进入glut事件处理循环，永远不会返回
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
