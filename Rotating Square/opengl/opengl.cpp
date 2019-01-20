#include "glut.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

GLfloat thetar,theta;

void display( )
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0);
	glBegin(GL_POLYGON);
	thetar = theta/(3.14159/180.0);
	glVertex2f(cos(thetar), sin(thetar));
	glVertex2f(-sin(thetar), cos(thetar));  
	glVertex2f(-cos(thetar), -sin(thetar)); 
	glVertex2f(sin(thetar), -cos(thetar));
	glEnd( );
	glutSwapBuffers( );
}

void myidle( )
{
	theta += 2;
	if (theta >=360)
		theta -= 360;
	glutPostRedisplay( );
}



void mouse (int button, int state, int x, int y)
{ if (button == GLUT_LEFT_BUTTON 
	&& state == GLUT_DOWN)
glutIdleFunc(myidle);
if (button == GLUT_MIDDLE_BUTTON
	&& state == GLUT_DOWN)
	glutIdleFunc(NULL); 
}




void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); 
}

int main(int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotating Square");
	init( );
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop( );
	return 0;
}