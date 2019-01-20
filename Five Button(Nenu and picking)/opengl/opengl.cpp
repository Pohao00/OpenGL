#include "glut.h"
#include "stdio.h"
#include "stdlib.h"
#define NULL 0
#define LINE 1
#define RECTANGLE 2
#define TRIANGLE 3
#define POINTS 4
#define TEXT 5


GLfloat ww=800,wh=600;
GLfloat r,g,b,size,fill;
GLint c_menu,p_menu,f_menu;

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

void right_menu(int id)
{
	if(id == 1) 
		{exit(0);}
	else 
		{display();}
} 

void middle_menu(int id)
{
}

void color_menu(int id)
{if(id == 1) {r = 1.0; g = 0.0; b = 0.0;} 
else if(id == 2) {r = 0.0; g = 1.0; b = 0.0;}
else if(id == 3) {r = 0.0; g = 0.0; b = 1.0;}
else if(id == 4) {r = 0.0; g = 1.0; b = 1.0;}
else if(id == 5) {r = 1.0; g = 0.0; b = 1.0;}
else if(id == 6) {r = 1.0; g = 1.0; b = 0.0;}
else if(id == 7) {r = 1.0; g = 1.0; b = 1.0;}
else if(id == 8) {r = 0.0; g = 0.0; b = 0.0;}
}

void pixel_menu(int id)
{
	if (id == 1) size = 2 * size;
	else if (size > 1) size = size/2;
}

void fill_menu(int id)
{
	if (id == 1) fill = 1;
	else fill = 0;
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

int pick(int x, int y)      
{   y = wh - y;
	if(y < wh-ww/10) return 0;
	else if(x < ww/10) return LINE;
	else if(x < ww/5) return RECTANGLE;
	else if(x < 3*ww/10) return TRIANGLE;
	else if(x < 2*ww/5) return POINTS;
	else if(x < ww/2) return TEXT;                    
	else return 0;
}

void mouse(int button, int state,int x, int y) 
{
	pick(x,y);
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
	glutCreateWindow("Five Button(Nenu and picking)");
	init();
	
	c_menu = glutCreateMenu(color_menu);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Green",2);
	glutAddMenuEntry("Blue",3);
	glutAddMenuEntry("Cyan",4);
	glutAddMenuEntry("Magenta",5);
	glutAddMenuEntry("Yellow",6);
	glutAddMenuEntry("White",7);
	glutAddMenuEntry("Black",8);

	p_menu = glutCreateMenu(pixel_menu);
	glutAddMenuEntry("increase pixel size", 1);
	glutAddMenuEntry("decrease pixel size", 2);
	f_menu = glutCreateMenu(fill_menu);
	glutAddMenuEntry("fill on", 1);
	glutAddMenuEntry("fill off", 2);  
	
	glutCreateMenu(right_menu); 
	glutAddMenuEntry("quit", 1);
	glutAddMenuEntry("clear", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutCreateMenu(middle_menu); 
	glutAddSubMenu("Colors", c_menu);
	glutAddSubMenu("Pixel Size", p_menu);
	glutAddSubMenu("Fill", f_menu);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	glutDisplayFunc(display);
	glutReshapeFunc(ChangeSize);
	glutMouseFunc (mouse);
	glutMainLoop();
	return 0;
}