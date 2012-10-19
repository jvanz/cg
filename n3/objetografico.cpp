
#include"objetografico.h"

ObjetoGrafico::ObjetoGrafico(int id)
{
	this->id = id;
}

int ObjetoGrafico::getId(void)
{
	return this->id;
}

int ObjetoGrafico::addObjGrafFilho(ObjetoGrafico* filho)
{
	this->filhos.push_back(filho);
	return this->filhos.size() - 1;
}

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
