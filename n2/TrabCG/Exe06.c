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

#include <stdio.h>
#include <math.h>
GLint gJanelaPrincipal = 0;           // gMainWindow

float p1x = -10.f, p2x = -10.f, p3x = 10.f, p4x = 10.f,
      p1y = -10.f, p2y = 10.f, p3y = 10.f, p4y = -10.f;

int pontoAtual = 0;

int qtdPontosSpline = 10;
const int INC_SPLINE = 1;
const int MIN_PONTOS_SPLINE = 1;
const int MAX_PONTOS_SPLINE = 5000;


void drawBezier(double t, float *x, float *y)
{
    *x = pow((1 - t), 3) * p1x + 3 * t * pow((1 -t), 2) * p2x  + 3 * (1-t) * pow(t, 2)* p3x  + pow (t, 3)* p4x;
    *y = pow((1 - t), 3) * p1y + 3 * t * pow((1 -t), 2) * p2y  + 3 * (1-t) * pow(t, 2)* p3y  + pow (t, 3)* p4y;
}

void desenhaLinha(float p1x, float p1y, float p2x, float p2y)
{
    glBegin(GL_LINES);
    glVertex2f(p1x, p1y);
    glVertex2f(p2x, p2y);
    glEnd();
}
void casteljau()
{

    float pAtualY, pAtualX, pProxX, pProxY;

    pAtualX = p1x;
    pAtualY = p1y;

    for(double t = 0.0;t <= 1.0; t += ((double)1/qtdPontosSpline))
    {
        drawBezier(t, &pProxX, &pProxY);
        desenhaLinha(pAtualX, pAtualY, pProxX, pProxY);
        //tAtual+= t;
        pAtualX = pProxX;
        pAtualY = pProxY;
    }
}

void desenhaSpline()
{
     casteljau();
}

void desenhaPontoVermelho()
{
    float *px, *py;
    switch(pontoAtual)
    {
    case 0:
    {
        px = &p1x;
        py = &p1y;
    }
    break;
    case 1:
    {

        px = &p2x;
        py = &p2y;
    }
    break;
    case 2:
    {
        px = &p3x;
        py = &p3y;
    }
    break;
    case 3:
    {
        px = &p4x;
        py = &p4y;
    }
    break;
    }

    printf("*px= %f *py= %f ponto= %d\n", *px, *py, pontoAtual);

    glColor3f(1.0f, 0.f, 0.f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);

    glVertex2f(*px, *py);
    glEnd();
}



void desenhaGL_LINE_STRIP()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(p1x, p1y);
    glVertex2f(p2x, p2y);
    glVertex2f(p3x, p3y);
    glVertex2f(p4x, p4y);
    glEnd();
}


void inicializacao(void);
void exibicaoPrincipal(void);
void SRU(void);
void reshape (int w, int h);

void inicializacao (void)           // init
{
    glClearColor(1.0f,1.0f,1.0f,1.0);

}

void exibicaoPrincipal(void)              // maindisplay
{

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D(-20, 20, -20, 20);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SRU();

    glColor3f(0.0,1.0,1.0);
    desenhaGL_LINE_STRIP();
    desenhaPontoVermelho();
    desenhaSpline();

    glutSwapBuffers();


}

void SRU(void)                              // Sistema de Referencia do Universo
{
    // eixo x
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin( GL_LINES );
    glVertex2f( 0.0f, 0.0f );
    glVertex2f( 10.0f, 0.0f );
    glEnd();

    // eixo y
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin( GL_LINES);
    glVertex2f(  0.0f, 0.0f);
    glVertex2f(  0.0f, 10.0f );
    glEnd();
}


void moverPonto(unsigned char direcao)
{
    float *px, *py;
    switch(pontoAtual)
    {
    case 0:
        px = &p1x;
        py = &p1y;
        break;
    case 1:
        px = &p2x;
        py = &p2y;
        break;
    case 2:
        px = &p3x;
        py = &p3y;
        break;
    case 3:
        px = &p4x;
        py = &p4y;
        break;
    }

    switch(direcao)
    {
    case 'e':
    {
        (*px)--;
        break;
    }
    case 'd':
    {
        (*px)++;
        break;
    }
    case 'c':
    {
        (*py)++;
        break;
    }

    case 'b':
    {
        (*py)--;
        break;
    }
    }

    printf("*px =%f *py=%f direcao=%d pontoAtual = %d\n", *px, *py, direcao, pontoAtual);
}

void keyPressed(unsigned char tecla, GLint x, GLint y)
{
    switch (tecla)
    {

    case '1':
        pontoAtual = 0;
        break;
    case '2':
        pontoAtual = 1;
        break;
    case '3':
        pontoAtual = 2;
        break;
    case '4':
        pontoAtual = 3;
        break;
    case 'e':
        moverPonto('e');
        break;
    case 'd':
        moverPonto('d');
        break;
    case 'c':
        moverPonto('c');
        break;
    case 'b':
        moverPonto('b');
        break;
    case 'q'://menos pontos na spline
        if((qtdPontosSpline - INC_SPLINE) > MIN_PONTOS_SPLINE)
            qtdPontosSpline -= INC_SPLINE;
        break;
    case 'w'://mais pontos na spline
        if(qtdPontosSpline + INC_SPLINE < MAX_PONTOS_SPLINE )
            qtdPontosSpline += INC_SPLINE;
        break;

    }

    exibicaoPrincipal();
    printf("Key pressed %d %c %d", tecla,tecla, qtdPontosSpline);

}


void reshape (int w, int h)
{
    //	glViewport(0,0,(GLsizei)w,(GLsizei)h);    // nao usar por enquanto...
    glutPostRedisplay();
}

int main (int argc, const char * argv[])
{
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition (250, 200);
    glutInitWindowSize (500, 500);
    gJanelaPrincipal = glutCreateWindow("Exe06");
    inicializacao();


    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutDisplayFunc(exibicaoPrincipal);
    glutMainLoop();

    return 0;
}
