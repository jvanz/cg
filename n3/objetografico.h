#include <list>
#include <vector>
#include <GL/glut.h>

using namespace std;

class ObjetoGrafico
{
	private:
		int id;
		vector<ObjetoGrafico> filhos;
		/* cores do objeto */
		int r, g, b;
	public:
		ObjetoGrafico(int);
		virtual void desenha(void)=0;
		int getId(void);
		int addObjGrafFilho(ObjetoGrafico&);
		int removeObjGrafFilho(int);
};
