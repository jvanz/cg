
#include<list>

using namespace std;

class ObjetoGrafico
{

	private:
		int id;
	public:
		ObjetoGrafico(int);
		virtual void desenha(void)=0;
		int addObjGrafFilho(ObjetoGrafico&);
		int removeObjGrafFilho(int);
		int getId(void);
	protected:
		/* cores do objeto */
		int r, g, b;
};
