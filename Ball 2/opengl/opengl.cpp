#include"iostream"
#include"glut.h"
 //using namespace std;
void display()
{
	double c,i1,x,y,z;
	double M_PI=3.14159;

	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glMatrixMode(GL_MODELVIEW); // 要設定ModelView矩陣 ☆
	glLoadIdentity(); // 轉換現在設定的矩陣(ModelView)成為單位矩陣 ☆
	gluLookAt(2,2,2,0,0,0,1,0,1);
	glBegin(GL_QUAD_STRIP);
	c=M_PI/180;
	for(int i=-80;i<=80;i+=15)
	{
		i1=(i+15);
		for(int j=-180;j<=180;j+=15)
		{
			x=sin(j*c)*cos(i*c);
			y=cos(j*c)*cos(i*c);
			z=sin(i*c);
			glVertex3d(x,y,z);
			x=sin(j*c)*cos(i1*c);
			y=cos(j*c)*cos(i1*c);
			z=sin(i1*c);
			glVertex3d(x,y,z);
		}
		
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0,0,-1);
	for(int i=-180;i<=180;i+=20)
	{
		x=sin(i*c)*cos(-80*c);
		y=cos(i*c)*cos(-80*c);
		z=sin(-80*c);
		glVertex3d(x,y,z);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0,0,1);
	for(int i=-180;i<=180;i+=20)
	{
		x=sin(i*c)*cos(80*c);
		y=cos(i*c)*cos(80*c);
		z=sin(80*c);
		glVertex3d(x,y,z);
	}
	glEnd();
	glFlush(); 
	
}

int main(int argc, char** argv)
{
	glutCreateWindow("Ball");
	glutDisplayFunc(display);
	glMatrixMode(GL_PROJECTION); // 要設定Projection矩陣 ☆
	glLoadIdentity(); // 轉換現在設定的矩陣(Projection)成為單位矩陣 ☆ 
	gluPerspective(45.0 /* 先不管它 */,1.0 /* 視窗寬除以高 */,0.1 /* 可視最近距離 */,10000.0 /* 可視最遠距離 */);
	glutMainLoop();
	return 0;
}
//有星號程式碼可以讓銀幕在拉大小時物體永遠置中
