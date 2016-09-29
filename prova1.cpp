// Joao Miguel Gehlen da Silva
// Computacao Grafica - 2016-2

#include <GL/glut.h>
#include <math.h>

GLfloat v[8][3] = { 
	{-1, -1, -1}, 
	{ 1, -1, -1}, 
	{ 1,  1, -1}, 
	{-1,  1, -1},
	{ 1, -1,  1}, 
	{-1, -1  ,1}, 
	{-1,  1,  1}, 
	{ 1,  1,  1}
};

GLfloat alpha = 0.0;

GLfloat camera = -20.0;
bool zoomIn = true;
bool zoomOut = false;
bool aumenta = true;
bool diminui = false;

void cubo() {
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(v[0]); //frente
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);

	glColor3f(0.0f, 01.0f, 0.0f);
	glVertex3fv(v[4]); // fundos
	glVertex3fv(v[5]);
	glVertex3fv(v[6]);
	glVertex3fv(v[7]);

	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3fv(v[0]); // esq
	glVertex3fv(v[3]);
	glVertex3fv(v[6]);
	glVertex3fv(v[5]);

	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3fv(v[3]); // topo
	glVertex3fv(v[2]);
	glVertex3fv(v[7]);
	glVertex3fv(v[6]);

	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3fv(v[1]); // dir
	glVertex3fv(v[4]);
	glVertex3fv(v[7]);
	glVertex3fv(v[2]);

	glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3fv(v[1]); // base
	glVertex3fv(v[0]);
	glVertex3fv(v[5]);
	glVertex3fv(v[4]);

	glEnd();
}

void alteraTamanhoCubo(){
	if(aumenta){
		for(int i = 0; i <= 7; i++){
			for(int j = 0; j <= 2; j++){
				if (v[i][j] < 0){
					v[i][j] = v[i][j] - 0.1;
				}else{
					v[i][j] = v[i][j] + 0.1;
				}
			}
		}
	}
	if(diminui){
		for(int i = 0; i <= 7; i++){
			for(int j = 0; j <= 2; j++){
				if (v[i][j] < 0){
					v[i][j] = v[i][j] + 0.1;
				}else{
					v[i][j] = v[i][j] - 0.1;
				}
			}
		}
	}
	if(v[0][0] <= -3){
		diminui = true;	
		aumenta = false;
	}
	if(v[0][0] >= -1){
		aumenta = true;
		diminui = false;	
	} 
}

void mudaCamera(){
	if(zoomIn) camera += 0.2;
	if(zoomOut) camera -= 0.2;

	if(camera <= -50.0){
		zoomIn = true;
		zoomOut = false;	
	} 
	if(camera >= -20.0){
		zoomOut = true;
		zoomIn = false;
	}
}

void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glRotatef(90, 0.0, 0.0, -1.0);
	gluLookAt(0.0, 5.0, camera, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidSphere(2.0, 100, 100);
 
	glRotatef(alpha+=0.5, 0.0, 0.0, -1.0);
	
	glRotatef(alpha+=0.5, 1.0, 0.0, 0.0);

	glTranslatef(7.0, 0.0, 0.0);

	cubo();
	
    glutSwapBuffers();
	glFinish();
}


void Redesenha(void)
{
	mudaCamera();
	alteraTamanhoCubo();

	glutPostRedisplay();
}

void Inicializa(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, w/h, 2, 100);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 350);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("CG/P1 - Joao Miguel");
	glutIdleFunc(Redesenha);
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	Inicializa();
	glutMainLoop();
}
