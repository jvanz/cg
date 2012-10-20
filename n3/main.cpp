/*Alunos: José Guilherme Vanz
 * 	  Marcos Paulo de Souza
 *Início do programa
 **/

#include <iostream>
#include "main.h"
#include "mundo.h"
using namespace std;

static float zoom = 1.0;
static Mundo mundo(0);

int mousePosX, mousePosY;

#define CIMA 101
#define BAIXO 103
#define DIREITA 102
#define ESQUERDA 100


/*
 *TODO - Na enum dos modo da aplicacao deve ser adicionado os modos de
 * rotacao, escala e translacao ( MODE_ROTATE, MODE_SCALE, MODE_TRANSLATE )
 *
 */


/**
 * teclado
 * Função responsável pelo processamento das tecla precionadas pelo usuário
 * Tecla O -> Zoom Out ( - )
 * Tacla I -> Zoom In ( + )
 * */
void teclado(int tecla)
{
	printf("Tecla = %d\n", tecla);
	//TODO processamento das teclas
	switch(tecla){
		case 'I': /*Zoom +*/
		case 'i':
			zoom += 0.1f;
			break;
		case 'O': /*Zoom -*/
		case 'o':
			zoom -= 0.1f;
			break;
		case 't': /*Translate*/
		case 'T':
			/*TODO - Translacao
			 * Setar o modo da aplicação para  MODE_TRANSLATE
			*/
			break;
		case 'r': /*Rotate*/
		case 'R':
			/*TODO - Rotate
			 * Setar o modo da aplicação para MODE_ROTATE
 			*/
			break;
		case 's':/*Scale*/
		case 'S':
			/*TODO - Scale
			 * Setar o modo da aplicacao para MODE_SCALE
 			*/
			break;
		case CIMA:
			printf("CIMA\n");
			break;
		case BAIXO:
			printf("BAIXO\n");
			break;
		case ESQUERDA:
			printf("ESQUERDA\n");
			break;
		case DIREITA:
			printf("DIREITA\n");
			break;
	}
	desenha();
}

void desenha()
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-20 * zoom, 20 * zoom, -20 * zoom, 20 * zoom);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//TODO - Desenha componentes de tela
	mundo.desenha();

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
	glPointSize(3.f);
}

/**
 * Buscar posição da tela
 * Captura posição do mouse quando este é movido
 */
void buscaPosicaoTela(GLint x, GLint y)
{
	mousePosX = x;
	mousePosY = y;
}

int main (int argc, const char * argv[]) 
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (500, 500);
	gluOrtho2D(-100, 100, -100, 100);
	(void)glutCreateWindow("Trabalho N3 - Jose Guilherme Vanz / Marcos Paulo de Souza");
	inicializacao();
 
	glutReshapeFunc(reshape);
	glutDisplayFunc(desenha);
	glutPassiveMotionFunc(buscaPosicaoTela);
 
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(keyPressedSpecial);
	glutMainLoop();
 
	return 0;
}
