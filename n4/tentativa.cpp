#include <GL/glut.h>
#include <math.h>
#include "glm.h"

GLint gJanelaPrincipal = 0;
GLMmodel *pmodel = NULL;

void inicializa(void) {
	glClearColor(238.0f, 233.0f, 233.0f, 0.0);
}

void redimensiona(int w, int h) {
	glutPostRedisplay();
}

void
drawmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("terra.obj");
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}

void desenha(void)
{
	GLdouble inverse[16];
	GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };

	glEnable(GL_LIGHTING);
        glPushMatrix();
        glMultMatrixd(inverse);
        glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
        glPopMatrix();

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();

	gluPerspective(60, 1, 0.1, 100);
	gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	drawmodel();
    
	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);

	glutSwapBuffers();
}

int main (int argc, const char * argv[]) {
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (400, 400);
	gJanelaPrincipal = glutCreateWindow("tcheeeeeeeeeee");
	inicializa();
    
	glutReshapeFunc(redimensiona);
	glutDisplayFunc(desenha);
	glutMainLoop();
	
    return 0;
}
