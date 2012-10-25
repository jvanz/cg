#include "vart/point4d.h"
#include <GL/glut.h>

class BBox
{
	private:
		int minX;
		int maxX;
		int minY;
		int maxY;

	public:
		int getMinX(void);
		int getMaxX(void);
		int getMinY(void);
		int getMaxY(void);
		void setMinX(int);
		void setMaxX(int);
		void setMinY(int);
		void setMaxY(int);
		int pontoEstaDentro(VART::Point4D *);
		VART::Point4D* getCentroObj();
};
