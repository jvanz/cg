#include <list>
#include <vector>
#include <GL/glut.h>
#include "vart/point4d.h"
#include <list>

using namespace std;

class ObjetoGrafico
{
	private:
		int id;
		vector<ObjetoGrafico*> filhos;
		VART::Point4D* ponto;
		std::list<VART::Point4D*> ListaPontos;
	public:
		ObjetoGrafico(int);
		virtual void desenha(void)=0;
		int getId(void);
		int addObjGrafFilho(ObjetoGrafico*);
		int removeObjGrafFilho(int);
		vector<ObjetoGrafico*> getFilhos(void);
	protected:
		/* cores do objeto */
		int r, g, b;
};
