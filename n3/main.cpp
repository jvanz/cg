/*Alunos: José Guilherme Vanz
 * 	  Marcos Paulo de Souza
 *Início do programa
 **/

#include <iostream>
#include "main.h"
#include "mundo.h"
using namespace std;

enum modo {DEFAULT, ADD, REMOVE, SELECTED};
typedef enum modo modo_app;

static float zoom = 1.0;
static Mundo mundo(0);
static modo_app estado;

int mousePosX, mousePosY;

#define CIMA 101
#define BAIXO 103
#define DIREITA 102
#define ESQUERDA 100

//enum direcao {ESQUERDA=100, CIMA,DIREITA,BAIXO};
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
			if(estado == SELECTED){
				printf("CIMA\n");
			}
			break;
		case BAIXO:
			if(estado == SELECTED){
				printf("BAIXO\n");
			}
			break;
		case ESQUERDA:
			if(estado == SELECTED){
				printf("ESQUERDA\n");
			}
			break;
		case DIREITA:
			if(estado == SELECTED){
				printf("DIREITA\n");
			}
			break;
		case 'a':
		case 'A':
			estado = ADD;
			break;
		case 'm':
		case 'M':
//	if(estado == SELECTED){
				mundo.doDelete();
//	}else{
//		printf("Você deve selecionar um objeto primeiro!\n");
//	}
			break;
			
		case 'c':
		case 'C':
			estado = SELECTED;
		case '1':
			if(estado == SELECTED){
				mundo.apagaPonto(1);
			}
			break;
		case '2':
			if(estado == SELECTED){
				mundo.apagaPonto(2);
			}
			break;
		case '3':
			if(estado == SELECTED){
				mundo.apagaPonto(3);
			}
			break;
		case '4':
			if(estado == SELECTED){
				mundo.apagaPonto(4);
			}
			break;
		case '5':
			if(estado == SELECTED){
				mundo.apagaPonto(5);
			}
			break;
		case '6':
			if(estado == SELECTED){
				mundo.apagaPonto(6);
			}
			break;
		case '7':
			if(estado == SELECTED){
				mundo.apagaPonto(7);
			}
			break;
		case '8':
			if(estado == SELECTED){
				mundo.apagaPonto(8);
			}
			break;
		case '9':
			if(estado == SELECTED){
				mundo.apagaPonto(9);
			}
			break;
		/*TODO - Melhorar essa porquice de apagar ponto!*/
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
 
	Poligno * p2 = new Poligno(2);
	p2->setSelecionado(1);
	VART::Point4D * ponto4 = new VART::Point4D(0,-10,0.0,1.0);
	p2->addPonto(ponto4);
	VART::Point4D * ponto5 = new VART::Point4D(10,0,0.0,1.0);
	p2->addPonto(ponto5);
	VART::Point4D * ponto6 = new VART::Point4D(-10,0,0.0,1.0);
	p2->addPonto(ponto6);
	mundo.addObjGrafFilho(p2);
	estado = SELECTED;
	return 0;
}
