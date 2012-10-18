#include "mundo.h"

void Mundo::desenha()
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2d(-5, 5);
	glVertex2d(5, 5);
	glVertex2d(0, -5);
	glEnd();	
}

void Mundo::setOrtho(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void Mundo::getOrtho(int *x1, int *y1, int *x2, int *y2) 
{
	*x1 = this->x1;
	*y1 = this->y1;
	*x2 = this->x2;
	*y2 = this->y2;
}

void Mundo::setRGB(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void Mundo::getRGB(int *r, int *g, int *b) 
{
	*r = this->r;
	*g = this->g;
	*b = this->b;
}
