#include <iostream>
#include"objetografico.h"

/**
 * objetoGrafico
 * Construtor padrão
 */
ObjetoGrafico::ObjetoGrafico(int id)
{
	this->id = id;
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
		this->getFilhos()[index]->desenha();
	}
}

void ObjetoGrafico::addPonto(VART::Point4D *p)
{
	this->ListaPontos.push_back(p);	
	this->initBBox();
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

void ObjetoGrafico::apagaPonto(int ponto)
{
	int qtdPontos = this->ListaPontos.size();
	if((this->isSelecionado()) & (ponto-1 < qtdPontos)){
		this->ListaPontos.erase(this->ListaPontos.begin()+(ponto-1));
	}else{
		unsigned int index;
		for(index = 0; index < this->getFilhos().size(); index++){
			this->getFilhos()[index]->apagaPonto(ponto);
		}
	}
	this->initBBox();

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
