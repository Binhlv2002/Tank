#include<GL/freeglut.h>
#include<stdlib.h>
#include<cmath>
GLfloat alpha = 0;
GLfloat alpha1 = 0;
GLfloat updw = 0;
GLfloat tien = 0;
GLfloat dc = 0;
GLfloat dcbx = 0;
GLfloat f = 0;
GLfloat f1 = 0;
GLfloat tlp = 0;
GLfloat tlt = 0;


void init(void)
{
	glClearColor(0.53, 0.81, 0.92, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);


	GLfloat light_pos[] = { 1.0, 0.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 0.0, 0.5, 0.1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 0, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 30;
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, shininess);


}

void vetruc()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(40.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 40.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 40.0);
	glEnd();

	glEnable(GL_LIGHTING);
}

void XeTang()
{

	// cửa nắp
	glColor3f(0, 0.54, 0);
	glPushMatrix();
	glRotatef(alpha1, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -3.8);
	glutSolidCylinder(1.5, -0.5, 5, 1);
	glPopMatrix();

	// đầu
	
	glColor3f(0.43, 0.54, 0.23);
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glRotatef(alpha1, 0, 1, 0);
	glTranslatef(0, 0.8, -3.5);
	glutSolidCylinder(3.5, 7, 6, 1);
	glPopMatrix();


	// Thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glScalef(2.5, -0.8, 2.0);
	glutSolidCube(6.0);
	glPopMatrix();

	// Trước thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(6.5, -1.9, -5.95);
	glutSolidCylinder(2.75, 11.9, 7, 1);
	glPopMatrix();

	// Sau thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(-6.5, -1.65, -5.95);
	glutSolidCylinder(2.75, 11.9, 7, 1);
	glPopMatrix();

	// trang trí sau thân trái
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	glTranslatef(-8.5, 1, -1);
	glutSolidCylinder(1, -5, 10, 1);
	glPopMatrix();

	// trang trí sau thân phải
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	glTranslatef(-8.5, 1, 1);
	glutSolidCylinder(1, 5, 10, 1);
	glPopMatrix();

	// tên lửa phải
	glColor3f(0.54, 0.50, 0.3);
	glPushMatrix();
	glTranslatef(tlp, tlp, 0);
	glRotatef(90, -3, 0, 0);
	glTranslatef(-10.4, 3.5, 1.6);
	glRotatef(-50, 0, -3, 0);
	glutSolidCylinder(0.8, 3.5, 30, 1);
	glTranslatef(0, 0, 3.5);
	glutSolidCone(0.8, 2, 10, 1);
	glTranslatef(0, 0, -4);
	glutSolidCone(1.2, 2, 30, 1);
	glPopMatrix();
	
	// tên lửa trái
	glColor3f(0.54, 0.50, 0.3 );
	glPushMatrix();
	glTranslatef(tlt, tlt, 0);
	glRotatef(90, -3, 0, 0);
	glTranslatef(-10.4, -3.5, 1.6);
	glRotatef(-50, 0, -3, 0);
	glutSolidCylinder(0.8, 3.5, 30, 1);
	glTranslatef(0, 0, 3.5);
	glutSolidCone(0.8, 2, 10, 1);
	glTranslatef(0, 0, -4);
	glutSolidCone(1.2, 2, 30, 1);
	glPopMatrix();

	// Bánh
	// bánh phải trên
	
	glPushMatrix();
	glTranslatef(5, -4, 6);
	glRotatef(tien, 0, 1, 0);
	glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix(); 
	
	// bánh phải giữa
	glPushMatrix();
	glTranslatef(0, -4, 6);
	glRotatef(tien, 0, 1, 0);
	glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();
	
	// bánh phải dưới
	glPushMatrix();
	glTranslatef(-5, -4, 6);
	glRotatef(tien, 0, 1, 0);
	glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	

	// bánh trái trên
	glPushMatrix();
	glTranslatef(5, -4, -6);
	glRotatef(tien, 0, 1, 0);
	glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh trái giữa
	glPushMatrix();
	glTranslatef(0, -4, -6);
	glRotatef(tien, 0, 1, 0);
	glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	
	glPopMatrix();

	// bánh trái dưới
	glPushMatrix();
	glTranslatef(-5, -4, -6);
	glRotatef(tien, 0, 1, 0);
	glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// Trục xoay nòng pháo
	glPushMatrix();
	glRotatef(alpha1, 0, 1, 0);
	glTranslatef(2, 2, -1);
	glColor3f(0.33, 0.41, 0.18);
	glutSolidCylinder(1.8 , 2 , 30 ,1);
	glPopMatrix();

	// Nòng pháo
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	glRotatef(alpha1, 0, 1, 0);
	glRotatef(updw, 0, 0, 1);
	glTranslatef(0, 1.5, 0);	
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0, 1, -1);
	glutSolidCylinder(0.6, 17, 30, 1);
	glTranslatef(0.0, 0.0, 16);
	glColor3f(0.0,0.4,0);
	glutSolidCylinder(0.8, 2, 30, 1);
	glPopMatrix();

	//// Đạn Bắn 1
	//glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	//glRotatef(updw, 0, 0, 1);
	//glTranslatef(4.5, 1.5, 0.0);
	//glRotatef(90, 0.0, 1.0, 0.0);
	//glTranslatef(0, 1, -1);
	//glTranslatef(0, 0, f);
	//glColor3f(0.54, 0.54, 0.47);
	//glutSolidCylinder(0.5, 1.5, 30, 1);
	//glTranslatef(0, 0, 1.5);
	//glutSolidCone(0.5, 1.5, 30, 1);
	//glTranslated(0,0,-2);
	//glutSolidCone(0.6, 2.3, 10, 1);
	//glPopMatrix();


	// Đạn Bắn 2
	glPushMatrix();
	glRotatef(alpha1, 0, 1, 0);
	glRotatef(updw, 0, 0, 1);
	glTranslatef(4.5, 1.5, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0, 1, -1);
	glTranslatef(0, 0, f1);
	glColor3f(0.54, 0.54, 0.47);
	glutSolidCylinder(0.5, 1.5, 30, 1);
	glTranslatef(0, 0, 1.5);
	glutSolidCone(0.5, 1.5, 30, 1);
	glTranslated(0, 0, -2);
	glutSolidCone(0.6, 2.3, 10, 1);
	glPopMatrix();

}

void Dan1() {
	// Đạn Bắn 1
	glPushMatrix();
	glRotatef(alpha1, 0, 1, 0);
	glRotatef(updw, 0, 0, 1);
	glTranslatef(4, 1.5, 0);  // Sử dụng các tọa độ của đạn
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0, 1, -1);
	glTranslatef(0, 0, f);
	glColor3f(0.54, 0.54, 0.47);
	glutSolidCylinder(0.5, 1.5, 30, 1);
	glTranslatef(0, 0, 1.5);
	glutSolidCone(0.5, 1.5, 30, 1);
	glTranslated(0, 0, -2);
	glutSolidCone(0.6, 2.3, 10, 1);
	glPopMatrix();

}


void XeTang1()
{
	// cửa nắp
	glColor3f(0, 0.54, 0);
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -3.8);
	glutSolidCylinder(1.5, -0.5, 5, 1);
	glPopMatrix();

	// đầu
	glColor3f(0.43, 0.54, 0.23);
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	glTranslatef(0, 0.8, -3.5);
	glutSolidCylinder(3.5, 7, 6, 1);
	glPopMatrix();


	// Thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glScalef(2.5, -0.8, 2.0);
	glutSolidCube(6.0);
	glPopMatrix();

	// Trước thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(6.5, -1.9, -5.95);
	glutSolidCylinder(2.75, 11.9, 7, 1);
	glPopMatrix();

	// Sau thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(-6.5, -1.65, -5.95);
	glutSolidCylinder(2.75, 11.9, 7, 1);
	glPopMatrix();

	// trang trí sau thân trái
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	glTranslatef(-8.5, 1, -1);
	glutSolidCylinder(1, -5, 10, 1);
	glPopMatrix();

	// trang trí sau thân phải
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	glTranslatef(-8.5, 1, 1);
	glutSolidCylinder(1, 5, 10, 1);
	glPopMatrix();

	//// tên lửa phải
	//glColor3f(0.54, 0.50, 0.3);
	//glPushMatrix();
	//glTranslatef(tlp, tlp, 0);
	//glRotatef(90, -3, 0, 0);
	//glTranslatef(-10.4, 3.5, 1.6);
	//glRotatef(-50, 0, -3, 0);
	//glutSolidCylinder(0.8, 3.5, 30, 1);
	//glTranslatef(0, 0, 3.5);
	//glutSolidCone(0.8, 2, 10, 1);
	//glTranslatef(0, 0, -4);
	//glutSolidCone(1.2, 2, 30, 1);
	//glPopMatrix();

	//// tên lửa trái
	//glColor3f(0.54, 0.50, 0.3);
	//glPushMatrix();
	//glTranslatef(tlt, tlt, 0);
	//glRotatef(90, -3, 0, 0);
	//glTranslatef(-10.4, -3.5, 1.6);
	//glRotatef(-50, 0, -3, 0);
	//glutSolidCylinder(0.8, 3.5, 30, 1);
	//glTranslatef(0, 0, 3.5);
	//glutSolidCone(0.8, 2, 10, 1);
	//glTranslatef(0, 0, -4);
	//glutSolidCone(1.2, 2, 30, 1);
	//glPopMatrix();

	// Bánh
	// bánh phải trên

	glPushMatrix();
	glTranslatef(5, -4, 6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh phải giữa
	glPushMatrix();
	glTranslatef(0, -4, 6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh phải dưới
	glPushMatrix();
	glTranslatef(-5, -4, 6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();



	// bánh trái trên
	glPushMatrix();
	glTranslatef(5, -4, -6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh trái giữa
	glPushMatrix();
	glTranslatef(0, -4, -6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh trái dưới
	glPushMatrix();
	glTranslatef(-5, -4, -6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// Trục xoay nòng pháo
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	glTranslatef(2, 2, -1);
	glColor3f(0.33, 0.41, 0.18);
	glutSolidCylinder(1.8, 2, 30, 1);
	glPopMatrix();

	// Nòng pháo
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	//glRotatef(updw, 0, 0, 1);
	glTranslatef(0, 1.5, 0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0, 1, -1);
	glutSolidCylinder(0.6, 17, 30, 1);
	glTranslatef(0.0, 0.0, 16);
	glColor3f(0.0, 0.4, 0);
	glutSolidCylinder(0.8, 2, 30, 1);
	glPopMatrix();

	//// Đạn Bắn
	//glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	//glRotatef(updw, 0, 0, 1);
	//glTranslatef(4.5, 1.5, 0.0);
	//glRotatef(90, 0.0, 1.0, 0.0);
	//glTranslatef(0, 1, -1);
	//glTranslatef(0, 0, f);
	//glColor3f(0.54, 0.54, 0.47);
	//glutSolidCylinder(0.5, 1.5, 30, 1);
	//glTranslatef(0, 0, 1.5);
	//glutSolidCone(0.5, 1.5, 30, 1);
	//glTranslated(0, 0, -2);
	//glutSolidCone(0.6, 2.3, 10, 1);
	//glPopMatrix();
}

void XeTang2() {
	// cửa nắp
	glColor3f(0, 0.54, 0);
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -3.8);
	glutSolidCylinder(1.5, -0.5, 5, 1);
	glPopMatrix();

	// đầu
	glColor3f(0.43, 0.54, 0.23);
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	glTranslatef(0, 0.8, -3.5);
	glutSolidCylinder(3.5, 7, 6, 1);
	glPopMatrix();


	// Thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glScalef(2.5, -0.8, 2.0);
	glutSolidCube(6.0);
	glPopMatrix();

	// Trước thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(6.5, -1.9, -5.95);
	glutSolidCylinder(2.75, 11.9, 7, 1);
	glPopMatrix();

	// Sau thân
	glColor3f(0, 0.39, 0.25);
	glPushMatrix();
	glTranslatef(-6.5, -1.65, -5.95);
	glutSolidCylinder(2.75, 11.9, 7, 1);
	glPopMatrix();

	// trang trí sau thân trái
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	glTranslatef(-8.5, 1, -1);
	glutSolidCylinder(1, -5, 10, 1);
	glPopMatrix();

	// trang trí sau thân phải
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	glTranslatef(-8.5, 1, 1);
	glutSolidCylinder(1, 5, 10, 1);
	glPopMatrix();

	// Bánh
	// bánh phải trên

	glPushMatrix();
	glTranslatef(5, -4, 6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh phải giữa
	glPushMatrix();
	glTranslatef(0, -4, 6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh phải dưới
	glPushMatrix();
	glTranslatef(-5, -4, 6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();



	// bánh trái trên
	glPushMatrix();
	glTranslatef(5, -4, -6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh trái giữa
	glPushMatrix();
	glTranslatef(0, -4, -6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// bánh trái dưới
	glPushMatrix();
	glTranslatef(-5, -4, -6);
	//glRotatef(tien, 0, 1, 0);
	//glRotatef(dcbx, 0, 0, 1);
	glColor3f(0.6, 0.4, 0.2);
	glutSolidTorus(0.9, 1.7, 30, 15);
	glColor3f(0.5, 0.5, 0.5);
	glutWireTorus(0.5, 0.5, 30, 5);
	glPopMatrix();

	// Trục xoay nòng pháo
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	glTranslatef(2, 2, -1);
	glColor3f(0.33, 0.41, 0.18);
	glutSolidCylinder(1.8, 2, 30, 1);
	glPopMatrix();

	// Nòng pháo
	glColor3f(0, 0.54, 0.27);
	glPushMatrix();
	//glRotatef(alpha1, 0, 1, 0);
	//glRotatef(updw, 0, 0, 1);
	glTranslatef(0, 1.5, 0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0, 1, -1);
	glutSolidCylinder(0.6, 17, 30, 1);
	glTranslatef(0.0, 0.0, 16);
	glColor3f(0.0, 0.4, 0);
	glutSolidCylinder(0.8, 2, 30, 1);
	glPopMatrix();
}

void hienThiXeTang() {
	glPushMatrix();
	glTranslatef(-20,0,50);
	XeTang();
	Dan1();
	glPopMatrix();
}


void XeTang11() {
		glPushMatrix();
		glTranslatef(30, 0, 10);
		glRotatef(180, 0, 1, 0);
		XeTang1();	
		glColor3f(1, 0.5, 0);
		glutSolidSphere(2, 20, 20); // Vẽ một quả cầu lửa
		glPopMatrix();
}

void Lua() {

	// Xác định tọa độ trùng
	float trungX = 30;
	float trungY = 0;
	float trungZ = 10;

	// Vẽ hiệu ứng lửa tại tọa độ trùng
	glPushMatrix();
	glTranslatef(trungX, trungY, trungZ);
	float triangleSize = 2;
	glColor3f(1.0, 0.5, 0.0); // Màu lửa
	glPointSize(5.0); // Tăng kích thước của điểm
	glBegin(GL_POINTS); // Sử dụng điểm để tạo hiệu ứng lửa
	for (int i = 0; i < 5000; ++i) { // Tăng số lượng điểm
		float offsetX = (rand() % 101 - 50) * 0.1; // Tạo độ biến đổi ngẫu nhiên
		float offsetY = (rand() % 101 - 50) * 0.1;
		float offsetZ = (rand() % 101 - 50) * 0.1;
		glVertex3f(offsetX, offsetY, offsetZ); // Vẽ điểm lửa ngẫu nhiên
		// Vẽ tam giác
		glBegin(GL_TRIANGLES);
		glVertex3f(offsetX, offsetY, offsetZ);
		glVertex3f(offsetX + triangleSize, offsetY, offsetZ);
		glVertex3f(offsetX + triangleSize / 2, offsetY + triangleSize, offsetZ);
		glEnd();
	}
	glEnd();
	glPopMatrix();
}

void XeTang22() {
	glPushMatrix();
	glTranslatef(30, 0, 70);
	glRotatef(180, 0, 1 , 0);
	XeTang2();
	glPopMatrix();
}

void Nen() {
	glColor3f(0.54, 0.27, 0.07);
	glBegin(GL_POLYGON);
	glVertex3f(-500.0, -100.0, -550.0);
	glVertex3f(-500.0, -100.0, -550.0);
	glVertex3f(500.0, -100.0, 550.0);
	glVertex3f(500.0, -100.0, -550.0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(20, 30, -60);
	glutSolidCylinder(6, 0.1, 50, 1);
	glPopMatrix();

}

void Cay() {
	glColor3f(0.6, 0.4, 0.2);  
	glPushMatrix();
	glTranslatef(0, 2, -30.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1); 
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2);  
	glPushMatrix();
	glTranslatef(-7, 2, -25.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1);
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2); 
	glPushMatrix();
	glTranslatef(-5, 2, -32.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 6, 10, 1); 
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();



	glColor3f(0.6, 0.4, 0.2);  
	glPushMatrix();
	glTranslatef(-22, 2, -30.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1);  
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2);  
	glPushMatrix();
	glTranslatef(-25, 2, -25.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1);
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2);  
	glPushMatrix();
	glTranslatef(-27, 2, -32.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 6, 10, 1);  
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2);  
	glPushMatrix();
	glTranslatef(-20, 2, -30.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1);  
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();



	glColor3f(0.6, 0.4, 0.2);  
	glPushMatrix();
	glTranslatef(-50, 0, -20.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1);
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2); 
	glPushMatrix();
	glTranslatef(-54, -1, -20.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 6, 10, 1); 
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();



	glColor3f(0.6, 0.4, 0.2); 
	glPushMatrix();
	glTranslatef(35, 0, -25.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1);  
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2); 
	glPushMatrix();
	glTranslatef(40, 1, -25.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 7, 30, 1);
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();

	glColor3f(0.6, 0.4, 0.2); 
	glPushMatrix();
	glTranslatef(37, 0, -20.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(0.5, 6, 10, 1); 
	glColor3f(0.0, 0.39, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidCone(3, 7, 6, 1);
	glPopMatrix();
}

void Nui() {

	

	// Vẽ núi
	glColor3f(0.2, 0.2, 0.2);  // Màu xám đậm
	glPushMatrix();
	glTranslatef(0.0, 0.0, -50.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20.0, 25.0, 8, 1);  // Thân núi
	glPopMatrix();

	glColor3f(0.2, 0.2, 0.2);  // Màu xám đậm
	glPushMatrix();
	glTranslatef(-10.0, 0.0, -70.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(25, 30.0, 8, 1);  // Thân núi
	glPopMatrix();

	glColor3f(0.2, 0.2, 0.2);  // Màu xám đậm
	glPushMatrix();
	glTranslatef(-50.0, 0.0, -50.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(30, 30.0, 8, 1);  // Thân núi
	glPopMatrix();

	glColor3f(0.2, 0.2, 0.2);  // Màu xám đậm
	glPushMatrix();
	glTranslatef(-30, 0.0, -60.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(25, 20.0, 8, 1);  // Thân núi
	glPopMatrix();


	glColor3f(0.2, 0.2, 0.2);  // Màu xám đậm
	glPushMatrix();
	glTranslatef(25.0, 0.0, -60.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(35, 30.0, 8, 1);  // Thân núi
	glPopMatrix();

}



void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case'a':
		glRotatef(alpha1, 0, 1, 0);
		alpha1 += 3.0;
		break;

	case'd':
		glRotatef(alpha1, 0, 1, 0);
		alpha1 -= 3.0;
		break;

	case'w':
		updw += 0.3;
		if (updw >= 20)
		{
			updw = 20;
		}
		break;

	case's':
		updw -= 0.3;
		if (updw <= -10)
		{
			updw = -10;
		}
		break;

	case'q':
		tien += 0.90;
		if (tien >= 30)
		{
			tien = 30;
		}
		break;

	case'e':
		tien -= 0.90;
		if (tien <= -30)
		{
			tien = -30;
		}
		break;

	case'z':
		dc -= 0.50;
		dcbx += 9;
		break;

	case'c':
		dc += 0.50;
		dcbx -= 9;
		break;

	case't':
		alpha -= 30.0;
		if (alpha >= 360)alpha = 0;
		break;

	case'p':
		alpha += 30.0;
		if (alpha >= 360)alpha = 0;
		break;

	case'f':
		f += 3;
		break;

	case 'y':
		f1 += 3;
		break;
		
	case'l':
		f = 0;
		f1 = 0;
		break;

	case 'm':
		tlp += 3;
		break;

	case 'n':
		tlt += 3;
		break;
	
	case 'o':
		tlp += 3;
		tlt += 3;
		break;

	case 'i':
		tlp = 0;
		tlt = 0;
		break;
}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(20, 20.0, 100.0		//mat nhin
		, 0.0, 0.0, 0.0       //nhin vao goc toa do 
		, 0.0, 1.0, 0.0);	  //Di chuyen cam
	Nen();
	Cay();
	Nui();
	glRotatef(alpha, 0, 1, 0);
	glTranslatef(dc, 0, 0);
	if ( f <= 45 ) {
		XeTang11();
	}
	if (f > 45) {
		Lua();
	}

	if (f == 45) {
		Lua();
	}

	hienThiXeTang();
	vetruc();
	
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
}

//Xoay xe
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		alpha += 04.0;
		if (alpha >= 360) alpha = 0;
	}

	if (button == GLUT_RIGHT_BUTTON) {
		alpha -= 04.0;
		if (alpha >= 360)alpha = 0;
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 2000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1100, 1200);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Tank");
	init();
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}