//Duyet Nguyen

#include <stdlib.h>
#include <stack>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "i_my_gl.h"
#include "my_glMatrixStack.h"

using namespace std;

const int MAX_DEPTH = 16;
const int NUM_COL = 4;
const int NUM_ROW = 4;
const int SIZE = NUM_ROW * NUM_COL;
const double PI = 3.14159265359;

my_glMatrixStack modelStack(MAX_DEPTH);
my_glMatrixStack projectionStack(MAX_DEPTH);
my_glMatrixStack* currentStack = &modelStack; //default



//--- code below ---//
void I_my_glLoadMatrixd(const GLdouble *matrix){
	if (!(*currentStack).empty()) (*currentStack).pop();
	(*currentStack).push(matrix, SIZE);
}

void I_my_glLoadMatrixf(const GLfloat *matrix){
	GLdouble copiedMatrix[SIZE];
	copy(matrix, matrix+SIZE, copiedMatrix);
	I_my_glLoadMatrixd(copiedMatrix);
}

void I_my_glLoadIdentity(){
	GLdouble identity[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
	I_my_glLoadMatrixd(identity);
}

void I_my_glMatrixMode(GLenum mode){
	if (mode == GL_MODELVIEW) currentStack = &modelStack;
	else if (mode == GL_PROJECTION) currentStack = &projectionStack;
	else{
		cerr<<"I_my_glMatrixMode: GL_INVALID_ENUM"<<endl;
		throw GL_INVALID_ENUM;
	}
}

void I_my_glPopMatrix(){
	(*currentStack).pop();
}

void I_my_glPushMatrix(){
	if ((*currentStack).empty()) I_my_glLoadIdentity();
	else (*currentStack).push((*currentStack).top(), SIZE);
}

//copy or direct access?
void I_my_glGetMatrixd(GLdouble *matrix){
	if ((*currentStack).empty()){
		matrix = NULL;
		return;
	}
	const GLdouble *result = (*currentStack).top();
	for (int index = 0; index < SIZE; index++){
		matrix[index] = result[index];
	}
}

void I_my_glGetMatrixf(GLfloat *matrix){
	GLdouble result[SIZE];
	I_my_glGetMatrixd(result);
	copy(result, result+SIZE, matrix);
}

void I_my_glMultMatrixd(const GLdouble *matrix){
	GLdouble result[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
	if ((*currentStack).empty()){
		cerr<<"I_my_glMultMatrixd: GL_INVALID_OPERATION"<<endl;
 		throw GL_INVALID_OPERATION;
	}
	const GLdouble *top = (*currentStack).top();
	for (int row = 0; row < 4; row++){
		for (int column = 0; column < 4; column++){
			for (int jump = 0; jump < 4; jump++){
				result[column*NUM_ROW+row] += top[jump*NUM_COL+row] * matrix[column*NUM_ROW+jump];
			}
		}
	}
	(*currentStack).pop();
	(*currentStack).push(result, SIZE);
}

void I_my_glMultMatrixf(const GLfloat *matrix){
	GLdouble copiedMatrix[SIZE];
	copy(matrix, matrix+SIZE, copiedMatrix);
	I_my_glMultMatrixd(copiedMatrix);
}

void I_my_glCrossProduct(GLdouble *ax, GLdouble *ay, GLdouble *az, GLdouble bx, GLdouble by, GLdouble bz, GLdouble cx, GLdouble cy, GLdouble cz){
	(*ax) = by*cz - bz*cy;
	(*ay) = bz*cx - bx*cz;
	(*az) = bx*cy - by*cx;
}

void I_my_glNormalize(GLdouble *x, GLdouble *y, GLdouble *z){
	GLdouble length = sqrt(pow(*x,2) + pow(*y,2) + pow(*z,2));
	(*x) = (*x)/length;
	(*y) = (*y)/length;
	(*z) = (*z)/length;
}

void I_my_glTranslated(GLdouble x, GLdouble y, GLdouble z){
	GLdouble translationMatrix[] = /*{1,0,0,x,0,1,0,y,0,0,1,z,0,0,0,1};*/{1,0,0,0,0,1,0,0,0,0,1,0,x,y,z,1};
	I_my_glMultMatrixd(translationMatrix);
}

void I_my_glTranslatef(GLfloat x, GLfloat y, GLfloat z){
	I_my_glTranslated((GLdouble)x,(GLdouble)y,(GLdouble)z);
}

void I_my_glRotated(GLdouble angleD, GLdouble x, GLdouble y, GLdouble z){
	I_my_glNormalize(&x, &y, &z);
	GLdouble angleR = angleD*PI/180;
	GLdouble rotationMatrix[] = {
		x*x*(1-cos(angleR))+cos(angleR), y*x*(1-cos(angleR))+z*sin(angleR), x*z*(1-cos(angleR))-y*sin(angleR), 0,
		x*y*(1-cos(angleR))-z*sin(angleR), y*y*(1-cos(angleR))+cos(angleR), y*z*(1-cos(angleR))+x*sin(angleR), 0,
		x*z*(1-cos(angleR))+y*sin(angleR), y*z*(1-cos(angleR))-x*sin(angleR), z*z*(1-cos(angleR))+cos(angleR), 0,
		0, 0, 0, 1
	};
	I_my_glMultMatrixd(rotationMatrix);
}

void I_my_glRotatef(GLfloat angleD, GLfloat x, GLfloat y, GLfloat z){
	I_my_glRotated((GLdouble)angleD,(GLdouble)x,(GLdouble)y,(GLdouble)z);
}

void I_my_glScaled(GLdouble x, GLdouble y, GLdouble z){
	GLdouble scaleMatrix[] = {x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1};
	I_my_glMultMatrixd(scaleMatrix);
}

void I_my_glScalef(GLfloat x, GLfloat y, GLfloat z){
	I_my_glScaled((GLdouble)x,(GLdouble)y,(GLdouble)z);
}

void I_my_gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble centerX, GLdouble centerY, GLdouble centerZ, GLdouble upX, GLdouble upY, GLdouble upZ){

	//f
	GLdouble Ax = centerX - eyeX;
	GLdouble Ay = centerY - eyeY;
	GLdouble Az = centerZ - eyeZ;
	I_my_glNormalize(&Ax, &Ay, &Az);

	//UP'
	GLdouble Bx = upX;
	GLdouble By = upY;
	GLdouble Bz = upZ;
	I_my_glNormalize(&Bx, &By, &Bz);

	//s
	GLdouble Cx;
	GLdouble Cy;
	GLdouble Cz;
	I_my_glCrossProduct(&Cx, &Cy, &Cz, Ax, Ay, Az, Bx, By, Bz);

	//u
	GLdouble Dx;
	GLdouble Dy;
	GLdouble Dz;
	I_my_glCrossProduct(&Dx, &Dy, &Dz, Cx, Cy, Cz, Ax, Ay, Az);

	GLdouble viewingMatrix[] = {Cx, Cy, Cz, 0, Dx, Dy, Dz, 0, -Ax, -Ay, -Az, 0, 0, 0, 0, 1};
	I_my_glMultMatrixd(viewingMatrix);
	I_my_glTranslated(-eyeX, -eyeY, -eyeZ);
}

void I_my_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far){
	if (near <= 0 || far <= 0 || left == right || bottom == top){
		cerr<<"I_my_glFrustum: GL_INVALID_VALUE"<<endl;
		throw GL_INVALID_VALUE;
	}
	GLdouble perspectiveMatrix[] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, (far+near)/(near-far), -1,
		0, 0, 2*far*near/(near-far),0
	};
	GLdouble scaleMatrix[] = {
		2*near/(right-left), 0, 0, 0,
		0, 2*near/(top-bottom), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	GLdouble shearMatrix[] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		(right+left)/(2*near), (top+bottom)/(2*near), 1, 0,
		0, 0, 0, 1
	};
	I_my_glMultMatrixd(perspectiveMatrix);
	I_my_glMultMatrixd(scaleMatrix);
	I_my_glMultMatrixd(shearMatrix);


	//GLdouble perspectiveMatrix[] = {
	//	2*near/(right-left), 0, 0, 0,
	//	0, 2*near/(top-bottom), 0, 0,
	//	(right+left)/(right-left), (top+bottom)/(top-bottom), (far+near)/(near-far), -1,
	//	0, 0, 2*far*near/(near-far), 0
	//};
	//I_my_glMultMatrixd(perspectiveMatrix);
}

// remember to convert fovy from degree to radius before calling tan
void I_my_gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar){
	GLdouble cotan = 1/tan((fovy/2)*PI/180);
	I_my_glFrustum(-aspect*zNear/cotan, aspect*zNear/cotan, -zNear/cotan, zNear/cotan, zNear, zFar);


	//GLdouble perspectiveMatrix[] = {
	//	cotan/aspect, 0, 0, 0,
	//	0, cotan, 0, 0,
	//	0, 0, (zFar+zNear)/(zNear-zFar), -1,
	//	0, 0, 2*zFar*zNear/(zNear-zFar), 0
	//};
	//I_my_glMultMatrixd(perspectiveMatrix);
}

//int main(){
//	I_my_glLoadIdentity();
//	I_my_glRotated(90,0,0,1);
//	for (int index = 0; index < 16; index++)
//		cout<<(*currentStack).top()[index]<<" ";

//}
//pushMatrix, popMatrix, loadMatrixd, loadMatrixf, loadIdentity, multMatrixf, multMatrixd, normalize, crossProduct
