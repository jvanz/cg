
#include"objetografico.h"

ObjetoGrafico::ObjetoGrafico(int id)
{
	this->id = id;
}

int ObjetoGrafico::getId(void)
{
	return this->id;
}

vector<ObjetoGrafico*> ObjetoGrafico::getFilhos(void)
{
	return this->filhos;
}
