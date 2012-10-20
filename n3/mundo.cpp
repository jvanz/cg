#include "mundo.h"

/**
 * Mundo
 * Construtor padrão da classe Mundo
 */
Mundo::Mundo(int id): ObjetoGrafico(id)
{
	cout << "Instanciando mundo" << endl;
	Poligno * p = new Poligno(1);
	Poligno *p2 = new Poligno(2);
	VART::Point4D * ponto4 = new VART::Point4D(0,-10,0.0,1.0);
	p2->addPonto(ponto4);
	VART::Point4D * ponto5 = new VART::Point4D(10,0,0.0,1.0);
	p2->addPonto(ponto5);
	VART::Point4D * ponto6 = new VART::Point4D(-10,0,0.0,1.0);
	p2->addPonto(ponto6);
	p->addObjGrafFilho(p2);
	this->addObjGrafFilho(p);
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
