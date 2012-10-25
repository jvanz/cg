#include "vart/point4d.h"
#include <GL/glut.h>

class BBox
{
	private:
		GLfloat minX;
		GLfloat maxX;
		GLfloat minY;
		GLfloat maxY;

	public:
		GLfloat getMinX(void);
		GLfloat getMaxX(void);
		GLfloat getMinY(void);
		GLfloat getMaxY(void);
		void setMinX(GLfloat);
		void setMaxX(GLfloat);
		void setMinY(GLfloat);
		void setMaxY(GLfloat);
		int pontoEstaDentro(VART::Point4D *);
		VART::Point4D* getCentroObj();
};
