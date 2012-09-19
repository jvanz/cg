/*Implementação do exercício 04 da trabalho n2
 * Autores: José Guilherme Vanz
 * 	    Marcos Paulo de Souza
 * */

#include<math.h>
#include<GL/freeglut.h>
#include<stdio.h>

void init(void);
void desenha(void);
void desenhaPrimitiva(int);
void redimensiona(int,int);
void desenhaQuadStrip(void);
double retornaX(double,double);
double retornaY(double,double);


int funcaoAtual = 0;
void init(void)
{
	glClearColor(1.0f,1.0f,1.0f,0.0);
}

void desenhaPrimitiva(int primitiva)
{
/* Foram adicionados if dentros dessa functions para que o desenho de algumas primitivas
 * gráficas não fiquem iguais. :-)
 */
	if(primitiva == GL_POINTS){
		printf("GL_POINTS\n");
	}
	if(primitiva == GL_LINES){
		printf("GL_LINES\n");
	}
	if(primitiva == GL_LINE_LOOP){
		printf("GL_LINE_LOOP\n");
	}
	if(primitiva == GL_LINE_STRIP){
		printf("GL_LINE_STRIP\n");
	}
	if(primitiva == GL_TRIANGLES){
		printf("GL_TRIANGLES\n");
	}
	if(primitiva == GL_TRIANGLE_FAN){
		printf("GL_TRIANGLE_FAN\n");
	}
	if(primitiva == GL_TRIANGLE_STRIP){
		printf("GL_TRIANGLE_STRIP\n");
	}
	if(primitiva == GL_QUADS){
		printf("GL_QUADS\n");
	}
	if(primitiva == GL_QUAD_STRIP){
		printf("GL_QUAD_STRIP\n");
	}
	if(primitiva == GL_POLYGON){
		printf("GL_POLYGON\n");
	}


	glPointSize(3.0f);
	glBegin(primitiva);

	if(primitiva == GL_TRIANGLE_FAN){
		//ponto verde
		glColor3f(0.0f,1.0f,0.0f);
		glVertex2f(10.0f,10.0f);
		//ponto azul
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(-10.0f,10.0f);

	}

	if(primitiva == GL_POLYGON)
		glVertex2f(0.0f, -5.0f);
		 
	//ponto vermelho
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(10.0f,-10.0f);

	if(primitiva == GL_POLYGON)
		glVertex2f(5.0f,0.0f);
 
	if(primitiva == GL_TRIANGLE_FAN){
		//ponto rosa
		glColor3f(1.0f,0.0f,1.0f);
		glVertex2f(-10.0f,-10.0f);
	}	

	//ponto verde
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(10.0f,10.0f);

	if(primitiva == GL_POLYGON)
		glVertex2f(0.0f,5.0f);

	if(primitiva != GL_TRIANGLE_FAN){	
		//ponto azul
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(-10.0f,10.0f);
	}
	if(primitiva == GL_POLYGON)
		glVertex2f(-5.0f,0.0f);
	
	//ponto rosa
	glColor3f(1.0f,0.0f,1.0f);
	glVertex2f(-10.0f,-10.0f);
	
	glEnd();
}

void desenha(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20,20,-20,20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	desenhaPrimitiva(funcaoAtual);
	glutSwapBuffers();
}

void redimensiona(int w, int h)
{
	glutPostRedisplay();
}

void desenhaQuadStrip()
{
	printf("Desenha GL_QUAD_STRIP\n");
	glBegin(GL_QUAD_STRIP);
	
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
	printf(GL_POINTS);
	glutReshapeFunc(redimensiona);
	glutKeyboardFunc(teclado);
	glutDisplayFunc(desenha);
	glutMainLoop();
		
	return 0;
}


