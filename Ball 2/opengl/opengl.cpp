#include"iostream"
#include"glut.h"
 //using namespace std;
void display()
{
	double c,i1,x,y,z;
	double M_PI=3.14159;

	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glMatrixMode(GL_MODELVIEW); // �n�]�wModelView�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(ModelView)�������x�} ��
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
	glMatrixMode(GL_PROJECTION); // �n�]�wProjection�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(Projection)�������x�} �� 
	gluPerspective(45.0 /* �����ޥ� */,1.0 /* �����e���H�� */,0.1 /* �i���̪�Z�� */,10000.0 /* �i���̻��Z�� */);
	glutMainLoop();
	return 0;
}
//���P���{���X�i�H���ȹ��b�Ԥj�p�ɪ���û��m��
