#include"iostream"
#include"glut.h"
 //using namespace std;

int old_rot_x=0;   //����U�ƹ��ɪ������y�� 
int old_rot_y=0; 

 int rot_x=0;      //�즲�᪺�۹�y�СA�γo�M�w�n����X�� 
 int rot_y=0; 

 int record_x=0;      //�����W�@�����઺���� 
 int record_y=0; 

void Mouse(int , int , int , int );         //����ƹ����U�M��}�ɪ��T�� 
void MotionMouse(int , int );            //����ƹ����U�������T�� 

GLubyte fire[128]={		0x00,0x7f,0xf4,0x00,
	0x00,0x80,0x04,0x00,
	0x01,0xff,0xfc,0x00,
	0x02,0x00,0x04,0x00,
	0x07,0xff,0x0fc,0x00,
	0x08,0xc0,0x02,0x00,
	0x0f,0xff,0xff,0x00,
	0x0e,0x89,0x38,0x80,
	0x01,0xff,0xf7,0x40,
	0x02,0x19,0x8a,0x40,
	0x03,0xef,0x7d,0xc0,
	0x02,0x19,0x64,0x00,  
	0x03,0xcf,0x3e,0x00,
	0x03,0x89,0x12,0x00,
	0x00,0x0f,0x0e,0x00,
	0x00,0x09,0x00,0x00,
	0x00,0x0f,0x00,0x00,
	0x00,0x06,0x00,0x00

};  

void Mouse(int button, int state, int x, int y) 
{ 
	if(state) 
	{ 
		record_x += x - old_rot_x; 
		record_y += y - old_rot_y; 
		
       rot_x = 0;   //�S���k�s�|�����z�Q�����G 
       rot_y = 0; 
   } 
   else 
   { 
   	old_rot_x = x; 
   	old_rot_y = y; 
   } 
} 

void MotionMouse(int x, int y) 
{ 
	rot_x = x - old_rot_x; 
	rot_y = y - old_rot_y; 
	glutPostRedisplay(); 
}

void display()
{
	double c,x,y,z;
	double M_PI=3.14159;
	int len;
	double flox[5]={0.05,0,-0.05,0},floz[5]={0,0.05,0,-0.05};

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glLineWidth(10);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glMatrixMode(GL_MODELVIEW); // �n�]�wModelView�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(ModelView)�������x�} ��
	gluLookAt(1,-5,2,0,1,0.5,0,1,1);
	glRotatef((float)rot_y+(float)record_y, 1.0, 0.0, 0.0);//�Hx�b�����b 
    glRotatef((float)rot_x+(float)record_x, 0.0, 1.0, 0.0);//�Hy�b�����b 
    
	glBegin(GL_LINE_STRIP); //�e�y
	glColor3f(0.0f, 0.0f, 1.0f);
	c=M_PI;
	for(double i=-3;i<=3;i+=0.1)
	{
		x=i;
		y=sin(i*10*c/5)/4;
		z=0;
		glVertex3d(x,y,z);
	}
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	
	for(double i=-3;i<=3;i+=0.1)
	{
		x=i;
		y=sin(i*10*c/5)/4-0.25;
		z=0;
		glVertex3d(x,y,z);
	}
	
	glEnd();
	glLineWidth(10);
	glBegin(GL_LINE_STRIP);
	
	for(double i=-3;i<=3;i+=0.1)
	{
		x=i;
		y=sin(i*10*c/5)/4-0.5;
		z=0;
		glVertex3d(x,y,z);
	}
	glEnd();
	
	glLineWidth(3);
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //�Ψ�
		glColor3f(1.0f, 1.0f, 0.5f);

		glBegin(GL_QUAD_STRIP);
		
		glVertex3d(-2.0,1,0.5);
		glVertex3d(-2.0,1,0);
		glVertex3d(1,1,0.5);
		glVertex3d(1,1,0);
		glVertex3d(1,2,0.5);
		glVertex3d(1,2,0);

		glVertex3d(-0.5,2,0.5);
		glVertex3d(-0.5,2,0);
		glVertex3d(-0.5,3,0.5);
		glVertex3d(-0.5,3,0);

		glVertex3d(-2.0,3,0.5);
		glVertex3d(-2.0,3,0);
		glVertex3d(-2.0,1,0.5);
		glVertex3d(-2.0,1,0);
		glEnd();

		glLineWidth(6);
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3d(1.1,2.5,0.5);
		glVertex3d(1.1,2.5,0);
		glEnd();

		glLineWidth(3);
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//�γ�
		glBegin(GL_TRIANGLE_FAN); 
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3d(0.25,1.75,1);
		glVertex3d(-0.5,0.9,0.5);
		glVertex3d(1.1,0.9,0.5);
		glVertex3d(1.1,2.5,0.5);
		glVertex3d(-0.5,2.5,0.5);
		glVertex3d(-0.5,0.9,0.5);
		glEnd();
		glBegin(GL_TRIANGLE_FAN); //�γ�
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3d(-1.25,2,1);
		glVertex3d(-2.1,0.9,0.5);
		glVertex3d(-0.5,0.9,0.5);
		glVertex3d(-0.5,3.1,0.5);
		glVertex3d(-2.1,3.1,0.5);
		glVertex3d(-2.1,0.9,0.5);
		glEnd();

		
        glBegin(GL_LINE_STRIP); //��
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3d(-0.1,1,0);
        glVertex3d(-0.1,1,0.2);
        glVertex3d(0.1,1,0.2);
        glVertex3d(0.1,1,0);
        glEnd();
        
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glBegin(GL_POLYGON); //�e���p��
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3d(0.1,1,0);
		glVertex3d(0.1,0.8,0);

		glVertex3d(-0.1,0.8,0);
		glVertex3d(-0.1,1,0);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3d(3,0.8,0);
		glVertex3d(3,0.6,0);
		glVertex3d(-3,0.6,0);
		glVertex3d(-3,0.8,0);
		
		//glVertex3d(0.1,1,0);
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//�s
		glBegin(GL_POLYGON); 
		glColor3f(1.0f, 0.0f, 0.0f);
		for(double i=-10;i<=10;i+=0.1)
		{
			x=i;
			y=9;
			z=sin(i*10*c/15)*2;
			if(z<0)
				z=z*(-1)/2;
			glVertex3d(x,y,z);
		}
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3d(10,9,0);
		glVertex3d(-10,9,0);
		/*for(double i=10;i>=-10;i=i-0.1)
		{
				x=i;
				y=sin(i*10*c/20)+8;
				z=0;
				glVertex3d(x,y,z);
		}*/
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //��G
		glBegin(GL_POLYGON);
		glColor3f(0.8f, 0.8f, 0.0f);
		for(double i=0;i<=360;i++)
		{
			x=cos(i*c/180)+3;
			y=12;
			z=3+sin(i*c/180);
			glVertex3d(x,y,z);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0f,0.0f,0.1f);
		glVertex3d(15,13,20);

		glColor3f(0.0f,0.0f,0.1f);
		glVertex3d(15,13,0);

		glColor3f(1.0f,1.0f,0.9f);
		glVertex3d(3,13,3);

		glColor3f(0.0f,0.0f,0.1f);
		glVertex3d(-20,13,0);

		glColor3f(0.0f,0.0f,0.1f);
		glVertex3d(-20,13,20);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0f,1.0f,0.9f);
		glVertex3d(3,13,3);
		glColor3f(0.0f,0.0f,0.01f);
		glVertex3d(15,13,0);
		glColor3f(0.0f,0.0f,0.1f);
		glVertex3d(-20,13,0);
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//��a
		glBegin(GL_LINES); 
		glColor3f(0.0f, 1.0f, 0.0f);
		y=5;
		for(int j=0;j<5;j++)
		{
			for(double i=0;i<=20;i++)
			{
				x=(rand()%10+1)/3;
				if((x>-0.5&&x<0.5&&y<1.5)||(x<0.5&&x>-0.5&&y<1.5))
					continue;
				if(i>=10)
					x=x*(-1);
				glVertex3d(x,y,0);
				glVertex3d(x+0.2,y,0);
			}
			y--;
		}
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glBegin(GL_POLYGON);
		glColor3f(0.1f, 0.2f, 0.0f);
		glVertex2f(-9, 8);
		glVertex2f(-9, 1);
		glColor3f(0.1f, 0.2f, 0.0f);
		glVertex2f(9, 1);
		glVertex2f(9, 8);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(3, 8);
		glColor3f(0.1f, 0.2f, 0.0f);
		glVertex2f(-9, 1);
		glVertex2f(9, 1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(3, 8);
		glColor3f(0.1f, 0.2f, 0.0f);
		glVertex2f(9, 8);
		glVertex2f(9, 1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(3, 8);
		glColor3f(0.1f, 0.2f, 0.0f);
		glVertex2f(-9, 8);
		glVertex2f(-9, 1);
		glEnd();

		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //��
		glColor3f(0.8f, 0.8f, 0.0f);
		for(int j=0;j<5;j++)
		{
			glBegin(GL_POLYGON);
			for(double i=0;i<=360;i++)
			{
				x=2+cos(i*c/180)/30+flox[j];
				y=1.5;
				z=0.2+sin(i*c/180)/30+floz[j];
				glVertex3d(x,y,z);
			}glEnd();
		}
		glBegin(GL_LINES);
		glShadeModel(GL_SMOOTH);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3d(2,1.5,0);
		glVertex3d(2,1.5,0.2);
		glEnd();

		glColor3f(0.8f, 0.2f, 0.2f);
		for(int j=0;j<5;j++)
		{
			glBegin(GL_POLYGON);
			for(double i=0;i<=360;i++)
			{
				x=-2.5+cos(i*c/180)/30+flox[j];
				y=1.5;
				z=0.2+sin(i*c/180)/30+floz[j];
				glVertex3d(x,y,z);
			}glEnd();
		}
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3d(-2.5,1.5,0);
		glVertex3d(-2.5,1.5,0.2);
		glEnd();

		glColor3f(1.0f, 1.0f, 1.0f);
		for(int j=0;j<5;j++)
		{
			glBegin(GL_POLYGON);
			for(double i=0;i<=360;i++)
			{
				x=-0.7+cos(i*c/180)/30+flox[j];
				y=4;
				z=0.2+sin(i*c/180)/30+floz[j];
				glVertex3d(x,y,z);
			}glEnd();
		}
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3d(-0.7,4,0);
		glVertex3d(-0.7,4,0.2);
		glEnd();

		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //�ϧw
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUAD_STRIP);
		glVertex3d(-0.7,2,1.2);
		glVertex3d(-0.7,2,0);
		glVertex3d(-0.6,2,1.2);
		glVertex3d(-0.6,2,0);
		glVertex3d(-0.6,2.1,1.2);
		glVertex3d(-0.6,2.1,0);

		glVertex3d(-0.7,2.1,1.2);
		glVertex3d(-0.7,2.1,0);
		glVertex3d(-0.7,2,1.2);
		glVertex3d(-0.7,2,0);
		glEnd();
//=======================================================================
		char A[10] = {'P', 'o', 'H', 'a', 'o', 'S','U'};
		glRasterPos2f(0.7, -1.5);
		len = (int)strlen(A);
		for(int i = 0; i < len; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, A[i]);
		}
		
	glEnable(GL_POLYGON_STIPPLE);//logo
	glPolygonStipple(fire);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glBegin(GL_POLYGON);
	//glRectf(-0.5f, -0.5f, 0.0f, 0.0f);
	//glRectf(0.0f, 0.0f, 0.5f, 0.5f);
		/*glVertex3d(-1.0,1,0.5);
		glVertex3d(-1.0,1,0);
		glVertex3d(0.5,1,0.5);
		glVertex3d(0.5,1,0);*/
	glBegin(GL_QUAD_STRIP);
	
	glVertex3d(-2.0,1,0.5);
	glVertex3d(-2.0,1,0);
	glVertex3d(1,1,0.5);
	glVertex3d(1,1,0);
	glVertex3d(1,2,0.5);
	glVertex3d(1,2,0);

	glVertex3d(-0.5,2,0.5);
	glVertex3d(-0.5,2,0);
	glVertex3d(-0.5,3,0.5);
	glVertex3d(-0.5,3,0);

	glVertex3d(-2.0,3,0.5);
	glVertex3d(-2.0,3,0);
	glVertex3d(-2.0,1,0.5);
	glVertex3d(-2.0,1,0);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);

		glEnable(GL_LINE_STIPPLE);    //��u
		GLushort pattern = 0xF00F;
		glLineStipple(5, pattern);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3d(0.25,1.75,1);
		glVertex3d(-0.5,0.9,0.5);
		glVertex3d(0.25,1.75,1);
		glVertex3d(1.1,0.9,0.5);
		glVertex3d(0.25,1.75,1);
		glVertex3d(1.1,2.5,0.5);
		glVertex3d(0.25,1.75,1);
		glVertex3d(-0.5,2.5,0.5);

		glVertex3d(-1.25,2,1);
		glVertex3d(-2.1,0.9,0.5);
		glVertex3d(-1.25,2,1);
		glVertex3d(-0.5,0.9,0.5);
		glVertex3d(-1.25,2,1);
		glVertex3d(-0.5,3.1,0.5);
		glVertex3d(-1.25,2,1);
		glVertex3d(-2.1,3.1,0.5);
		glEnd();
		glDisable(GL_LINE_STIPPLE);
		glFlush();
	}


	int main(int argc, char** argv)
	{
	glutInitWindowSize(600,400);         //�������e 
    glutInitWindowPosition(0,0);         //�������W������m 
    glutCreateWindow("PoHao's house");
    glutDisplayFunc(display);
    glutMouseFunc(Mouse); 
    glutMotionFunc(MotionMouse); 
	glMatrixMode(GL_PROJECTION); // �n�]�wProjection�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(Projection)�������x�} �� 
	gluPerspective(45.0 /* �����ޥ� */,1.0 /* �����e���H�� */,0.1 /* �i���̪�Z�� */,10000.0 /* �i���̻��Z�� */);
	glutMainLoop();
	return 0;
}

