/*Alunos: José Guilherme Vanz
 * 	  Marcos Paulo de Souza
 *Início do programa
 **/

#include "main.h"

void teclado(int tecla)
{
	//TODO processamento das teclas
}

void desenha()
{
	//TODO
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
	glPointSize(3.f);
}

int main (int argc, const char * argv[]) 
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (500, 500);
	GLint gJanelaPrincipal = glutCreateWindow("Trabalho N3 - José Guilherme Vanz / Marcos Paulo de Souza");
	inicializacao();
 
	glutReshapeFunc(reshape);
	glutDisplayFunc(desenha);
 
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(keyPressedSpecial);
	glutMainLoop();
 
	return 0;
}
