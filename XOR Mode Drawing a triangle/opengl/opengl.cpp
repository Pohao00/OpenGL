#include "glut.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

float xm, ym, xmm, ymm ,x=0,y=2;
int first = 0,s=0,l=30;

void display( )
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0);
	glEnable(GL_COLOR_LOGIC_OP);

	glFlush();
}

void mouse(int btn, int state, int x, int y)
{ 
	if (btn == GLUT_LEFT_BUTTON && 
		state == GLUT_DOWN)
		{ xm = x;
			ym = (500-y);
			glColor3f(0.0, 0.0, 1.0);
			glBegin(GL_POLYGON);
			glVertex2f(xm, ym+l);
			glVertex2f(xm-l, ym-l);
			glVertex2f(xm+l, ym-l);
			glEnd();

			

			glFlush();
			glLogicOp(GL_XOR);
			first = 0;
			s=1;  }
			if (btn == GLUT_LEFT_BUTTON && 
				state == GLUT_UP)
				{ glColor3f(1.0, 1.0, 0.0);
					xmm = x;
					ymm = (500-y);
					glLogicOp(GL_COPY);
					
					glBegin(GL_POLYGON);
					glVertex2f(xmm, ymm+l);
					glVertex2f(xmm-l, ymm-l);
					glVertex2f(xmm+l, ymm-l);
					glEnd();
					
					
					glFlush(); }
				}
				void move(int x, int y)
				{
					if (s == 1)
					{ 
						glBegin(GL_POLYGON);
						glVertex2f(xm, ym+l);
						glVertex2f(xm-l, ym-l);
						glVertex2f(xm+l, ym-l);
						glEnd();
						s=0;
						glFlush(); }

						if (first == 1)
						{ 
							glBegin(GL_POLYGON);
							glVertex2f(xmm, ymm+l);
							glVertex2f(xmm-l, ymm-l);
							glVertex2f(xmm+l, ymm-l);
							glEnd();
							
							glFlush(); }
							xmm = x;
							ymm = (500-y);
							glBegin(GL_POLYGON);
							glVertex2f(xmm, ymm+l);
							glVertex2f(xmm-l, ymm-l);
							glVertex2f(xmm+l, ymm-l);
							glEnd();
							
							glFlush();
							first = 1;
						}



						void init()
						{
							glClearColor(0.0, 0.0, 0.0, 0.0); 
							glViewport(0, 0, 500, 500);
							glMatrixMode(GL_PROJECTION);    
							glLoadIdentity( );
							glOrtho(0.0, 500 , 0.0, 500 ,
								-1.0, 1.0);
							glMatrixMode(GL_MODELVIEW);
						}

						int main(int argc,char** argv)
						{
							
							glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
							glutInitWindowSize(500, 500);
   //glutInitWindowPosition(100, 100);
							glutCreateWindow("XOR Mode: Drawing a triangle");
							init( );
							
							glutDisplayFunc(display);
							glutMouseFunc(mouse);
							glutMotionFunc(move);
							glutMainLoop( );
							return 0;
						}