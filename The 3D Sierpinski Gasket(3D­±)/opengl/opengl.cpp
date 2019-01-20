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

void triangle(GLfloat *a, GLfloat *b,
	GLfloat *c)
{
	glVertex3fv(a);
	glVertex3fv(b);
     glVertex3fv(c); //�w�T����
 }

/*void tetra (GLfloat *a, GLfloat *b, GLfloat *c,  GLfloat *d)
                 
{
	GLfloat colors[][3] = {{1.0,1.0,1.0},{1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},  {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
	//���P���Τ��P���C��ӵe,�e�X�|���骺���P��
	
glColor3fv(colors[6]);    
triangle (b, a, c);
glColor3fv(colors[2]);
triangle (c, a, b);
glColor3fv(colors[3]);
triangle (a, d, b);          
glColor3fv(colors[4]);
triangle (b, d, c);
}*/
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)                             //m �� recursive m��
{   GLfloat v[3][3]  ;  // �T�Ӥ��I�A�e���n���w�q point2
                               //  typedef GLfloat point2[2]
	int j;
	if(m>0)
	{
        // j = 0�� x axis�Aj = 1 �� y axis
        for(j=0; j<3; j++) v[0][j]=(a[j]+b[j])/2; //�⤤�I
        for(j=0; j<3; j++) v[1][j]=(a[j]+c[j])/2; //�⤤�I              	
		for(j=0; j<3; j++) v[2][j]=(b[j]+c[j])/2; //�⤤�I
        divide_triangle(a, v[0], v[1], m-1);  //Recursive
    divide_triangle(c, v[1], v[2], m-1);
    divide_triangle(b, v[2], v[0], m-1);
}
else(triangle(a,b,c));
}

void display()
{
	glOrtho(-50, 50, -50, 50, 50.0, -50.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glMatrixMode(GL_MODELVIEW); // �n�]�wModelView�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(ModelView)�������x�} ��
	gluLookAt(1,0,1,0,0,0,0,1,1);
	glRotatef((float)rot_y+(float)record_y, 0.0, 1.0, 0.0);//�Hx�b�����b 
    glRotatef((float)rot_x+(float)record_x, 1.0, 0.0, 0.0);//�Hy�b�����b 
    GLfloat v[4][3] = {{0.0, 0.0, 50},{-30,-25,0}, {30, -25, 0},{0.0, 50, 0}};
    GLfloat colors[][3] = {{1.0,1.0,1.0},{1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},  {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
    int n=5;
	//glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3fv(colors[0]);
    glBegin(GL_TRIANGLES);
    divide_triangle(v[0], v[1], v[2], n);
    glEnd();
    glColor3fv(colors[1]);
    glBegin(GL_TRIANGLES);
    divide_triangle(v[0], v[2], v[3], n);
    glEnd();
    glColor3fv(colors[2]);
    glBegin(GL_TRIANGLES);
    divide_triangle(v[0], v[1], v[3], n);
    glEnd();
    glColor3fv(colors[3]);
    glBegin(GL_TRIANGLES);
    divide_triangle(v[1], v[2], v[3], n);
    glEnd();
    glFlush();
    
}

int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("The 3D Sierpinski Gasket(3D��)");
	glutDisplayFunc(display);
	glutMouseFunc(Mouse); 
	glutMotionFunc(MotionMouse);
	glMatrixMode(GL_PROJECTION); // �n�]�wProjection�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(Projection)�������x�} ��
	//gluPerspective(0.0 /* �����ޥ� */,1.0 /* �����e���H�� */,0.1 /* �i���̪�Z�� */,10000.0 /* �i���̻��Z�� */);
	glutMainLoop();
	return 0;
}

