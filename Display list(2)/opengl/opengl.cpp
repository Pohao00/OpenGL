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
GLfloat angle;
void OurFont(GLint c)
{
	GLfloat r=2;
	switch(c)
	{
		case 1:
		glTranslatef(0,-1.5,0);
		glBegin(GL_LINES);
		glVertex2f(0.025*r,0.085*r);
		glVertex2f(0.025*r,0.015*r);
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(int i=0;i<=12;i++)
		{
			angle=3.14/6*i;
			glVertex2f(0.025*r*cos(angle)+0.05*r,0.025*r*sin(angle)+0.0625*r);
		}
		glEnd();		
		break;
		
		case 2:
		glTranslatef(0.15,0,0);
		glBegin(GL_LINES);
		glVertex2f(0.025*r,0.085*r);
		glVertex2f(0.025*r,0.015*r);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.025*r,0.05*r);
		glVertex2f(0.075*r,0.05*r);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.075*r,0.085*r);
		glVertex2f(0.075*r,0.015*r);
		glEnd();
		break;
		
		case 3:
		glTranslatef(0.2,0,0);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0.07*r,0.09*r);
		glVertex2f(0.04*r,0.09*r);

		glVertex2f(0.025*r,0.07*r);

		glVertex2f(0.04*r,0.05*r);
		glVertex2f(0.06*r,0.05*r);

		glVertex2f(0.075*r,0.03*r);

		glVertex2f(0.06*r,0.01*r);
		glVertex2f(0.03*r,0.01*r);
		glEnd();
		break;

		case 4:
		glTranslatef(0.15,0,0);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0.025*r,0.085*r);
		glVertex2f(0.025*r,0.03*r);
		glVertex2f(0.037*r,0.025*r);

		glVertex2f(0.05*r,0.022*r);

		glVertex2f(0.063*r,0.025*r);
		glVertex2f(0.075*r,0.03*r);
		glVertex2f(0.075*r,0.085*r);
		
		glEnd();
		break;

	}
}
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
	glLineWidth(3);
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
		//glVertex3d(-1,0,0);
		//glVertex3d(1,0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	for(double i=-3;i<=3;i+=0.1)
	{
		x=i;
		y=sin(i*10*c/5)/4-0.5;
		z=0;
		glVertex3d(x,y,z);
	}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUAD_STRIP);//�Ψ�
		glVertex3d(-1.0,1,0.5);
		glVertex3d(-1.0,1,0);
		glVertex3d(0.5,1,0.5);
		glVertex3d(0.5,1,0);
		glVertex3d(0.5,1.5,0.5);
		glVertex3d(0.5,1.5,0);

		glVertex3d(-0.5,1.5,0.5);
		glVertex3d(-0.5,1.5,0);
		glVertex3d(-0.5,2.5,0.5);
		glVertex3d(-0.5,2.5,0);

		glVertex3d(-1.0,2.5,0.5);
		glVertex3d(-1.0,2.5,0);
		glVertex3d(-1.0,1,0.5);
		glVertex3d(-1.0,1,0);
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	    glBegin(GL_TRIANGLE_FAN); //�γ�
	    glColor3f(1.0f, 0.0f, 1.0f);
	    glVertex3d(0,1.25,1);
	    glVertex3d(-0.5,1,0.5);
	    glVertex3d(0.5,1,0.5);
	    glVertex3d(0.5,1.5,0.5);
	    glVertex3d(-0.5,1.5,0.5);
	    glVertex3d(-0.5,1,0.5);
	    glEnd();
		glBegin(GL_TRIANGLE_FAN); //�γ�
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3d(-0.75,1.75,1);
		glVertex3d(-1,1,0.5);
		glVertex3d(-0.5,1,0.5);
		glVertex3d(-0.5,2.5,0.5);
		glVertex3d(-1,2.5,0.5);
		glVertex3d(-1,1,0.5);
		glEnd();

		
        glBegin(GL_LINE_STRIP); //��
        glVertex3d(-0.1,1,0);
        glVertex3d(-0.1,1,0.2);
        glVertex3d(0.1,1,0.2);
        glVertex3d(0.1,1,0);
        glEnd();
        
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_POLYGON); //�e���p��
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3d(0.1,1,0);
		glVertex3d(0.1,0.8,0);
		glVertex3d(3,0.8,0);
		glVertex3d(3,0.6,0);
		glVertex3d(-3,0.6,0);
		glVertex3d(-3,0.8,0);
		glVertex3d(-0.1,0.8,0);
		glVertex3d(-0.1,1,0);
		glVertex3d(0.1,1,0);
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glBegin(GL_POLYGON); //�s
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
			x=cos(i*c/180);
			y=12;
			z=3+sin(i*c/180);
			glVertex3d(x,y,z);
		}
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_LINES); //��a
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
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //��
		glColor3f(0.8f, 0.8f, 0.0f);
		for(int j=0;j<5;j++)
		{
			glBegin(GL_POLYGON);
			for(double i=0;i<=360;i++)
			{
				x=1+cos(i*c/180)/30+flox[j];
				y=1.5;
				z=0.2+sin(i*c/180)/30+floz[j];
				glVertex3d(x,y,z);
			}glEnd();
		}
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3d(1,1.5,0);
		glVertex3d(1,1.5,0.2);
		glEnd();

		glColor3f(0.8f, 0.2f, 0.2f);
		for(int j=0;j<5;j++)
		{
			glBegin(GL_POLYGON);
			for(double i=0;i<=360;i++)
			{
				x=-1.5+cos(i*c/180)/30+flox[j];
				y=1.5;
				z=0.2+sin(i*c/180)/30+floz[j];
				glVertex3d(x,y,z);
			}glEnd();
		}
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3d(-1.5,1.5,0);
		glVertex3d(-1.5,1.5,0.2);
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

//=======================================================================
/*glMatrixMode(GL_PROJECTION);
glLoadIdentity();
*/
		for(int i=1;i<=4;i++)
		{
			
			glNewList(i,GL_COMPILE);
			OurFont(i);
			glEndList();
			
		//gluOrtho2D(0,2,0,2);
			glCallList(i);
		}
		glMatrixMode(GL_MODELVIEW);
		glFlush();
	}

	int main(int argc, char** argv)
	{
	glutInitWindowSize(600,400);         //�������e 
    glutInitWindowPosition(600,80);         //�������W������m 
    glutCreateWindow("Display list(2)");
    glutDisplayFunc(display);
    glutMouseFunc(Mouse); 
    glutMotionFunc(MotionMouse); 
	glMatrixMode(GL_PROJECTION); // �n�]�wProjection�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(Projection)�������x�} �� 
	gluPerspective(45.0 /* �����ޥ� */,1.0 /* �����e���H�� */,0.1 /* �i���̪�Z�� */,10000.0 /* �i���̻��Z�� */);
	glutMainLoop();
	return 0;
}

