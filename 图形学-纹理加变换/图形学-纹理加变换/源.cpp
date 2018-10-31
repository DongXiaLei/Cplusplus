#include "pch.h"
#include <gl/glut.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>


// ͼ��ѧ-���任-��������ҵ.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"
// ͼ��ѧ-�任�ƶ�.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"
#include <iostream>
#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#define GLUT_DISABLE_ATEXIT_HACK

// ASCII�ַ��ܹ�ֻ��0��127��һ��128���ַ�
#define MAX_CHAR       128
#define GLUT_DISABLE_ATEXIT_HACK
//��ʾ�ַ�����������ʾ����ֻ����ʾASC��
void drawString(const char* str) {
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall) { // ����ǵ�һ�ε��ã�ִ�г�ʼ��
						// Ϊÿһ��ASCII�ַ�����һ����ʾ�б�
		isFirstCall = 0;

		// ����MAX_CHAR����������ʾ�б���
		lists = glGenLists(MAX_CHAR);

		// ��ÿ���ַ��Ļ������װ����Ӧ����ʾ�б���
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// ����ÿ���ַ���Ӧ����ʾ�б�����ÿ���ַ�
	for (; *str != '\0'; ++str)
		glCallList(lists + *str);
}


GLfloat AngleX;
GLfloat AngleY;
GLfloat sca[3] = { 1.5,1.5,1.5 };
GLfloat tra[3] = { 0,0,0 };

//�Լ������С���ӣ��Ƚϳ󣬹���Ԥ�����
void Draw_Cube(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, GLfloat z1, GLfloat z2)
{	//��������������ɣ���֪�����������ɹ���˸�����
	int i, j;
	GLfloat vertex[8][3] = {
		//�˸����㣬��v1-v8
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
		//v1��Ӧ0,�Դ�����
		0,1,3,2,
		4,5,7,6,
		2,3,7,6,
		0,1,5,4,
		0,2,6,4,
		1,3,7,5
	};

	glBegin(GL_QUADS);//ָ�����Ʒ�ʽ
	//��ÿ��������ֳ����������
	for (i = 0; i < 6; i++)
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	glEnd();
}
void Draw_Table()
{

	//�����Ӳ�ֳ�5�����������
	Draw_Cube(0.0, 50.0, 0.0, 40, 30, 40);//����
	Draw_Cube(5, 15, 5, 15, 0.0, 30);//������
	Draw_Cube(35, 45, 5, 15, 0, 30);
	Draw_Cube(5, 15, 25, 35, 0, 30);
	Draw_Cube(35, 45, 25, 35, 0, 30);
}



void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//�ָ���λ����

	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(-30.0f, 65.0f);//λ�����ĵ�Ϊ��0��0��
	drawString("2016301500159_DongXiaLei");

	glPushMatrix();
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glRotatef(AngleX, 1.0f, 0.0f, 0.0f);//����������������ת
		glRotated(AngleY, 0.0f, 1.0f, 0.0f);
		
		
		glColor3f(1.0f, 1.0f, 1.0f);
		Draw_Cube(0.0, 50.0, 0.0, 50, 0, 50);//����

	}
	glPopMatrix();

	glutSwapBuffers();
}
void DrawGLScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �����Ļ����Ȼ���
	glLoadIdentity();	// ���õ�ǰ��ģ�͹۲����
	//��ӻ�ͼ����
	glTranslatef(-1.5f, 0.0f, -6.0f);	// ���� 1.5 ��λ����������Ļ 6.0
	glRotatef(30.0f, 0.0f, 1.0f, 0.0f);	// ��Y����ת������
	glBegin(GL_TRIANGLES);	// ����������
		//����ƽ����ɫģʽ
	glColor3f(1.0f, 0.0f, 0.0f);		// ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	// �����ε��϶��� (ǰ����)
	glColor3f(0.0f, 1.0f, 0.0f);		// ��ɫ
	glVertex3f(-1.0f, -1.0f, 1.0f);	// �����ε����¶��� (ǰ����)
	glColor3f(0.0f, 0.0f, 1.0f);		// ��ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	// �����ε����¶��� (ǰ����)

	glColor3f(1.0f, 0.0f, 0.0f);		// ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	// �����ε��϶��� (�Ҳ���)
	glColor3f(0.0f, 0.0f, 1.0f);		// ��ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	// �����ε����¶��� (�Ҳ���)
	glColor3f(0.0f, 1.0f, 0.0f);		// ��ɫ
	glVertex3f(1.0f, -1.0f, -1.0f);	// �����ε����¶��� (�Ҳ���)

	glColor3f(1.0f, 0.0f, 0.0f);		// ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	// �����ε��϶��� (�����)
	glColor3f(0.0f, 1.0f, 0.0f);		// ��ɫ
	glVertex3f(1.0f, -1.0f, -1.0f);	// �����ε����¶��� (�����)
	glColor3f(0.0f, 0.0f, 1.0f);		// ��ɫ
	glVertex3f(-1.0f, -1.0f, -1.0f);	// �����ε����¶��� (�����)

	glColor3f(1.0f, 0.0f, 0.0f);		// ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	// �����ε��϶��� (�����)
	glColor3f(0.0f, 0.0f, 1.0f);		// ��ɫ
	glVertex3f(-1.0f, -1.0f, -1.0f);	// �����ε����¶��� (�����)
	glColor3f(0.0f, 1.0f, 0.0f);		// ��ɫ
	glVertex3f(-1.0f, -1.0f, 1.0f);	// �����ε����¶��� (�����)
	glEnd();

	glLoadIdentity();	// ���õ�ǰ��ģ�͹۲����
	glTranslatef(1.50f, 0.0f, -7.0f);	// ����1.5��λ����������Ļ6����λ
	glRotatef(30.0f, 1.0f, 1.0f, 1.0f);	// ��XYZ����ת������
	glBegin(GL_QUADS);		//  ����������
		//����������ɫģʽ����֤�������ÿ�������ɫ����ͬ
	glColor3f(0.0f, 1.0f, 0.0f);		// һ���Խ���ǰɫ����Ϊ��ɫ
	glVertex3f(1.0f, 1.0f, -1.0f);	// �ı��ε����϶��� (����)
	glVertex3f(-1.0f, 1.0f, -1.0f);	// �ı��ε����϶��� (����)
	glVertex3f(-1.0f, 1.0f, 1.0f);	// �ı��ε����¶��� (����)
	glVertex3f(1.0f, 1.0f, 1.0f);	// �ı��ε����¶��� (����)

	glColor3f(1.0f, 0.5f, 0.0f);		// ��ɫ�ĳɳ�ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	// �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, 1.0f);	// �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, -1.0f);	// �ı��ε����¶���(����)
	glVertex3f(1.0f, -1.0f, -1.0f);	// �ı��ε����¶���(����)

	glColor3f(1.0f, 0.0f, 0.0f);		// ��ɫ�ĳɺ�ɫ
	glVertex3f(1.0f, 1.0f, 1.0f);	// �ı��ε����϶���(ǰ��)
	glVertex3f(-1.0f, 1.0f, 1.0f);	// �ı��ε����϶���(ǰ��)
	glVertex3f(-1.0f, -1.0f, 1.0f);	// �ı��ε����¶���(ǰ��)
	glVertex3f(1.0f, -1.0f, 1.0f);	// �ı��ε����¶���(ǰ��)

	glColor3f(1.0f, 1.0f, 0.0f);		// ��ɫ�ĳɻ�ɫ
	glVertex3f(1.0f, -1.0f, -1.0f);	// �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, -1.0f);	// �ı��ε����϶���(����)
	glVertex3f(-1.0f, 1.0f, -1.0f);	// �ı��ε����¶���(����)
	glVertex3f(1.0f, 1.0f, -1.0f);	// �ı��ε����¶���(����)

	glColor3f(0.0f, 0.0f, 1.0f);		// ��ɫ�ĳ���ɫ
	glVertex3f(-1.0f, 1.0f, 1.0f);	// �ı��ε����϶���(����)
	glVertex3f(-1.0f, 1.0f, -1.0f);	// �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, -1.0f);	// �ı��ε����¶���(����)
	glVertex3f(-1.0f, -1.0f, 1.0f);	// �ı��ε����¶���(����)

	glColor3f(1.0f, 0.0f, 1.0f);		// ��ɫ�ĳ�������ɫ
	glVertex3f(1.0f, 1.0f, -1.0f);	// �ı��ε����϶���(����)
	glVertex3f(1.0f, 1.0f, 1.0f);	// �ı��ε����϶���(����)
	glVertex3f(1.0f, -1.0f, 1.0f);	// �ı��ε����¶���(����)
	glVertex3f(1.0f, -1.0f, -1.0f);	// �ı��ε����¶���(����)
	glEnd();	// ��������ƽ���

	return ;	//  һ�� OK
}

void reshape(int w, int h) {
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	GLfloat nRange = 100.0f;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h) {
		glOrtho(-nRange, nRange, -nRange * aspect, nRange*aspect, -nRange, nRange);//ȷ��ͼ�β������
	}
	else
		glOrtho(-nRange, nRange, -nRange / aspect, nRange / aspect, -nRange, nRange);
}


void init() {
	AngleX = 45.0f;
	AngleY = 315.f;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//���ñ���Ϊ��

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DITHER);
	glShadeModel(GL_SMOOTH);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);//��glut��������г�ʼ�� 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);;//ָ��glutCreateWindow������Ҫ�����Ĵ�����ʾģʽ RGB ˫����
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("ͼ��ѧ");//�����úõĴ��ڣ�����glutMainLoop֮ǰ������ڲ�����ʾ
	glEnable(GL_TEXTURE_2D);    // ��������
	glutReshapeFunc(reshape);//�ػ�   ע�ᴰ�ڴ�С�ı�ʱ���ص�����������Ҫ
	glutDisplayFunc(DrawGLScene);//��ʾ  ָ����ǰ������Ҫ�ػ�ʱ���õĺ���

	init();
	glutMainLoop();//����glut�¼�����ѭ������Զ���᷵��
	return 0;
}


