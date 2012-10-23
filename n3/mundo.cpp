#include "mundo.h"

/**
 * Mundo
 * Construtor padrão da classe Mundo
 */
Mundo::Mundo(int id): ObjetoGrafico(id)
{
	cout << "Instanciando mundo" << endl;
}

/**
 * desenha
 * Método para desenhar todos os objetos que estão na tela
 */
void Mundo::desenha()
{
	this->desenhaFilhos();	
}

/**
 * setOrtho
 * Setar todos os valores de Ortho
 */
void Mundo::setOrtho(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

/**
 * getOrtho
 * Retorna aos ponteiros os valores atuais do Ortho
 */
void Mundo::getOrtho(int *x1, int *y1, int *x2, int *y2) 
{
	*x1 = this->x1;
	*y1 = this->y1;
	*x2 = this->x2;
	*y2 = this->y2;
}

/**
 * setRGB
 * Seta cor de fundo da tela principal
 */
void Mundo::setRGB(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

/**
 * getRGB
 * Retorna aos ponteiros a cor atual da tela principal
 */
void Mundo::getRGB(int *r, int *g, int *b) 
{
	*r = this->r;
	*g = this->g;
	*b = this->b;
}
