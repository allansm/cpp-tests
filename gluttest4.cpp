#include <cpp-lib/dependent/freeglut/test.h>

using action = void(*)();
using keyaction = void(*)(unsigned char,int,int);

struct glut{
	const char* title = "";
	int width = 400;
	int height = 300;
	action callback;
	keyaction keycallback;
	int argc;
	char ** argv;
	
	glut(int argc,char** argv){
		this->argc = argc;
		this->argv = argv;
	}

	void start(){
		glutInit(&this->argc, this->argv);
		glutInitWindowSize(this->width, this->height);
		glutCreateWindow(this->title);
		glutDisplayFunc(this->callback);
		glutKeyboardFunc(this->keycallback);	
		glutMainLoop();	
	}
};
auto cube = loadObj("cube.obj");
main(int argc,char **argv){
	auto g = glut(argc,argv);
	
	g.callback = [](){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		/*glColor(1,0,0);
		glBegin(GL_POLYGON);
			glVertex3f(0,1,0);
			glVertex3f(1,0,0);
			glVertex3f(-1,0,0);
		glEnd();*/
		auto current = Matrix();
		glScalef(0.1,0.1,0.1);
		cube.show();
		current.load();
		glFlush();	
	};
	g.keycallback = [](unsigned char c,int x,int y){
		glutPostRedisplay();
		if(c == 'x'){
			glScalef(2,2,2);
		}
	};
	g.start();	
}
