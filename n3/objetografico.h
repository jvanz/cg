#include <vector>
#include <GL/glut.h>
#include "vart/point4d.h"
#include "vart/transform.h"
#include <iostream>
#include "bbox.h"

using namespace std;

enum direcoes {CIMA,BAIXO,ESQUEDA,DIREITA};
typedef enum direcoes direcao;

class ObjetoGrafico
{
	private:
		int id;
		int selecionado;
		vector<ObjetoGrafico*> filhos;
		BBox * bBox;

		void initBBox(void);
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
		void addPonto(VART::Point4D *);
		void doTranslate(int,int);
		void doRotate(int,int);
		void doScale(int);
		int isSelecionado();
		void setSelecionado(int);
		void doDelete();
		void apagaPonto(int);
		void setTodosSelecionadosFalse();
		int selecionaObj(VART::Point4D *);
		BBox* getBBox(void);
	protected:
		vector<VART::Point4D*> ListaPontos;
		VART::Transform matrizObjeto;
		VART::Transform matrizTranslacao;
		VART::Transform matrizEscala;
		VART::Transform matrizRotacao;
		VART::Transform matrizTranslacaoInversa; 
		VART::Transform matrizGlobal;
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
