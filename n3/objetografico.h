
#include<list>

using namespace std;

class ObjetoGrafico
{
	private:
		int id;
		list<ObjetoGrafico> *filhos;
	public:
		ObjetoGrafico(int);
		virtual void desenha(void)=0;
		int getId(void);
	protected:
		/* cores do objeto */
		int r, g, b;
		int addObjGrafFilho(ObjetoGrafico&);
		int removeObjGrafFilho(int);
};
