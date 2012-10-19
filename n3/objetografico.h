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
		/**
		 * desenha
		 * Método abstrato para desenhar todos os objetos filhos
		 */
		virtual void desenha(void)=0;
		int getId(void);
		int addObjGrafFilho(ObjetoGrafico*);
		int removeObjGrafFilho(int);
		vector<ObjetoGrafico*> getFilhos(void);
		void desenhaFilhos(void);
	protected:
		vector<VART::Point4D*> ListaPontos;
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
