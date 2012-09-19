#include <GL/glut.h>
#include <math.h>

GLint gJanelaPrincipal = 0;

void inicializa(void) {
	glClearColor(238.0f, 233.0f, 233.0f, 0.0);
}

void redimensiona(int w, int h)
{
	glutPostRedisplay();
}

void desenhaEixos(void)
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glLineWidth(1.5f);
	
	// y
	glBegin( GL_LINES );
        	glVertex2f(0.0f, 0.0f);
	        glVertex2f(0.0f, 10.0f);
	glEnd();

	// x
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin( GL_LINES);
        	glVertex2f(0.0f,  0.0f);
		glVertex2f(10.0f, 0.0f);
  	glEnd();	
}

void figuras(void)
{
	int grau, raio = 5;
	float x, y;
	glColor3f(0.0f, 0.0f, 1.0f);

	glPointSize(1.5f);
    
	// esquerda
	glBegin(GL_POINTS);
		for (grau = 0; grau < 360; grau++) {
			x = (raio * cos(M_PI * grau / 180.0f));
			y = (raio * sin(M_PI * grau / 180.0f));

			glVertex2d(x - 5.1, y + 5);
		}
	glEnd();

	// direita
	glBegin(GL_POINTS);
		for (grau = 0; grau < 360; grau++) {
			x = (raio * cos(M_PI * grau / 180.0f));
			y = (raio * sin(M_PI * grau / 180.0f));

			glVertex2d(x + 5.1, y + 5);
		}
	glEnd();

	// Baixo
	glBegin(GL_POINTS);
		for (grau = 0; grau < 360; grau++) {
			x = (raio * cos(M_PI * grau / 180.0f));
			y = (raio * sin(M_PI * grau / 180.0f));

			glVertex2d(x, y - 5);
		}
	glEnd();

	//triangulo
	glBegin(GL_LINE_LOOP);
		glVertex2d(-5, 5);
		glVertex2d(5, 5);
		glVertex2d(0, -5);
	glEnd();
	
}

void desenha(void)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-20, 20, -20, 20);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	desenhaEixos();
	figuras();
    
	glutSwapBuffers();
}

int main (int argc, const char * argv[]) {
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (400, 400);
	gJanelaPrincipal = glutCreateWindow("Respostas-03-Pratica OpenGL");
	inicializa();
    
	glutReshapeFunc(redimensiona);
	glutDisplayFunc(desenha);
	glutMainLoop();
	
    return 0;
}
