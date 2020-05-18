#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat delta = 0.0;
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(255.0, 0.0, 0.0);
	glutSolidSphere(0.5, 100, 100);

	glPushMatrix();

	glRotatef((GLfloat)delta, 0.0, 1.0f, 0.0);
	glTranslatef(-3.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 255.0);
	glutSolidSphere(0.25, 100, 100);

	glRotatef((GLfloat)delta, 0.0, 1.0f, 0.0);
	glTranslatef(-0.5, 0.0, 0.0);
	glColor3f(128.0, 128.0, 128.0);
	glutSolidSphere(0.05, 100, 100);

	glPopMatrix();
	glutSwapBuffers();

	glFlush();
}

void MyReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	GLfloat widthFactor = (GLfloat)width / 300;
	GLfloat heightFactor = (GLfloat)height / 300;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * widthFactor, 1.0 * widthFactor, -1.0 * heightFactor, 1.0 * heightFactor, -10.0, 10.0);
}

void MyTimer(int time)
{
	delta = delta + 1.0f;
	glutPostRedisplay();
	glutTimerFunc(10, MyTimer, 1);
}

int main()
{
	glutInitWindowSize(1500, 700);
	glutCreateWindow("OpenGL Solar System");
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutTimerFunc(100, MyTimer, 1);
	glutMainLoop();
	return 0;
}

