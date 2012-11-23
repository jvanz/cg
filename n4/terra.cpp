#include <GL/glut.h>
#include "glm.h"

GLMmodel* pmodel = NULL;

void desenha(void)
{
	glMatrixMode (GL_PROJECTION);
        glLoadIdentity (); 
        gluOrtho2D(0, 500, 0, 500);
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity();

        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	if (!pmodel) {
	        pmodel = glmReadOBJ("objs/terra.obj");
        	if (!pmodel)
			exit(0);
	        glmUnitize(pmodel);
        	glmFacetNormals(pmodel);
	        glmVertexNormals(pmodel, 90.0);
	}

	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
        glDisable(GL_LIGHTING);
}

void
screen_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	gluLoookAt(10,10,10,10,10,10,0,1,0);
	desenha();
	glutSwapBuffers();
}

void reshape(int width, int height)
{
}

void inicializacao(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

//	Posiciona luz 
// 	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);


}

int main(int argc, char *argv[])
{
	glutInit(&argc, (char **)argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowPosition (250, 200);
        glutInitWindowSize (300, 300);
        (void)glutCreateWindow("Trabalho N4 - Jose Guilherme Vanz / Marcos Paulo de Souza");
	inicializacao();
	//glutReshapeFunc(reshape);
	//glutDisplayFunc(screen_display);
/*
	glNewList(SPHERE, GL_COMPILE);
	sphere = gluNewQuadric();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sphere_mat);
	gluSphere(sphere, 20.f, 20, 20);
	gluDeleteQuadric(sphere);
	glEndList();
*/
        glutMainLoop();
}
