
#include"poligno.h"

Poligno::Poligno(int id): ObjetoGrafico(id)
{

	VART::Point4D * ponto = new VART::Point4D(10.0,10.0,0.0,1.0);
	this->ListaPontos.push_back(ponto);
	VART::Point4D * ponto2 = new VART::Point4D(10.0,20.0,0.0,1.0);
	this->ListaPontos.push_back(ponto2);
	VART::Point4D * ponto3 = new VART::Point4D(20.0,20.0,0.0,1.0);
	this->ListaPontos.push_back(ponto3);
	cout << "Pontos do poligno = " << this->ListaPontos.size() << endl;
}

void Poligno::desenha(void)
{
	cout << "Desenha poligno ID = " << this->getId() << endl;
	int index;
	glBegin(GL_POLYGON);
	for(index = 0; index < this->ListaPontos.size(); index++){
		VART::Point4D * ponto = this->ListaPontos[index];
		glVertex2f(ponto->GetX(),ponto->GetY());
	}
	glEnd();
	this->desenhaFilhos();
}
