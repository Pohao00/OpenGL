#include "glut.h"
#include "stdio.h"
#include "stdlib.h"
#define SIZE 512

GLint nameBuffer[];

void draw_objects(GLenum mode)
{
	if (mode == GL_SELECT) glLoadName(1);
	glColor3f (1.0, 0.0, 0.0);
	glRectf(-0.5, -0.5, 1.0, 1.0);
	
	if (mode == GL_SELECT) glLoadName(2);
	glColor3f (0.0, 0.0, 1.0);
	glRectf(-1.0, -1.0, 0.5, 0.5); 
}


void display( )
{
	glClear (GL_COLOR_BUFFER_BIT);
	draw_objects(GL_RENDER); 
	glFlush( );
}

void processHits(GLint hits, GLuint buffer[ ] )
{ 
	unsigned int i, j;
	GLuint names, *ptr;
	printf("hits=%d\n", hits);   
	ptr = (GLuint*) buffer;
	for (i = 0; i < hits;i++)
		{  names = *ptr;
			ptr += 3;
			for (j = 0; j < names; j++)
				{ if (*ptr == 1) printf ("red rectangle\n");
			else printf("blue rectangle\n");
			ptr++ ;
		}
	}
}


void mouse(int button, int state, int x, int y)
{  GLuint selectBuf[SIZE];
	GLint hits;
	GLint viewport[4]; 
	if (button == GLUT_LEFT_BUTTON && state ==  GLUT_DOWN)
		{  glGetIntegerv(GL_VIEWPORT, viewport);
			glSelectBuffer(SIZE, selectBuf);
			glRenderMode(GL_SELECT);
			glInitNames( );
			glPushName(0);
			glMatrixMode(GL_PROJECTION);     
			glPushMatrix( );
			glLoadIdentity( ); 
			gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 
				5.0, 5.0, viewport);
			gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
			draw_objects(GL_SELECT);   
			glMatrixMode(GL_PROJECTION); 
			glPopMatrix( );
			glFlush( );
			hits = glRenderMode(GL_RENDER);
			processHits(hits, selectBuf);
			glutPostRedisplay( ); 
		}
	}


	void keyboard(unsigned char key, int x, int y)
	{
		switch(key)
		{
      case 27:            //ESC
      exit(0);
      break;
  }
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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Picking");
	init( );
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop( );
	return 0;
}