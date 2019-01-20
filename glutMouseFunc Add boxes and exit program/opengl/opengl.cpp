#include"iostream"
#include"glut.h"

static GLdouble gx,gy;
static GLdouble size=10;
static GLdouble windowWidth=300,windowHeight=300;

void drawSquare(int x, int y)
{    
	y = windowHeight-y;  
	glColor3ub((char)rand()%256,
		(char)rand()%256,
		(char)rand()%256 );
	gx=x; gy=y;
	glBegin(GL_POLYGON);
	glVertex2f(x+size, y+size);   
	glVertex2f(x-size, y+size);
	glVertex2f(x-size, y-size);
	glVertex2f(x+size, y-size);
	glEnd();
	glFlush();
}

void mymouse(int btn, int state, int x, int y)          
{                  
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
		{exit(0);}

	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{drawSquare(x, y);}

}
/*void ChangeSize(GLsizei w, GLsizei h) 
   {  GLfloat aspectRatio;
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
 }*/
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	glFlush();
}


void Init()
{
	glViewport (0, 0, windowWidth, windowHeight); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity ();                                
	gluOrtho2D (0.0,windowWidth,  0.0, windowHeight);
	
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("glutMouseFunc: Add boxes and exit program");
	Init();
	glutDisplayFunc(display);
	//glutReshapeFunc(ChangeSize);
	glutMouseFunc(mymouse);
	glutMainLoop();
	return 0;
}

