#include "glut.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define NULL 0
#define LINE 1
#define RECTANGLE 2
#define TRIANGLE 3
#define POINTS 4
#define TEXT 5
#define CIRCLE 6

GLfloat ww=800,wh=600,rx,ry;
GLfloat r=1,g=1,b=1,size=3.0,fill=0,ra=20;
GLint c_menu,p_menu,f_menu,r_menu;
GLint draw_mode = 0;

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
	int shift = 0;         
	glPushAttrib(GL_ALL_ATTRIB_BITS);
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
	glColor3f(1.0, 0.0, 1.0);
	screen_box(ww/2,wh-ww/10,ww/10); 

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

	glBegin(GL_POLYGON);
	for(int i=0;i<=50;i++)
	{
		//ww/2,wh-ww/10,ww/10
		glVertex2f(cos(3.14/25*i)*ww/30+ww/2+ww/20,sin(3.14/25*i)*ww/30+wh-ww/10+ww/20);

	}
	glEnd();
	glPopAttrib( );
	glFlush( );
	
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

void radius_menu(int id)
{
	if(id == 1) ra=20;
	else if(id == 2) ra=30;
	else if(id == 3) ra=40;
	else if(id == 4) ra=80;
	else if(id == 5) ra=120;
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
	else if(x < 3*ww/5) return CIRCLE;
	else return 0;
}

void drawSquare(int x, int y)
{ y = wh - y;
	glColor3ub( (char) rand()%256, (char)
		rand()%256, (char) rand()%256);
	glBegin(GL_POLYGON);
	glVertex2f(x+size, y+size);
	glVertex2f(x-size, y+size);
	glVertex2f(x-size, y-size);
	glVertex2f(x+size, y-size);
	glEnd();
	
}

void circle(int x,int y,int r)
{
	GLfloat cx,cy;
	
	if (fill) glBegin(GL_POLYGON);
	else glBegin(GL_LINE_LOOP);
	for(int i=0;i<=50;i++)
	{
		cx=cos(3.14/25*i)*r+x;
		cy=sin(3.14/25*i)*r+(wh-y);
		glVertex2f(cx,cy);
	}
	glEnd();
}

void mouse(int button, int state,int x, int y) 
{
	static int count;  //所要畫的物件已輸入的
	
   int wheree=0;           // 所pick的結果
   static int xp[2], yp[2];        //存二個vertices
   if (button == GLUT_LEFT_BUTTON && 
   	state == GLUT_DOWN)
   	{ glPushAttrib(GL_ALL_ATTRIB_BITS);
   		
       wheree = pick(x, y);   // pick會送回被選到的 
       
       glColor3f(r, g, b); 
   }
   if (wheree != 0) 
   {  
   	count = 0;
   	draw_mode = wheree; 
   }

   else if (button == GLUT_LEFT_BUTTON && 
   	state == GLUT_DOWN)switch(draw_mode)

   { 

   	case(LINE):
   	{if (count == 0)
   		{ count++;
   			xp[0] = x;           
   			yp[0] = y;  }        
   			else
   				{ glBegin(GL_LINES);
   					glVertex2i(x, wh-y);
   					glVertex2i(xp[0], wh-yp[0]);     
   					glEnd();

   					draw_mode = 0;
   					count = 0;}
   					glPopAttrib( );
   					glFlush( ); 
   					break;}
   					case(RECTANGLE):
   					{if (count == 0)
   						{  count++;
   							xp[0] = x; yp[0] = y; }
   							else
   								{   if(fill) glBegin(GL_POLYGON);
   									else glBegin(GL_LINE_LOOP);
   									glVertex2i(x, wh-y);
   									glVertex2i(x, wh-yp[0]);
   									glVertex2i(xp[0], wh-yp[0]);
   									glVertex2i(xp[0], wh-y);
   									glEnd();
   									draw_mode = 0;
   									count = 0;  }
   									glPopAttrib( );
   									glFlush( );
   									break;}
   									case (TRIANGLE): 
   									switch(count)
   									{  case(0):
   										count++;
   										xp[0] = x;
   										yp[0] = y;
   										break;
   										case(1):
   										count++;
   										xp[1] = x;
   										yp[1] = y;
   										break;
   										case(2):
   										if (fill) glBegin(GL_POLYGON);
   										else glBegin(GL_LINE_LOOP);
   										glVertex2i(xp[0], wh-yp[0]);
   										glVertex2i(xp[1], wh-yp[1]);
   										glVertex2i(x, wh-y);
   										glEnd();
   										draw_mode = 0;
   										count = 0; }
   										glPopAttrib( );
   										glFlush( );
   										break;
   										case(POINTS):                        
   										{  
   											drawSquare(x, y); 
   											count++; }
   											glPopAttrib( );
   											glFlush( );
   											break;
   											case(TEXT):
   											{   rx = x;
   												ry = wh-y;
   												glRasterPos2i(rx, ry);    
   												count = 0; } 
   												glPopAttrib( );
   												glFlush( );
   												break;
   												case(CIRCLE):
   												{
			  //circle((xp[0]+xp[1])/2,(yp[0]+yp[1])/2,2);
   													circle(x,y,ra);
   													count ++;
   													glPopAttrib( );
   													glFlush( ); 
   													break;}	
   												}
   											}

   											void key(unsigned char k, int xx, int yy)  
   											{ if (draw_mode != TEXT) return;
   												glColor3f(0.0, 0.0, 0.0);
   												glRasterPos2i(rx, ry);
   												glutBitmapCharacter(GLUT_BITMAP_9_BY_15, k);
                     // or by glCallList(k)，利用display list
   												rx += glutBitmapWidth(GLUT_BITMAP_9_BY_15, k);                                                                                                       
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
   												glutCreateWindow("Painting(final)");
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

   												r_menu = glutCreateMenu(radius_menu);
   												glutAddMenuEntry("20R",1);
   												glutAddMenuEntry("30R",2);
   												glutAddMenuEntry("40R",3);
   												glutAddMenuEntry("80R",4);
   												glutAddMenuEntry("120R",5);
   												
   												glutCreateMenu(right_menu); 
   												glutAddMenuEntry("quit", 1);
   												glutAddMenuEntry("clear", 2);
   												glutAttachMenu(GLUT_RIGHT_BUTTON);

   												glutCreateMenu(middle_menu); 
   												glutAddSubMenu("Colors", c_menu);
   												glutAddSubMenu("Pixel Size", p_menu);
   												glutAddSubMenu("Fill", f_menu);
   												glutAddSubMenu("Circle Radius",r_menu);
   												glutAttachMenu(GLUT_MIDDLE_BUTTON);

   												glutDisplayFunc(display);
   												glutReshapeFunc(ChangeSize);
   												glutKeyboardFunc(key);
   												glutMouseFunc (mouse);
   												glutMainLoop();
   												return 0;
   											}