#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int a = 0;
int b = 0;
int c = 1;

void triangle(){
	glRotatef(10,0,1,0);
	glBegin(GL_POLYGON);
        	glColor3f(a, b, c); glVertex3f(0, 1, 0);
		glColor3f(c, b, a); glVertex3f(-1, 0, 0);
		glColor3f(b, a, c); glVertex3f(1, 0, 0);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();	
	glFlush();
	//glutSwapBuffers();

}
void test(int n){
	/*if(a == 1){
		a = 0;
	}else{
		a = 1;
	}
	if(b == 1){
		b = 0;
	}else{
		b = 1;
	}
	if(c == 1){
		c = 0;
	}else{
		c = 1;
	}*/

	glutPostRedisplay();	
	glutTimerFunc(30, test, 0);	
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutCreateWindow("");
	glutDisplayFunc(display);
	glutTimerFunc(30, test, 0);
   	glRotatef(20,1,0,0);
	glutMainLoop();
}
