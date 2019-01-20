#include"iostream"
#include"glut.h"

static GLdouble x=0;
static GLdouble y=0;
static GLdouble xstep=15;
static GLdouble ystep=20;
static GLdouble rsize=50;
static GLdouble windowWidth=150,windowHeight=150;
int r;
void Timer(int value)
{ 

	GLfloat colors[][3] = {{1.0,1.0,1.0},{1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},  {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
	r=rand()%8;
	if(x > windowWidth-rsize || x < -windowWidth)
		{ xstep = -xstep;} 
	if(y > windowHeight || y < -windowHeight + rsize)
		{ ystep = -ystep; }
	x += xstep;
	y += ystep; 
	if(x > (windowWidth-rsize + xstep))
		{x = windowWidth-rsize-1;
			glColor3fv(colors[r]); 
		}
		else if(x < -(windowWidth + xstep))
			{x = -windowWidth -1;
				glColor3fv(colors[r]); }
				if(y > (windowHeight + ystep))
					{ y = windowHeight-1; 
						glColor3fv(colors[r]); }
						else if(y < -(windowHeight - rsize + ystep))
							{ y = -windowHeight + rsize - 1;
								glColor3fv(colors[r]); }
								
								glutPostRedisplay();
								glutTimerFunc(150,Timer, 0); 

							}


							void display()
							{
								
								glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
								glEnable(GL_DEPTH_TEST);
								glDepthFunc(GL_LEQUAL);
								
								glRectf(x, y, x + rsize, y - rsize); 
   glutSwapBuffers(); //使用雙緩衝 ,可以不用glFlush()
   
}
void ChangeSize(GLsizei w, GLsizei h) 
{  GLfloat aspectRatio;
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity(); 
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h) 
		{ windowWidth = 150;
			windowHeight = 150 / aspectRatio;
			glOrtho (-150, 150, -windowHeight, 
				windowHeight, 1.0, -1.0); }   
			else 
				{ windowWidth = 150 * aspectRatio;
					windowHeight = 150;
					glOrtho (-windowWidth, windowWidth, -150, 
						150, 1.0, -1.0); }
					glMatrixMode(GL_MODELVIEW);  
					glLoadIdentity();
				}

				void Init()
				{
					glOrtho(-windowWidth, windowWidth,  -windowHeight, windowHeight, 1.0, -1.0);
				}


				int main(int argc, char** argv)
				{
					glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
					glutCreateWindow("Bouncing Square");
					Init();
					glutReshapeFunc(ChangeSize);
					glutDisplayFunc(display);
					glutTimerFunc(150, Timer, 0);
					glutMainLoop();
					return 0;
				}

