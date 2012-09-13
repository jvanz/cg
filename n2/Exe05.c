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
void desenhaPoligono(void);
double retornaX(double,double);
double retornaY(double,double);


//TODO - Implementar a interação com a barra de espaço
int funcaoAtual = 0;
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

	if(funcaoAtual == 0){
		desenhaPontos();
	}else if(funcaoAtual == 1){
		desenhaLinhas();
	}else if(funcaoAtual == 2){
		desenhaLineLoop();
	}else if(funcaoAtual == 3){
		desenhaLineStrip();
	}else if(funcaoAtual == 4){
		desenhaTriangulos();
	}else if(funcaoAtual == 5){
		desenhaTriangulosFan();
	}else if(funcaoAtual == 6){
		desenhaTrianguloStrip();
	}else if(funcaoAtual == 7){
		desenhaQuads();
	}else if(funcaoAtual == 8){
		// TODO - desenha quad strip
	}else if(funcaoAtual == 9){
		desenhaPoligono();	
	}
	glutSwapBuffers();
}

void redimensiona(int w, int h)
{
	glutPostRedisplay();
}

void desenhaPontos()
{
	printf("Desenha GL_POINTS\n");
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
	printf("Desenha GL_LINES\n");
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
	printf("Desenha GL_LINE_LOOP\n");
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
	printf("Desenha GL_LINE_STRIP\n");
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
	printf("Desenha GL_TRIANGLES\n");
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
	printf("Desenha GL_TRIANGLE_FAN\n");
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
	printf("Desenha GL_TRIANGLE_STRIP\n");
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

void desenhaPoligono()
{
	printf("Desenha GL_POLYGON\n");
	glBegin(GL_POLYGON);

	glVertex2f(0.0f,5.0f);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(10.0f,10.0f);

	glVertex2f(5.0f,0.0f);

	glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(10.0f,-10.0f);

	glVertex2f(0.0f,-5.0f);

        glColor3f(1.0f,0.0f,1.0f);
        glVertex2f(-10.0f,-10.0f);

	glVertex2f(-5.0f, 0.0f);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(-10.0f,10.0f);

	glEnd();	
}
#define ESPACO 32
void teclado(unsigned char tecla, GLint x, GLint y)
{
	switch(tecla){
		case ESPACO:
			funcaoAtual++;
			if(funcaoAtual == 10)
				funcaoAtual = 0;
			desenha();
			
	}	
		
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
	glutKeyboardFunc(teclado);
	glutDisplayFunc(desenha);
	glutMainLoop();
	
	return 0;
}


