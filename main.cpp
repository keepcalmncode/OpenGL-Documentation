#include<stdio.h>
#include<GL/glut.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
//void myMouse();
void helpscreen();
void *currentfont;
GLint flag=0;
int fontMenu,mainMenu;
// menu status
int menuFlag = 0;
// default font
void *font = GLUT_BITMAP_TIMES_ROMAN_24;

#define basics 1
#define mainf 2
#define reshape  3
#define animate  4
#define keyboard  5
#define camview  6
#define navgs  7


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
drawstring(360,500,0.0,"                        OPENGL DOCUMENTATION");
glColor3f(1,0.5,0);
drawstring(200,400,0.0,"BY:");
glColor3f(1,1,1);
drawstring(100,300,0.0,"AMAN KUMAR PANDEY (1OX15CS008)");
glColor3f(1,1,1);
drawstring(100,260,0.0,"ANIKET KUMAR SINGH(1OX15CS010)");
glColor3f(1,1,1);
drawstring(100,220,0.0,"KALI KIRAN KUMAR K (1OX15CS047)");
glColor3f(1,1,1);
drawstring(100,180,0.0,"MANEESH KUMAR V (1OX15CS052)");
glColor3f(1,0.5,0);
drawstring(980,400,0.0,"GUIDE:");
glColor3f(1,1,1);
drawstring(930,300,0.0," MR. SENTHIL KUMAR");
glColor3f(1,0.1,1);
drawstring(543,100,0.0,"PRESS ENTER TO GET STARTED");
glFlush();
}


void helpscreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"NAVIGATION");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"  ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"SHEET");
glColor3f(1,1,1);
drawstring(200.0,640.0,0.0,"PRESS NUMBER 1 - 7 TO TO KNOW THE HISTORY OF OPENGL MAJOR RELEASES");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,590.0,0.0,"Methods in OpenGL");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"Press the mapped key to navigate to the reference page:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,500.0,0.0," a -> glBegin                                     b -> glClear                    c -> glClearColor");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,450.0,0.0," d -> glEnable                                     e -> glFlush                    f -> glColor");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0," g -> glMatrixMode                         h -> glLoadIdentity                   i -> glOrtho");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,350.0,0.0," j -> glutMainLoop                            k -> glutInit                     l -> glutInitWindowSize ");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,300.0,0.0," m -> glutBitmapCharacter             n -> glutKeyboardFunc             o -> glutSwapBuffers");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,250.0,0.0," p -> glutInitDisplayMode             q -> glutCreateWindow             r -> glutReshapeFunc");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,200.0,0.0," s -> glutIdleFunc                     t -> gluLookAt             ");
glColor3f(1.0,0.7,0.9);
drawstring(300.0,110.0,0.0,"RIGHT-CLICK THE MOUSE BUTTON TO OPEN NAVIGATION MENU");
glColor3f(1.0,1.0,0.9);
drawstring(300.0,70.0,0.0,"PRESS 'w' KEY TO NAVIGATE TO PROGRAMMING BASICS IN OPENGL");
glColor3f(1.0,0.7,0.9);
drawstring(300.0,30.0,0.0,"PRESS ESC KEY  TO RETURN TO NAVIGATION SHEET");
glFlush();
}


void startscreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"WHAT");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"IS");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"OPENGL ?");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"OPENGL refers to Open Graphics Library");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,540.0,0.0,"It is a Cross-Language, Cross-Platform Application Programming Interface");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,500.0,0.0,"for rendering 2D and 3D vector graphics");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,460.0,0.0,"Since its introduction in 1992, OpenGL has become the industry's most widely used and supported ");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,420.0,0.0,"2D and 3D graphics application programming interface (API), bringing thousands of applications ");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,380.0,0.0,"to a wide variety of computer platforms.");
glColor3f(0.2,0.1,0.9);
drawstring(350.0,325.0,0.0,"MAJOR RELEASES IN OPENGL");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,300.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,280.0,0.0,"| OPENGL VERSIONS |  RELEASE DATE |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,265.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,250.0,0.0,"| 	OpenGL 1.0                  |   1992                     |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,235.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,210.0,0.0,"| OPENGL 1.5                |  2003                      |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,195.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,180.0,0.0,"| OPENGL 2.0                |  2004                      |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,165.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,150.0,0.0,"| OPENGL 3.0                |  2008                      |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,135.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,120.0,0.0,"| OPENGL 4.0                |  2010                      |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,105.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,90.0,0.0,"| OPENGL 4.3                |  2012                      |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,75.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,60.0,0.0,"| OPENGL 4.5                |  2014                      |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,45.0,0.0,"+----------------+-------------+");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,30.0,0.0,"| OPENGL 4.6                |  2017                      |");
glColor3f(0.5,0.1,0.9);
drawstring(300.0,15.0,0.0,"+----------------+-------------+");

glFlush();
}


void openglver10()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"   VER");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"1.0");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,650.0,0.0,"The first version of OpenGL, version 1.0, was released in January 1992 by Mark Segal and Kurt Akeley.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,600.0,0.0," Since then, OpenGL has occasionally been extended by releasing a new version of the specification.");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"Such releases define a baseline set of features which all conforming graphics cards must support,");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,500.0,0.0," and against which new extensions can more easily be written.");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,450.0,0.0,"Each new version of OpenGL tends to incorporate several extensions which have widespread support");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0,"among graphics-card vendors, although the details of those extensions may be changed.");
glFlush();
}


void opengl15()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"   VER");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"1.5");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,650.0,0.0,"Alongside the release of OpenGL 1.5, the ARB released the OpenGL Shading Language specification,");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,600.0,0.0,"and the extensions ARB_shader_objects, ARB_vertex_shader, and ARB_fragment_shader.");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"EXTESIONS ADDED IN THIS RELEASE:");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,500.0,0.0,"ARB_vertex_buffer_object : ");
glColor3f(0.5,0.1,0.8);
drawstring(250.0,450.0,0.0,"A new type of GL object, the 'buffer', which stores various types of data in fast video memory");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0,"ARB_occlusion_query : ");
glColor3f(0.5,0.1,0.9);
drawstring(250.0,350.0,0.0,"The programmer may query whether or not a primitive was occluded during rendering");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,300.0,0.0,"EXT_shadow_funcs : ");
glColor3f(0.5,0.1,0.9);
drawstring(250.0,250.0,0.0,"The abilities of the ARB_shadow extension are slightly extended.");
glFlush();
}


void opengl20()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"   VER");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"2.0");
glColor3f(0.5,0.1,0.2);
drawstring(350.0,650.0,0.0,"OPENGL 2.0 was released on September 7, 2004.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,600.0,0.0,"OpenGL 2.0 was originally conceived by 3Dlabs to address concerns that OpenGL was stagnating ");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"and lacked a strong direction. 3Dlabs proposed a number of major additions to the standard.");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,500.0,0.0,"The final OpenGL 2.0 specification[31] includes support for GLSL.");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,450.0,0.0,"EXTESIONS ADDED IN THIS RELEASE:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0,"ARB_shader_objects,ARB_vertex_shader,ARB_fragment_shader,ARB_shading_language_100 : ");
glColor3f(0.5,0.1,0.8);
drawstring(220.0,350.0,0.0,"Provides direct access to programmable vertex and fragment processors");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,300.0,0.0,"ARB_texture_non_power_of_two : ");
glColor3f(0.5,0.1,0.8);
drawstring(220.0,250.0,0.0,"Texture images may have non-power-of-two dimensions ");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,200.0,0.0,"ARB_point_sprite");
glColor3f(0.5,0.1,0.8);
drawstring(220.0,150.0,0.0,"Points may be rendered as small, screen-oriented texture quads; useful when developing particle systems ");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,100.0,0.0,"EXT_stencil_two_side, ATI_separate_stencil : ");
glColor3f(0.5,0.1,0.8);
drawstring(220.0,50.0,0.0,"Separate stencil algorithms may be used when rendering the front and back faces of primitives");
glFlush();
}


void opengl30()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"   VER");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"3.0");
glColor3f(0.5,0.1,0.2);
drawstring(350.0,650.0,0.0,"OPENGL 3.0 was released on August 11, 2008. ");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,600.0,0.0,"OpenGL 3.0 introduced a deprecation mechanism to simplify future revisions of the API.");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"Certain features, marked as deprecated, could be completely disabled by requesting a ");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,500.0,0.0,"forward-compatible context from the windowing system. OpenGL 3.0 features could");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,450.0,0.0,"still be accessed alongside these deprecated features, however, by requesting a full context.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0,"Deprecated features include :");
glColor3f(0.5,0.1,0.9);
drawstring(220.0,350.0,0.0,"* All fixed-function vertex and fragment processing");
glColor3f(0.5,0.1,0.9);
drawstring(220.0,300.0,0.0,"* Direct-mode rendering, using glBegin and glEnd");
glColor3f(0.5,0.1,0.9);
drawstring(220.0,250.0,0.0,"* Display lists");
glColor3f(0.5,0.1,0.9);
drawstring(220.0,200.0,0.0,"* Indexed-color rendering targets");
glColor3f(0.5,0.1,0.9);
drawstring(220.0,150.0,0.0,"* OpenGL Shading Language versions 1.10 and 1.20");
glFlush();
}

void opengl40()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"   VER");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"4.0");
glColor3f(0.5,0.1,0.2);
drawstring(350.0,650.0,0.0,"OPENGL VERSION 4.0 was released on March 11, 2010");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,600.0,0.0,"OpenGL 4.0 was released alongside version 3.3. It was designed for hardware able to support Direct3D 11.");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"As in OpenGL 3.0, this version of OpenGL contains a high number of fairly inconsequential extensions,");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,500.0,0.0," designed to thoroughly expose the abilities of Direct3D 11-class hardware.");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,450.0,0.0,"Hardware support: Nvidia GeForce 400 series and newer, AMD Radeon HD 5000 Series and newer, ");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0,"Intel HD Graphics in Intel Ivy Bridge processors and newer.");
glFlush();
}


void opengl45()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"   VER");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"4.5");
glColor3f(0.5,0.1,0.2);
drawstring(350.0,650.0,0.0,"OPENGL VERSION 4.5  was released on August 11, 2014");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,600.0,0.0,"Direct State Access (DSA) – object accessors enable state to be queried and modified");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"without binding objects to contexts,for increased application,middleware efficiency and flexibility");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,500.0,0.0,"Flush Control – applications can control flushing of pending commands before context switching.");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,450.0,0.0,"Robustness – providing a secure platform for applications such as WebGL browsers.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0,"OpenGL ES 3.1 API and shader compatibility – to enable the easy development and execution of the latest OpenGL ES applications");
glFlush();
}


void opengl46()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"   VER");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"4.6");
glColor3f(0.5,0.1,0.2);
drawstring(350.0,650.0,0.0,"OPENGL VERSION 4.6 was released on July 31, 2017");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,600.0,0.0,"+ more efficient, GPU-sided, geometry processing");
glColor3f(0.5,0.1,0.4);
drawstring(200.0,550.0,0.0,"+ more efficient shader execution (AZDO)");
glColor3f(0.4,0.1,0.5);
drawstring(200.0,500.0,0.0,"+ more information through statistics, overflow query and counters");
glColor3f(0.5,0.1,0.8);
drawstring(200.0,450.0,0.0,"+ clamping of polygon offset function, solves a shadow rendering problem");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,400.0,0.0,"+ higher performance through no error handling contexts");
glFlush();
}


void a()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"glBegin");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," and ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"glEnd");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"glBegin and glEnd delimit the vertices that define a primitive or a group of like primitives.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"glBegin accepts a single argument that specifies which way the vertices are interpreted.");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"Taking n as an integer count starting at one,and N as the total number of vertices specified,");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0," the interpretations are as follows:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"GL_POINTS : Treats each vertex as a single point. Vertex n defines point n. N points are drawn.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"GL_LINES : Treats each pair of vertices as an independent line segment.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"GL_LINE_STRIP : Draws a connected group of line segments from the first vertex to the last. Vertices n and");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0," n+1 define line n. N-1 lines drawn.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0," GL_LINE_LOOP : Draws a connected group of line segments from the first vertex to the last,then back to the first.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"  Vertices n and n+1 define line n. The last line, however, is defined   by vertices N and 1. N lines are drawn.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"GL_TRIANGLES : Treates each triplet of vertices as an independent triangle. Vertices 3n-2, 3n-1, ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0," and 3n define triangle n. N/3 triangles are drawn.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"GL_TRIANGLE_STRIP :Draws connected group of triangles.One triangle is defined for each vertex presented after the first two vertices.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"GL_QUADS : Treats each group of four vertices as an independent quadrilateral. N/4 quadrilaterals are drawn.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"GL_POLYGON : Draws a single, convex polygon. Vertices 1 through N define this polygon.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"void glBegin(GLenum mode)");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"Ten symbolic constants are accepted: GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, ");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, GL_QUAD_STRIP,");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0," and GL_POLYGON.");
glFlush();
}



void b()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(650.0,700.0,0.0,"glClear");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"clear buffers within the viewport");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glClear( GLbitfield mask )");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"Bitwise OR of masks that indicate the buffers to be cleared. The four masks are GL_COLOR_BUFFER_BIT,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0," GL_DEPTH_BUFFER_BIT, GL_ACCUM_BUFFER_BIT, and GL_STENCIL_BUFFER_BIT");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"GL_COLOR_BUFFER_BIT : Indicates the buffers currently enabled for color writing.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"GL_DEPTH_BUFFER_BIT : Indicates the depth buffer. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"GL_ACCUM_BUFFER_BIT : Indicates the accumulation buffer.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0," GL_STENCIL_BUFFER_BIT : Indicates the stencil buffer.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"NOTES:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"If a buffer is not present, then a glClear directed at that buffer has no effect.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"glClear sets the bitplane area of the window to values previously selected by glClearColor");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0," glClearIndex, glClearDepth, glClearStencil, and glClearAccum. Multiple color buffers can be");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,190.0,0.0," cleared simultaneously by selecting more than one buffer at a time using glDrawBuffer.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,160.0,0.0,"glClear takes a single argument that is the bitwise OR of several values indicating which buffer is to be cleared.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"ERRORS:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"GL_INVALID_VALUE is generated if any bit other than the four defined bits is set in mask.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"GL_INVALID_OPERATION is generated if glClear is called between a call to glBegin");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0," and the corresponding call to glEnd.");
glFlush();
}



void c()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glClearColor ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glClearColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"Specify the red, green, blue, and alpha values used when the color buffers are cleared.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0," The default values are all zero.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"glClearColor specifies the red, green, blue, and alpha values used by glClear to clear the ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"color buffers. Values specified by glClearColor are clamped to the range [0,1].");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"ERRORS: ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"GL_INVALID_OPERATION is generated if glClearColor is called between");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"a call to glBegin and the corresponding call to glEnd.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,".");
glFlush();
}



void d()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0," glEnable  ");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," and ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0," glDisable ");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"enable or disable GL capabilities");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glEnable( GLenum cap )");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"cap - Specifies a symbolic constant indicating a GL capability.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"glEnable and glDisable enable and disable various capabilities.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0," Use glIsEnabled or glGet to determine the current setting of any capability.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"Both glEnable and glDisable take a single argument, cap, which can assume one of the following values:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"GL_ALPHA_TEST : If enabled, do alpha testing. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"GL_BLEND	: If enabled, blend the incoming RGBA color values with the values in the color buffers");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"GL_DEPTH_TEST : If enabled, do depth comparisons and update the depth buffer.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"GL_LIGHTING : If enabled, use the current lighting parameters to compute the vertex color or index");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"GL_LINE_SMOOTH : If enabled, draw lines with correct filtering. Otherwise, draw aliased lines");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"GL_NORMALIZE	: If enabled, normal vectors specified with glNormal are scaled to unit length after transformation");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"ERRORS:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"GL_INVALID_ENUM is generated if cap is not one of the values listed above.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"GL_INVALID_OPERATION is generated if glEnable is called between a call to glBegin ");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"and the corresponding call to glEnd.");
glFlush();
}



void e()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glFlush ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0," force execution of GL commands in finite time");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glFlush( void )");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"Does not take any parameters.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"Different GL implementations buffer commands in several different locations, including");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"network buffers and the graphics accelerator itself. glFlush empties all of these buffers, ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"causing all issued commands to be executed as quickly as they are accepted by the actual");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"rendering engine. Though this execution may not be completed  in any particular time period,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"it does complete in finite time.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"Because any GL program might be executed over a network, or on an accelerator that buffers commands,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0," all programs should call glFlush whenever they count on having all of their previously issued ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"commands completed. For example, call glFlush before waiting for user input that depends on the generated image.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,220.0,0.0,"NOTES:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"glFlush does not wait until the execution of all previously issued OpenGL commands is complete.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"ERRORS:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"GL_INVALID_OPERATION is generated if glFlush is called between a call to");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0," glBegin and the corresponding call to glEnd.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glFlush();
}



void f()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glColor");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"Used to set color to any object.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glColor3f( GLfloat red, GLfloat green, GLfloat blue ) ");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"red, green, blue	- Specify new red, green, and blue values for the current color.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"alpha - Specifies a new alpha value for the current color. Included only in the four-argument glColor4 command.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"The GL stores both a current single-valued color index and a current four-valued RGBA color. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0," glColor sets a new four-valued RGBA color. glColor has two major variants: glColor3 and glColor4.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"glColor3 variants specify new red, green, and blue values explicitly, and set the current alpha  ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"value to 1.0 implicitly. glColor4 variants specify all four color components explicitly.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"glColor3b, glColor4b, glColor3s, glColor4s, glColor3i, and glColor4i take three or four unsigned byte,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"short, or long integers as arguments. When v is appended to the name, the color commands can take");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0," a pointer to an array of such values.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,220.0,0.0,"NOTES:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"The current color can be updated at any time. In particular, glColor can be called between a");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"glBegin and the corresponding call to glEnd.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"Example:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"glColor3f(1.0,0.0,0.0):");
glColor3f(0.5,0.1,0.9);
drawstring(230.0,70.0,0.0,"Sets the color to red.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}



void g()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"glMatrixMode");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"specify which matrix is the current matrix");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glMatrixMode( GLenum mode )");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"Specifies which matrix stack is the target for subsequent matrix operations.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"Three values are accepted: GL_MODELVIEW, GL_PROJECTION, and GL_TEXTURE.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"glMatrixMode sets the current matrix mode. mode can assume one of three values:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"GL_MODELVIEW	: Applies subsequent matrix operations to the modelview matrix stack");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"GL_PROJECTION : Applies subsequent matrix operations to the projection matrix stack ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"GL_TEXTURE : Applies subsequent matrix operations to the texture matrix stack");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"ERRORS");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"GL_INVALID_ENUM is generated if mode is not an accepted value.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"GL_INVALID_OPERATION is generated if glMatrixMode is called between");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"a call to glBegin and the corresponding call to glEnd.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}



void h()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"glLoadIdentity");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"replace the current matrix with the identity matrix");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glLoadIdentity( void )");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"glLoadIdentity replaces the current matrix with the identity matrix.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"It is semantically equivalent to calling glLoadMatrix with the identity matrix.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"ERRORS:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"GL_INVALID_OPERATION is generated if glLoadIdentity is called between");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"a call to glBegin and the corresponding call to glEnd.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}



void i()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"glOrtho");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"	void glOrtho(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top,GLdouble zNear,GLdouble zFar )");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"  left,right - Specify the coordinates for the left and right vertical clipping	planes");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"bottom,top - Specify the coordinates for the bottom and top horizontal clipping planes.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"zNear,zFar - Specify the distances to the nearer and farther depth clipping planes.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"These values are negative if the plane is to be behind the viewer.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"DESCRIPTION");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"glOrtho describes a transformation that produces a parallel projection. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"zFar specifies the location of the far clipping plane.zNear specifies near clipping plane.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0," Both zNear and zFar can be either positive or	negative.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"Use glPushMatrix and glPopMatrix to save and restore the current matrix stack.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"ERRORS:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"GL_INVALID_OPERATION is generated if glOrtho is executed between the ");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"execution	of glBegin and the corresponding execution of glEnd.");
glFlush();
}



void j()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glutMainLoop ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"enters the GLUT event processing loop.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutMainLoop(void);");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"Does not take any parameters.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"glutMainLoop enters the GLUT event processing loop. This routine should be called");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0," at most once in a GLUT program. Once called, this routine will never return. It will ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"call as necessary any callbacks that have been registered.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0," ");
glFlush();
}



void k()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glutInit ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"glutInit is used to initialize the GLUT library.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutInit(int *argcp, char **argv);");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"argcp:");
glColor3f(0.5,0.1,0.9);
drawstring(60.0,490.0,0.0,"A pointer to the program's unmodified argc variable from main. Upon return, the value pointed to");
glColor3f(0.5,0.1,0.9);
drawstring(60.0,460.0,0.0,"by argcp will be updated, because glutInit extracts any command line options");
glColor3f(0.5,0.1,0.9);
drawstring(60.0,430.0,0.0,"intended for the GLUT library.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"argv:");
glColor3f(0.5,0.1,0.9);
drawstring(60.0,370.0,0.0,"The program's unmodified argv variable from main. Like argcp, the data for argv will be");
glColor3f(0.5,0.1,0.9);
drawstring(60.0,340.0,0.0,"updated because glutInit extracts any command line options understood by the GLUT library.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"glutInit will initialize the GLUT library and negotiate a session with the window system.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"During this process, glutInit may cause the termination of the GLUT program with an error");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"message to the user if GLUT cannot be properly initialized. Examples of this situation ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,190.0,0.0,"include the failure to connect to the window system, the lack of window system support for OpenGL,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,160.0,0.0,"and invalid command line options.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,130.0,0.0,"glutInit also processes command line options, but the specific options parse are window system dependent.");
glFlush();
}



void l()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"glutInitWindowPosition");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," and ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"glutInitWindowSize");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"glutInitWindowPosition and   glutInitWindowSize set the initial window position and size respectively.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(70.0,580.0,0.0,"void glutInitWindowSize(int width, int height);");
glColor3f(0.4,0.1,0.5);
drawstring(70.0,550.0,0.0,"void glutInitWindowPosition(int x, int y);");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"width - Width in pixels");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"height - Height in pixels");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"x - Window X location in pixels");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"y - Window Y location in pixels");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"Windows created by glutCreateWindow will be requested to be created with the current initial ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"window position and size.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"The initial value of the initial window position GLUT state is -1 and -1.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"If either the X or Y component to the initial window position is negative, the actual window ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"position is left to the window system to determine. The initial value of the initial window size");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,190.0,0.0,"GLUT state is 300 by 300. The initial window size components must be greater than zero.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,160.0,0.0,"The intent of the initial window position and size values is to provide a suggestion to the window  ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,130.0,0.0,"system for a window's initial size and position.The window system is not obligated to use this information.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,100.0,0.0," Therefore, GLUT programs  should not assume the window was created at the specified size or position. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,70.0,0.0," A GLUT program should use the window's reshape callback to determine the true size of the window.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,50.0,0.0,"");
glFlush();
}



void m()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glutBitmapCharacter ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"glutBitmapCharacter renders a bitmap character using OpenGL.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutBitmapCharacter(void *font, int character);");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"font - Bitmap font to use.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"character - Character to render.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"glutBitmapCharacter renders the character in the named bitmap font. The available fonts are:");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,400.0,0.0,"GLUT_BITMAP_8_BY_13");
glColor3f(0.5,0.1,0.9);
drawstring(90.0,370.0,0.0,"A fixed width font with every character fitting in an 8 by 13 pixel rectangle. ");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,340.0,0.0,"GLUT_BITMAP_9_BY_15");
glColor3f(0.5,0.1,0.9);
drawstring(90.0,310.0,0.0,"A fixed width font with every character fitting in an 9 by 15 pixel rectangle.");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,280.0,0.0,"GLUT_BITMAP_TIMES_ROMAN_10");
glColor3f(0.5,0.1,0.9);
drawstring(90.0,250.0,0.0,"A 10-point proportional spaced Times Roman font.");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,220.0,0.0,"Other Fonts are listed below");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,190.0,0.0,"GLUT_BITMAP_TIMES_ROMAN_24");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,160.0,0.0,"GLUT_BITMAP_HELVETICA_10");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,130.0,0.0,"GLUT_BITMAP_HELVETICA_12");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,100.0,0.0,"GLUT_BITMAP_HELVETICA_18");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,70.0,0.0,"Rendering a nonexistent character has no effect. glutBitmapCharacter automatically sets the OpenGL");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,50.0,0.0,"unpack pixel storage modes it needs appropriately and saves and restores the previous modes before returning.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,20.0,0.0,"The generated call to glBitmap will adjust the current raster position based on the width of the character.");
glFlush();
}



void n()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glutKeyboardFunc ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0," glutKeyboardFunc sets the keyboard callback for the current window.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutKeyboardFunc(void (*func)(unsigned char key,int x, int y));");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"func:");
glColor3f(0.5,0.1,0.9);
drawstring(70.0,490.0,0.0,"The new keyboard callback function.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"glutKeyboardFunc sets the keyboard callback for the current window. When a user types into the window,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0," each key press generating an ASCII character will generate a keyboard callback. The key callback ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"parameter is the generated ASCII character. The state of modifier keys such as Shift cannot be determined");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"directly; their only effect will be on the returned ASCII data. The x and y callback parameters ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"indicate the mouse location in window relative coordinates when the key was pressed. When a new window");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0," is created, no keyboard callback is initially registered, and ASCII key strokes in the window are");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"ignored. Passing NULL to glutKeyboardFunc disables the generation of keyboard callbacks.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"During a keyboard callback, glutGetModifiers may be called to determine the state of modifier");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,190.0,0.0," keys when the keystroke generating the callback occurred.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"Creating Keyboard Function:");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"void my_keyboard(unsigned char key,int x, int y)");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"{ switch(key) {");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"case 'a': new_function();");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"break; }");
glFlush();
}



void o()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," glutSwapBuffers ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0," glutSwapBuffers swaps the buffers of the current window if double buffered. ");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutSwapBuffers(void);");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"Does not take any parameters.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"Description:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"Performs a buffer swap on the layer in use for the current window. Specifically, glutSwapBuffers");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0," promotes the contents of the back buffer of the layer in use of the current window to become the ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"contents of the front buffer. The contents of the back buffer then become undefined.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"The update typically takes place during the vertical retrace of the monitor, ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"rather than immediately after glutSwapBuffers is called.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"An implicit   glFlush is done by glutSwapBuffers before it returns. Subsequent OpenGL commands ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"can be issued immediately after calling glutSwapBuffers, but are not executed until the buffer ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"exchange is completed.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"If the layer in use is not double buffered, glutSwapBuffers has no effect.");
glFlush();
}



void p()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"glutInitDisplayMode");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"glutInitDisplayMode sets the initial display mode.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutInitDisplayMode(unsigned int mode);");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"mode : Display mode, normally the bitwise OR-ing of GLUT display mode bit masks. See values below:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"GLUT_RGBA : Bit mask to select an RGBA mode window. This is the default if neither GLUT_RGBA nor GLUT_INDEX are specified.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"GLUT_SINGLE : Bit mask to select a single buffered window. This is the default if neither GLUT_DOUBLE or GLUT_SINGLE are specified.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"GLUT_DOUBLE : Bit mask to select a double buffered window. This overrides GLUT_SINGLE if it is also specified ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"GLUT_DEPTH : Bit mask to select a window with a depth buffer.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"Description");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"The initial display mode is used when creating top-level windows, subwindows, and overlays to determine the OpenGL display mode");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0," for the to-be-created window or overlay.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"Note that GLUT_RGBA selects the RGBA color model, but it does not request any bits of alpha be allocated.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"To request alpha, specify GLUT_ALPHA. The same applies to GLUT_LUMINANCE.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}



void q()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"glutCreateWindow");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"  glutCreateWindow creates a top-level window.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"int glutCreateWindow(char *name);");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"name : ASCII character string for use as window name.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"Description:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"glutCreateWindow creates a top-level window. The name will be provided to the window system as the");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"window's name. The intent is that the window system will label the window with the name. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"Implicitly, the current window is set to the newly created window.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"Each created window has a unique associated OpenGL context. State changes to a window's ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0," associated OpenGL context can be done immediately after the window is created.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"The display state of a window is initially for the window to be shown. But the window's display ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"state is not actually acted upon until glutMainLoop is entered. This means until glutMainLoop is called,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0," rendering to a created window is ineffective because the window can not yet be displayed.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"The value returned is a unique small integer identifier for the window. The range of allocated");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0," identifiers starts at one. This window identifier can be used when calling glutSetWindow.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}


void r()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"glutReshapeFunc");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"  glutReshapeFunc sets the reshape callback for the current window.");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutReshapeFunc(void (*func)(int width, int height));");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"func : The new reshape callback function.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"glutReshapeFunc sets the reshape callback for the current window. The reshape callback is triggered when ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"a window is reshaped. A reshape callback is also triggered immediately before a window's first  ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"display callback after a window is created or whenever an overlay for the window is established.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"The width and height parameters of the callback specify the new window size in pixels. Before the callback,  ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"the current window is set to the window that has been reshaped.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"If a reshape callback is not registered for a window or NULL is passed to glutReshapeFunc the default reshape callback is used");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"This default callback will simply call glViewport(0,0,width,height) on the normal plane.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"If an overlay is established for the window, a single reshape callback is generated. It is the callback's responsibility");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0," to update both the normal plane and overlay for the window ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,190.0,0.0,"When a top-level window is reshaped, subwindows are not reshaped. It is up to the GLUT program to manage the size");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,160.0,0.0,"and positions of subwindows within a top-level window. Still, reshape callbacks will be triggered ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,130.0,0.0,"for subwindows when their size is changed using glutReshapeWindow.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,100.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}



void s()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"glutIdleFunc");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0," glutIdleFunc sets the global idle callback");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void glutIdleFunc(void (*func)(void));");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0," or continuous animation when window system events are not being received. If enabled, the idle");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0," callback is continuously called when events are not being received. The callback routine has no parameters. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"The current window and current menu will not be changed before the idle callback. Programs with multiple windows ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"and/or menus should explicitly set the current window and/or current menu and not rely on its current setting.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"The amount of computation and rendering done in an idle callback should be minimized to avoid affecting the program's  ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0," interactive response. In general, not more than a single frame of rendering should be done in an idle callback.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0," Passing NULL to glutIdleFunc disables the generation of the idle callback.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}



void t()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"gluLookAt");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"define a viewing transformation");
glColor3f(0.5,0.4,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"void gluLookAt(GLdouble eyeX,GLdouble eyeY,GLdouble eyeZ,GLdouble centerX,");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"GLdouble centerY,GLdouble centerZ,GLdouble upX,GLdouble upY,GLdouble upZ);");
glColor3f(0.5,0.4,0.8);
drawstring(50.0,520.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"eyeX, eyeY, eyeZ - Specifies the position of the eye point.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"centerX, centerY, centerZ - Specifies the position of the reference point.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"upX, upY, upZ - Specifies the direction of the up vector.");
glColor3f(0.5,0.4,0.9);
drawstring(50.0,400.0,0.0,"DESCRIPTION:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"gluLookAt creates a viewing matrix derived from an eye point,a reference point indicating the center of the scene, and an UP vector.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"The matrix maps the reference point to the negative z axis and the eye point to the origin. When a typical");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0," projection matrix is used, the center of the scene therefore maps to the center of the viewport. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"Similarly, the direction described by the UP vector projected onto the viewing plane is mapped to the positive");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0," y axis so that it points upward in the viewport. The UP vector must not be parallel to the line of ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"sight from the eye point to the reference point.");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}

void u()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"gl");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0," ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0," ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,".");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}

void v()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"gl");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"C SPECIFICATION:");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"PARAMETERS:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0," ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0," ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,".");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"");
glFlush();
}

void w()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"Programming Basics for OpenGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"In order to write a C application using GLUT you’ll need three files:");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"-> glut.h – This is the file you’ll have to include in your source code. The common place to put this ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"file is in the gl folder which should be inside the include folder of your system.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"-> glut32.lib (Windows) – This file must be linked to your application so make sure to put it your lib folder.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"-> glut32.dll (Windows) – You could place the dll file in your exe’s folder. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"In this section we’re going to build the main function of our application. The main function will perform  ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"the required initializations and start the event processing loop.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,310.0,0.0,"The first part of our main function code will initialize GLUT and create the window.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"The skeleton of our main function is going to start as:");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"int main(int argc, char **argv) {");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,190.0,0.0,"	        // init GLUT and create window");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,160.0,0.0,"	        // register callbacks");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,130.0,0.0,"	        // enter GLUT event processing cycle");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,100.0,0.0,"}");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.7,0.9);
drawstring(200.0,50.0,0.0,"PRESS x TO GOTO NEXT SCREEN");
glFlush();
}

void x()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"Functions inside main()");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"All the functions in GLUT have the prefix glut, and those which perform some kind of initialization ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"have the prefix glutInit. The first thing you must do is call the function glutInit.");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,460.0,0.0,"PRESS k KEY TO NAVIGATE TO glutInit specification");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0,"After initializing GLUT itself, we’re going to define our window. First we establish the window’s  ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"position, i.e. its top left corner. In order to do this we use the function glutInitWindowPosition.");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,370.0,0.0," PRESS l KEY TO NAVIGATE TO glutInitWindowPosition specification");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"Next we’ll choose the window size. In order to do this we use the function glutInitWindowSize.");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,310.0,0.0,"PRESS l KEY TO NAVIGATE TO glutInitWindowSize specification");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"Then you should define the display mode using the function glutInitDisplayMode.");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,250.0,0.0,"PRESS p KEY TO NAVIGATE TO glutInitDisplayMode specification");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0,"After all the above steps, the window can be created with glutCreateWindow.");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,190.0,0.0,"PRESS q KEY TO NAVIGATE TO glutCreateWindow specification");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,160.0,0.0,"GLUT provides a function that gets the application in a never ending loop, always waiting for the next event ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,130.0,0.0,"to process. The GLUT function is glutMainLoop used to achieve that,");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,100.0,0.0,"PRESS j KEY TO NAVIGATE TO glutMainLoop specification");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,50.0,0.0,"PRESS y TO GOTO NEXT SCREEN");
glFlush();
}

void y()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"Preparing the window for a reshape");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"GLUT provides a way to define which function should be called when the window is resized, i.e. to register a callback");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"for recomputing the perspective. Furthermore, this function will also be called when the window is initially created, so that even");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0," if you’re initial window is not square things will look OK. GLUT registers the callback function when you call glutReshapeFunc.");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,430.0,0.0," PRESS 'r' KEY TO NAVIGATE TO glutReshapeFunc specification");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,"Finally, we tell OpenGL that all matrix operations that follow will use the modelview matrix. This is just to be on the safe side.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,370.0,0.0,"Most operations, such as setting the camera and transforming objects will use this matrix. ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,340.0,0.0,"The idea is to have always the modelview matrix as default.");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,310.0,0.0,"ANIMATION IN OPENGL");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,280.0,0.0,"The first thing we must do is to tell GLUT that when the application is idle, the render function should be called. This causes ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,250.0,0.0," GLUT to keep calling our rendering function therefore enabling animation. GLUT provides a function, glutIdleFunc,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,220.0,0.0," that lets you register a callback function to be called when the application is idle.");
glColor3f(0.5,0.7,0.9);
drawstring(200.0,190.0,0.0,"PRESS 's' KEY TO NAVIGATE TO glutIdleFunc specification");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,160.0,0.0,"NOTE ON DOUBLE BUFFERING");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,130.0,0.0,"The glutSwapBuffers function cause the front and back buffers to switch thereby showing what was previously drawn in the back buffer.");
glColor3f(0.5,0.7,0.9);
drawstring(200.0,100.0,0.0,"PRESS 'o' KEY TO NAVIGATE TO glutSwapBuffers specification");
glColor3f(0.5,0.1,0.9);
drawstring(200.0,70.0,0.0,"");
glColor3f(0.5,0.7,0.9);
drawstring(200.0,50.0,0.0,"PRESS z TO GOTO NEXT SCREEN");
glFlush();
}

void z()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"Keyboard Functions in OPENGL");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0," ");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"");
glColor3f(0.5,0.1,0.2);
drawstring(200.0,640.0,0.0,"");
glColor3f(0.5,0.1,0.3);
drawstring(200.0,610.0,0.0,"");
glColor3f(0.5,0.1,0.4);
drawstring(50.0,580.0,0.0,"");
glColor3f(0.4,0.1,0.5);
drawstring(50.0,550.0,0.0,"");
glColor3f(0.5,0.1,0.8);
drawstring(50.0,520.0,0.0,"GLUT allows us to build applications that detect keyboard input using either the “normal” keys, or the special keys like F1 and Up.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,490.0,0.0,"In this section we’ll see how to detect which key was pressed, what further information we get from GLUT, and how to deal with it.");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,460.0,0.0,"GLUT provides two functions to register callbacks for keyboard events that occur when you press a key. The first one, glutKeyboardFunc,");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,430.0,0.0," is used to tell the windows system which function we want to process the “normal” key events. By “normal” keys, ");
glColor3f(0.5,0.1,0.9);
drawstring(50.0,400.0,0.0,", we mean letters, numbers, anything that has an ASCII code. ");
glColor3f(0.5,0.7,0.9);
drawstring(50.0,370.0,0.0,"PRESS 'n' KEY TO NAVIGATE TO glutKeyboardFunc specification ");
glColor3f(0.5,0.1,0.3);
drawstring(50.0,340.0,0.0,"MOVING THE CAMERA IN OPENGL");
glColor3f(0.3,0.1,0.9);
drawstring(50.0,310.0,0.0,"Variable declarations for setting the camera");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,280.0,0.0,"// angle of rotation for the camera direction");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,250.0,0.0,"float angle=0.0;");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,220.0,0.0,"// actual vector representing the camera's direction");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,190.0,0.0,"float lx=0.0f,lz=-1.0f;");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,160.0,0.0,"// XZ position of the camera");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,130.0,0.0,"float x=0.0f,z=5.0f;");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,100.0,0.0,"The gluLookAt function provides an easy and intuitive way to set the camera position and orientation. ");
glColor3f(0.5,0.1,0.9);
drawstring(80.0,70.0,0.0,"Basically it has three groups of parameters, each one is composed of 3 floating point values.");
glColor3f(0.5,0.7,0.9);
drawstring(200.0,50.0,0.0,"PRESS 't' KEY TO NAVIGATE TO gluLookAt specification ");
glColor3f(0.5,0.7,0.9);
drawstring(200.0,20.0,0.0,"PRESS 'v' KEY TO NAVIGATE TO next screen ");
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
        flag=1;
        mydisplay();
		}
            break;
	case 27:
	    flag=1;
        mydisplay();
		break;
    case '1':
        flag=3;
        mydisplay();
        break;
     case '2':
        flag=4;
        mydisplay();
        break;
    case '3':
        flag=5;
        mydisplay();
        break;
    case '4':
        flag=6;
        mydisplay();
        break;
    case '5':
        flag=7;
        mydisplay();
        break;
    case '6':
        flag=8;
        mydisplay();
        break;
    case '7':
        flag=9;
        mydisplay();
        break;
    case 'a':
        flag=10;
        mydisplay();
        break;
    case 'b':
        flag=11;
        mydisplay();
        break;
    case 'c':
        flag=12;
        mydisplay();
        break;
    case 'd':
        flag=13;
        mydisplay();
        break;
     case 'e':
        flag=14;
        mydisplay();
        break;
    case 'f':
        flag=15;
        mydisplay();
        break;
    case 'g':
        flag=16;
        mydisplay();
        break;
    case 'h':
        flag=17;
        mydisplay();
        break;
    case 'i':
        flag=18;
        mydisplay();
        break;
    case 'j':
        flag=19;
        mydisplay();
        break;
    case 'k':
        flag=20;
        mydisplay();
        break;
    case 'l':
        flag=21;
        mydisplay();
        break;
    case 'm':
        flag=22;
        mydisplay();
        break;
    case 'n':
        flag=23;
        mydisplay();
        break;
    case 'o':
        flag=24;
        mydisplay();
        break;
    case 'p':
        flag=25;
        mydisplay();
        break;
    case 'q':
        flag=26;
        mydisplay();
        break;
    case 'r':
        flag=27;
        mydisplay();
        break;
    case 's':
        flag=28;
        mydisplay();
        break;
    case 't':
        flag=29;
        mydisplay();
        break;
    case 'u':
        flag=30;
        mydisplay();
        break;
    case 'v':
        flag=31;
        mydisplay();
        break;
    case 'w':
        flag=32;
        mydisplay();
        break;
    case 'x':
        flag=33;
        mydisplay();
        break;
    case 'y':
        flag=34;
        mydisplay();
        break;
    case 'z':
        flag=35;
        mydisplay();
        break;
	default:break;
}
glFlush();
}

void mydisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
if(flag==0)
frontscreen ();
if(flag==1)
	helpscreen();
if(flag==2)
    startscreen();
if(flag==3)
    openglver10();
if(flag==4)
    opengl15();
if(flag==5)
    opengl20();
if(flag==6)
    opengl30();
if(flag==7)
    opengl40();
if(flag==8)
    opengl45();
if(flag==9)
    opengl46();
if(flag==10)
    a();
if(flag==11)
    b();
if(flag==12)
    c();
if(flag==13)
    d();
if(flag==14)
    e();
if(flag==15)
    f();
if(flag==16)
    g();
if(flag==17)
    h();
if(flag==18)
    i();
if(flag==19)
    j();
if(flag==20)
    k();
if(flag==21)
    l();
if(flag==22)
    m();
if(flag==23)
    n();
if(flag==24)
    o();
if(flag==25)
    p();
if(flag==26)
    q();
if(flag==27)
    r();
if(flag==28)
    s();
if(flag==29)
    t();
if(flag==30)
    u();
if(flag==31)
    v();
if(flag==32)
    w();
if(flag==33)
    x();
if(flag==34)
    y();
if(flag==35)
    z();
glutSwapBuffers();
}

// -----------------------------------
//             MENUS
// -----------------------------------

void processMenuStatus(int status, int x, int y) {

	if (status == GLUT_MENU_IN_USE)
		menuFlag = 1;
	else
		menuFlag = 0;
}
void processMainMenu(int option) {

	// nothing to do in here
	// all actions are for submenus
}

void processFontMenu(int option) {

	switch (option) {
		case basics:
			flag=32;
            mydisplay();
			break;
		case mainf:
			flag=33;
            mydisplay();
			break;
		case reshape:
			flag=34;
            mydisplay();
			break;
		case animate:
			flag=34;
            mydisplay();
            break;
		case keyboard:
            flag=35;
            mydisplay();
			break;
		case camview:
            flag=35;
            mydisplay();
			break;
		case navgs:
            flag=1;
            mydisplay();;
			break;
	}
}

void createPopupMenus() {

	fontMenu = glutCreateMenu(processFontMenu);

	glutAddMenuEntry("Basics Of OpenGL",basics );
	glutAddMenuEntry("main() function",mainf );
	glutAddMenuEntry("Reshape Basics",reshape  );
	glutAddMenuEntry("Animation Basics",animate  );
	glutAddMenuEntry("KeyBoard Basics ",keyboard  );
	glutAddMenuEntry("Camera-View Basics",camview  );
	glutAddMenuEntry("Navigation Sheet",navgs  );
    mainMenu = glutCreateMenu(processMainMenu);
    glutAddSubMenu("Navigate",fontMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// this will allow us to know if the menu is active
	glutMenuStatusFunc(processMenuStatus);
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
glutCreateWindow("OpenGL Documentation");

/*call back functions*/
glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboard);
//glutMouseFunc(myMouse);
	// init Menus
	createPopupMenus();
myinit();
glutMainLoop();
}

