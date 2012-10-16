/*
 * Marcos Paulo de Souza
 * José Guilherme Vanz
 *
 * Classe mundo -  responsável por abrigar os objetos
 */

class mundo {
	private:
		/* valores ortho */
		int x1,
		    y1,
		    x2,
		    y2;

		/* cor de fundo */
		int r,
		    g,
		    b;
	public:
		void ListaObjetosAdd();
		void ListaObjetosRemove();
		
		/* funções inline */
		void setOrtho(int x1, int y1, int x2, int y2) {
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
		}

		void setRGB(int r, int g, int b) {
			this->r = r;
			this->g = g;
			this->b = b;
		};
}
