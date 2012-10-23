#include"poligno.h"

Poligno::Poligno(int id): ObjetoGrafico(id)
{
	this->setSelecionado(0);
}

void Poligno::desenha(void)
{
	/*Desenha o ponto se o objeto estiver selecionado*/
	cout << "Desenhando " << this->getId() << ". Pontos = " << this->ListaPontos.size() << endl;
	int index;
	if(this->isSelecionado()){
		glColor3f(1.0, 0.0, 0.0);
		for(index = 0; index < this->ListaPontos.size(); index++){
			glBegin(GL_POINTS);
			VART::Point4D * ponto = this->ListaPontos[index];
			glVertex2f(ponto->GetX(),ponto->GetY());
			glEnd();
		}
	}
	/*Desenha o poligno*/
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		for(index = 0; index < this->ListaPontos.size(); index++){
			VART::Point4D * ponto = this->ListaPontos[index];
			glVertex2f(ponto->GetX(),ponto->GetY());
			cout << ponto->GetX() << " - " << ponto->GetY() << endl;
		}
	glEnd();
	this->desenhaFilhos();
}
