#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cpp-lib/files.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>
#include <cpp-lib/parser.hpp>
//#include <cpp-lib/array.hpp>

auto f = Files();
auto u = Util();

struct torus{
	vector<float> x;
	vector<float> y;
	vector<float> z;

	torus(){}
};

torus test;

vector<vector<int>> faces;
void display(){
	int i = 0;
	int x = 1,y=0,z=0;
	//glClear(GL_COLOR_BUFFER_BIT);
	 glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        	for(auto n : faces){
			
			/*println(test.x[i]);
			println(test.y[i]);
			println(test.z[i]);
			println("");*/
 glShadeModel(GL_FLAT); 
			glBegin(GL_POLYGON);
			
			for(auto nn : n){
				/*if(x == 1){
					x = 0;
				}else{
					x = 1;
				}
				if(x == 0){
					y = 0;
				}else{
					y = 1;
				}
				if(y == 1){
					z = 0;
				}else{
					z = 1;
				}*/
				glColor3f(x,y,z);glVertex3f(test.x[nn],test.y[nn],test.z[nn]);
			}
			glEnd();
		}
	
	glFlush();
}

void aaa(int n){
	glutPostRedisplay();
	glRotatef(0.2,0,1,0);
	//glRotatef(0.2,1,0,1);
	glutTimerFunc(10, aaa, 0);	
}

void init() {
	  glEnable(GL_DEPTH_TEST);
	GLfloat yellow[] = {1.0, 1.0, 0.5, 1.0};
	      glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
	        glEnable(GL_LIGHTING);
		  glEnable(GL_LIGHT0);
}


void reshape (int w, int h)
{
	   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	      glMatrixMode (GL_PROJECTION);
	         glLoadIdentity();
		    if (w <= h)
			          glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
						           1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
		       else
			             glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
						              1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
		          glMatrixMode(GL_MODELVIEW);
			     glLoadIdentity();
}

main(int argc, char** argv){
	torus t = torus();

	int i = 0;
	
	for(auto l : f.getLines("torus.obj")){
		if(u.has(l,"v ")){
			auto tmp = u.explode(l," ");
			float x,y,z;
			x = to<float>(tmp[1]);
			y = to<float>(tmp[2]);
			z = to<float>(tmp[3]);	

			t.x.push_back(x);
			t.y.push_back(y);
			t.z.push_back(z);
		}
		if(u.has(l,"f ")){
			std::string str = "";
			vector<int> face;
			for(auto str2 : u.explode(l," ")){
				if(str2 != "f"){
					face.push_back(to<int>(u.explode(str2,"//")[0])-1);
				}
			}
			faces.push_back(face);
		}
	}
	//print_r(faces);
	test = t;

	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //| GLUT_DEPTH);
	glutInitWindowSize(400, 300);
	glutCreateWindow("");
	//init();
	glutDisplayFunc(display);
	
	glutTimerFunc(10, aaa, 0);
	
	//glMatrixMode(GL_MODELVIEW);
	glFrustum(-2, 2, -1.5, 1.5, 1, 200);

	//glLoadIdentity();
	//glTranslatef(0,-5,0);
	glTranslatef(0,-0.5,-5);
	glRotatef(40,1,0,0);	
	//glDepthMask(GL_TRUE);
	//glMatrixMode(GL_PROJECTION);
	//glEnable( GL_LIGHTING );
	//glutReshapeFunc(reshape);
	glutMainLoop();
}
