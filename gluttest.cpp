#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  
  /*glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_LINES);
  for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
    glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
    glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
  }
  glEnd();
	*/
  
  //glBegin(GL_TRIANGLE_STRIP);
    /*glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
    glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
    glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4);
    glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);*/
	/*glColor3f(1,1,1); glVertex3f(0,1,0);
	glColor3f(1,0,1); glVertex3f(-1,0,0);
	glColor3f(1,1,0); glVertex3f(1,0,0);
	glColor3f(1,1,0); glVertex3f(0,-1,0);*/

  //glEnd();
	glBegin(GL_POLYGON);
        	glColor3f(0, 1, 1); glVertex3f(0, 0.05, 0);
		glColor3f(1, 1, 1); glVertex3f(-0.05, 0, 0);
		glColor3f(1, 1, 0); glVertex3f(0.05, 0, 0);
	glEnd();
	glTranslatef(0.1,0,0);
	glBegin(GL_POLYGON);
        	glColor3f(0, 1, 1); glVertex3f(0, -0.05, 0);
		glColor3f(1, 1, 1); glVertex3f(-0.05, 0, 0);
		glColor3f(1, 1, 0); glVertex3f(0.05, 0, 0);
	glEnd();
	glTranslatef(0.5,0,0);
	glBegin(GL_POLYGON);
        	glColor3f(0, 1, 1); glVertex3f(0.05, 0.05, 0);
		glColor3f(0, 1, 1); glVertex3f(-0.05, 0.05, 0);
		glColor3f(0, 1, 1); glVertex3f(-0.05, -0.05, 0);
		glColor3f(0, 1, 1); glVertex3f(0.05, -0.05, 0);	
	glEnd();
	glTranslatef(-0.6,0,0);
	glTranslatef(-0.5,0,0);
	glBegin(GL_POLYGON);
        	glColor3f(0, 1, 1); glVertex3f(0.05, 0.05, 0);
		glColor3f(0, 1, 1); glVertex3f(-0.05, 0.05, 0);
		glColor3f(0, 1, 1); glVertex3f(-0.05, -0.05, 0);
		glColor3f(0, 1, 1); glVertex3f(0.05, -0.05, 0);	
	glEnd();	
  glFlush();
	glTranslatef(0.5,0,0);
}


void init() {
glClearColor(0.1, 0.39, 0.88, 1.0);
	   glColor3f(1.0, 1.0, 1.0);


  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
	   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-2, 2, -1.5, 1.5, 1, 40);
 
  glTranslatef(0,0,-1);
  glRotatef(40,0,1,0);
  glRotatef(60,1,0,0);
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("");
  glutDisplayFunc(display);
  //init();
  //glClearColor(0.1, 0.39, 0.88, 1.0);
  //glRotatef(10,1,0,0);
  //glRotatef(50,0,1,0);
  glutMainLoop();
}
