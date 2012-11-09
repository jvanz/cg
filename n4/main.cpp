/*Alunos: José Guilherme Vanz
 * 	  Marcos Paulo de Souza
 *Início do programa
 **/

/*
 *TODO - Verificar!
 * 1. Iremos movimentar a camera com o mouse ou teclado?
 *
 * */

#include <GL/glut.h>

/* Tamanho da tela */
#define X_MAX 500
#define Y_MAX 500

/* Código das teclas*/
#define CIMA 101
#define BAIXO 103
#define DIREITA 102
#define ESQUERDA 100
#define ESC 27

/**
 * teclado
 * Função responsável pelo processamento das tecla precionadas pelo usuário
 * */
void teclado(int tecla)
{
	switch(tecla){
		case CIMA:
			break;
		case BAIXO:
			break;
		case ESQUERDA:
			break;
		case DIREITA:
			break;
	}
	glutPostRedisplay();
}

void desenha()
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(0, X_MAX, 0, Y_MAX );
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glutSwapBuffers();
}

void keyPressedSpecial(int tecla, GLint px, GLint py)
{
	teclado(tecla);
}

void keyPressed(unsigned char tecla, GLint x, GLint y)
{
	teclado(tecla);
}

void reshape (int w, int h)
{
	glutPostRedisplay();
}

void inicializacao (void)
{
	glClearColor(1.0f,1.0f,1.0f,1.0);
	glPointSize(5.0f);
}

int main (int argc, const char * argv[]) 
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (X_MAX, Y_MAX);
	(void)glutCreateWindow("Trabalho N4 - Jose Guilherme Vanz / Marcos Paulo de Souza");
	inicializacao();
 
	glutReshapeFunc(reshape);
	glutDisplayFunc(desenha);
 
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(keyPressedSpecial);
	glutMainLoop();
 
	return 0;
}
