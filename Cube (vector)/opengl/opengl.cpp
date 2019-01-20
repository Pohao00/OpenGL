#include "glut.h"


GLfloat ww=600,wh=400;

void display()
{
	
    //glClearColor (0.8, 0.8, 0.8, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW); // 要設定ModelView矩陣 ☆
	glLoadIdentity(); // 轉換現在設定的矩陣(ModelView)成為單位矩陣 ☆
	gluLookAt(4,-4,4,0,0,0,0,1,0);
	
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glNormal3f(1,0,0);
	glVertex3d(1,1,1);
	glVertex3d(1,-1,1);
	glVertex3d(1,-1,-1);
	glVertex3d(1,1,-1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0,1,0);
	glVertex3d(1,1,1);
	glVertex3d(1,1,-1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,1,1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,-1,1);
	glVertex3d(1,-1,1);
	glEnd();
	
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,-1,1);
	glVertex3d(1,-1,1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1,0,0);
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	glVertex3d(-1,-1,1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0,-1,0);
	glVertex3d(1,-1,1);
	glVertex3d(-1,-1,1);
	glVertex3d(-1,-1,-1);
	glVertex3d(1,-1,-1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0,0,-1);
	glVertex3d(1,1,-1);
	glVertex3d(1,-1,-1);
	glVertex3d(-1,-1,-1);
	glVertex3d(-1,1,-1);
	glEnd();

	glFlush( );
	
}

/*void ChangeSize(GLsizei w, GLsizei h)
    {   glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glViewport(0, 0, w, h);
        glClearColor (0.8, 0.8, 0.8, 1.0);
        glClear(GL_COLOR_BUFFER_BIT); 
        display();  
        glFlush();
        ww = w;
        wh = h; 
}*/


void init()
{
   //glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);    
	glLoadIdentity( );
	glOrtho(-3, 3, -3, 3 ,-3, 3);
   glMatrixMode(GL_MODELVIEW); // 要設定ModelView矩陣 ☆
	glLoadIdentity(); // 轉換現在設定的矩陣(ModelView)成為單位矩陣 ☆
	
}

int main(int argc,char **agrv)
{
	glutInitWindowSize(ww, wh); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Cube (vector)");
	init();
	glutDisplayFunc(display);
	//glutReshapeFunc(ChangeSize);
	glMatrixMode(GL_PROJECTION); // 要設定Projection矩陣 ☆
	glLoadIdentity(); // 轉換現在設定的矩陣(Projection)成為單位矩陣 ☆ 
	gluPerspective(45.0 /* 先不管它 */,1.0 /* 視窗寬除以高 */,0.1 /* 可視最近距離 */,10000.0 /* 可視最遠距離 */);
	glutMainLoop();
	return 0;
}