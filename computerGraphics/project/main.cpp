#include<windows.h>
#include <GL/glut.h>
#include <math.h>


float shift = 0;
float boithaPos = 0;
float bx = 0;

void init(void)
{
	glClearColor(0.878, 0.949, 0.988, 0.0);	// Set display window colour to black

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}


void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

	//Set colour to black
	glColor3f(0.0, 0.0, 0.0);
	//Adjust the point size
	glPointSize(10.0);

	// Draw a couple of points

	//Set colour to blue


	glBegin(GL_QUADS);    // river
	glColor3f(0.161, 0.761, 0.941);
        glVertex2i(380, 0);
        glVertex2i(380, 600);
        glVertex2i(1450, 600);
        glVertex2i(1400, 0);
	glEnd();



	glBegin(GL_POLYGON);        // top feild
	    glColor3f(0.945, 0.796, 0.471);
	    glVertex2i(300, 360);
	    glVertex2i(500, 460);
	    glVertex2i(0, 500);
	    glVertex2i(0, 440);

	glEnd();




	// Draw a filled Road
	glBegin(GL_POLYGON);
	glColor3f(0.929, 0.929, 0.925);
        glVertex2i(300, 360);
        glVertex2i(120, 460);
        glVertex2i(0, 440);
        glVertex2i(0, 360);

        glVertex2i(140, 340);
        glVertex2i(220, 300);
        glVertex2i(200, 200);
        glVertex2i(240, 240);
        glVertex2i(200, 100);
        glVertex2i(240, 140);
		glVertex2i(200, 0);

		glVertex2i(400, 0);
		glVertex2i(390, 200);
		glVertex2i(450, 270);
		glVertex2i(500, 320);
		glVertex2i(500, 460);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.898, 0.631, 0.427);
        glVertex2i(500, 460);
        glVertex2i(600, 460);
        glVertex2i(600, 340);
        glVertex2i(500, 320);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.898, 0.631, 0.427);

        glVertex2i(600, 460);
        glVertex2i(1370, 360);
        glVertex2i(1300, 240);
        glVertex2i(600, 340);


	glEnd();

	circle(150, 50, 750, 410);      //road feild curve
	circle(200, 50, 1100, 300);

	glColor3f(0.161, 0.761, 0.941);
	circle(150, 50, 750, 290);
	circle(200, 50, 1100, 430);




	// feild

	glBegin(GL_POLYGON);  // left feild
	glColor3f(0.682, 1, 0.655);
        glVertex2i(0, 0);
        glVertex2i(0, 360);
        glVertex2i(140, 340);
        glVertex2i(220, 300);
        glVertex2i(200, 200);
        glVertex2i(240, 240);
        glVertex2i(200, 100);
        glVertex2i(240, 140);
		glVertex2i(200, 0);
	glEnd();


	glBegin(GL_POLYGON);        // right feild
	glColor3f(0.682, 1, 0.655);
        glVertex2i(390, 200);
        glVertex2i(450, 270);
        glVertex2i(500, 320);
        glVertex2i(540, 300);
        glVertex2i(520, 240);
        glVertex2i(450, 200);
        glVertex2i(480, 160);
        glVertex2i(440, 100);
        glVertex2i(470, 80);
        glVertex2i(400, 0);


	glEnd();

	glBegin(GL_POLYGON);           //home feild
	glColor3f(0.682, 1, 0.655);
        glVertex2i(1920, 0);
        glVertex2i(1400, 0);
        glVertex2i(1320, 100);
        glVertex2i(1300, 200);
        glVertex2i(1300, 260);
        glVertex2i(1350, 340);
        glVertex2i(1380, 380);
        glVertex2i(1340, 460);
        glVertex2i(1360, 560);
        glVertex2i(1460, 600);
        glVertex2i(1700, 640);
        glVertex2i(1920, 650);

	glEnd();


	glBegin(GL_POLYGON);           // hill
	glColor3f(0.416, 0.839, 0.376);
        glVertex2i(500, 460+10);
        glVertex2i(0, 500+10);
        glVertex2i(0, 600+10);
        glVertex2i(40, 615+10);
        glVertex2i(60, 625+10);
        glVertex2i(80, 620+10);
        glVertex2i(100, 600+10);
        glVertex2i(140, 620+10);
        glVertex2i(180, 630+10);
        glVertex2i(360, 700+10);
        glVertex2i(440, 690+10);
        glVertex2i(600, 800+10);
        glVertex2i(700, 780+10);
        glVertex2i(860, 700+10);
        glVertex2i(1000, 820+10);
        glVertex2i(1200, 700+10);
        glVertex2i(1340, 760+10);
        glVertex2i(1440, 700+10);
        glVertex2i(1500, 600+10);
        glVertex2i(1100, 570+10);
        glVertex2i(800, 540+10);


	glEnd();



	glBegin(GL_POLYGON);           // hill
	glColor3f(0.533, 0.949, 0.498);
        glVertex2i(500, 460);
        glVertex2i(0, 500);
        glVertex2i(0, 600);
        glVertex2i(40, 615);
        glVertex2i(60, 625);
        glVertex2i(80, 620);
        glVertex2i(100, 600);
        glVertex2i(140, 620);
        glVertex2i(180, 630);
        glVertex2i(360, 700);
        glVertex2i(440, 690);
        glVertex2i(600, 800);
        glVertex2i(700, 780);
        glVertex2i(860, 700);
        glVertex2i(1000, 820);
        glVertex2i(1200, 700);
        glVertex2i(1340, 760);
        glVertex2i(1440, 700);
        glVertex2i(1500, 600);
        glVertex2i(1100, 570);
        glVertex2i(800, 540);

	glEnd();






    glColor3f(0.682, 1, 0.655);
	circle(210, 190, 1500, 200);  // home feild curve
	circle(240, 160, 1570, 500);

	glColor3f(0.161, 0.761, 0.941); // river feild curve
	circle(50,50, 500, 115);

	glBegin(GL_QUADS);           // Tree B House Right
	glColor3f(0.49, 0.29, 0);
        glVertex2i(1800, 645);
        glVertex2i(1840, 645);
        glVertex2i(1840, 800);
        glVertex2i(1800, 800);
	glEnd();
	glBegin(GL_POLYGON);           // Tree B House leaf Right
	glColor3f(0.212, 0.941, 0.027);
        glVertex2i(1820, 860);
        glVertex2i(1750, 760);
        glVertex2i(1800, 800);
        glVertex2i(1760, 720);
        glVertex2i(1800, 740);
        glVertex2i(1840, 740);
        glVertex2i(1880, 720);
        glVertex2i(1840, 800);
        glVertex2i(1890, 760);
	glEnd();
	glBegin(GL_POLYGON);           // Tree B House leaf Right
	glColor3f(0.212, 0.941, 0.027);
        glVertex2i(1820, 850);
        glVertex2i(1750, 750);
        glVertex2i(1800, 790);
        glVertex2i(1760, 710);
        glVertex2i(1800, 730);
        glVertex2i(1840, 730);
        glVertex2i(1880, 710);
        glVertex2i(1840, 790);
        glVertex2i(1890, 750);
	glEnd();


	glBegin(GL_QUADS);           // Tree B House  middle
	glColor3f(0.49, 0.29, 0);
        glVertex2i(1700, 645);
        glVertex2i(1730, 645);
        glVertex2i(1730, 750);
        glVertex2i(1700, 750);
	glEnd();
	glBegin(GL_POLYGON);           // Tree B House leaf middle
	glColor3f(0.192, 1, 0);
        glVertex2i(1720, 830);
        glVertex2i(1670, 730);
        glVertex2i(1700, 750);
        glVertex2i(1680, 690);
        glVertex2i(1700, 710);
        glVertex2i(1730, 710);
        glVertex2i(1750, 690);
        glVertex2i(1740, 750);
        glVertex2i(1770, 730);
	glEnd();

	glBegin(GL_QUADS);           // Tree B House  middle
	glColor3f(0.49, 0.29, 0);
        glVertex2i(1640, 645);
        glVertex2i(1670, 645);
        glVertex2i(1670, 750);
        glVertex2i(1640, 750);
	glEnd();
	glBegin(GL_POLYGON);           // Tree B House leaf middle
	glColor3f(0.192, 1, 0);
        glVertex2i(1660, 830);
        glVertex2i(1610, 730);
        glVertex2i(1640, 750);
        glVertex2i(1620, 690);
        glVertex2i(1640, 710);
        glVertex2i(1670, 710);
        glVertex2i(1690, 690);
        glVertex2i(1680, 750);
        glVertex2i(1710, 730);
	glEnd();

	glBegin(GL_QUADS);           // Tree B House Left
	glColor3f(0.49, 0.29, 0);
        glVertex2i(1800-240, 645);
        glVertex2i(1840-240, 645);
        glVertex2i(1840-240, 800);
        glVertex2i(1800-240, 800);
	glEnd();
	glBegin(GL_POLYGON);           // Tree B House leaf Left
	glColor3f(0.212, 0.941, 0.027);
        glVertex2i(1820-240, 860);
        glVertex2i(1750-240, 760);
        glVertex2i(1800-240, 800);
        glVertex2i(1760-240, 720);
        glVertex2i(1800-240, 740);
        glVertex2i(1840-240, 740);
        glVertex2i(1880-240, 720);
        glVertex2i(1840-240, 800);
        glVertex2i(1890-240, 760);
	glEnd();
	glBegin(GL_POLYGON);           // Tree B House leaf Left
	glColor3f(0.212, 0.941, 0.027);
        glVertex2i(1820-240, 850);
        glVertex2i(1750-240, 750);
        glVertex2i(1800-240, 790);
        glVertex2i(1760-240, 710);
        glVertex2i(1800-240, 730);
        glVertex2i(1840-240, 730);
        glVertex2i(1880-240, 710);
        glVertex2i(1840-240, 790);
        glVertex2i(1890-240, 750);
	glEnd();




	glBegin(GL_POLYGON);           // tree 1
	glColor3f(0.49, 0.29, 0);
        glVertex2i(100, 420);
        glVertex2i(60, 420);
        glVertex2i(80, 440);
        glVertex2i(80, 820);
        glVertex2i(100, 810);
        glVertex2i(100, 720);
        glVertex2i(120, 700);
        glVertex2i(140, 680);
        glVertex2i(140, 440);
        glVertex2i(160, 420);
	glEnd();
	glBegin(GL_QUADS);           // tree 1
	glColor3f(0.49, 0.29, 0);
        glVertex2i(140, 680);
        glVertex2i(120, 700);
        glVertex2i(200, 780);
        glVertex2i(200, 760);
	glEnd();

	glColor3f(0.192, 1, 0);   // tree 1 leaf
	circle(70, 50, 100, 800);
	circle(70, 50, 130, 840);
	circle(70, 50, 150, 820);
	circle(70, 50, 190, 780);


	glBegin(GL_POLYGON);           // tree 2
	glColor3f(0.49, 0.29, 0);
        glVertex2i(100+300, 420-30);
        glVertex2i(60+300, 420-30);
        glVertex2i(80+300, 440-30);
        glVertex2i(80+300, 820-30);
        glVertex2i(100+300, 810-30);
        glVertex2i(100+300, 720-30);
        glVertex2i(120+300, 700-30);
        glVertex2i(140+300, 680-30);
        glVertex2i(140+300, 440-30);
        glVertex2i(160+300, 420-30);
	glEnd();
	glBegin(GL_QUADS);           // tree 2
	glColor3f(0.49, 0.29, 0);
        glVertex2i(140+300, 680-30);
        glVertex2i(120+300, 700-30);
        glVertex2i(200+300, 780-30);
        glVertex2i(200+300, 760-30);
	glEnd();

	glColor3f(0.192, 1, 0);   // tree 2 leaf
	circle(70, 50, 100+300, 800-30);
	circle(70, 50, 130+300, 840-30);
	circle(70, 50, 150+300, 820-30);
	circle(70, 50, 190+300, 780-30);


	/*
	glBegin(GL_POLYGON);           // tree 1
	glColor3f(0.404, 0.812, 0);
        glVertex2i(80-10, 810);
        glVertex2i(80-10, 760);
        glVertex2i(40-10, 800);
        glVertex2i(50-10, 820);
        glVertex2i(40-10, 850);
        glVertex2i(55-10, 880);
        glVertex2i(80-10, 900);
        glVertex2i(120-10, 920);
        glVertex2i(160-10, 900);
        glVertex2i(180-10, 880);
        glVertex2i(190-10, 860);
        glVertex2i(180-10, 830);
        glVertex2i(160-10, 810);
        glVertex2i(120-10, 770);
        glVertex2i(100-10, 760);
        glVertex2i(80-10, 760);

	glEnd();

	glBegin(GL_POLYGON);           // tree 1
	glColor3f(0.404, 0.812, 0);
        glVertex2i(80+30, 810);
        glVertex2i(80+30, 760);
        glVertex2i(40+30, 800);
        glVertex2i(50+30, 820);
        glVertex2i(40+30, 850);
        glVertex2i(55+30, 880);
        glVertex2i(80+30, 900);
        glVertex2i(120+30, 920);
        glVertex2i(160+30, 900);
        glVertex2i(180+30, 880);
        glVertex2i(190+30, 860);
        glVertex2i(180+30, 830);
        glVertex2i(160+30, 810);
        glVertex2i(120+30, 770);
        glVertex2i(100+30, 760);
        glVertex2i(80+30, 760);

	glEnd();

*/




//  house


	glBegin(GL_POLYGON);           // House
	glColor3f(0.91, 0.886, 0.855);
        glVertex2i(1600, 500);
        glVertex2i(1600, 660);
        glVertex2i(1660, 680);
        glVertex2i(1700, 620);
        glVertex2i(1700, 500);

	glEnd();
	glBegin(GL_QUADS);           // House
	glColor3f(0.91, 0.886, 0.855);
        glVertex2i(1700, 500);
        glVertex2i(1820, 500);
        glVertex2i(1820, 620);
        glVertex2i(1700, 620);

   glColor3f(0.588, 0.78, 0.843);   //door
        glVertex2i(1740, 500);
        glVertex2i(1780, 500);
        glVertex2i(1780, 560);
        glVertex2i(1740, 560);

        glVertex2i(1620, 540);   //window
        glVertex2i(1620, 580);
        glVertex2i(1660, 580);
        glVertex2i(1660, 540);
	glEnd();


	glBegin(GL_QUADS);           // Cala
	glColor3f(0.851, 0.498, 0.42);
        glVertex2i(1580, 640);
        glVertex2i(1580, 660);
        glVertex2i(1640, 700);
        glVertex2i(1660, 680);

        glVertex2i(1640, 700);
        glVertex2i(1700, 620);
        glVertex2i(1840, 620);
        glVertex2i(1800, 700);

	glEnd();

	glBegin(GL_LINES);           // Border
	glColor3f(0, 0, 0);
        glVertex2i(1700, 620);
        glVertex2i(1700, 500);
	glEnd();
	glBegin(GL_LINES);           // Border
	glColor3f(0, 0, 0);
        glVertex2i(1600, 650);
        glVertex2i(1600, 500);
        glVertex2i(1820, 500);
        glVertex2i(1820, 620);

	glEnd();

	// boat

    glBegin(GL_QUADS);
        glVertex2d(465 + shift, 90);
        glVertex2d(540 + shift, 90);
        glVertex2d(565 + shift, 120);
        glVertex2d(440 + shift, 120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.804, 0.522, 0.247);
        glVertex2d(465 + shift, 120);
        glVertex2d(540 + shift, 120);
        glVertex2d(530 + shift, 150);
        glVertex2d(475 + shift, 150);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
        glVertex2d(470 + shift, 120);
        glVertex2d(480 + shift, 150);

        glVertex2d(480 + shift, 120);
        glVertex2d(490 + shift, 150);

        glVertex2d(490 + shift, 120);
        glVertex2d(500 + shift, 150);

        glVertex2d(535 + shift, 120);
        glVertex2d(525 + shift, 150);

        glVertex2d(525 + shift, 120);
        glVertex2d(515 + shift, 150);

        glVertex2d(515 + shift, 120);
        glVertex2d(505 + shift, 150);
    glEnd();


    glBegin(GL_QUADS);              // left
    glColor3f(0.749, 0.722, 0.694);
        glVertex2d(455 + shift + boithaPos, 130);
        glVertex2d(458 + shift + boithaPos, 130);
        glVertex2d(456 + shift + boithaPos, 70);
        glVertex2d(453 + shift + boithaPos, 70);
    glEnd();
    circle(10, 15, 454.5 + shift + boithaPos, 80);


    // cloud 1

    glPushMatrix();
    glTranslatef(bx, 0, 0);

    glColor3f(0.741, 0.898, 0.957);//shadow
    circle(20, 30, 535, 1005);
    circle(15, 20, 510, 1005);
    circle(15, 20, 565, 1005);

    glColor3f(1, 1, 1);
    circle(20, 30, 535, 1010);
    circle(15, 20, 510, 1010);
    circle(15, 20, 565, 1010);



    // cloud 2

    glColor3f(0.741, 0.898, 0.957);//shadow
    circle(20, 30, 400, 975);
    circle(15, 20, 415, 975);
    circle(15, 20, 385, 975);

    glColor3f(1, 1, 1);
    circle(20, 30, 400, 980);
    circle(15, 20, 415, 980);
    circle(15, 20, 385, 980);

    // cloud movement

    glPopMatrix();
    bx += .05;
    if (bx > 1920)
        bx = 0;
    glutPostRedisplay();
















glutSwapBuffers();

glFlush();	// Process all OpenGL routines

}

void key(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_LEFT:
        if(shift>=5){
            shift -= 5;
            boithaPos = 100;
        glutPostRedisplay();
        }
        break;
    case GLUT_KEY_RIGHT:
        if(shift<=765){
            shift += 5;
            boithaPos = 0;
            glutPostRedisplay();

        }
        break;
    }
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);						// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

	glutInitWindowPosition(50, 50);				// Set window position
	glutInitWindowSize(1920, 1080);					// Set window size
	glutCreateWindow("An Example OpenGL Program");	// Create display window

	init();							// Execute initialisation procedure
	glutDisplayFunc(drawShapes);		// Send graphics to display window
	glutSpecialFunc(key);
	glutMainLoop();					// Display everything and wait

	return 0;
}
