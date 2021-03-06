#include"iostream"
#include"glut.h"
 //using namespace std;

int old_rot_x=0;   //剛按下滑鼠時的視窗座標 
int old_rot_y=0; 
 int rot_x=0;      //拖曳後的相對座標，用這決定要旋轉幾度 
 int rot_y=0; 
 int record_x=0;      //紀錄上一次旋轉的角度 
 int record_y=0; 
void Mouse(int , int , int , int );         //獲取滑鼠按下和放開時的訊息 
void MotionMouse(int , int );            //獲取滑鼠按下期間的訊息 

void Mouse(int button, int state, int x, int y) 
{ 
	if(state) 
	{ 
		record_x += x - old_rot_x; 
		record_y += y - old_rot_y; 
		
       rot_x = 0;   //沒有歸零會有不理想的結果 
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
     glVertex3fv(c); //定三角形
 }

/*void tetra (GLfloat *a, GLfloat *b, GLfloat *c,  GLfloat *d)
                 
{
	GLfloat colors[][3] = {{1.0,1.0,1.0},{1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},  {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
	//不同面用不同的顏色來畫,畫出四面體的不同面
	
glColor3fv(colors[6]);    
triangle (b, a, c);
glColor3fv(colors[2]);
triangle (c, a, b);
glColor3fv(colors[3]);
triangle (a, d, b);          
glColor3fv(colors[4]);
triangle (b, d, c);
}*/
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)                             //m �� recursive m次
{   GLfloat v[3][3]  ;  // 三個中點，前面要先定義 point2
                               //  typedef GLfloat point2[2]
	int j;
	if(m>0)
	{
        // j = 0表 x axis，j = 1 表 y axis
        for(j=0; j<3; j++) v[0][j]=(a[j]+b[j])/2; //算中點
        for(j=0; j<3; j++) v[1][j]=(a[j]+c[j])/2; //算中點              	
		for(j=0; j<3; j++) v[2][j]=(b[j]+c[j])/2; //算中點
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
	glMatrixMode(GL_MODELVIEW); // 要設定ModelView矩陣 ☆
	glLoadIdentity(); // 轉換現在設定的矩陣(ModelView)成為單位矩陣 ☆
	gluLookAt(1,0,1,0,0,0,0,1,1);
	glRotatef((float)rot_y+(float)record_y, 0.0, 1.0, 0.0);//以x軸當旋轉軸 
    glRotatef((float)rot_x+(float)record_x, 1.0, 0.0, 0.0);//以y軸當旋轉軸 
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
	glutCreateWindow("The 3D Sierpinski Gasket(3D面)");
	glutDisplayFunc(display);
	glutMouseFunc(Mouse); 
	glutMotionFunc(MotionMouse);
	glMatrixMode(GL_PROJECTION); // 要設定Projection矩陣 ☆
	glLoadIdentity(); // 轉換現在設定的矩陣(Projection)成為單位矩陣 ☆
	//gluPerspective(0.0 /* 先不管它 */,1.0 /* 視窗寬除以高 */,0.1 /* 可視最近距離 */,10000.0 /* 可視最遠距離 */);
	glutMainLoop();
	return 0;
}

