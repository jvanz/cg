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
		/**
		 * desenha
		 * Método abstrato para desenhar todos os objetos filhos
		 */
		virtual void desenha(void)=0;
		int getId(void);
		int addObjGrafFilho(ObjetoGrafico*);
		int removeObjGrafFilho(int);
		vector<ObjetoGrafico*> getFilhos(void);
	protected:
		/**
		 * R
		 * Nivel de vermelho do objeto
		 */
		int r, 
		/**
		 * G
		 * Nivel de verde do objeto
		 */
		    g,
		/**
		 * B
		 * Nível de azul do objeto
		 */
		    b;
};
