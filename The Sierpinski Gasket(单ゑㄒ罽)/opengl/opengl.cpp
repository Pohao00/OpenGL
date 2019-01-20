#include"iostream"
#include"glut.h"
 //using namespace std;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	GLfloat vertices[3][3] = {{-100.0, -100.0, 0}, {0.0, 100.0, 0}, {100.0, -100.0, 0}};                             
	GLfloat p[3] = {0, 0.1, 0}; 
	int j, k;
	int rand();   
	//glBegin(GL_POLYGON);
	glVertex3fv(p); 
	for(k = 0; k < 5000; k++)
	{
		j = (int)rand()%3;                                 
		p[0] = (p[0] + vertices[j][0]) / 2;   
		p[1] = (p[1] + vertices[j][1]) / 2;      
		glVertex3fv(p);                              
	}
	glEnd();                                     
	glFlush();                                   
}

void Reshape(int w,int h)
{
	GLfloat aspectRatio;
	if (h == 0)  h = 1;        //預防h為0,無法÷

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
		glOrtho(-100, 100, -100/aspectRatio,
			100/aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100*aspectRatio, 
			100*aspectRatio, -100, 100,
			1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutCreateWindow("The Sierpinski Gasket(等比例縮放)");
	glutDisplayFunc(display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}

