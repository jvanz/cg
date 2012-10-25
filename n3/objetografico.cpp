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
//	this->matrizObjeto.MakeIdentity();
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
	//TODO - Implementar
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
	/*FIXME - double free or corruption*/
	unsigned int index;
	for(index = 0; index < this->getFilhos().size(); index++){
		if(this->getFilhos()[index]->isSelecionado()){
			this->getFilhos().erase(this->getFilhos().begin());
			break;
		}
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

}

void ObjetoGrafico::setTodosSelecionadosFalse()
{
	this->setSelecionado(0);
	unsigned int index;
	for(index = 0; index < this->getFilhos().size(); index++){
		this->getFilhos()[index]->setTodosSelecionadosFalse();
	}
}
