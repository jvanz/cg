/*
    projection.c
    Nate Robins, 1997

    Tool for teaching about OpenGL projections.
    
*/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "glm.h"

typedef struct _cell {
    int id;
    int x, y;
    float min, max;
    float value;
    float step;
    char* info;
    char* format;
} cell;

double rotate_y=0; 
double rotate_x=0;

cell lookat[9] = {
    { 1, 180, 120, -5.0, 5.0, 0.0, 0.1,
        "Specifies the X position of the eye point.", "%.2f" },
    { 2, 240, 120, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Y position of the eye point.", "%.2f" },
    { 3, 300, 120, -5.0, 5.0, 2.0, 0.1,
    "Specifies the Z position of the eye point.", "%.2f" },
    { 4, 180, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the X position of the reference point.", "%.2f" },
    { 5, 240, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Y position of the reference point.", "%.2f" },
    { 6, 300, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Z position of the reference point.", "%.2f" },
    { 7, 180, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the X direction of the up vector.", "%.2f" },
    { 8, 240, 200, -2.0, 2.0, 1.0, 0.1,
    "Specifies the Y direction of the up vector.", "%.2f" },
    { 9, 300, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the Z direction of the up vector.", "%.2f" },
};

cell lookat_cima[9] = {
    { 1, 180, 120, -5.0, 5.0, 0.0, 0.1,
        "Specifies the X position of the eye point.", "%.2f" },
    { 2, 240, 120, -5.0, 5.0, 5.0, 0.1,
    "Specifies the Y position of the eye point.", "%.2f" },
    { 3, 300, 120, -5.0, 5.0, 1.0, 0.1,
    "Specifies the Z position of the eye point.", "%.2f" },
    { 4, 180, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the X position of the reference point.", "%.2f" },
    { 5, 240, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Y position of the reference point.", "%.2f" },
    { 6, 300, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Z position of the reference point.", "%.2f" },
    { 7, 180, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the X direction of the up vector.", "%.2f" },
    { 8, 240, 200, -2.0, 2.0, 1.0, 0.1,
    "Specifies the Y direction of the up vector.", "%.2f" },
    { 9, 300, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the Z direction of the up vector.", "%.2f" },
};

cell lookat_lateral[9] = {
    { 1, 180, 120, -5.0, 5.0, 0.0, 0.1,
        "Specifies the X position of the eye point.", "%.2f" },
    { 2, 240, 120, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Y position of the eye point.", "%.2f" },
    { 3, 300, 120, -5.0, 5.0, 3.0, 0.1,
    "Specifies the Z position of the eye point.", "%.2f" },
    { 4, 180, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the X position of the reference point.", "%.2f" },
    { 5, 240, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Y position of the reference point.", "%.2f" },
    { 6, 300, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Z position of the reference point.", "%.2f" },
    { 7, 180, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the X direction of the up vector.", "%.2f" },
    { 8, 240, 200, -2.0, 2.0, 1.0, 0.1,
    "Specifies the Y direction of the up vector.", "%.2f" },
    { 9, 300, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the Z direction of the up vector.", "%.2f" },
};

cell perspective[4] = {
    { 10, 180, 80, 1.0, 179.0, 60.0, 1.0,
        "Specifies field of view angle (in degrees) in y direction.", "%.1f" },
    { 11, 512, 512, -3.0, 3.0, 1.0, 0.01,
    "Specifies field of view in x direction (width/height).", "%.2f" },
    { 12, 512, 512, 0.1, 10.0, 1.0, 0.05,
    "Specifies distance from viewer to near clipping plane.", "%.1f" },
    { 13, 512, 512, 0.1, 10.0, 10.0, 0.05,
    "Specifies distance from viewer to far clipping plane.", "%.1f" },
};

const int PERSPECTIVE = 0;
int  mode = 0; //perspective

GLMmodel* pmodel = NULL;
GLint selection = 0;

void redisplay_all(void);
GLdouble projection[16], modelview[16], inverse[16];
GLuint window;
GLuint sub_width = 256, sub_height = 256;
/*
void
drawmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("al.obj");
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
*/
void another_keyboard(unsigned char key, int x, int y)
{
	printf("another\n");
    switch (key) {
    case 'l':
    case 'L':
        lookat[0].value = lookat_lateral[0].value;
        lookat[1].value = lookat_lateral[1].value;
        lookat[2].value = lookat_lateral[2].value;
        lookat[3].value = lookat_lateral[3].value;
        lookat[4].value = lookat_lateral[4].value;
        lookat[5].value = lookat_lateral[5].value;
        lookat[6].value = lookat_lateral[6].value;
        lookat[7].value = lookat_lateral[7].value;
        lookat[8].value = lookat_lateral[8].value;
        break;
    case 'c':
    case 'C':
        lookat[0].value = lookat_cima[0].value;
        lookat[1].value = lookat_cima[1].value;
        lookat[2].value = lookat_cima[2].value;
        lookat[3].value = lookat_cima[3].value;
        lookat[4].value = lookat_cima[4].value;
        lookat[5].value = lookat_cima[5].value;
        lookat[6].value = lookat_cima[6].value;
        lookat[7].value = lookat_cima[7].value;
        lookat[8].value = lookat_cima[8].value;
        break;
    }
    redisplay_all();
}

void
main_keyboard(int key, int x, int y)
{
	printf("main\n");
    switch (key) {
    case 100: //esquerda
        lookat[3].value -= 0.1;
	printf("esq\n");
	break;
    case 101: //cima
    case 102: //direita
        lookat[3].value += 0.1;
	printf("dir\n");
	break;
    case 103: //baixo
	break;
    case 27:
        exit(0);
    }
    
    redisplay_all();
}

void
screen_reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(perspective[0].value, perspective[1].value, perspective[2].value, perspective[3].value);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(lookat[0].value, lookat[1].value, lookat[2].value,
        lookat[3].value, lookat[4].value, lookat[5].value,
        lookat[6].value, lookat[7].value, lookat[8].value);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int old_y;

void draw_fucking_cube()
{
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 
  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included
 
  //Multi-colored side - FRONT
  glBegin(GL_POLYGON);
 
  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple
 
  glEnd();
 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  glFlush();
  glutSwapBuffers();
}

 void
screen_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    drawmodel();
    draw_fucking_cube();
    glutSwapBuffers();
}

void
redisplay_all(void)
{
    glutSetWindow(window);
    //screen_reshape(sub_width, sub_height);
	draw_fucking_cube();
    glutPostRedisplay();
}

void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

int
main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(50, 50);
    glutInit(&argc, argv);
    
    window = glutCreateWindow("Projection");
//    glutReshapeFunc(screen_reshape);
//    glutReshapeFunc(redisplay_all);
    glutDisplayFunc(screen_display);
    glutKeyboardFunc(another_keyboard);
//    glutSpecialFunc(main_keyboard);
    glutSpecialFunc(specialKeys);

    redisplay_all();
    
    glutMainLoop();
    
    return 0;
}
