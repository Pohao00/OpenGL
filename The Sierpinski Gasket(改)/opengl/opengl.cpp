#include"iostream"
#include"glut.h"
 //using namespace std;
void display()
{


	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	GLfloat vertices[3][3] = {{25, 0.0, 0}, {0, -50, 0}, {50, -50.0, 0}}; 
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

int main(int argc, char** argv)
{
 glutInitWindowSize(300,300); //�������e 
glutInitWindowPosition(0,0); //�������W������m 

glutCreateWindow("The Sierpinski Gasket(��)");
glutDisplayFunc(display);
 glMatrixMode(GL_PROJECTION); // �n�]�wProjection�x�} ��
 glLoadIdentity(); // �ഫ�{�b�]�w���x�}(Projection)�������x�} �� 
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity( );
 gluOrtho2D(0.0, 50.0, -50.0, 0.0);
 glMatrixMode(GL_MODELVIEW);
 glutMainLoop();
 return 0;
}


