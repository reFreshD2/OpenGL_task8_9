#include <GL/glut.h>
#include <math.h> 
#include <time.h>
#include <cstdlib>
#define PI 3.14159265

void Light()
{
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	float col[] = { 0.55,1,0.75,1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, col);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, col);
	glMaterialfv(GL_BACK, GL_SPECULAR, col);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_NORMALIZE);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glTranslatef(-0.2, -0.1, 0);
	glutSolidSphere(0.2, 50, 40);
	glTranslatef(0.85, 0.1, 0);
	glutSolidSphere(0.3, 50, 40);
	glPopMatrix();
	glFlush();
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		glRotated(5, 0, 0.1, 0); break;
	case GLUT_KEY_RIGHT:
		glRotated(-5, 0, 0.1, 0); break;
	case GLUT_KEY_UP:
		glScalef(1.1,1.1,1.1); break;
	case GLUT_KEY_DOWN:
		glScalef(0.9, 0.9, 0.9); break;
}
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Ex 8");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	Light();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}