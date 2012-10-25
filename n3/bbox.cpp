#include "bbox.h"

BBox::BBox(void)
{
	this->minX = INT_MAX;
	this->maxX = INT_MIN;
	this->minY = INT_MAX;
	this->maxY = INT_MIN;
}

int BBox::getMinX(void)
{
	return this->minX;
}

int BBox::getMaxX(void)
{
	return this->maxX;
}

int BBox::getMinY(void)
{
	return this->minY;
}

int BBox::getMaxY(void)
{
	return this->maxY;
}

void BBox::setMinX(int x)
{
	this->minX = x;
}

void BBox::setMaxX(int x)
{
	this->maxX = x;
}

void BBox::setMinY(int y)
{
	this->minY = y;
}

void BBox::setMaxY(int y)
{
	this->maxY = y;
}

int BBox::pontoEstaDentro(VART::Point4D * ponto)
{
	if(((ponto->GetX() > this->minX) & (ponto->GetX() < this->maxX)) &
	   ((ponto->GetY() > this->minY) & (ponto->GetY() < this->maxY))){
		return 1;
	}
	return 0;
}


VART::Point4D* BBox::getCentroObj()
{
	float xCentral = this->minX + ((this->maxX - this->minX) / 2);
	float yCentral = this->minY + ((this->maxY - this->minY) / 2);
	VART::Point4D * pontoCentral = new VART::Point4D(xCentral,yCentral,0.0,0.0);
	return pontoCentral;
}
