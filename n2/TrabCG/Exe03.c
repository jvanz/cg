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

GLint gJanelaPrincipal = 0;           // gMainWindow

void inicializacao(void);
void exibicaoPrincipal(void);
void SRU(void);
void reshape (int w, int h);

double RetornaX(double angulo, double raio){
    return (raio * cos(M_PI * angulo / 180.0));
}

double RetornaY(double angulo, double raio){
    return (raio * sin(M_PI * angulo / 180.0));
}
void inicializacao (void) {         // init
	glClearColor(1.0f,1.0f,1.0f,1.0);
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
    glVertex3f(xIni, yIni, 0.0f); // origin of the line
    glVertex3f(xFim, yFim, 0.0f); // ending point of the line
    glEnd( );
}



void exibicaoPrincipal(void) {            // maindisplay
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-20, 20, -20, 20);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SRU();

    //desenha circulo
    glColor3f(0.0f,0.0,1.0);//Azul


    glPointSize(2.0f);

    desenhaCirculo(5.0f, 5.0f, 5.0f);

    desenhaCirculo(5.0f, -5.0f, 5.0f);

    desenhaCirculo(5.0f, 0.0f, -5.0f);

    //traça o triangulo entre os centros dos circulos
    //a - b
    desenhaReta(-5, 5, 5, 5);

    desenhaReta(5, 5, 0, -5);

    desenhaReta(0, -5, -5, 5);




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
    glutMainLoop();

    return 0;
}
