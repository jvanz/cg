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
GLint gJanelaPrincipal = 0;           // gMainWindow

float p1x = 10.f, p2x = -10.f, p3x = -10.f, p4x = 10.f,
      p1y = 10.f, p2y = 10.f, p3y = -10.f, p4y = -10.f;

float redI, redF, greenI, greenF, blueI,blueF;


enum COLOR {
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    PURPLE =3
};

 struct  Cor{
    int r,g,b;
};


Cor cores[4];

//Color azul;//, verde, vermelho, roxo;

//azul.r = 1;
//azul.g = 0.f;
//azul.b = 1.f;


void desenhaPonto(float x, float y)
{

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void setColor(Cor c)
{
    glColor3f(c.r, c.g, c.b);
}

void desenhaGL_POINTS()
{
    printf("GL_POINTS\n");
    glPointSize(3.f);
    setColor(cores[RED]);
    desenhaPonto(p1x, p1y );
    desenhaPonto(p2x, p2y);
    desenhaPonto(p3x, p3y);
    desenhaPonto(p4x, p4y);
}
//, float redI, float redF, float greenI, float greenF, float blueI, float blueF
void desenhaReta(float xIni, float yIni,float xFim,float yFim)
{

}
void desenhaGL_LINES(){
    desenhaReta(p3x, p3y, p2x, p2y);
    printf("GL_LINES\n");
    glBegin(GL_LINES);
    setColor(cores[PURPLE]);
    glVertex2f(p3x, p3y);
    setColor(cores[BLUE]);
    glVertex2f( p2x, p2y);

    setColor(cores[RED]);
    glVertex2f(p4x, p4y);
    setColor(cores[GREEN]);
    glVertex2f(p1x, p1y);

    glEnd();
}

void desenhaGL_LINE_LOOP(){

    printf("GL_LINE_LOOP\n");
    glBegin(GL_LINE_LOOP);
    setColor(cores[PURPLE]);
    glVertex2f(p1x, p1y);
    setColor(cores[BLUE]);
    glVertex2f(p2x, p2y);
    setColor(cores[RED]);
    glVertex2f(p3x, p3y);
    setColor(cores[GREEN]);
    glVertex2f(p4x, p4y);
    glEnd();


}
void desenhaGL_LINE_STRIP(){

    printf("GL_LINE_STRIP\n");
    glBegin(GL_LINE_STRIP);

    glVertex2f(p3x, p3y);
    setColor(cores[PURPLE]);
    glVertex2f(p2x, p2y);
    setColor(cores[BLUE]);
    glVertex2f(p1x, p1y);
    setColor(cores[RED]);
    glVertex2f(p4x, p4y);

    glEnd();
}
void desenhaGL_TRIANGLES(){
    printf("GL_TRIANGLES\n");
    glBegin(GL_TRIANGLES);

    setColor(cores[GREEN]);
    glVertex2f(p2x, p2y);
    setColor(cores[RED]);
    glVertex2f(p1x, p1y);
    setColor(cores[BLUE]);
    glVertex2f(p4x, p4y);

    glEnd();


}
void desenhaGL_TRIANGLE_FAN(){
    printf("GL_TRIANGLE_FAN\n");
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p2x, p2y);
    glVertex2f(p1x, p1y);
    glVertex2f(p4x, p4y);

    glEnd();

}
void desenhaGL_TRIANGLE_STRIP(){

    printf("GL_TRIANGLE_STRIP\n");
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(p2x, p2y);
    glVertex2f(p1x, p1y);
    setColor(cores[BLUE]);
    glVertex2f(p4x, p4y);

    glEnd();

}
void desenhaGL_QUADS(){

    printf("GL_QUADS \n");
    glBegin(GL_QUADS);
    setColor(cores[RED]);
    glVertex2f(p2x, p2y);
    setColor(cores[PURPLE]);
    glVertex2f(p1x, p1y);
    setColor(cores[RED]);
    glVertex2f(p4x, p4y);
    setColor(cores[PURPLE]);
    glVertex2f(p3x, p3y);


    glEnd();

}

void desenhaGL_QUAD_STRIP(){
    printf("GL_QUAD_STRIP \n");
    glBegin(GL_QUAD_STRIP);

    setColor(cores[RED]);
    glVertex2f(p2x, p2y);
    setColor(cores[GREEN]);
    glVertex2f(p1x, p1y);
    setColor(cores[BLUE]);
    glVertex2f(p4x, p4y);
    setColor(cores[PURPLE]);
    glVertex2f(p3x, p3y);

    glEnd();

}
void desenhaGL_POLYGON(){
    printf("GL_POLYGON\n");

    glBegin(GL_POLYGON);
    setColor(cores[RED]);
    glVertex2f(p2x, p2y);
    setColor(cores[GREEN]);
    glVertex2f(p1x, p1y);
    setColor(cores[BLUE]);
    glVertex2f(p4x, p4y);
    setColor(cores[PURPLE]);
    glVertex2f(p3x, p3y);

    glEnd();

}

void inicializacao(void);
void exibicaoPrincipal(void);
void SRU(void);
void reshape (int w, int h);

void inicializacao (void) {         // init
	glClearColor(1.0f,1.0f,1.0f,1.0);

	cores[RED].r = 1.0f;
    cores[GREEN].g = 1.0f;
    cores[BLUE].b = 1.0f;
    cores[PURPLE].r = 1.0f;
    cores[PURPLE].b = 1.0f;
}

void exibicaoPrincipal(void) {            // maindisplay

    static int tipoFigura = 0;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-20, 20, -20, 20);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //SRU();
	glColor3f(0.0,1.0,1.0);


    switch(tipoFigura)
    {/*void desenhaGL_POINTS();
void desenhaGL_LINES();
void desenhaGL_LINE_LOOP();
void desenhaGL_LINE_STRIP();
void desenhaGL_TRIANGLES();
void desenhaGL_TRIANGLE_FAN();
void desenhaGL_TRIANGLE_STRIP();
void desenhaGL_QUADS();
void desenhaGL_QUAD_STRIP();
void desenhaGL_POLYGON();
*/
        case 0:
            desenhaGL_POINTS();
        break;
        case 1:
            desenhaGL_LINES();
        break;
        case 2:
            desenhaGL_LINE_LOOP();
        break;
        case 3:
            desenhaGL_LINE_STRIP();
        break;
        case 4:
            desenhaGL_TRIANGLES();
        break;
        case 5:
            desenhaGL_TRIANGLE_FAN();
        break;
        case 6:
            desenhaGL_TRIANGLE_STRIP();
        break;
        case 7:
            desenhaGL_QUADS();
        break;
        case 8:
            desenhaGL_QUAD_STRIP();
            break;
        case 9:
            desenhaGL_POLYGON();
            break;
    }
    //GL_POINTS,  GL_LINES,  GL_LINE_LOOP,  GL_LINE_STRIP,  GL_TRIANGLES,  GL_TRIANGLE_FAN,  GL_TRIANGLE_STRIP,  GL_QUADS, GL_QUAD_STRIP e GL_POLYGON.

	glutSwapBuffers();
	tipoFigura++;

    if(tipoFigura >= 10)
        tipoFigura = 0;
	//tipoFigura = (tipoFigura % 8)+1;//? tipoFigura+1 : 1

}

void SRU(void) {                            // Sistema de Referencia do Universo
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

void keyPressed(unsigned char tecla, GLint x, GLint y) {
	switch (tecla) {

    case 32://Nao encontrei DEFINE para SPACE, pode dar conflito em outras plataformas
        exibicaoPrincipal();
        break;
	}

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
    glutKeyboardFunc(keyPressed);
    glutDisplayFunc(exibicaoPrincipal);
    glutMainLoop();

    return 0;
}
