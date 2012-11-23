/*Alunos: José Guilherme Vanz
 * 	  Marcos Paulo de Souza
 *Início do programa
 **/

/*
 *TODO - Verificar!
 * 1. Iremos movimentar a camera com o mouse ou teclado?
 *
 * */

#include <GL/glut.h>
#include <stdio>

/* Tamanho da tela */
#define X_MAX 500
#define Y_MAX 500

/* Código das teclas*/
#define CIMA 101
#define BAIXO 103
#define DIREITA 102
#define ESQUERDA 100
#define ESC 27

/**
 * teclado
 * Função responsável pelo processamento das tecla precionadas pelo usuário
 * */
void teclado(int tecla)
{
	switch(tecla){
		case CIMA:
			break;
		case BAIXO:
			break;
		case ESQUERDA:
			break;
		case DIREITA:
			break;
	}
	glutPostRedisplay();
}

GLMmodel* pmodel = NULL;
void desenha()
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(0, X_MAX, 0, Y_MAX );
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
       	pmodel = glmReadOBJ("objs/terra.obj");
        if (!pmodel) exit(0);
       	glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
	glutSwapBuffers();
}

void
drawaxes(void)
{
    glColor3ub(255, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.0, 0.0, 0.0);
	glutSwapBuffers();
}

void keyPressedSpecial(int tecla, GLint px, GLint py)
{
	teclado(tecla);
}

void keyPressed(unsigned char tecla, GLint x, GLint y)
{
	teclado(tecla);
}

void reshape (int w, int h)
{
	glutPostRedisplay();
}

void inicializacao (void)
{
	glClearColor(1.0f,1.0f,1.0f,1.0);
	glPointSize(5.0f);
}

int main (int argc, const char * argv[]) 
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (X_MAX, Y_MAX);
	(void)glutCreateWindow("Trabalho N4 - Jose Guilherme Vanz / Marcos Paulo de Souza");
	inicializacao();
 
	glutReshapeFunc(reshape);
	glutDisplayFunc(desenha);
 
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(keyPressedSpecial);
	glutMainLoop();
 
	return 0;
}


GLMmodel* glmReadOBJ(char* filename)
{
    GLMmodel* model;
    FILE* file;
    
    /* open the file */
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "glmReadOBJ() failed: can't open data file \"%s\".\n",
            filename);
        exit(1);
    }
    
    /* allocate a new model */
    model = (GLMmodel*)malloc(sizeof(GLMmodel));
    model->pathname    = strdup(filename);
    model->mtllibname    = NULL;
    model->numvertices   = 0;
    model->vertices    = NULL;
    model->numnormals    = 0;
    model->normals     = NULL;
    model->numtexcoords  = 0;
    model->texcoords       = NULL;
    model->numfacetnorms = 0;
    model->facetnorms    = NULL;
    model->numtriangles  = 0;
    model->triangles       = NULL;
    model->nummaterials  = 0;
    model->materials       = NULL;
    model->numgroups       = 0;
    model->groups      = NULL;
    model->position[0]   = 0.0;
    model->position[1]   = 0.0;
    model->position[2]   = 0.0;
    
    /* make a first pass through the file to get a count of the number
    of vertices, normals, texcoords & triangles */
    glmFirstPass(model, file);
    
    /* allocate memory */
    model->vertices = (GLfloat*)malloc(sizeof(GLfloat) *
        3 * (model->numvertices + 1));
    model->triangles = (GLMtriangle*)malloc(sizeof(GLMtriangle) *
        model->numtriangles);
    if (model->numnormals) {
        model->normals = (GLfloat*)malloc(sizeof(GLfloat) *
            3 * (model->numnormals + 1));
    }
    if (model->numtexcoords) {
        model->texcoords = (GLfloat*)malloc(sizeof(GLfloat) *
            2 * (model->numtexcoords + 1));
    }
    
    /* rewind to beginning of file and read in the data this pass */
    rewind(file);
    
    glmSecondPass(model, file);
    
    /* close the file */
    fclose(file);
    
    return model;
}
