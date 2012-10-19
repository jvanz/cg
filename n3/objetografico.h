#include <vector>
#include <GL/glut.h>
#include "vart/point4d.h"
#include<iostream>

using namespace std;

class ObjetoGrafico
{
	private:
		int id;
		vector<ObjetoGrafico*> filhos;
	public:
		ObjetoGrafico(int);
		virtual void desenha(void)=0;
		int getId(void);
		int addObjGrafFilho(ObjetoGrafico*);
		int removeObjGrafFilho(int);
		vector<ObjetoGrafico*> getFilhos(void);
		void desenhaFilhos(void);
	protected:
		/* cores do objeto */
		int r, g, b;
		vector<VART::Point4D*> ListaPontos;
};
