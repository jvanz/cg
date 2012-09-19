/// \file main.cpp
/// \brief Implementation file for "exemplos_c++-opengl_mac".
/// \version $Revision: 1.0 $
/// \author Dalton Reis.
/// \date 03/05/11.

#if defined(__APPLE__) || defined(MACOSX)
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#else
    #ifdef WIN32
        #include <windows.h>
        #include <GL/gl.h>
        #include <GL/glut.h>
    #endif
#endif

#include <math.h>
#include <stdio.h>
GLint gJanelaPrincipal = 0;           // gMainWindow

const float RAIO_EXTERNO = 15.f;
const float RAIO_JOYSTICK = 5.f;

float p1x, p2x, p3x, p4x,
      p1y, p2y, p3y, p4y;

float posicaoJoystickX = 0.f;
float posicaoJoystickY = 0.f;

void desenhaCirculo(float raio, float x, float y);
void inicializacao(void);
void exibicaoPrincipal(void);
void SRU(void);
void reshape (int w, int h);
void calculaQuadrado(float raio);
void desenhaPontoCentral(float x, float y);
void desenhaJoystick();
float radian(float v);
bool movimentar(float x, float y);
bool dentroCirculo(float x, float y);
bool dentroDoQuadrado(float x, float y);

double RetornaX(double angulo, double raio){
    return (raio * cos(M_PI * angulo / 180.0));
}

double RetornaY(double angulo, double raio){
    return (raio * sin(M_PI * angulo / 180.0));
}
void inicializacao (void) {         // init
	glClearColor(1.0f,1.0f,1.0f,1.0);
	glPointSize(3.f);
}

float radian(float v)
{
    return v* M_PI / 180;
}

void calculaQuadrado(float raio)
{
    p1x = RetornaX(45, raio);
    p1y = RetornaY(45, raio);
    printf ("p1x=%f, p1y=%f \n", p1x, p1y);

    p2x = RetornaX(135, raio);
    p2y = RetornaY(135, raio);
    printf ("p2x=%f, p2y=%f \n", p2x, p2y);

    p3x = RetornaX(225, raio);
    p3y = RetornaY(225, raio);
    printf ("p3x=%f, p3y=%f \n", p3x, p3y);

    p4x = RetornaX(315, raio);
    p4y = RetornaY(315, raio);
    printf ("p4x=%f, p4y=%f \n", p4x, p4y);

}

void desenhaPontoCentral(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void desenhaCirculo(float raio, float x, float y)
{
    for(int i = 0; i < 360; i++)
    {
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
    glEnd( );
}
void desenhaQuadrado()
{
    desenhaReta(p1x, p1y, p2x, p2y);
    desenhaReta(p2x, p2y, p3x, p3y);
    desenhaReta(p3x, p3y, p4x, p4y);
    desenhaReta(p4x, p4y, p1x, p1y);
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
    //case 'd':
    case GLUT_KEY_RIGHT:
        if(movimentar(posicaoJoystickX + 1, posicaoJoystickY))
            posicaoJoystickX++;
        break;
    default:
        break;
	}
	exibicaoPrincipal();


    printf ("KEY: %c %d \n", tecla, tecla);
}

void keyPressedSpecial(int tecla, GLint px, GLint py)
{
    processaTeclado(tecla);
}

//Teclas Normais
void keyPressed(unsigned char tecla, GLint x, GLint y) {
    processaTeclado(tecla);
    /*
	switch (tecla) {

	case 'w': // cima
        if(movimentar(posicaoJoystickX, posicaoJoystickY + 1.f))
            posicaoJoystickY++;
		break;
	case 's'://baixo
        if(movimentar(posicaoJoystickX, posicaoJoystickY -1))
            posicaoJoystickY--;
        break;
    case 'a'://esquerda
        if(movimentar(posicaoJoystickX -1, posicaoJoystickY))
            posicaoJoystickX--;
        break;
    case 'd'://direita
        if(movimentar(posicaoJoystickX + 1, posicaoJoystickY))
            posicaoJoystickX++;
        break;
	}

	printf ("KEY: %c %d \n", tecla, tecla);*/

}

bool dentroDoQuadrado(float x, float y)
{
    return (((p1x > x) && (p2x < x)) && ((p1y > y) && (p4y < y)));
}

bool dentroCirculo(float x, float y)
{
    float distancia = sqrtf( pow(x, 2) + pow(y,2));

    return distancia <= RAIO_EXTERNO;

}

bool movimentar(float x, float y)
{
    if(dentroDoQuadrado(x,y))
    {
        return true;
    }
    return dentroCirculo(x, y);
}
void desenhaJoystick()
{
    desenhaCirculo(RAIO_JOYSTICK, posicaoJoystickX,  posicaoJoystickY);
    desenhaPontoCentral(posicaoJoystickX, posicaoJoystickY);
}

void exibicaoPrincipal(void) {            // maindisplay


        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        gluOrtho2D(-20, 20, -20, 20);
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity ();
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //SRU();

        //desenha circulo
        glColor3f(0.0f,0.0,0.0);

        desenhaCirculo(RAIO_EXTERNO,0.f,0.f);
        calculaQuadrado(RAIO_EXTERNO);
        desenhaQuadrado();

        desenhaJoystick();

        glutSwapBuffers();


}

void SRU(void) {                            // Sistema de Referencia do Universo
	// eixo x
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(1.0f);
	glBegin( GL_LINES );
    glVertex2f(  0.0f, 0.0f );
    glVertex2f(  10.0f, 0.0f );
	glEnd();

	// eixo y
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin( GL_LINES);
    glVertex2f(  0.0f, 0.0f);
    glVertex2f(  0.0f, 10.0f );
  	glEnd();
}

void reshape (int w, int h) {
    //	glViewport(0,0,(GLsizei)w,(GLsizei)h);    // nao usar por enquanto...
	glutPostRedisplay();
}

int main (int argc, const char * argv[]) {
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (500, 500);
	gJanelaPrincipal = glutCreateWindow("Exe01");
    inicializacao();


    glutReshapeFunc(reshape);
    glutDisplayFunc(exibicaoPrincipal);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(keyPressedSpecial);
    glutMainLoop();

    return 0;
}
