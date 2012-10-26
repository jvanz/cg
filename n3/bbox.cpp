#include "bbox.h"

/// Construtor padrão
BBox::BBox(void)
{
	this->minX = INT_MAX;
	this->maxX = INT_MIN;
	this->minY = INT_MAX;
	this->maxY = INT_MIN;
}

/// Retorna X minimo
int BBox::getMinX(void)
{
	return this->minX;
}

/// Retorna X maximo
int BBox::getMaxX(void)
{
	return this->maxX;
}

/// Retorna Y minimo
int BBox::getMinY(void)
{
	return this->minY;
}

/// Retorna Y maximo
int BBox::getMaxY(void)
{
	return this->maxY;
}

/// Seta X minimo
void BBox::setMinX(int x)
{
	this->minX = x;
}

/// Seta X maximo
void BBox::setMaxX(int x)
{
	this->maxX = x;
}

/// Seta Y minimo
void BBox::setMinY(int y)
{
	this->minY = y;
}

/// Seta Y maximo
void BBox::setMaxY(int y)
{
	this->maxY = y;
}

/// Retorna true se o ponto selecionado está dentro do objeto
int BBox::pontoEstaDentro(VART::Point4D * ponto)
{
	if(((ponto->GetX() > this->minX) & (ponto->GetX() < this->maxX)) &
	   ((ponto->GetY() > this->minY) & (ponto->GetY() < this->maxY))){
		return 1;
	}
	return 0;
}

/// Retorna centro do objeto
VART::Point4D* BBox::getCentroObj()
{
	float xCentral = this->minX + ((this->maxX - this->minX) / 2);
	float yCentral = this->minY + ((this->maxY - this->minY) / 2);
	VART::Point4D * pontoCentral = new VART::Point4D(xCentral,yCentral,0.0,0.0);
	return pontoCentral;
}
