#include "glut.h"


GLfloat ww=800,wh=600;
void screen_box(int x, int y, int s)
{
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+s, y);
	glVertex2i(x+s, y+s); 
	glVertex2i(x, y+s);
	glEnd();
}

void display()
{
	int shift = 0;         glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor (0.8, 0.8, 0.8, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 

	glColor3f(1.0, 1.0, 1.0); 
	screen_box(0,wh-ww/10,ww/10); 
	glColor3f(1.0, 0.0, 0.0);
	screen_box(ww/10,wh-ww/10,ww/10);
	glColor3f(0.0, 1.0, 0.0);
	screen_box(ww/5,wh-ww/10,ww/10);
	glColor3f(0.0, 0.0, 1.0);
	screen_box(3*ww/10,wh-ww/10,ww/10);
	glColor3f(1.0, 1.0, 0.0);
	screen_box(2*ww/5,wh-ww/10,ww/10);  

	glColor3f(0.0, 0.0, 0.0); 
	glBegin(GL_LINES);                         
	glVertex2i(wh/40,wh-ww/20);           
	glVertex2i(wh/40+ww/20,wh-ww/20);
	glEnd();

	glBegin(GL_QUADS);                                   
	glVertex2i(ww/10+wh/40,wh-ww/40);      
	glVertex2i(ww/10+wh/40,wh-ww/10+ww/40);
	glVertex2i(ww/5-ww/40,wh-ww/10+ww/40);
	glVertex2i(ww/5-ww/40,wh-ww/40);
	glEnd();

	glBegin(GL_TRIANGLES);                                   
	glVertex2i(ww/5+ww/40,wh-ww/10+ww/40);      
	glVertex2i(ww/5+ww/20,wh-ww/40);
	glVertex2i(ww/5+3*ww/40,wh-ww/10+ww/40);
	glEnd();
	glPointSize(3.0); 
	glBegin(GL_POINTS);
	glVertex2i(3*ww/10+ww/20, wh-ww/20);
	glEnd();

	glRasterPos2i(2*ww/5,wh-ww/20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
	shift = glutBitmapWidth(GLUT_BITMAP_9_BY_15, 'A'); 
	glRasterPos2i(2*ww/5+shift, wh-ww/20);                              
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'B');
	shift += glutBitmapWidth(GLUT_BITMAP_9_BY_15, 'B');
	glRasterPos2i(2*ww/5+shift, wh-ww/20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'C');


	glFlush( );
	glPopAttrib( );
}

void ChangeSize(GLsizei w, GLsizei h)
{   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
	glClearColor (0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT); 
	display();  
	glFlush();
	ww = w;
	wh = h; 
}


void init()
{
	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);    
	glLoadIdentity( );
	glOrtho(0.0, (GLdouble) ww , 0.0, (GLdouble) wh ,
		-1.0, 1.0);
	glClearColor (0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT); 
	glFlush();
}

int main(int argc,char **agrv)
{
	glutInitWindowSize(ww, wh); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Five Button");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}