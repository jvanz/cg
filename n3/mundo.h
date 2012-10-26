/*
 * Marcos Paulo de Souza
 * José Guilherme Vanz
 *
 * Classe mundo -  responsável por abrigar os objetos
 */

#include "poligno.h"

/// Base para todos os objetos do mundo
class Mundo: public ObjetoGrafico
{
	private:
		/* valores ortho */
		int x1,
		    y1,
		    x2,
		    y2;
	public:
		Mundo(int id);
		void desenha(); /*Método de ObjetoGrafico*/
		void setOrtho(int,int,int,int);
		void getOrtho(int*,int*,int*,int*);
		void setRGB(int,int,int);
		void getRGB(int*,int*,int*);
};
