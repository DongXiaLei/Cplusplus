// 图形学-旋转平移缩放.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。




#include "pch.h"
#include <gl/glut.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>


float fTranslate[2] = { 0,0 };//平移因子
float fRotate;//旋转因子
float fScale = 1.0f;//缩放因子

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
	Draw_Cube(0.0, 1.0, 0.0, 0.8, 0.6, 0.8);//桌面
	Draw_Cube(0.1, 0.3, 0.1, 0.3, 0.0, 0.6);//四条腿
	Draw_Cube(0.7, 0.9, 0.1, 0.3, 0.0, 0.6);
	Draw_Cube(0.1, 0.3, 0.5, 0.7, 0.0, 0.6);
	Draw_Cube(0.7, 0.9, 0.5, 0.7, 0.0, 0.6);
}

void idle()
{
	glutPostRedisplay();//重新显示
}
void reshape(int width, int height)
{
	//当窗口尺寸改变时改变尺寸
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}
	glViewport(0, 0, width, height);						// 重置视角

	glMatrixMode(GL_PROJECTION);						// 选择影射矩阵
	glLoadIdentity();									//重置影射矩阵

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// 选择Modelview视角矩阵
	glLoadIdentity();									//重置Modelview视角矩阵
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口
	//模型变换——旋转
	glPushMatrix();
	//glTranslatef(-0.5f, -0.5f, -6.0f);//初始位置
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(.0f, .0f, .0f, .0f); //设置背景色为白色
	//glTranslatef(1.0f, 0.0f, 0.0f);//放在左边
	//glRectf(-0.5, -0.5, 0.5, 0.5);
	
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		Draw_Table();
	}
	
	glPopMatrix();
	
	//glutSwapBuffers();
	//glutIdleFunc(idle);
	glFlush();
}

void Twist()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口
	//模型变换——旋转
	glPushMatrix();
	glTranslatef(-0.5f, -0.5f, -6.0f);//初始位置
	glTranslatef(fTranslate[1], fTranslate[0], 0.0f);
	glRotatef(fRotate, -0.0, 1.0f, 0);			// Rotate around Y axis
	glScalef(fScale, fScale, fScale);
	Draw_Table();
	glPopMatrix();

	for (int i = 0; i < 2; i++)
	{
		if (fTranslate[i] > 1.5f)
			fTranslate[i] = 0.0f;
	}
	//fRotate += 10.0f;
	if (fScale < 0.3f)//缩小到一定程度之后变回原来大小
		fScale = 1.0f;
	glutIdleFunc(idle);
	glutSwapBuffers();
}
bool leftButtonState;
bool rightButtonState;
void MousePressEvent(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			fRotate += 10.0f;
			//fTranslate[0] = 0;
			//fTranslate[1] = 0;
			//fScale = 1.0f;
			Twist();
			leftButtonState = true;
		}
		else
		{
			leftButtonState = false;
		}
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			rightButtonState = true;
		}
		else
		{
			rightButtonState = false;
		}
	}

}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 033: // Escape Key
	case 'w': case 'W':
		fTranslate[0] += 0.1f;
		//fScale = 1.0f;
		Twist();
		break;
	case 'a': case 'A':
		fTranslate[1] -= 0.1f;
		//fScale = 1.0f;
		Twist();
		break;
	case 's': case 'S':
		fTranslate[0] -= 0.1f;
		//fScale = 1.0f;
		Twist();
		break;
	case 'd': case 'D':
		fTranslate[1] += 0.1f;
		//fScale = 1.0f;
		Twist();
		break;
	case 'z': case 'Z':
		fScale -= 0.01f;
		//fTranslate[0] = 0;
		//fTranslate[1] = 0;
		Twist();
		break;
	case 'x': case 'X':
		fScale += 0.01f;
		//fTranslate[0] = 0;
		//fTranslate[1] = 0;
		Twist();
		
		break;
	case 'q': case 'Q':
		exit(EXIT_SUCCESS);
		break;
	}
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);//对glut函数库进行初始化
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);//指定glutCreateWindow函数将要创建的窗口显示模式 RGB 双缓冲
	glutInitWindowSize(640, 400);//窗口大小
	glutInitWindowPosition(600, 300);
	glutCreateWindow("图形学实验一");//打开设置好的窗口，进入glutMainLoop之前这个窗口不会显示

	glutDisplayFunc(display);//显示  指定当前窗口需要重绘时调用的函数
	glutReshapeFunc(reshape);//重绘   注册窗口大小改变时，回调函数，必须要
	glutMouseFunc(MousePressEvent);
	glutKeyboardFunc(keyboard);

	glutMainLoop();//进入glut事件处理循环，永远不会返回
	system("pause");
	return 0;
}
/*
void redraw()
{
	//display in wireframe mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口
	glLoadIdentity();						// 重置Modelview视角矩阵
	//模型变换——移动
	glPushMatrix();   //glpushmatrix与glpopmatrix配合使用可以消除上一次变换对本次变换的影响
	glTranslatef(-2.5f, -0.8f, -6.0f);//放在左边
	glTranslatef(0.0f, fTranslate[0], 0.0f);
	Draw_Table();
	glPopMatrix();
	//模型变换——旋转
	glPushMatrix();
	glTranslatef(0.0f, -1.5f, -6.0f);//放在中间
	glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
	Draw_Table();						// Draw triangle
	glPopMatrix();
	//模型变换——缩放
	glPushMatrix();
	glTranslatef(2.0f, 0.0f, -6.0f);
	glScalef(fScale, fScale, fScale);
	Draw_Table();
	glPopMatrix();
	//更新因子
	fTranslate[0] += 0.0001f;
	fRotate += 0.01f;
	fScale -= 0.0001f;

	if (fTranslate[0] > 1.5f)
		fTranslate[0] = 0.0f;
	if (fScale < 0.3f)//缩小到一定程度之后变回原来大小
		fScale = 1.0f;
	glutSwapBuffers();
}
*/





/*
#include"GL/glut.h"
#include<memory>
#include "RoamingScenceManager.h"

void MousePressEvent(int button, int state, int x, int y);
void MouseMoveEvent(int x, int y);
void ProcessSpecialKeys(int key, int x, int y);

void reshape(int w, int h);
void display();

bool leftButtonState;
bool rightButtonState;

//#define  GLUT_WHEEL_UP 3           //定义滚轮操作
//#define  GLUT_WHEEL_DOWN 4

std::auto_ptr<RoamingScenceManager> manager(new RoamingScenceManager());


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("原生OpenGL");
	manager->init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(MousePressEvent);
	glutMotionFunc(MouseMoveEvent);
	glutSpecialFunc(ProcessSpecialKeys);
	glutMainLoop();
	return 0;

}

void display()
{
	manager->render();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, -(w - h) / 2, w, w);
}

void MousePressEvent(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			manager->getInitPos(x, y);
			leftButtonState = true;
		}
		else
		{
			leftButtonState = false;
		}
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			manager->getInitPos(x, y);
			rightButtonState = true;
		}
		else
		{
			rightButtonState = false;
		}
	}

}

void MouseMoveEvent(int x, int y)
{
	if (leftButtonState)
	{
		manager->executeRotateOperation(x, y);
	}
	if (rightButtonState)
	{
		manager->executeTranslateOperation(x, y);
	}
	display();
}

void ProcessSpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		manager->executeScaleOperation(-0.1);
	}
	if (key == GLUT_KEY_DOWN)
	{
		manager->executeScaleOperation(0.1);
	}
	display();
}






*/
/*


#include "pch.h"


#include<GL/glut.h>
#include <windows.h>



static GLfloat spin = 0.0;				//旋转量
static GLfloat move = 0.0;				//平移量
static GLfloat size = 1.0;				//缩放量

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);		//指定清除颜色（黑色），即背景颜色
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		//清除所有的像素
	glPushMatrix();
	glTranslatef(move, 0, 0);				//移动，参数含义(x轴位移,y轴位移,z轴位移)
	glRotatef(spin, 0, 0, 1);				//旋转，参数含义(旋转量,x轴,y轴,z轴)
	glScalef(size, size, 1);				//缩放，参数含义(x轴倍数,y轴倍数,z轴倍数)
	glColor3f(0.0, 1.0, 0.0);				//绘制颜色RGB
	glRectf(-10.0, -10.0, 10.0, 10.0);		//绘制矩形
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void SpinDisplay()
{
	spin > 360 ? spin -= 360 : spin += 2;
	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
	Sleep(20);
}
void SizeDisplay()
{
	size > 2 ? size -= 2 : size += 0.003;
	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
	Sleep(20);
}
void MoveDisplay()
{
	move = move > 20 ? move -= 20 : move += 1;
	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
	Sleep(20);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);							//初始化GLUT并处理命令行参数
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);		//指定模式：双缓存；RGB模式
	glutInitWindowSize(500, 500);					//指定窗口大小（像素）
	glutInitWindowPosition(300, 200);				//指定窗口左上角在屏幕上的位置
	glutCreateWindow(argv[0]);						//使用OpenGL场景创建一个窗口，参数为窗口名称
	init();											//调用初始化函数
	glutDisplayFunc(display);						//显示
	glutReshapeFunc(reshape);						//重绘
	glutIdleFunc(SizeDisplay);						      //缩放
	//glutIdleFunc(SpinDisplay);                          //旋转
	//glutIdleFunc(MoveDisplay);						  //移动(与上边函数只能有一个有效)
	glutMainLoop();									//进入主循环并处理事件，此时创建的所有窗口都会显示出来，被渲染到这些窗口中的内容也将显示出来，程序开始处理事件，注册的显示回调函数被触发
	return 0;										//ANSI C要求函数main()返回一个int值
}

*/

