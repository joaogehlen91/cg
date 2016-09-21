// PrimeiroPrograma.c - Isabel H. Manssour
// Um programa OpenGL simples que abre uma janela GLUT
// Este código está baseado no Simple.c, exemplo 
// disponível no livro "OpenGL SuperBible", 
// 2nd Edition, de Richard S. e Wright Jr.
#include <GL/glut.h>
#include <GL/glu.h>


void esfera(GLdouble *centro, GLdouble radius, GLfloat num) {
	GLdouble c, c2, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
	GLdouble phi, theta, phi1, theta1, phi2, theta2;
	GLdouble senphi1, cosphi1, senphi2, cosphi2,
	         sentheta1, costheta1, sentheta2, costheta2,
	         passo;

	glVertex3d(centro[0], centro[1] + radius, centro[2]);

//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	c = pi / 180;
	passo = 180 / num * c;
	glBegin(GL_TRIANGLES);
	phi1 = 0;
	senphi1 = sin(phi1);
	cosphi1 = cos(phi1);
	int i,j;
	for (i=0; i < num; i++) {
		phi2 = phi1 + passo;
		senphi2 = sin(phi2);
		cosphi2 = cos(phi2);
		theta1 = 0;
		sentheta1 = sin(theta1);
		costheta1 = cos(theta1);
		for (j=0; j < 2 * num; j++) {
			theta2 = theta1 + passo;
			sentheta2 = sin(theta2);
			costheta2 = cos(theta2);
			x1 = centro[0] + radius * senphi1 * costheta1;
			y1 = centro[1] + radius * senphi1 * sentheta1;
			z1 = centro[2] + radius * cosphi1;
			glVertex3d(x1, y1, z1);
			x2 = centro[0] + radius * senphi2 * costheta1;
			y2 = centro[1] + radius * senphi2 * sentheta1;
			z2 = centro[2] + radius * cosphi2;
			glVertex3d(x2, y2, z2);
			x3 = centro[0] + radius * senphi2 * costheta2;
			y3 = centro[1] + radius * senphi2 * sentheta2;
			z3 = centro[2] + radius * cosphi2;
			glVertex3d(x3, y3, z3);
			glVertex3d(x1, y1, z1);
			glVertex3d(x3, y3, z3);
			x4 = centro[0] + radius * senphi1 * costheta2;
			y4 = centro[1] + radius * senphi1 * sentheta2;
			z4 = centro[2] + radius * cosphi1;
			glVertex3d(x4, y4, z4);
			theta1 = theta2;
			sentheta1 = sentheta2;
			costheta1 = costheta2;
		}
		phi1 = phi2;
		senphi1 = senphi2;
		cosphi1 = cosphi2;
	}
	glEnd();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	//Limpa a janela de visualização com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	esfera():
	//Executa os comandos OpenGL 
	glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
}

// Programa Principal 
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Trabalho 1");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}