
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
