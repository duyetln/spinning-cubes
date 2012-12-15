//Duyet Nguyen

#include <GL/glut.h>

class my_glMatrixStack{
	private:
		GLdouble** stack;
		int current;

	public:
		const int MAX_SIZE;

		my_glMatrixStack(int capacity);
		~my_glMatrixStack();

		void push(const GLdouble matrix[], const int length);
		void pop();
		const GLdouble* top();

		int size() const;
		bool empty() const;
};
