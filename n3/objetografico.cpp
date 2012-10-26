#include <iostream>
#include"objetografico.h"

/**
 * objetoGrafico
 * Construtor padrão
 */
ObjetoGrafico::ObjetoGrafico(int id)
{
	this->id = id;
	srand(time(NULL));
	float random = ((float) rand()) / (float) RAND_MAX;	
	r = (random* (0.9 - 0.1)) + 0.1;
	random = ((float) rand()) / (float) RAND_MAX;	
	g = (random* (0.9 - 0.1)) + 0.1;
	random = ((float) rand()) / (float) RAND_MAX;	
	b = (random* (0.9 - 0.1)) + 0.1;
}

ObjetoGrafico::~ObjetoGrafico(void)
{
}

/**
 * getID
 * Retorna ID relacionado ao objeto
 */
int ObjetoGrafico::getId(void)
{
	return this->id;
}

/**
 * addObjGrafFilho
 * Adiciona Objeto Grafico aos Objetos filhos do objeto corrente
 */
int ObjetoGrafico::addObjGrafFilho(ObjetoGrafico* filho)
{
	this->filhos.push_back(filho);
	cout << "Adicionando filho no obj ID = " << this->getId() << ". Total filhos = " << this->filhos.size() << endl;
	return this->filhos.size() - 1;
}

/**
 * removeObjGrafFilho
 * Remove um objeto da lista de objetos filhos
 */
int ObjetoGrafico::removeObjGrafFilho(int id)
{
	return 0;
}

/**
 * getFilhos
 * Retorna lista com todos os objetos filhos do objeto corrente
 */
vector<ObjetoGrafico*> ObjetoGrafico::getFilhos(void)
{
	return this->filhos;
}

void ObjetoGrafico::desenhaFilhos(void)
{
	unsigned int index;
	for(index = 0; index < this->getFilhos().size(); index++){
		if (this->getFilhos()[index]->ListaPontos.size() > 2)
			this->getFilhos()[index]->desenha();
	}
}

void ObjetoGrafico::addPonto(VART::Point4D *p)
{
	this->ListaPontos.push_back(p);	
	this->initBBox();
}

void ObjetoGrafico::removePonto(VART::Point4D *p)
{
	vector<VART::Point4D*>::iterator it;
	it = this->ListaPontos.begin();

	for (;it < this->ListaPontos.end(); it++)
		if (((*it)->GetX() <= p->GetX() + 5 && (*it)->GetY() <= p->GetY() + 5) &&
		    ((*it)->GetX() >= p->GetX() - 5 && (*it)->GetY() >= p->GetY() - 5))
			this->ListaPontos.erase(it);

	for (unsigned int i = 0; i < this->getFilhos().size(); i++)
		this->getFilhos()[i]->removePonto(p);

	/* se temos apenas dis vertices, nao temos mais 
	   um poligno, entao podemos apagar os vertices */
	if (this->ListaPontos.size() == 2)
		this->ListaPontos.clear();
}

void ObjetoGrafico::doTranslate(int dir, int valor)
{
	cout << "Translate ";
	if(dir == 1){
		cout << "CIMA" << endl;
		
	}
	//TODO - Implementar
}

void ObjetoGrafico::doRotate(int dir, int valor)
{
	VART::Point4D p = *this->getBBox()->getCentroObj();

	this->matrizRotacao.MakeZRotation(5);
	this->matrizTranslacaoInversa.MakeTranslation(p);

	p = -p;
	this->matrizObjeto = this->matrizObjeto * (this->matrizTranslacaoInversa * (matrizEscala * matrizTranslacao));
}

void ObjetoGrafico::doScale(int valor)
{
	//TODO - Implmentar
}

void ObjetoGrafico::setSelecionado(int selecionado)
{
	this->selecionado = selecionado;
}

int ObjetoGrafico::isSelecionado(void)
{
	return this->selecionado;
}

void ObjetoGrafico::doDelete(void)
{
	unsigned int index;	
	vector<ObjetoGrafico*> novosFilhos; /*O desespero faz coisa :( */
	for(index = 0; index < this->getFilhos().size(); index++){
		if(!this->getFilhos()[index]->isSelecionado()){
			novosFilhos.push_back(this->getFilhos()[index]);	
		}
	}
	this->filhos = novosFilhos;

	for(index = 0; index < this->getFilhos().size(); index++){
		this->getFilhos()[index]->doDelete();
	}
}

void ObjetoGrafico::setTodosSelecionadosFalse()
{
	this->setSelecionado(0);
	unsigned int index;
	for(index = 0; index < this->getFilhos().size(); index++){
		this->getFilhos()[index]->setTodosSelecionadosFalse();
	}
}

void ObjetoGrafico::initBBox(void)
{
	unsigned int index;	
	bBox = new BBox();
	for(index = 0; index < this->ListaPontos.size(); index++){
		if(this->ListaPontos[index]->GetX() > this->getBBox()->getMaxX()){
			this->getBBox()->setMaxX(this->ListaPontos[index]->GetX());
		}
		if(this->ListaPontos[index]->GetX() < this->getBBox()->getMinX()){
			this->getBBox()->setMinX(this->ListaPontos[index]->GetX());
		}
		if(this->ListaPontos[index]->GetY() > this->getBBox()->getMaxY()){
			this->getBBox()->setMaxY(this->ListaPontos[index]->GetY());
		}
		if(this->ListaPontos[index]->GetY() < this->getBBox()->getMinY()){
			this->getBBox()->setMinY(this->ListaPontos[index]->GetY());
		}
	}
}
BBox* ObjetoGrafico::getBBox(void)
{
	return this->bBox;
}

int ObjetoGrafico::selecionaObj(VART::Point4D * ponto)
{
	unsigned int index;

	for(index = 0; index < this->getFilhos().size(); index++){
		if(this->getFilhos()[index]->selecionaObj(ponto)){
			return 1;
		}
	}

	/* se for o mundo, não faz nada */
	if (!this->getId())
		return 0;

	if(this->getBBox()->pontoEstaDentro(ponto)){
		this->setSelecionado(1);
		return 1;
	}

	return 0;
}

ObjetoGrafico* ObjetoGrafico::getObjSelecionado(void)
{
	if(this->isSelecionado())
		return this;

	ObjetoGrafico * obj;
	unsigned int index;
	for(index = 0; index < this->getFilhos().size(); index++){
		obj = this->getFilhos()[index]->getObjSelecionado();
		if(obj)
			return obj;
	}
	return NULL;
}
