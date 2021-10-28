#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cpp-lib/files.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>
#include <cpp-lib/parser.hpp>

struct obj{
	vector<float> x;
	vector<float> y;
	vector<float> z;

	vector<vector<int>> faces;

	void show(){
		for(auto face : this->faces){
			glBegin(GL_POLYGON);
			for(auto index : face){
				glVertex3f(this->x[index],this->y[index],this->z[index]);
			}
			glEnd();
		}
	}
};


obj loadObj(std::string fn){
	obj t;
	Util u = Util();
	Files f = Files();
	
	for(auto l : f.getLines(fn.c_str())){
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
					if(u.has(str2,"//")){
						face.push_back(to<int>(u.explode(str2,"//")[0])-1);
					}else{
						face.push_back(to<int>(u.explode(str2,"/")[0])-1);
					}
				}
			}

			t.faces.push_back(face);
		}
	}

	return t;
}

obj torus = loadObj("torus.obj");

void display(){
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	torus.show();
	glTranslatef(0,0.5,0);
	torus.show();
	glTranslatef(0,-0.5,0);
	glFlush();
}

int x=1,y=0,z=0;
void after(int n){
	glutPostRedisplay();
	if(z == 0 && y ==0 && x == 0){
		x = 1;
	}else{
		x = 0;
	}
	
	if(x == 0 && z == 0 && y == 0){
		y = 1;
	}else{
		y = 0;
	}
	
	if(x == 0 && y == 0 && z == 0){
		z = 1;
	}else{
		z = 0;
	}
	if(x == 0 && y == 0 && z == 0){
		x = 1;
	}
	glColor3f(x,y,z);
	glRotatef(5,0,0,1);
	glRotatef(20,0,1,0);
	glutTimerFunc(30,after,0);
}

main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(400, 300);
	glutCreateWindow("");
	glutDisplayFunc(display);
	glutTimerFunc(30,after,0);
	glRotatef(40,1,0,0);
	glutMainLoop();
}
