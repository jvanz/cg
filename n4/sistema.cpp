#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
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

cell lookat[9] = {
    { 1, 180, 120, -5.0, 5.0, 5.0, 0.1,
        "Specifies the X position of the eye point.", "%.2f" },
    { 2, 240, 120, -5.0, 5.0, 7.0, 0.1,
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
    { 1, 180, 120, -5.0, 5.0, 5.0, 0.1,
        "Specifies the X position of the eye point.", "%.2f" },
    { 2, 240, 120, -5.0, 5.0, 7.0, 0.1,
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

cell lookat_lateral[9] = {
    { 1, 180, 120, -5.0, 5.0, 0.0, 0.1,
        "Specifies the X position of the eye point.", "%.2f" },
    { 2, 240, 120, -5.0, 5.0, 10.0, 0.1,
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
    { 13, 512, 512, 0.1, 10.0, 20.0, 0.05,
    "Specifies distance from viewer to far clipping plane.", "%.1f" },
};

float x  = 0, y  = 0, z  = 0, raio  = 4, g  = 360, a  = 360;
float x2 = 0, y2 = 0, z2 = 0, raio2 = 3, g2 = 0, a2   = 360;
float x3 = 0, y3 = 0, z3 = 0, raio3 = 2, g3 = 360, a3 = 360;

int troca = 1;
void redisplay_all(void);
void screen_display(void);

GLdouble projection[16], modelview[16];
GLuint window;
GLuint sub_width = 512, sub_height = 512;

void screen_reshape(int width, int height)
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

void screen_display(void)
{
    GLfloat pos[4] = {0.0, 3.0, 0.0, 1};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    
	// treta muito forte para não perder a identidade... D:

	// cubo 1
	glPushMatrix();

        glTranslatef(x, y, z);
	glRotated(a, x, y, z);
	glutSolidCube(0.5);

        glPopMatrix();

	// cubo 2
	glPushMatrix();

        glTranslatef(x2, y2, z2);
	glRotated(a2, x2, y2, z2);
	glutSolidCube(0.5);

        glPopMatrix();

	// tche 3
	glPushMatrix();

        glTranslatef(x3, y3, z3);
	glRotated(a3, x3, y3, z3);
	glutSolidTeapot(0.5);

        glPopMatrix();

    glDisable(GL_LIGHTING);
    glutSwapBuffers();
}

void redisplay_all(void)
{
    glutSetWindow(window);
    screen_reshape(sub_width, sub_height);
    glutPostRedisplay();
}

void move(int sig)
{
	while (1) {
		if (g <= 0) {
			x = 0.0;
			y = 0.0;
			g = 360.0;
			troca = !troca;
			if(!troca)
				memcpy(lookat, lookat_lateral, sizeof(lookat_lateral));
			else
				memcpy(lookat, lookat_cima, sizeof(lookat_cima));
			screen_reshape(sub_width, sub_height);
		} else {
			x = (raio * cos(M_PI * g / 180.0f));
	        	y = (raio * sin(M_PI * g / 180.0f));
			g -= 0.1;
		}
		if (g2 >= 360) {
			x2 = 0.0;
			y2 = 0.0;
			g2 = 0.0;
		} else {
			x2 = (raio2 * cos(M_PI * g2 / 180.0f));
	        	y2 = (raio2 * sin(M_PI * g2 / 180.0f));
			g2 += 0.1;
		}
		if (a3 <= 0)
			a3 = 360;
		else
			a3 -= 5;
		if (a <= 0)
			a = 360;
		else
			a -= 15;
		if (a2 <= 0)
			a2 = 360;
		else
			a2 -=50;

		if (g3 <= 0) {
			x3 = 0.0;
			y3 = 0.0;
			g3 = 360.0;
		} else {
			x3 = (raio3 * cos(M_PI * g3 / 180.0f));
	        	y3 = (raio3 * sin(M_PI * g3 / 180.0f));
			g3 -= 0.1;
		}

		screen_display();
	}
}

int
main(int argc, char** argv)
{
	struct sigaction sact;

    sigemptyset( &sact.sa_mask );
    sact.sa_flags = 0;
    sact.sa_handler = move;
    sigaction( SIGALRM, &sact, NULL );

    alarm(1);

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(sub_width, sub_height);
    glutInitWindowPosition(50, 50);
    glutInit(&argc, argv);
    
    window = glutCreateWindow("N4 - Marcos Paulo de Souza / José Guilherme Vanz");
    glutReshapeFunc(screen_reshape);
    glutDisplayFunc(screen_display);

    redisplay_all();

    glutMainLoop();

    return 0;
}
