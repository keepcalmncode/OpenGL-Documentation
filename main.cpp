#include<stdio.h>
#include<GL/glut.h>
void road();
void signal();
void car();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void helpscreen();
GLint a=300,b=-300,flag=0,traffic_regulator=1,control_keyl,control_keyr;
GLfloat red=0,blue=1,green=.3;

GLfloat p=0,q=0,r=0;

void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen(void)
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0.15,0.1,0.11,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
drawstring(450.0,700.0,0.0," THE OXFORD COLLEGE OF ENGINEERING ");
glColor3f(0.7,0,1);
drawstring(330,650,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
glColor3f(1,0.5,0);
drawstring(530,600,0.0,"A MINI PROJECT ON");
glColor3f(1,0,0);
drawstring(360,500,0.0,"GRAPHICAL REPRESENTATION OF TRAFFIC SIGNAL");
glColor3f(1,0.5,0);
drawstring(200,400,0.0,"BY:");
glColor3f(1,1,1);
drawstring(100,300,0.0,"ANIKET KUMAR SINGH(1OX15CS010)");
glColor3f(1,1,1);
drawstring(100,260,0.0,"AMAN KUMAR PANDEY (1OX15CS008)");
glColor3f(1,1,1);
drawstring(100,220,0.0,"KALI KIRAN KUMAR K (1OX15CS047)");
glColor3f(1,1,1);
drawstring(100,180,0.0,"MANEESH KUMAR V (1OX15CS053)");
glColor3f(1,0.5,0);
drawstring(980,400,0.0,"GUIDES:");
glColor3f(1,1,1);
drawstring(930,300,0.0," MR. SENTHIL KUMAR");
glColor3f(1,1,1);
drawstring(930,240,0.0," MRS. CHANDANITHA CHATERGEE ");
glColor3f(1,0.1,1);
drawstring(543,100,0.0,"PRESS ENTER TO START");
glFlush();
}

void helpscreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"HOW");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"IT");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"WORKS");
glColor3f(0.5,0.1,0.2);
drawstring(350.0,640.0,0.0,"Stop the traffic (Red Light)                                  MOUSE LEFT CLICK");
glColor3f(0.5,0.1,0.3);
drawstring(350.0,540.0,0.0,"Yellow Signal                                                        MOUSE RIGHT BUTTON (HOLD ON)");
glColor3f(0.5,0.1,0.4);
drawstring(350.0,440.0,0.0,"Green Signal                                                         MOUSE RIGHT BUTTON (RELEASE)");
glColor3f(0.4,0.1,0.5);
drawstring(350.0,340.0,0.0,"Speed up the vehicles                                           PRESS 'S'");
glColor3f(0.5,0.1,0.8);
drawstring(350.0,240.0,0.0,"Help                                                                      PRESS 'H'");
glColor3f(0.5,0.1,0.9);
drawstring(350.0,140.0,0.0,"Escape                                                                  PRESS 'ENTER'");
glFlush();
}
void myKeyboard( unsigned char key, int x, int y )
{
switch(key)
{
	case 13:
		if(flag==1)
		{
			flag=2;
			mydisplay();
		}
		if(flag==0) //Ascii of 'enter' key is 13
		{
	flag=1;mydisplay();
		}

	break;
	case 's':mydisplay();
	break;
	case 'h':
	    flag=1;
        mydisplay();
		break;
	default:break;
}

}

void myMouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	traffic_regulator=0;
	p=1;
	q=0;
	r=0;
	}

	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
	traffic_regulator=0;
	p=0;
	q=1;
	r=0;
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
	{
	traffic_regulator=1;
	p=0;
	q=0;
	r=1;
	}
	glutPostRedisplay();
}

void mydisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
if(flag==0)
frontscreen ();
if(flag==1)
	helpscreen();
if(flag==2)
display();
glutSwapBuffers();
}

void update(int value)
{
a=a-6;
b=b+6;
glutPostRedisplay();
}

void display(void)
{
	if(traffic_regulator)
glutTimerFunc(40,update,0);
glClear(GL_COLOR_BUFFER_BIT);
road();
signal();
car();
glFlush();
}

void road()
{
glPushMatrix();
glScaled(40.0,40.0,0.0);
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
//straight road
glVertex2f(0,5);
glVertex2f(40,5);
glVertex2f(40,10);
glVertex2f(0,10);
glEnd();
glPopMatrix();
}

void signal()
{
glPushMatrix();
glScaled(40.0,40.0,0.0);
//board
glBegin(GL_POLYGON);
glVertex2f(15.5,15);
glVertex2f(17.5,15);
glVertex2f(17.5,10);
glVertex2f(15.5,10);
glEnd();
//red
glColor3f(p,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(16,14.5);
glVertex2f(17,14.5);
glVertex2f(17,14);
glVertex2f(16,14);
glEnd();
//yellow
glColor3f(q,q,0.0);
glBegin(GL_POLYGON);
glVertex2f(16,13.5);
glVertex2f(17,13.5);
glVertex2f(17,13);
glVertex2f(16,13);
glEnd();
//green
glColor3f(0.0,r,0.0);
glBegin(GL_POLYGON);
glVertex2f(16,12.5);
glVertex2f(17,12.5);
glVertex2f(17,12);
glVertex2f(16,12);
glEnd();
glPopMatrix();
}

void car()
{
glPushMatrix(); //making color for outer line
glTranslated(b,190.0,0.0);
glScaled(20.0,20.0,0.0);
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
//glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
//glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
//glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
//glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
//glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
//glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
//glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
//glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
//glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
//glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
//glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
//glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
//glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
//glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
//glVertex2f(2.0,2.5);
glEnd();

glColor3f(1.0,1.0,1.0); //color for outer window
glBegin(GL_POLYGON);
glVertex2f(5.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glEnd();

glBegin(GL_POLYGON); //drawing a back tyre
glVertex2f(3.0,2.5);
glVertex2f(3.0,2.6);
//glVertex2f(3.15,3.1);
glVertex2f(3.2,3.2);
glVertex2f(3.3,3.35);
//glVertex2f(3.4,3.4);
glVertex2f(3.5,3.45);
glVertex2f(3.6,3.55);
//glVertex2f(3.7,3.6);
glVertex2f(3.8,3.63);
glVertex2f(4.0,3.65);
//glVertex2f(4.2,3.7);
glVertex2f(4.4,3.7);
glVertex2f(4.6,3.65);
//glVertex2f(4.8,3.55);
glVertex2f(5.0,3.45);
glVertex2f(5.1,3.4);
//glVertex2f(5.2,3.25);
glVertex2f(5.3,3.2);
glVertex2f(5.4,3.0);
//glVertex2f(5.5,2.5);

glVertex2f(5.45,2.15);
glVertex2f(5.4,1.9);
glVertex2f(5.35,1.8);
glVertex2f(5.2,1.6);
glVertex2f(5.0,1.5);
glVertex2f(4.9,1.4);
glVertex2f(4.7,1.3);
glVertex2f(4.6,1.27);
glVertex2f(4.4,1.25);
//glVertex2f(4.0,1.25);
glVertex2f(3.9,1.3);
//glVertex2f(3.75,1.35);
glVertex2f(3.6,1.4);
glVertex2f(3.45,1.55);
//glVertex2f(3.3,1.7);
//glVertex2f(3.2,1.8);
glVertex2f(3.1,2.2);
glEnd();


glBegin(GL_POLYGON); //drawing front tyre
glVertex2f(17.0,2.5);
glVertex2f(17.15,3.1);
glVertex2f(17.3,3.35);
glVertex2f(17.5,3.45);
glVertex2f(17.7,3.6);
glVertex2f(18.0,3.65);
glVertex2f(18.4,3.7);
glVertex2f(18.8,3.55);
glVertex2f(19.1,3.4);
glVertex2f(19.3,3.2);
glVertex2f(19.5,2.5);
glVertex2f(19.4,1.9);
glVertex2f(19.2,1.6);
glVertex2f(18.9,1.4);
glVertex2f(18.6,1.27);
glVertex2f(18.0,1.25);
glVertex2f(17.6,1.4);
glVertex2f(17.3,1.7);
glVertex2f(17.1,2.2);
glEnd();
glPopMatrix();
}

void myinit()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1346,728);
glutInitWindowPosition(0,0);
glutCreateWindow("Traffic signal");

/*call back functions*/
glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboard);
glutMouseFunc(myMouse);


myinit();
glutMainLoop();
}
