/*Implementação do exercício 04 da trabalho n2
 * Autores: José Guilherme Vanz
 * 	    Marcos Paulo de Souza
 * */

#include<math.h>
#include<GL/freeglut.h>
#include<stdio.h>

void init(void);
void desenha(void);
void redimensiona(int,int);
void desenhaPontos(void);
void desenhaLinhas(void);
void desenhaLineLoop(void);
void desenhaLineStrip(void);
void desenhaTriangulos(void);
void desenhaTriangulosFan(void);
void desenhaQuads(void);
void desenhaTrianguloStrip();
double retornaX(double,double);
double retornaY(double,double);


//TODO - Implementar a interação com a barra de espaço
void init(void)
{
	glClearColor(1.0f,1.0f,1.0f,0.0);
}

void desenha(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20,20,-20,20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	desenhaTrianguloStrip();

	glutSwapBuffers();
}

void redimensiona(int w, int h)
{
	glutPostRedisplay();
}

void desenhaPontos()
{
	glPointSize(3.0f);
	glBegin(GL_POINTS);

	//ponto azul
	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(-10.0f,10.0f);

	//ponto vermelho
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

	//ponto verde
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);

	//ponto rosa
	glColor3f(1.0f,0.0f,1.0f);
	glVertex2f(-10.0f,-10.0f);
	
	
	glEnd();
	

}

void desenhaLinhas()
{
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(-10.0f,10.0f);
	glColor3f(1.0f,0.0f,1.0f);
	glVertex2f(-10.0f,-10.0f);
	
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

	glEnd();	
}

void desenhaLineLoop()
{
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(-10.0f,10.0f);
	
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);
	
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

	glColor3f(1.0f,0.0f,1.0f);
	glVertex2f(-10.0f,-10.0f);

	glEnd();	

}

void desenhaLineStrip()
{
	glLineWidth(3.0f);
	glBegin(GL_LINE_STRIP);

	glColor3f(1.0f,0.0f,1.0f);
	glVertex2f(-10.0f,-10.0f);

	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(-10.0f,10.0f);

	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);

	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

	glEnd();	

}

void desenhaTriangulos()
{
	glLineWidth(3.0f);
	glBegin(GL_TRIANGLES);

	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(-10.0f,10.0f);

	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);

	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

	glEnd();
	
}

void desenhaTriangulosFan()
{
	glLineWidth(3.0f);
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(-10.0f,10.0f);

	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);

	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);

	glColor3f(1.0f,0.0f,1.0f);
	glVertex2f(-10.0f,-10.0f);
	

	glEnd();
	
}

void desenhaTrianguloStrip()
{
	glLineWidth(3.0f);
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);

	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

        glColor3f(1.0f,0.0f,1.0f);
        glVertex2f(-10.0f,-10.0f);
	
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(-10.0f,10.0f);

	glEnd();

	
}

void desenhaQuads()
{
	printf("Desenha GL_QUADS\n");
        glBegin(GL_QUADS);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(-10.0f,10.0f);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(10.0f,10.0f);

        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(10.0f,-10.0f);

        glColor3f(1.0f,0.0f,1.0f);
        glVertex2f(-10.0f,-10.0f);

        glEnd();

}

int main(int argc, const char * argv[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300,250);
	glutInitWindowSize(800,800);
	GLint gJanelaPrincipal = glutCreateWindow("N2 - Exe05");
	init();
	
	glutReshapeFunc(redimensiona);
	glutDisplayFunc(desenha);
	glutMainLoop();
	
	return 0;
}


