#include"iostream"
#include"stdio.h"
#include"stdlib.h"
#include"glut.h"
#include "math.h"
using namespace std;

static GLfloat xx=-8,ay=0,t;
static GLfloat power,powerd=-9,rpower=10;
static GLint caseth,ting=0,stop=0;
static GLint who=1,style=0,catblood=1000,dogblood=1000,wind=3,windp=1;
void Timer(int value)
{ 
	glutPostRedisplay();    //重秀畫面
	glutTimerFunc(80,Timer, 0);
}
void mouse(GLint button, GLint state, GLint x, GLint y)
{
	
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && ting==0)
	{
		if(who==1)
			{stop=1;
				ting=1;
				rpower=powerd+(wind-3);}
				if(who==0)
					{stop=1;
						ting=1;
						rpower=powerd-(wind-3);}
						
					}

				}



				void display()
				{
					glPointSize(15);
					glLineWidth(400);
					glClear(GL_COLOR_BUFFER_BIT);
					glClear(GL_DEPTH_BUFFER_BIT);
					glClearColor(1.0,0.0,0.0,1.0);
					glEnable(GL_LINE_STIPPLE);
					glEnable(GL_DEPTH_TEST);
					glDepthFunc(GL_LEQUAL);           
					glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	 if(windp==1)//風強
	 	{wind=rand()%5+1;
	 		windp=0;}
	  if((who==1 && ay<0))//換角
	  {
	  	xx=8;
	  	stop=0;
	  	ting=0;
	  	who=0;
	  	ay=0;
	  	windp=1;
	  }
	  if((who==0 && ay<0))
	  {
	  	xx=-8;
	  	stop=0;
	  	ting=0;
	  	who=1;
	  	ay=0;
	  	windp=1;
	  }

	  
	  

	 if(wind==1)//風項指標
	 {
	 	glBegin(GL_LINES);
	 	glVertex2f(1.5,8);
	 	glVertex2f(-1.5,8);
	 	glVertex2f(-1.5,8);
	 	glVertex2f(-1.1,8.1);
	 	glEnd();
	 }
	 else if(wind==2)
	 {
	 	glBegin(GL_LINES);
	 	glVertex2f(1,8);
	 	glVertex2f(-1,8); glVertex2f(-1,8);
	 	glVertex2f(-0.6,8.1);
	 	glEnd();
	 }
	 else if(wind==4)
	 {
	 	glBegin(GL_LINES);
	 	glVertex2f(-1,8);
	 	glVertex2f(1,8); glVertex2f(1,8);
	 	glVertex2f(0.6,8.1);
	 	glEnd();
	 }
	 else if(wind==5)
	 {
	 	glBegin(GL_LINES);
	 	glVertex2f(-1.5,8);
	 	glVertex2f(1.5,8);glVertex2f(1.5,8);
	 	glVertex2f(1.1,8.1);
	 	glEnd();
	 }
	 else
	 {
	 	glBegin(GL_LINES);
	 	glVertex2f(0,8);
	 	glVertex2f(0,8.5);
	 	glEnd();
	 }

	 
	 
     /*if(xx==-2) 
		 {xx=-8;
		//glClearColor(1.0,0.0,0.0,1.0); 
	 }*/
	 if(powerd==-4) 
	 	{t=1;
	 	}
	 	if(powerd==-9) 
	 		{t=0;
	 		}
	  if(who==0 && stop==1)//狗
	  {
	  	if(rpower==-9)
	  	{
	  		ay=-3*(xx*xx)/16+9*xx/8+3;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  		style=1;
	  	}
	  	else if(rpower==-8)
	  	{
	  		ay=-5*(xx*xx)/36+5*xx/9+40/9+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  		style=2;
	  	}
	  	else if(rpower==-7)
	  	{
	  		ay=-6*(xx*xx)/49+12*xx/49+288/49+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  		style=3;
	  	}
	  	else if(rpower==-6)
	  	{
	  		ay=-7*(xx*xx)/64+6.5+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  		style=4;
	  	}
	  	else if(rpower==-5)
	  	{
	  		ay=-8*(xx*xx)/81-16*xx/81+640/81+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  		style=5;
	  	}
	  	else if(rpower==-4)
	  	{
	  		ay=-(xx*xx)/10-2*xx/5+48/5+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  		style=6;
	  	}
	  	else if(rpower>-4)
	  	{
	  		ay=-10*(xx*xx)/121-60*xx/121+1120/121+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  	}
	  	else if(rpower<-9)
	  	{
	  		ay=-(xx*xx)/3+10*xx/3-16/3+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx-=0.2;
	  	}
	  }

	  if(who==1 && stop==1)//貓
	  {
	  	
	  	if(rpower==-9)
	  	{
	  		ay=-3*(xx*xx)/16-9*xx/8+3;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx=xx+0.2;
	  		style=1;
	  	}
	  	else if(rpower==-8)
	  	{
	  		ay=-5*(xx*xx)/36-5*xx/9+40/9+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx=xx+0.2;
	  		style=2;
	  	}
	  	else if(rpower==-7)
	  	{
	  		ay=-6*(xx*xx)/49-12*xx/49+288/49+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx=xx+0.2;
	  		style=3;
	  	}
	  	else if(rpower==-6)
	  	{
	  		ay=-7*(xx*xx)/64+6.5+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx=xx+0.2;
	  		style=4;
	  	}
	  	else if(rpower==-5)
	  	{
	  		ay=-8*(xx*xx)/81+16*xx/81+640/81+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx=xx+0.2;
	  		style=5;
	  	}
	  	else if(rpower==-4)
	  	{
	  		ay=-(xx*xx)/10+2*xx/5+48/5+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx+=0.2;
	  		style=6;
	  	}
	  	else if(rpower>-4)
	  	{
	  		ay=-10*(xx*xx)/121+60*xx/121+1120/121+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx+=0.2;
	  	}
	  	else if(rpower<-9)
	  	{
	  		ay=-(xx*xx)/3-10*xx/3-16/3+1;
	  		glBegin(GL_POINTS); 
	  		glVertex2f(xx, ay);
	  		glEnd();
	  		xx+=0.2;
	  	}
	  }

	  if(style==4&&ay<0)//擊中
	  {
	  	if(who==1)
	  		{dogblood-=125;
	  			style=0;
	  			glBegin(GL_LINES);
	  			glVertex2f(-8,3);
	  			glVertex2f(-8,4);
	  			glEnd();
	  		}
	  		else
	  			{catblood-=200;
	  				style=0;}
	  			}
	 glBegin(GL_LINES);   //血量
	 glVertex2f(-9,9);
	 glVertex2f(-9+catblood/125,9);
	 glEnd();
	 glBegin(GL_LINES);
	 glVertex2f(1,9);	
	 glVertex2f(1+dogblood/125,9);
	 glEnd();
	 glColor3f(1,1,0);
	 glBegin(GL_POLYGON);
	 glVertex2f(-9,8.2);	
	 glVertex2f(-9,7.8);
	 glVertex2f(-4,7.8);	
	 glVertex2f(-4,8.2);	
	 glEnd();
	 
	 
		/*y=-(x*x)/2+2;
     glBegin(GL_POINTS); 
        glVertex2d(x, y);
		y=-(x*x)-2*x;
     glBegin(GL_POINTS); 
        glVertex2d(x, y);
		y=-(x*x)-2*x; */                        
	 glColor3f(0,0,0);
	 glBegin(GL_POINTS); 
	 glVertex2d(powerd, 8);
	 glEnd();
	 
	 if(t==1) 
	 {
	 	powerd=powerd-1;
	 }
	 if(t==0) 
	 {
	 	powerd=powerd+1;
	 }
	 glColor3f(1,1,1);
	 glutSwapBuffers();

//glFlush();

	}
	void init()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-10, 10, -0.5,  10);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
	}

	int main(int argc, char** argv)
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
		glutInitWindowSize(800, 600);
		glutCreateWindow("Spiral Points: Timer function");
		init();
		glutDisplayFunc(display);
		glutTimerFunc(150, Timer, 0);
		glutMouseFunc (mouse);
		glutMainLoop();
		return 0;
	}

