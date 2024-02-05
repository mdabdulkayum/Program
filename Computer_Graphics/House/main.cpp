#include<windows.h>
#include <GL/glut.h>


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window colour to black

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 700.0, -50.0, 500.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

	//Adjust the point size
	glPointSize(10.0);

    glBegin(GL_QUADS);
    glColor3f(0.91, 0.886, 0.855);
		glVertex2i(280, 0);
		glVertex2i(280, 240);
		glVertex2i(600, 240);
		glVertex2i(600, 0);

	glColor3f(0.851, 0.498, 0.42);
		glVertex2i(280, 240);
		glVertex2i(240, 340);
		glVertex2i(600, 340);
		glVertex2i(640, 240);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
        glVertex2i(280, 0);
		glVertex2i(280, 240);
		glVertex2i(600, 240);
		glVertex2i(600, 0);


    glEnd();
    glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
        glVertex2i(280, 240);
		glVertex2i(240, 340);
		glVertex2i(600, 340);
		glVertex2i(640, 240);


    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(0.749, 0.675, 0.588);
		glVertex2i(500, 360);
		glVertex2i(480, 360);
		glVertex2i(480, 380);
		glVertex2i(560, 380);
		glVertex2i(560, 360);
		glVertex2i(540, 360);
		glVertex2i(540, 340);
		glVertex2i(500, 340);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
        glVertex2i(500, 360);
		glVertex2i(480, 360);
		glVertex2i(480, 380);
		glVertex2i(560, 380);
		glVertex2i(560, 360);
		glVertex2i(540, 360);
		glVertex2i(540, 340);
		glVertex2i(500, 340);

    glEnd();


	// Draw a filled triangle

	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.886, 0.855);
		glVertex2i(60, 0);
		glVertex2i(60, 280);
		glVertex2i(180, 380);
		glVertex2i(300, 280);
		glVertex2i(300, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
        glVertex2i(60, 0);
		glVertex2i(60, 280);
		glVertex2i(180, 380);
		glVertex2i(300, 280);
		glVertex2i(300, 0);

    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.851, 0.498, 0.42);
		glVertex2i(180, 400);
		glVertex2i(20, 270);
		glVertex2i(40, 260);
		glVertex2i(180, 370);
		glVertex2i(320, 260);
		glVertex2i(340, 270);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
        glVertex2i(180, 400);
		glVertex2i(20, 270);
		glVertex2i(40, 260);
		glVertex2i(180, 370);
		glVertex2i(320, 260);
		glVertex2i(340, 270);

    glEnd();



	glBegin(GL_QUADS);
	//windo
    glColor3f(0.851, 0.498, 0.42);
		glVertex2i(120, 100);
		glVertex2i(180, 100);
		glVertex2i(180, 200);
		glVertex2i(120, 200);

		glVertex2i(480, 100);
		glVertex2i(520, 100);
		glVertex2i(520, 200);
		glVertex2i(480, 200);


	glColor3f(0.588, 0.78, 0.843);
		glVertex2i(180, 100);
		glVertex2i(240, 100);
		glVertex2i(240, 200);
		glVertex2i(180, 200);

		glVertex2i(520, 100);
		glVertex2i(560, 100);
		glVertex2i(560, 200);
		glVertex2i(520, 200);


    // Door
    glColor3f(0.588, 0.78, 0.843);
        glVertex2i(330, 10);
		glVertex2i(330, 140);
		glVertex2i(390, 140);
		glVertex2i(390, 10);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
        glVertex2i(330, 10);
		glVertex2i(330, 140);
		glVertex2i(390, 140);
		glVertex2i(390, 10);
    glEnd();

    glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
        glVertex2i(320, 0);
        glVertex2i(320, 10);
        glVertex2i(400, 10);
        glVertex2i(400, 0);



    glEnd();




glFlush();	// Process all OpenGL routines

}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);						// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

	glutInitWindowPosition(100, 100);				// Set window position
	glutInitWindowSize(600, 600);					// Set window size
	glutCreateWindow("An Example OpenGL Program");	// Create display window

	init();							// Execute initialisation procedure
	glutDisplayFunc(drawShapes);		// Send graphics to display window
	glutMainLoop();					// Display everything and wait

	return 0;
}
