
#include<iostream>
#include"poligno.h"

/**
 * Poligno
 * Construtor padrão
 */
Poligno::Poligno(int id): ObjetoGrafico(id){}

void Poligno::desenha(void)
{
	cout << "Teste poligno" << endl;
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2d(-5, 5);
	glVertex2d(5, 5);
	glVertex2d(0, -5);
	glEnd();	
}
