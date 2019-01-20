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
	glOrtho(-50, 50, -50, 50, 50.0, -50.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); // �n�]�wModelView�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(ModelView)�������x�} ��
	gluLookAt(1,-5,2,0,0,0,0,1,1);
	glRotatef((float)rot_y+(float)record_y, 0.0, 1.0, 0.0);//�Hx�b�����b 
    glRotatef((float)rot_x+(float)record_x, 1.0, 0.0, 0.0);//�Hy�b�����b 
    
    glBegin(GL_POINTS);
    GLfloat vertices[4][3] = {{0.0, 0.0, 50}, {0.0, 50, 0}, {30, -25, 0},{-30,-25,0}};                             
    GLfloat p[3] = {0, 0, 0}; 
    int j, k;
    int rand();   
    glColor3d(1.f,0.f,0.f);
    glVertex3fv(p); 
    for(k = 0; k < 5000; k++)
    {
    	j=0;
    	while(j==0)
    		{j = (int)rand()%4;}
    	
    	p[0] = (p[0] + vertices[j][0]) / 2;   
    	p[1] = (p[1] + vertices[j][1]) / 2;
    	p[2] = (p[2] + vertices[j][2]) / 2;
    	glVertex3fv(p);                              
    }
    glColor3d(0.f,0.f,1.f);
    glVertex3fv(p); 
    for(k = 0; k < 5000; k++)
    {
    	j=1;
    	while(j==1)
    		{j = (int)rand()%4;}
    	
    	p[0] = (p[0] + vertices[j][0]) / 2;   
    	p[1] = (p[1] + vertices[j][1]) / 2;
    	p[2] = (p[2] + vertices[j][2]) / 2;
    	glVertex3fv(p);                              
    }
    glColor3d(1.f,1.f,0.f);
    glVertex3fv(p); 
    for(k = 0; k < 5000; k++)
    {
    	j=2;
    	while(j==2)
    		{j = (int)rand()%4;}
    	
    	p[0] = (p[0] + vertices[j][0]) / 2;   
    	p[1] = (p[1] + vertices[j][1]) / 2;
    	p[2] = (p[2] + vertices[j][2]) / 2;
    	glVertex3fv(p);                              
    }
    glColor3d(1.f,0.f,1.f);
    glVertex3fv(p); 
    for(k = 0; k < 5000; k++)
    {
    	j=3;
    	while(j==3)
    		{j = (int)rand()%4;}
    	
    	p[0] = (p[0] + vertices[j][0]) / 2;   
    	p[1] = (p[1] + vertices[j][1]) / 2;
    	p[2] = (p[2] + vertices[j][2]) / 2;
    	glVertex3fv(p);                              
    }
    glEnd();                                     
    glFlush();                                   
}

int main(int argc, char** argv)
{
	glutCreateWindow("The 3D Sierpinski Gasket");
	glutDisplayFunc(display);
	glutMouseFunc(Mouse); 
	glutMotionFunc(MotionMouse);
	glMatrixMode(GL_PROJECTION); // �n�]�wProjection�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(Projection)�������x�} ��
	//gluPerspective(0.0 /* �����ޥ� */,1.0 /* �����e���H�� */,0.1 /* �i���̪�Z�� */,10000.0 /* �i���̻��Z�� */);
	glutMainLoop();
	return 0;
}

