#include"iostream"
#include"glut.h"
#define BOX 1


static GLdouble windowWidth=300,windowHeight=300;


void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClear(GL_COLOR_BUFFER_BIT);
	int i = 1;
	glMatrixMode(GL_PROJECTION);
	for (i=1; i<5; i++)
		{ if (i==1)    glColor3f(0.0, 1.0, 1.0); 
			if (i==2)    glColor3f(0.0, 1.0, 0.0); 
			if (i==3)    glColor3f(0.0, 0.0, 1.0); 
			if (i==4)    glColor3f(1.0, 0.0, 0.0); 
			glLoadIdentity( );
			gluOrtho2D(-2.0*i, 2.0*i, -2.0*i, 2.0*i);
			glCallList(BOX); } 
			glFlush();
		}


		void Init()
		{
			glViewport (0, 0, windowWidth, windowHeight); 
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity ();                                
			gluOrtho2D (0.0,windowWidth,  0.0, windowHeight);
			glMatrixMode(GL_MODELVIEW);
    //glClearColor(1.0, 1.0, 1.0, 1.0); 
			glNewList(BOX, GL_COMPILE);
			glBegin(GL_POLYGON);
			glVertex2f(-1, -1);
			glVertex2f(1, -1);
			glVertex2f(1, 1);
			glVertex2f(-1, 1);
			glEnd( );
			glEndList( );
			
		}
		void ChangeSize(GLsizei w, GLsizei h) 
		{ 
			GLfloat aspectRatio;
			if (h == 0) h = 1;
			glViewport(0, 0, w, h);
			glMatrixMode(GL_PROJECTION);  
			glLoadIdentity(); 
			aspectRatio = (GLfloat)w / (GLfloat)h;
			
			if (w <= h) 
				{ windowWidth = 300;
					windowHeight = 300 / aspectRatio;
					glOrtho (0, 300, 0, 
						windowHeight, 1.0, -1.0); }   
					else 
						{ windowWidth = 300 * aspectRatio;
							windowHeight = 300;
							glOrtho (0, windowWidth, 0, 
								300, 1.0, -1.0); }
							
							glMatrixMode(GL_MODELVIEW);
							glLoadIdentity ();
						}

						int main(int argc, char** argv)
						{
							glutInit(&argc, argv);
							glutInitWindowSize(windowWidth, windowHeight); 
							glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
							glutCreateWindow("Display list(1)");
							Init();
							glutDisplayFunc(display);
							glutReshapeFunc(ChangeSize);
							glutMainLoop();
							return 0;
						}

