/*Alunos: José Guilherme Vanz
 * 	  Marcos Paulo de Souza
 *Início do programa
 **/

#include <iostream>
#include "main.h"
#include "mundo.h"

/* Tamanho da tela */
#define X_MAX 500
#define Y_MAX 500

using namespace std;

enum modo {DEFAULT, ADD, REMOVE, SELECTED, ADD_IN_SELECTED, TRANSLATE, RM_VERTEX};
typedef enum modo modo_app;

static float zoom = 1.0;
Mundo * mundo;
static modo_app estado;
vector<VART::Point4D*> pontosNovoPoligno;
int mousePosX, mousePosY;
static int contador = 1;

#define CIMA 101
#define BAIXO 103
#define DIREITA 102
#define ESQUERDA 100
#define ESC 27

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
			estado = TRANSLATE;
			cout << "Estado = TRANSLATE" << endl;
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
			if(estado == TRANSLATE){
				mundo->doTranslate(1,1);
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
			if(estado == SELECTED){
				estado = ADD_IN_SELECTED;
				cout << "Estado = ADD_IN_SELECTED" << endl;
			}else{
				estado = ADD;
				cout << "Estado = ADD" << endl;
			}
			break;
		case 'm':
		case 'M':
			if(estado == SELECTED){
				mundo->doDelete();
			}else{
				cout << "Você deve selecionar um objeto primeiro!" << endl;
			}
			break;
		case 'v':
		case 'V':
			estado = RM_VERTEX;
			cout << "Estado = RM_VERTEX" << endl;
			break;
		case 'c':
		case 'C':
			estado = SELECTED;
			cout << "Estado = SELECTED" << endl;
			break;
		case ESC:
			if(pontosNovoPoligno.size() > 0){
				ObjetoGrafico * obj;
				if(estado == ADD_IN_SELECTED){
					obj = mundo->getObjSelecionado();
				}else{
					obj = mundo;
				}
				unsigned int index;
				Poligno * p2 = new Poligno(contador);
				for(index = 0; index < pontosNovoPoligno.size(); index++){
					p2->addPonto(pontosNovoPoligno[index]);
				}
				obj->addObjGrafFilho(p2);
				contador++;
				cout << "Contador = " << contador << endl;
			}
			estado = DEFAULT;
			pontosNovoPoligno.clear();
			mundo->setTodosSelecionadosFalse();
			cout << "Estado = DEFAULT" << endl;
	}
	glutPostRedisplay();
}

void desenha()
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(0, X_MAX * zoom, 0, Y_MAX * zoom);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	mundo->desenha();
	glColor3f(1.0, 0.0, 0.0);
	unsigned int index;
	for(index = 0; index < pontosNovoPoligno.size(); index++){
		glBegin(GL_POINTS);
		VART::Point4D * ponto = pontosNovoPoligno[index];
		glVertex2f(ponto->GetX(),ponto->GetY());
		glEnd();
	}
	if(pontosNovoPoligno.size() > 1){
		glBegin(GL_LINE_STRIP);
		for(index = 0; index < pontosNovoPoligno.size(); index++){
			VART::Point4D * ponto = pontosNovoPoligno[index];
			glVertex2f(ponto->GetX(),ponto->GetY());
		}
		glEnd();
	}
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
	mundo = new Mundo(0);
	estado = DEFAULT;
}

/**
 * Buscar posição da tela
 * Captura posição do mouse quando este é movido
 */
void buscaPosicaoTela(GLint x, GLint y)
{
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT,viewport);
	mousePosX = x;
	mousePosY = viewport[3]-y;
}

void mouseEvento(GLint botao, GLint estadoEvento, GLint x, GLint y) {
	if (estadoEvento == GLUT_DOWN) {
		buscaPosicaoTela(x,y);
		if((estado == ADD) | (estado == ADD_IN_SELECTED)){
			VART::Point4D * ponto = new VART::Point4D(mousePosX,mousePosY,0.0,1.0);
			pontosNovoPoligno.push_back(ponto);
		}else if(estado == SELECTED){
			mundo->setTodosSelecionadosFalse();
			VART::Point4D * ponto = new VART::Point4D(mousePosX,mousePosY,0.0,1.0);
			mundo->selecionaObj(ponto);
		}else if (estado == RM_VERTEX) {
			VART::Point4D * ponto = new VART::Point4D(mousePosX,mousePosY,0.0,1.0);
			mundo->removePonto(ponto);
		}
	}
	
	glutPostRedisplay();
}

void mouseMovimento(GLint x, GLint y) {
	mousePosX = x; mousePosY = y;
  	glutPostRedisplay();    
}

int main (int argc, const char * argv[]) 
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (X_MAX, Y_MAX);
	(void)glutCreateWindow("Trabalho N3 - Jose Guilherme Vanz / Marcos Paulo de Souza");
	inicializacao();
 
	glutReshapeFunc(reshape);
	glutDisplayFunc(desenha);
	glutPassiveMotionFunc(buscaPosicaoTela);
 
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(keyPressedSpecial);
	glutMotionFunc(mouseMovimento);
	glutMouseFunc(mouseEvento);
	glutMainLoop();
 
	return 0;
}
