#include<windows.h>
#include <GL/glut.h>


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Set display window colour to black

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

	//Adjust the point size
	glPointSize(10.0);

	// Draw four stars
	glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
        glVertex2i(140, -60);
        glVertex2i(0, 0);
        glVertex2i(140, 60);
        glVertex2i(200, 200);
        glVertex2i(260, 60);
        glVertex2i(400, 0);
        glVertex2i(260, -60);
        glVertex2i(200, -200);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
        glVertex2i(-260, -60);
        glVertex2i(-400, 0);
        glVertex2i(-260, 60);
        glVertex2i(-200, 200);
        glVertex2i(-140, 60);
        glVertex2i(0, 0);
        glVertex2i(-140, -60);
        glVertex2i(-200, -200);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
        glVertex2i(-60, 140);
        glVertex2i(-200, 200);
        glVertex2i(-60, 260);
        glVertex2i(0, 400);
        glVertex2i(60, 260);
        glVertex2i(200, 200);
        glVertex2i(60, 140);
        glVertex2i(0, 0);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
        glVertex2i(-60, -140);
        glVertex2i(0, 0);
        glVertex2i(60, -140);
        glVertex2i(200, -200);
        glVertex2i(60, -260);
        glVertex2i(0, -400);
        glVertex2i(-60, -260);
        glVertex2i(-200, -200);
	glEnd();


glFlush();	// Process all OpenGL routines

}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);						// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

	glutInitWindowPosition(100, 100);				// Set window position
	glutInitWindowSize(400, 400);					// Set window size
	glutCreateWindow("Draw four stars");	// Create display window

	init();							// Execute initialisation procedure
	glutDisplayFunc(drawShapes);		// Send graphics to display window
	glutMainLoop();					// Display everything and wait

	return 0;
}
