//Duyet Nguyen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <signal.h>

#include "sceneModule.h"
#include "viewModule.h"
#include "inputModule.h"
#include	"my_gl.h"

#include <iostream>
using namespace std;

const double PI = 3.14159265359;


//=====================
static float alpha = 0;
static float beta = 0;
static float charlie = 0;
static float delta = 0;
static float echo = 0;

void drawObject1(){
	glPushMatrix();

	glBegin(GL_QUADS);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f(-0.25,  0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f( 0.25, -0.25, -0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 1);
  glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f( 0.25,  0.25, -0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);

  glEnd();

	glPopMatrix();

}

void drawObject2(){
	glPushMatrix();

	glTranslatef(1.5,0,0);

	glBegin(GL_QUADS);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125, -0.125);
	glVertex3f(-0.125, -0.125,  0.125);
	glVertex3f(-0.125,  0.125,  0.125);
	glVertex3f(-0.125,  0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f( 0.125, -0.125, -0.125);
	glVertex3f( 0.125, -0.125,  0.125);
	glVertex3f( 0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125, -0.125);
	glVertex3f(-0.125, -0.125,  0.125);
	glVertex3f( 0.125, -0.125,  0.125);
	glVertex3f( 0.125, -0.125, -0.125);

	glColor3f(0, 0, 1);
  glVertex3f(-0.125,  0.125, -0.125);
	glVertex3f(-0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125, -0.125);
	glVertex3f(-0.125,  0.125, -0.125);
	glVertex3f( 0.125,  0.125, -0.125);
	glVertex3f( 0.125, -0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125,  0.125);
	glVertex3f(-0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125,  0.125);
	glVertex3f( 0.125, -0.125,  0.125);

  glEnd();

	glPopMatrix();
	
}

void drawObject3(){
	glPushMatrix();

	glTranslatef(2.25,0,0);
	glRotatef(echo,0,1,0);

	glBegin(GL_QUADS);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f(-0.25,  0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f( 0.25, -0.25, -0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 0);
  glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f( 0.25,  0.25, -0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);

  glEnd();

	glPopMatrix();
	
}

void drawObject4(){

	glPushMatrix();

	glTranslatef(2.25,0,0);
	glRotatef(beta,1,0,0);
	glTranslatef(0,1,0);
	
	glColor3f(1, 0, 0);
	glutSolidSphere(0.25, 32, 32);

	glPopMatrix();

}

void drawObject5(){

	glPushMatrix();

	glTranslatef(0,2*sin(charlie*PI/180),0);
	glTranslatef(0,0,1.5*cos(charlie*PI/180));

	glColor3f(1, 1, 0);
	glutSolidSphere(0.25, 32, 32);

	glPopMatrix();

}

void drawObject6(){

	glPushMatrix();

	glTranslatef(0,2*sin(charlie*PI/180),0);
	glTranslatef(0,0,1.5*cos(charlie*PI/180));

	glRotatef(delta,0,1,0);
	glTranslatef(0.5,0,0);

	glColor3f(1, 0, 1);
	glutSolidSphere(0.125, 32, 32);

	glPopMatrix();

}

void draw(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	setUserView();

  //glLoadIdentity();
	//glTranslatef(0, 0, -10);
  //glRotatef(30, 1, 0, 0);
	glRotatef(alpha,0,1,0);

	drawObject1();
	drawObject2();
	drawObject3();
	drawObject4();
	drawObject5();
	drawObject6();

	alpha = alpha + 0.5;
	beta = beta + 2;
	charlie = charlie + 0.75;
	delta = delta + 2;
	echo = echo + 3;
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();

}


//=====================
static float my_alpha = 0;
static float my_beta = 0;
static float my_charlie = 0;
static float my_delta = 0;
static float my_echo = 0;

void my_drawObject1(){
	my_glPushMatrix();

	glBegin(GL_QUADS);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f(-0.25,  0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f( 0.25, -0.25, -0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 1);
  glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f( 0.25,  0.25, -0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 1);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);

  glEnd();

	my_glPopMatrix();

}

void my_drawObject2(){
	my_glPushMatrix();

	my_glTranslatef(1.5,0,0);

	glBegin(GL_QUADS);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125, -0.125);
	glVertex3f(-0.125, -0.125,  0.125);
	glVertex3f(-0.125,  0.125,  0.125);
	glVertex3f(-0.125,  0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f( 0.125, -0.125, -0.125);
	glVertex3f( 0.125, -0.125,  0.125);
	glVertex3f( 0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125, -0.125);
	glVertex3f(-0.125, -0.125,  0.125);
	glVertex3f( 0.125, -0.125,  0.125);
	glVertex3f( 0.125, -0.125, -0.125);

	glColor3f(0, 0, 1);
  glVertex3f(-0.125,  0.125, -0.125);
	glVertex3f(-0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125, -0.125);
	glVertex3f(-0.125,  0.125, -0.125);
	glVertex3f( 0.125,  0.125, -0.125);
	glVertex3f( 0.125, -0.125, -0.125);

	glColor3f(0, 0, 1);
	glVertex3f(-0.125, -0.125,  0.125);
	glVertex3f(-0.125,  0.125,  0.125);
	glVertex3f( 0.125,  0.125,  0.125);
	glVertex3f( 0.125, -0.125,  0.125);

  glEnd();

	my_glPopMatrix();
	
}

void my_drawObject3(){
	my_glPushMatrix();

	my_glTranslatef(2.25,0,0);
	my_glRotatef(my_echo,0,1,0);

	glBegin(GL_QUADS);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f(-0.25,  0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f( 0.25, -0.25, -0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 0);
  glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25, -0.25);
	glVertex3f(-0.25,  0.25, -0.25);
	glVertex3f( 0.25,  0.25, -0.25);
	glVertex3f( 0.25, -0.25, -0.25);

	glColor3f(0, 1, 0);
	glVertex3f(-0.25, -0.25,  0.25);
	glVertex3f(-0.25,  0.25,  0.25);
	glVertex3f( 0.25,  0.25,  0.25);
	glVertex3f( 0.25, -0.25,  0.25);

  glEnd();

	my_glPopMatrix();
	
}

void my_drawObject4(){

	my_glPushMatrix();

	my_glTranslatef(2.25,0,0);
	my_glRotatef(my_beta,1,0,0);
	my_glTranslatef(0,1,0);
	
	glColor3f(1, 0, 0);
	glutSolidSphere(0.25, 32, 32);

	my_glPopMatrix();

}

void my_drawObject5(){

	my_glPushMatrix();

	my_glTranslatef(0,3*sin(my_charlie*PI/180),0);
	my_glTranslatef(0,0,1*cos(my_charlie*PI/180));

	glColor3f(1, 1, 0);
	glutSolidSphere(0.25, 32, 32);

	my_glPopMatrix();

}

void my_drawObject6(){

	my_glPushMatrix();

	my_glTranslatef(0,3*sin(my_charlie*PI/180),0);
	my_glTranslatef(0,0,1*cos(my_charlie*PI/180));

	my_glRotatef(my_delta,0,1,0);
	my_glTranslatef(0.5,0,0);

	glColor3f(1, 0, 1);
	glutSolidSphere(0.125, 32, 32);

	my_glPopMatrix();

}

void my_draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	my_setUserView();

  //my_glLoadIdentity();
	//my_glTranslatef(0, 0, -10);
  //my_glRotatef(30, 1, 0, 0);
	my_glRotatef(my_alpha,0,1,0);

	my_drawObject1();
	my_drawObject2();
	my_drawObject3();
	my_drawObject4();
	my_drawObject5();
	my_drawObject6();

	my_alpha = my_alpha + 0.5;
	my_beta = my_beta + 2;
	my_charlie = my_charlie + 0.75;
	my_delta = my_delta + 2;
	my_echo = my_echo + 3;
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void drawAll(){
	if (funcFlag == 0)draw();
	else my_draw();
}


//=======================================
perspectiveData pD;
int window;
int updateFlag;


void initDisplay(){
  /* Perspective projection parameters */
  pD.fieldOfView = 45.0;
  pD.aspect      = (float)IMAGE_WIDTH/IMAGE_HEIGHT;
  pD.nearPlane   = 0.1;
  pD.farPlane    = 50.0;

  /* setup context */
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluPerspective( pD.fieldOfView, pD.aspect, pD.nearPlane, pD.farPlane );

  glEnable( GL_DEPTH_TEST );
  glDisable( GL_CULL_FACE );

  glClearColor( 0.0, 0.0, 0.0, 1.0 );
  glClearIndex( 0 );
  glClearDepth( 1 );

  glMatrixMode( GL_MODELVIEW );
}


int main(int argc, char **argv)
{

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE );
  glutInitWindowSize( IMAGE_WIDTH,IMAGE_HEIGHT );
  glutCreateWindow("Spinning animation");


  glClearColor(0, 0, 0, 0);
  glEnable(GL_DEPTH_TEST);


  glutDisplayFunc(drawAll);

	glutKeyboardFunc( readKeyboard );
  glutMouseFunc( mouseButtHandler );
  glutMotionFunc( mouseMoveHandler );
  glutPassiveMotionFunc( mouseMoveHandler );
  glutIdleFunc( NULL );

  initDisplay( );

	


  glutMainLoop();

  return 0;
}

