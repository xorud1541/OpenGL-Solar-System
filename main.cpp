#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat delta = 0.0;
GLfloat cameraY = 0.0;
GLfloat cameraZ = 0.0;

void showEvent()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		0.0, cameraY, 7.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0
	);

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

void resizeEvent(int width, int height)
{
	glViewport(0, 0, width, height);
	GLfloat widthFactor = (GLfloat)width / 300;
	GLfloat heightFactor = (GLfloat)height / 300;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1.0 * widthFactor, 1.0 * widthFactor, -1.0 * heightFactor, 1.0 * heightFactor, 3.0f, 15.0f);
}

void timerEvent(int time)
{
	delta = delta + 1.0f;
	glutPostRedisplay();
	glutTimerFunc(10, timerEvent, 1);
}

void keyEvent(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a': //left
		break;
	case 'd': //right
		break;
	case 'w': // up
		cameraY += 0.1;
		break;
	case 's': // down
		cameraY -= 0.1;
		break;
	}

	glutPostRedisplay();
}

int main()
{
	glutInitWindowSize(1500, 700);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("OpenGL Solar System");
	glutDisplayFunc(showEvent);
	glutReshapeFunc(resizeEvent);
	glutKeyboardFunc(keyEvent);
	glutTimerFunc(10, timerEvent, 1);
	glutMainLoop();
	return 0;
}

