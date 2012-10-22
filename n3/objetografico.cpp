
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
	int index;
	for(index = 0; index < this->getFilhos().size(); index++){
		this->getFilhos()[index]->desenha();
	}
}

void ObjetoGrafico::addPonto(VART::Point4D *p)
{
	this->ListaPontos.push_back(p);
}

void ObjetoGrafico::doTranslate(direcao dir, int valor)
{
	//TODO - Implementar
}

void ObjetoGrafico::doRotate(direcao dir, int valor)
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
