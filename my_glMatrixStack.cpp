//Duyet Nguyen

#include <stdlib.h>
#include <stack>
#include <GL/glut.h>
#include <iostream>
#include "my_glMatrixStack.h"

using namespace std;

my_glMatrixStack::my_glMatrixStack(int capacity) : MAX_SIZE(capacity){
	stack = new GLdouble*[MAX_SIZE];
	current = -1;
}

my_glMatrixStack::~my_glMatrixStack(){
	for (int index = 0; index <= current; index++){
		delete[] stack[index];
	}
	delete[] stack;
}

void my_glMatrixStack::push(const GLdouble matrix[], const int length){
	if (size() >= MAX_SIZE){
		cerr<<"my_glMatrixStack::push: GL_STACK_OVERFLOW"<<endl;		
		throw GL_STACK_OVERFLOW;
	}
	else{
		stack[++current] = new GLdouble[length];		
		for (int index = 0; index < length; index++){
			stack[current][index] = matrix[index];
		}
	}
}

void my_glMatrixStack::pop(){
	if (empty()){
		cerr<<"my_glMatrixStack::pop: GL_STACK_UNDERFLOW"<<endl;
		throw GL_STACK_UNDERFLOW;
	}
	else delete[] stack[current--];
}

const GLdouble* my_glMatrixStack::top(){
	return stack[current];
}

int my_glMatrixStack::size() const {return current+1;}
bool my_glMatrixStack::empty() const {return size()==0;}



