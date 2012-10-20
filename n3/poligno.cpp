#include"poligno.h"

Poligno::Poligno(int id): ObjetoGrafico(id)
{
	VART::Point4D * ponto = new VART::Point4D(0,10,0.0,1.0);
	this->ListaPontos.push_back(ponto);
	VART::Point4D * ponto2 = new VART::Point4D(10,0,0.0,1.0);
	this->ListaPontos.push_back(ponto2);
	VART::Point4D * ponto3 = new VART::Point4D(-10,0,0.0,1.0);
	this->ListaPontos.push_back(ponto3);
}

void Poligno::desenha(void)
{
	int index;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		for(index = 0; index < this->ListaPontos.size(); index++){
			VART::Point4D * ponto = this->ListaPontos[index];
			glVertex2f(ponto->GetX(),ponto->GetY());
		}
	glEnd();
	this->desenhaFilhos();
}
