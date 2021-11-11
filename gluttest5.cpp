#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

struct glut{
	const char* title = "";
	int width = 400;
	int height = 300;
	
	void (*callback)() = [](){};
	void (*before)() = [](){};
	void (*after)() = [](){};
	
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
		before();
		glutDisplayFunc(this->callback);
		after();	
		glutMainLoop();	
	}
};

main(int argc,char ** argv){
	auto g = glut(argc,argv);
	g.start();
}
