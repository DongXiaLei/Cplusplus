#include "pch.h"

#include <GL/glut.h>
#include <iostream>
using namespace std;
#include <cmath>
const int n = 200;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;
const GLfloat factor = 0.31415f;
void myDisplay1(void)//����ǡ�
{
	glColor3f(1.0f, 1.0f, 1.0f);
	GLfloat a = 1 / (2 - 2 * cos(72 * Pi / 180));
	GLfloat bx = a * cos(18 * Pi / 180);
	GLfloat by = a * sin(18 * Pi / 180);
	GLfloat cy = -a * cos(18 * Pi / 180);
	GLfloat
		PointA[2] = { 0, a },
		PointB[2] = { bx, by },
		PointC[2] = { 0.5, cy },
		PointD[2] = { -0.5, cy },
		PointE[2] = { -bx, by };

	glClear(GL_COLOR_BUFFER_BIT);
	// ����A->C->E->B->D->A��˳�򣬿���һ�ʽ�����ǻ���
	glBegin(GL_LINE_LOOP);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();
	glFlush();
}
void myDisplay2(void)//һ��Բ
{
	int i;
	//glPointSize(5.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for (i = 0; i < n; ++i)
		glVertex2f(R*cos(2 * Pi / n * i), R*sin(2 * Pi / n * i));
	glEnd();
	glFlush();
}
void myDisplay(void)//���ߣ����Ϊ2

{

	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_LINE_STIPPLE);

	glLineStipple(2, 0x0F0F);

	glLineWidth(10.0f);

	glBegin(GL_LINES);

	glVertex2f(0.0f, 0.0f);

	glVertex2f(0.5f, 0.5f);

	glEnd();

	glFlush();

}
void myDisplay3(void)//������

{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 1.0f);
	glLineWidth(5.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);

	glFlush();

}
void myDisplay4(void)//���Һ�������
{
	GLfloat x;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);         // ������������Ի�x��
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);         // ������������Ի�y��
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (x = -1.0f / factor; x < 1.0f / factor; x += 0.01f)
	{
		glVertex2f(x*factor, sin(x)*factor);
	}
	glEnd();
	glFlush();
}
void myDisplay5(void)//������

{

	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0f);

	glBegin(GL_POINTS);

	glVertex2f(0.0f, 0.0f);

	glVertex2f(0.5f, 0.5f);

	glEnd();

	glFlush();

}
void myDisplay6(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT, GL_FILL); // ��������Ϊ���ģʽ

	glPolygonMode(GL_BACK, GL_LINE);   // ���÷���Ϊ����ģʽ

	glFrontFace(GL_CCW);               // ������ʱ�뷽��Ϊ����

	glBegin(GL_POLYGON);               // ����ʱ�����һ�������Σ������·�

	glVertex2f(-0.5f, -0.5f);

	glVertex2f(0.0f, -0.5f);

	glVertex2f(0.0f, 0.0f);

	glVertex2f(-0.5f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);               // ��˳ʱ�����һ�������Σ������Ϸ�

	glVertex2f(0.0f, 0.0f);

	glVertex2f(0.0f, 0.5f);

	glVertex2f(0.5f, 0.5f);

	glVertex2f(0.5f, 0.0f);

	glEnd();

	glFlush();
}
void myDisplay7(void)

{
	int i;
	// glShadeModel(GL_FLAT);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	for (i = 0; i <= 8; ++i)
	{
		glColor3f(i & 0x04, i & 0x02, i & 0x01);
		glVertex2f(cos(i*Pi / 4), sin(i*Pi / 4));
	}
	glEnd();
	glFlush();
	

}
void myDisplay8(void)
{

}
static int day = 180; // day�ı仯����0��359
void myDisplay9(void)
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 400000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

	// ���ƺ�ɫ�ġ�̫����
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600000, 20, 20);
	// ������ɫ�ġ�����
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(150000000, 0.0f, 0.0f);
	glutSolidSphere(15945000, 20, 20);
	// ���ƻ�ɫ�ġ�������
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day / 30.0*360.0 - day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000000, 0.0f, 0.0f);
	glutSolidSphere(4345000, 20, 20);

	glFlush();
}
int main(int argc, char *argv[])

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);

	glutInitWindowSize(400, 400);

	glutCreateWindow("��һ��OpenGL����");

	glutDisplayFunc(&myDisplay9);

	glutMainLoop();

	return 0;

}