/*Implementação do exercício 04 da trabalho n2
 * Autores: José Guilherme Vanz
 * 	    Marcos Paulo de Souza
 * */

#include<math.h>
#include<GL/freeglut.h>

void init(void);
void desenha(void);
void redimensiona(int,int);
void desenhaEixos();
void desenhaAspiral(int);
double retornaX(double,double);
double retornaY(double,double);


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

	desenhaEixos();
	desenhaAspiral(10);

	glutSwapBuffers();
}

void redimensiona(int w, int h)
{
	glutPostRedisplay();
}

/*Função responsável em desenha as aspirais*/
void desenhaAspiral(int voltas)
{
	glColor4f(0.0f,0.0f,0.0f,0);
	glPointSize(1.0f);
	glBegin(GL_POINTS);
	int contadorVoltas = 0;
	double raio = 0.1;
	while(contadorVoltas <= voltas){
		double angulo;
		for(angulo = 0.0 ; angulo < 360.0; angulo += 0.1){
			double x = retornaX(angulo,raio);
			double y = retornaY(angulo,raio);
			glVertex2d(x,y);
			raio += 0.00015 * raio;
		}
		contadorVoltas++;
	}
	glEnd();

	
}

double retornaX(double angulo, double raio)
{
	return (raio * cos(M_PI * angulo / 180.0));
}

double retornaY(double angulo, double raio)
{
	return (raio * sin(M_PI * angulo / 180.0));
}

void desenhaEixos()
{
	//eixo x
	glColor3f(1.0f,0.0f,0.0f);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f,0.0f);
	glVertex2f(10.0f,0.0f);
	glEnd();

	//eixo y
	glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.0f,10.0f);
	glEnd();
}

int main(int argc, const char * argv[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300,250);
	glutInitWindowSize(800,800);
	GLint gJanelaPrincipal = glutCreateWindow("N2 - Exe04");
	init();
	
	glutReshapeFunc(redimensiona);
	glutDisplayFunc(desenha);
	glutMainLoop();
	
	return 0;
}


