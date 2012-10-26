#include <vector>
#include <GL/glut.h>
#include "vart/point4d.h"
#include "vart/transform.h"
#include <iostream>
#include "bbox.h"

using namespace std;

enum direcoes {CIMA,BAIXO,ESQUEDA,DIREITA};
typedef enum direcoes direcao;

/// Classe base para todas as outras classes do mundo
class ObjetoGrafico
{
	private:
		int id;
		int selecionado;
		vector<ObjetoGrafico*> filhos;
		BBox *bBox;

		void initBBox(void);
	public:
		ObjetoGrafico(int);
		~ObjetoGrafico(void);
		/**
		 * desenha
		 * Método abstrato para desenhar todos os objetos filhos
		 */
		virtual void desenha(void)=0;
		int getId(void);
		int addObjGrafFilho(ObjetoGrafico*);
		int removeObjGrafFilho(int);
		vector<ObjetoGrafico*> getFilhos(void);
		/// Desenha objetos filhos
		void desenhaFilhos(void);
		/// Adiciona um ponto ao poligno
		void addPonto(VART::Point4D *);
		/// Remove um ponto do poligno
		void removePonto(VART::Point4D *p);
		/// Translada o objeto selecionado
		void doTranslate(int,int);
		/// Rotaciona o objeto selecionado
		void doRotate(int,int);
		/// Escala o objeto selecionado
		void doScale(int);
		/// Retorna o status do objeto quanto a selecionado ou não
		int isSelecionado();
		/// Seleciona objeto indicado pelo parametro
		void setSelecionado(int);
		/// Excluir objeto filho
		void doDelete();
		/// Marca todos os objetos como não selecionados
		void setTodosSelecionadosFalse();
		/// Seleciona objeto conforme a posição do clique
		int selecionaObj(VART::Point4D *);
		/// Retorna BBox do objeto
		BBox* getBBox(void);
		/// Retornar um ponteiro para o objeto selecionado
		ObjetoGrafico* getObjSelecionado(void);
	protected:
		/// Lista de vertices do objetos
		vector<VART::Point4D*> ListaPontos;
		/// Matriz do objeto
		VART::Transform matrizObjeto;
		/// Matriz usada para transformacoes de translacao
		VART::Transform matrizTranslacao;
		/// Matriz usada para transformacoes de escala
		VART::Transform matrizEscala;
		/// Matriz usada para transformacoes de rotacao
		VART::Transform matrizRotacao;
		/// Matriz para transladar o objeto de volta ao ponto desejado
		VART::Transform matrizTranslacaoInversa; 
		/// Matriz global para transformacoes acumuladas
		VART::Transform matrizGlobal;
		/**
		 * R
		 * Nivel de vermelho do objeto
		 */
		float r, 
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
