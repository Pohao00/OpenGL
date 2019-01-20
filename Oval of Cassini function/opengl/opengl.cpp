#include"iostream"
#include"glut.h"
 //using namespace std;

/*int old_rot_x=0;   //����U�ƹ��ɪ������y�� 
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
 }*/

int cell (double a, double b, double c, double d,double Threshold)
// a, b, c, d��4��corner����
{

	int n = 0;
	if (a > Threshold) n += 1;  //Threshold: �ҭn��z��
	if (b > Threshold) n += 8;
	if (c > Threshold) n += 4;
	if (d > Threshold) n += 2;
	
	return n;
}
void draw_one(int num, double i, double j, double a, double b, double c, double d)
{ 
	double x1,y1,x2,y2;
	glColor3d(1.0f,1.0f,0.0f);
	switch(num)
	{ 
		case 1: case 14:
		x1 = i;
		y1 = j+0.005;
		x2 = i+0.005;
		y2 = j;
		break;
		case 2: case 13:
		x1 = i+0.005;
		y1 = j;
		x2 = i+0.01;
		y2 = j+0.005;
		break;
		case 4: case 11:
		x1 = i+0.005;
		y1 = j+0.01;
		x2 = i+0.01;
		y2 = j+0.005;
		break;
		case 7: case 8:
		x1 = i;
		y1 = j+0.005;
		x2 = i+0.005;
		y2 = j+0.01;
		break;
	} 
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
	
}
void draw_adjacent(int num, double i, double j, double a, double b, double c, double d)
{ 
	double x1,y1,x2,y2;
	switch(num)
	{ 
		case 3: case 12:
		x1 = i;
		y1 = j+0.005;
		x2 = i+0.01;
		y2 = j+0.005;
		break;
		case 6: case 9:
		x1 = i+0.005;
		y1 = j+0.01;
		x2 = i+0.005;
		y2 = j;
		break;
	}
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
	
}
void draw_opposite(int num, double i, double j, double a, double b, double c, double d)
{ 
	double x1,y1,x2,y2;
	switch(num)
	{ 
		case 5: 
		x1 = i;
		y1 = j+0.005;
		x2 = i+0.005;
		y2 = j+0.01;
		glBegin(GL_LINES);
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
		glVertex2d(x1+0.005, y1-0.005);
		glVertex2d(x2+0.005, y2-0.005);
		glEnd();
		break;
		case 10:
		x1 = i;
		y1 = j+0.005;
		x2 = i+0.005;
		y2 = j;
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
		glVertex2d(x1+0.005, y1+0.005);
		glVertex2d(x2+0.005, y2+0.005);
		break;
	}
}


void display()
{
	double i=-50,j,x,y;
	double p[4][2];
	double z[4];
	int num;
	//gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	/*glMatrixMode(GL_MODELVIEW); // �n�]�wModelView�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(ModelView)�������x�} ��
	gluLookAt(1,0,1,0,0,0,0,1,1);
	glRotatef((float)rot_y+(float)record_y, 0.0, 1.0, 0.0);//�Hx�b�����b 
    glRotatef((float)rot_x+(float)record_x, 1.0, 0.0, 0.0);//�Hy�b�����b */
	GLfloat colors[][3] = {{1.0,1.0,1.0},{1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},  {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
	for(double t=-1.5;t<=0.4;t+=0.05)
	{
		for(j=-1;j<=1;j+=0.01)
		{
			for(i=-1;i<1;i+=0.01)
			{
				x=i;
				y=j;
				z[0]=(x*x+y*y+0.49*0.49)*(x*x+y*y+0.49*0.49)-(4*(0.49)*(0.49)*x*x)-((0.5)*(0.5)*(0.5)*(0.5));
				x=i;
				y=j+0.01;
				z[1]=(x*x+y*y+0.49*0.49)*(x*x+y*y+0.49*0.49)-(4*(0.49)*(0.49)*x*x)-((0.5)*(0.5)*(0.5)*(0.5));
				x=i+0.01;
				y=j+0.01;
				z[2]=(x*x+y*y+0.49*0.49)*(x*x+y*y+0.49*0.49)-(4*(0.49)*(0.49)*x*x)-((0.5)*(0.5)*(0.5)*(0.5));
				x=i+0.01;
				y=j;
				z[3]=(x*x+y*y+0.49*0.49)*(x*x+y*y+0.49*0.49)-(4*(0.49)*(0.49)*x*x)-((0.5)*(0.5)*(0.5)*(0.5));
				
				num=cell(z[0],z[1],z[2],z[3],t);
				
				switch(num)
				{  
					case 1: case 2: case 4: case 7: case 8:
					case 11: case 13: case 14:
				draw_one(num, i, j, z[0],z[1],z[2],z[3]);        // i, j: �y��
				break;
				case 3: case 6: case 9: case 12:
				draw_adjacent(num, i, j, z[0],z[1],z[2],z[3]);
				break;
				case 5: case 10:
				draw_opposite(num, i, j, z[0],z[1],z[2],z[3]);
				break;
				case 0: case 15:
				break; }
			}
		}
	}
	glFlush();

}

int main(int argc, char** argv)
{
	glutCreateWindow("Oval of Cassini function");
	glutDisplayFunc(display);
	/*glutMouseFunc(Mouse); 
    glutMotionFunc(MotionMouse);
	glMatrixMode(GL_PROJECTION); // �n�]�wProjection�x�} ��
	glLoadIdentity(); // �ഫ�{�b�]�w���x�}(Projection)�������x�} ��*/
	//gluPerspective(0.0 /* �����ޥ� */,1.0 /* �����e���H�� */,0.1 /* �i���̪�Z�� */,10000.0 /* �i���̻��Z�� */);
	glutMainLoop();
	return 0;
}

