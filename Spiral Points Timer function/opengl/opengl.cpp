#include"iostream"
#include"glut.h"

void Timer(int value)
{ 
	glutPostRedisplay();    //­«¨qµe­±
	glutTimerFunc(20,Timer, 0);
}


void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,0.0,0.0,1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	static GLdouble dRadius = 0.1;
	static GLdouble dAngle = 0.0;               
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	if(dAngle == 0.0)         
		glClearColor(1.0,0.0,0.0,1.0); 
	glBegin(GL_POINTS);          
	glVertex2d(dRadius * cos(dAngle), 
		dRadius * sin(dAngle));
	glEnd();
	dRadius *= 1.01;
	dAngle += 0.1;
	if(dAngle > 30.0) 
		{dRadius = 0.1;
			dAngle = 0.0; }
			glFlush();

		}

		int main(int argc, char** argv)
		{
			glutCreateWindow("Spiral Points: Timer function");
			glutDisplayFunc(display);
			glutTimerFunc(50, Timer, 0);
			glutMainLoop();
			return 0;
		}

