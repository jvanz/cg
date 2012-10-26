#include"poligno.h"

/**
 * Poligno::Poligno
 * Construtor padrão do objeto poligno
 */
Poligno::Poligno(int id): ObjetoGrafico(id)
{
	this->setSelecionado(0);
}

void Poligno::desenha(void)
{
	/*Desenha o ponto se o objeto estiver selecionado*/
	unsigned int index;
	if(this->isSelecionado()){
		glColor3f(1.0, 0.0, 0.0);
		for(index = 0; index < this->ListaPontos.size(); index++){
			glBegin(GL_POINTS);
			VART::Point4D * ponto = this->ListaPontos[index];
			glVertex2f(ponto->GetX(),ponto->GetY());
			glEnd();
		}
		glBegin(GL_LINE_LOOP);
		glVertex2f(this->getBBox()->getMinX(),this->getBBox()->getMinY());
		glVertex2f(this->getBBox()->getMaxX(),this->getBBox()->getMinY());
		glVertex2f(this->getBBox()->getMaxX(),this->getBBox()->getMaxY());
		glVertex2f(this->getBBox()->getMinX(),this->getBBox()->getMaxY());
		glEnd();
	}
	/*Desenha o poligno*/
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
		for(index = 0; index < this->ListaPontos.size(); index++){
			VART::Point4D * ponto = this->ListaPontos[index];
			glVertex2f(ponto->GetX(),ponto->GetY());
		}
	glEnd();
	
	this->desenhaFilhos();
}
