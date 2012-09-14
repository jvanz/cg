#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLint gJanelaPrincipal = 0;
const float RAIO_EXTERNO = 15.f, RAIO_JOYSTICK = 5.f;
float p1x, p2x, p3x, p4x, p1y, p2y, p3y, p4y, posicaoJoystickX = 0.f, posicaoJoystickY = 0.f;

double inline RetornaX(double angulo, double raio)
{
	return (raio * cos(M_PI * angulo / 180.0));
}

double inline RetornaY(double angulo, double raio)
{
	return (raio * sin(M_PI * angulo / 180.0));
}

void inicializacao (void)
{
	glClearColor(1.0f,1.0f,1.0f,1.0);
	glPointSize(3.f);
}

float inline radian(float v)
{
	return v * M_PI / 180;
}

void calculaQuadrado(float raio)
{
	p1x = RetornaX(45, raio);
	p1y = RetornaY(45, raio);

	p2x = RetornaX(135, raio);
	p2y = RetornaY(135, raio);

	p3x = RetornaX(225, raio);
	p3y = RetornaY(225, raio);

	p4x = RetornaX(315, raio);
	p4y = RetornaY(315, raio);
}

void desenhaPontoCentral(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
}

void desenhaCirculo(float raio, float x, float y)
{
	int i;

	glPointSize(2.0);

	for(i = 0; i < 360; i++) {
		glBegin(GL_POINTS);
			glVertex2f(RetornaX(i, raio) + x, RetornaY(i, raio)+y);
		glEnd();
	}
}

void desenhaReta(float xIni, float yIni,float xFim,float yFim)
{
	glBegin(GL_LINES);
		glVertex3f(xIni, yIni, 0.0f);
		glVertex3f(xFim, yFim, 0.0f);
	glEnd();
}
void desenhaQuadrado()
{
	desenhaReta(p1x, p1y, p2x, p2y);
	desenhaReta(p2x, p2y, p3x, p3y);
	desenhaReta(p3x, p3y, p4x, p4y);
	desenhaReta(p4x, p4y, p1x, p1y);
}

int dentroCirculo(float x, float y)
{
	return sqrtf( pow(x, 2) + pow(y,2)) <= RAIO_EXTERNO;
}

int dentroDoQuadrado(float x, float y)
{
	return (((p1x > x) && (p2x < x)) && ((p1y > y) && (p4y < y)));
}

int movimentar(float x, float y)
{
	if(dentroDoQuadrado(x,y))
		return 1;
	return dentroCirculo(x, y);
}

void desenhaJoystick()
{
	desenhaCirculo(RAIO_JOYSTICK, posicaoJoystickX,  posicaoJoystickY);
	desenhaPontoCentral(posicaoJoystickX, posicaoJoystickY);
}

void exibicaoPrincipal(void)
{
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        gluOrtho2D(-20, 20, -20, 20);
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity ();
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //desenha circulo
        glColor3f(0.0f,0.0,0.0);

        desenhaCirculo(RAIO_EXTERNO,0.f,0.f);
        calculaQuadrado(RAIO_EXTERNO);
        desenhaQuadrado();
        desenhaJoystick();

        glutSwapBuffers();
}

void processaTeclado(int tecla)
{
	switch (tecla) {
	case 'w': // cima
	case GLUT_KEY_UP:
		if(movimentar(posicaoJoystickX, posicaoJoystickY + 1.f))
			posicaoJoystickY++;
		break;

	case 's'://baixo
	case GLUT_KEY_DOWN:
        	if(movimentar(posicaoJoystickX, posicaoJoystickY -1))
			posicaoJoystickY--;
		break;

	case 'a'://esquerda
	case GLUT_KEY_LEFT:
		if(movimentar(posicaoJoystickX -1, posicaoJoystickY))
			posicaoJoystickX--;
	break;

	case GLUT_KEY_RIGHT:
		if(movimentar(posicaoJoystickX + 1, posicaoJoystickY))
			posicaoJoystickX++;
		break;
	}
	exibicaoPrincipal();
}

void keyPressedSpecial(int tecla, GLint px, GLint py)
{
	processaTeclado(tecla);
}

void keyPressed(unsigned char tecla, GLint x, GLint y)
{
	processaTeclado(tecla);
}

void reshape (int w, int h)
{
	glutPostRedisplay();
}

int main (int argc, const char * argv[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (500, 500);
	gJanelaPrincipal = glutCreateWindow("Respostas-07-Pratica OpenGL");
	inicializacao();

	glutReshapeFunc(reshape);
	glutDisplayFunc(exibicaoPrincipal);
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(keyPressedSpecial);
	glutMainLoop();

	return 0;
}
