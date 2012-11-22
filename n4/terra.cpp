#include <GL/glut.h>
#include "glm.h"

GLMmodel* pmodel = NULL;

void desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    desenha();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, (char **)argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowPosition (250, 200);
        glutInitWindowSize (300, 300);
        (void)glutCreateWindow("Trabalho N4 - Jose Guilherme Vanz / Marcos Paulo de Souza");

	glutDisplayFunc(screen_display);

        glutMainLoop();
}
