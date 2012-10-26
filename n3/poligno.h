
#include"objetografico.h"

/// Base para todo objeto desenhado no mundo
class Poligno : public ObjetoGrafico
{
	public:
		Poligno(int);
		void desenha(void);
};
