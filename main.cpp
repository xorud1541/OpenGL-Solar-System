#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(255.0, 0.0, 0.0);
	glutSolidSphere(0.5, 100, 100);
	glEnd();
	glFlush();
}

void MyReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	GLfloat widthFactor = (GLfloat)width / 300;
	GLfloat heightFactor = (GLfloat)height / 300;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * widthFactor, 1.0 * widthFactor, -1.0 * heightFactor, 1.0 * heightFactor, -1.0, 1.0);
}

int main()
{
	glutInitWindowSize(900, 300);
	glutCreateWindow("OpenGL Solar System");
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}

