#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include<math.h>
#include <ctime>


float shift = 0;
float boithaPos = 0;
float bx = 0;
float downOb = 0;
float upOb = 0;
bool isDay = true;

float dayBackgroundColor[3] = {0.878, 0.949, 0.988};
float nightBackgroundColor[3] = {0.1, 0.1, 0.2};

//RAIN

bool isRaining = false;
std::vector<std::pair<int, int>> raindrops;

void drawRain()
{
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1); // Blue color for raindrops
    for (const auto& drop : raindrops)
    {
        glVertex2i(drop.first, drop.second);
    }
    glEnd();
}

void updateRain()
{
    if (isRaining)
    {
        // Add new raindrops
        if (raindrops.size() < 100)
        {
            for (int i = 0; i < 10; ++i)
            {
                raindrops.push_back({rand() % 1920, rand() % 1080});
            }
        }

        // Move existing raindrops down
        for (auto& drop : raindrops)
        {
            drop.second -= 5; // Adjust speed as needed
            // Reset drop if it falls off the screen
            if (drop.second < 0)
            {
                drop.second = 1080;
            }
        }
    }
}

void setBackgroundColor()
{
    if (isDay)
    {
        glClearColor(dayBackgroundColor[0], dayBackgroundColor[1], dayBackgroundColor[2], 0.0);
    }
    else
    {
        glClearColor(nightBackgroundColor[0], nightBackgroundColor[1], nightBackgroundColor[2], 0.0);
    }
}

void drawRainbow(GLfloat cx, GLfloat cy, GLfloat radius)
{
    GLfloat colors[7][3] =
    {
        {1.0, 0.0, 0.0}, // Red
        {1.0, 0.5, 0.0}, // Orange
        {1.0, 1.0, 0.0}, // Yellow
        {0.0, 1.0, 0.0}, // Green
        {0.0, 0.0, 1.0}, // Blue
        {0.29, 0.0, 0.51}, // Indigo
        {0.56, 0.0, 1.0} // Violet
    };

    for (int i = 0; i < 7; i++)
    {
        glColor3fv(colors[i]);
        glBegin(GL_POLYGON);
        for (int j = 0; j <= 180; j++)
        {
            float angle = j * 3.1416 / 180;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex2f(cx + x, cy + y);
        }
        glEnd();
        radius -= 20; // Decrease radius for next color band
    }
}

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

void circleTop(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 180; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void treeleafStyle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    for (int i = 20; i <= 90; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}
void drawBird(GLfloat x, GLfloat y, GLfloat size)
{

    glLineWidth(2.0f);

    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x - size, y - size);

    glVertex2f(x, y);
    glVertex2f(x + size, y - size);
    glEnd();
}

void khorKuta(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 180; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void drawStar(GLfloat x, GLfloat y, GLfloat radius, GLfloat innerRadius, int numPoints)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of star
    for (int i = 0; i <= numPoints * 2; i++)
    {
        float angle = i * 3.1416 / numPoints;
        float r = (i % 2 == 0) ? radius : innerRadius;
        float xOffset = r * cos(angle);
        float yOffset = r * sin(angle);
        glVertex2f(x + xOffset, y + yOffset);
    }
    glEnd();
}

void drawGrass(float x, float y)
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);  // green color for grass
    glVertex2f(1800 + x, 200 + y);
    glVertex2f(1815 + x, 200 + y);
    glVertex2f(1820 + x, 225 + y);

    glVertex2f(1800 + x, 200 + y);
    glVertex2f(1810 + x, 200 + y);
    glVertex2f(1805 + x, 225 + y);

    glVertex2f(1800 + x, 200 + y);
    glVertex2f(1815 + x, 200 + y);
    glVertex2f(1785 + x, 225 + y);

    glVertex2f(1800 + x, 200 + y);
    glVertex2f(1815 + x, 200 + y);
    glVertex2f(1800 + x, 225 + y);

    glEnd();
}


void house(int m, int n)
{

    glBegin(GL_POLYGON);  // House
    glColor3f(0.91, 0.886, 0.855);
    glVertex2i(1600 + m, 500 + n);
    glVertex2i(1600 + m, 660 + n);
    glVertex2i(1660 + m, 680 + n);
    glVertex2i(1700 + m, 620 + n);
    glVertex2i(1700 + m, 500 + n);
    glEnd();

    glBegin(GL_QUADS);  // House
    glColor3f(0.91, 0.886, 0.855);
    glVertex2i(1700 + m, 500 + n);
    glVertex2i(1820 + m, 500 + n);
    glVertex2i(1820 + m, 620 + n);
    glVertex2i(1700 + m, 620 + n);

    glColor3f(0.588, 0.78, 0.843);  // door
    glVertex2i(1740 + m, 500 + n);
    glVertex2i(1780 + m, 500 + n);
    glVertex2i(1780 + m, 560 + n);
    glVertex2i(1740 + m, 560 + n);

    glVertex2i(1620 + m, 540 + n);  // window
    glVertex2i(1620 + m, 580 + n);
    glVertex2i(1660 + m, 580 + n);
    glVertex2i(1660 + m, 540 + n);


    glColor3f(0.573, 0.616, 0.624);


    glVertex2i(1745 + m, 495 + n); // door step 1
    glVertex2i(1775 + m, 495 + n);
    glVertex2i(1775 + m, 490 + n);
    glVertex2i(1745 + m, 490 + n);

    glVertex2i(1750 + m, 500 + n);  // // door step 2
    glVertex2i(1770 + m, 500 + n);
    glVertex2i(1770 + m, 495 + n);
    glVertex2i(1750 + m, 495 + n);

    glEnd();

    glBegin(GL_QUADS);  // Cala
    glColor3f(0.851, 0.498, 0.42);
    glVertex2i(1580 + m, 640 + n);
    glVertex2i(1580 + m, 660 + n);
    glVertex2i(1640 + m, 700 + n);
    glVertex2i(1660 + m, 680 + n);

    glVertex2i(1640 + m, 700 + n);
    glVertex2i(1700 + m, 620 + n);
    glVertex2i(1840 + m, 620 + n);
    glVertex2i(1800 + m, 700 + n);
    glEnd();

    glBegin(GL_LINE_LOOP);  // Border
    glColor3f(0, 0, 0);
    glVertex2i(1580 + m, 640 + n);
    glVertex2i(1580 + m, 660 + n);
    glVertex2i(1640 + m, 700 + n);
    glVertex2i(1655 + m, 678 + n);
    glEnd();
    glBegin(GL_LINE_LOOP);  // Border
    glVertex2i(1640 + m, 700 + n);
    glVertex2i(1700 + m, 620 + n);
    glVertex2i(1840 + m, 620 + n);
    glVertex2i(1800 + m, 700 + n);
    glEnd();
    glBegin(GL_LINE_LOOP);  // Border
    glVertex2i(1620 + m, 540 + n);  // window
    glVertex2i(1620 + m, 580 + n);
    glVertex2i(1660 + m, 580 + n);
    glVertex2i(1660 + m, 540 + n);
    glEnd();
    glBegin(GL_LINE_LOOP);  // Border
    // door
    glVertex2i(1740 + m, 500 + n);
    glVertex2i(1780 + m, 500 + n);
    glVertex2i(1780 + m, 560 + n);
    glVertex2i(1740 + m, 560 + n);

    glEnd();
    glBegin(GL_LINE_LOOP);  // Border
    // door
    glVertex2i(1700 + m, 500 + n);
    glVertex2i(1820 + m, 500 + n);
    glVertex2i(1820 + m, 620 + n);
    glVertex2i(1700 + m, 620 + n);

    glEnd();
    glBegin(GL_LINE_LOOP);  // Border
    // door
    glVertex2i(1600 + m, 500 + n);
    glVertex2i(1600 + m, 650 + n);
    glVertex2i(1655 + m, 680 + n);
    glVertex2i(1700 + m, 620 + n);
    glVertex2i(1700 + m, 500 + n);
    glEnd();
    glBegin(GL_LINE_LOOP);  // Border
    // door
    glVertex2i(1745 + m, 495 + n); // door step 1
    glVertex2i(1775 + m, 495 + n);
    glVertex2i(1775 + m, 490 + n);
    glVertex2i(1745 + m, 490 + n);


    glEnd();
    glBegin(GL_LINE_LOOP);  // Border
    // door
    glVertex2i(1750 + m, 500 + n);  // // door step 2
    glVertex2i(1770 + m, 500 + n);
    glVertex2i(1770 + m, 495 + n);
    glVertex2i(1750 + m, 495 + n);
    glEnd();


}

void flower(int x, int y)
{

    glBegin(GL_QUADS);              // left
    glColor3f(0.749, 0.722, 0.694);
    glVertex2d(1190+x, 450+y);
    glVertex2d(1195+x, 450+y);
    glVertex2d(1195+x, 480+y);
    glVertex2d(1190+x, 480+y);
    glEnd();

    glColor3f(0.98, 0.949, 0);
    circle(8, 8, 1192+x, 480+y);

    glColor3f(1, 0.678, 0.78+y);
    circle(8, 8, 1182+x, 480+y);
    circle(8, 8, 1192+x, 490+y);
    circle(8, 8, 1203+x, 480+y);
    circle(8, 8, 1192+x, 470+y);
}


void drawShapes(void)
{
    glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

     //SKY

    // Birds
    glColor3f(0.0, 0.0, 0.0);
    drawBird(1280, 950, 20);
    drawBird(1320, 1000, 20);
    drawBird(1370, 970, 20);
    drawBird(1410, 1010, 20);
    drawBird(1450, 970, 20);

    glBegin(GL_QUADS);    // river
    glColor3f(0.161, 0.761, 0.941);
    glVertex2i(380, 0);
    glVertex2i(380, 600);
    glVertex2i(1450, 600);
    glVertex2i(1400, 0);
    glEnd();

             // day night sun and star

    if (isDay)
    {
        glColor3f(1.0, 1.0, 0.0);  // Yellow for sun
    }
    else
    {
        glColor3f(1.0, 1.0, 1.0);  // White for moon

    }
    circle(50, 50, 1700, 900);  //sun and moon

    if (isDay)
    {
        glColor3f(0.878, 0.949, 0.988);  // White for star

    }
    else
    {
        glColor3f(1.0, 1.0, 0.0);  // Yellow for star
    }

    drawStar(680, 940, 5, 10, 5);
    drawStar(680+50, 940, 5, 10, 5);
    drawStar(680+80, 940+40, 5, 10, 5);
    drawStar(680+150, 940, 5, 10, 5);

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

    // white point sky
    if (!isDay)
    {
        glColor3f(1.0, 1.0, 1.0);
        circle(2,2,500,1000);
        circle(2,2,450,1050);
        circle(2,2,700,940);
        circle(2,2,600,1000);
        circle(2,2,540,1030);

        circle(2,2,1000,990);
        circle(2,2,1300,1020);
        circle(2,2,1150,890);
        circle(2,2,1200,920);
        circle(2,2,990,870);

        circle(2,2,1400,990);
        circle(2,2,1450,870);
        circle(2,2,1500,1000);
        circle(2,2,1570,890);
    }

     if (isDay)
    {
        drawRainbow(960, 600, 350);  //rainbow
        glColor3f(0.878, 0.949, 0.988);
        circleTop(215, 215, 960, 600);
    }

            // Rain
    if (isRaining)
    {
        updateRain();
        drawRain();
    }

    //SKY END

    // Shapla

    glColor3f(0.129, 0.722, 0.153);
    circle(20, 10, 1200, 450);
    circle(20, 10, 1190, 460);
    circle(20, 10, 1210, 460);

    glColor3f(0.129, 0.722, 0.153);
    circle(15, 7, 1200+100, 450+60);
    circle(15, 7, 1190+100, 460+60);
    circle(15, 7, 1210+100, 460+60);

    glColor3f(0.129, 0.722, 0.153);
    circle(11, 6, 1200-10, 450+80);
    circle(11, 6, 1190-10, 460+80);
    circle(11, 6, 1210-10, 460+80);


    glBegin(GL_QUADS);              // Flower
    glColor3f(0.749, 0.722, 0.694);
    glVertex2d(1190, 450);
    glVertex2d(1195, 450);
    glVertex2d(1195, 480);
    glVertex2d(1190, 480);
    glEnd();

    glColor3f(0.98, 0.949, 0);
    circle(5, 5, 1192, 480);

    glColor3f(1, 0.678, 0.78);
    circle(5, 5, 1182, 480);
    circle(5, 5, 1192, 490);
    circle(5, 5, 1203, 480);
    circle(5, 5, 1192, 470);



      // Field

    glBegin(GL_POLYGON);        // top feild
    glColor3f(0.945, 0.796, 0.471);
    glVertex2i(300, 360);
    glVertex2i(500, 460);
    glVertex2i(0, 500);
    glVertex2i(0, 440);

    glEnd();


    // Draw a filed Road
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

    // feild

    glBegin(GL_POLYGON);  // left feild
    glColor3f(0.129, 0.722, 0.153);
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
    glColor3f(0.973, 0.816, 0.533);
    glVertex2i(390+5, 200);
    glVertex2i(450+5, 270);
    glVertex2i(500+5, 320);
    glVertex2i(540+5, 300);
    glVertex2i(520+5, 240);
    glVertex2i(450+5, 200);
    glVertex2i(480+5, 160);
    glVertex2i(440+5, 100);
    glVertex2i(470+5, 80);
    glVertex2i(400+5, 0);
    glEnd();

    glBegin(GL_POLYGON);        // right feild
    glColor3f(0.129, 0.722, 0.153);
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
    glColor3f(0.129, 0.722, 0.153);
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
    glVertex2i(1700, 645);
    glVertex2i(1920, 650);

    glEnd();


    glBegin(GL_POLYGON);           // hill Back
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

    glColor3f(0.129, 0.722, 0.153);
    circle(210, 190, 1500, 200);  // home feild curve
    circle(240, 150, 1570, 500);

    glColor3f(0.973, 0.816, 0.533); // river feild curve
    circle(50,50, 500, 115);
    glColor3f(0.161, 0.761, 0.941); // river feild curve
    circle(50,53, 505, 114);



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


    int tree1 = 40; // Initial vertical offset for the tree

    glColor3f(0.506, 0.671, 0.243); // tree 1 leaf
    circle(80, 80, 80, 800 + tree1);
    circle(80, 80, 80, 900 + tree1);
    circle(90, 80, 180, 950 + tree1);
    circle(80, 80, 180, 800 + tree1);
    circle(100, 90, 240, 870 + tree1);
    circle(70, 50, 230, 760 + tree1);

    glBegin(GL_POLYGON);           // tree 1 trunk
    glColor3f(0.49, 0.29, 0);
    glVertex2i(100, 420 + tree1);
    glVertex2i(180, 420 + tree1);
    glVertex2i(180, 700 + tree1);
    glVertex2i(100, 700 + tree1);
    glEnd();

    glBegin(GL_POLYGON);           // tree 1 root
    glColor3f(0.49, 0.29, 0);
    glVertex2i(70, 380 + tree1);
    glVertex2i(210, 380 + tree1);
    glVertex2i(190, 400 + tree1);
    glVertex2i(180, 420 + tree1);
    glVertex2i(100, 420 + tree1);
    glVertex2i(90, 400 + tree1);
    glEnd();


    glBegin(GL_TRIANGLES);           // tree 1 root
    glColor3f(0.929, 0.929, 0.925);
    glVertex2i(100, 380 + tree1);
    glVertex2i(120, 400 + tree1);
    glVertex2i(140, 380+ tree1);
    glEnd();

    glBegin(GL_TRIANGLES);           // tree 1 root desin
    glColor3f(0.929, 0.929, 0.925);
    glVertex2i(100+40, 380 + tree1);
    glVertex2i(120+40, 400 + tree1);
    glVertex2i(140+40, 380+ tree1);
    glEnd();

    glBegin(GL_POLYGON);           // tree 1 upper body right
    glColor3f(0.49, 0.29, 0);
    glVertex2i(140, 700 + tree1);
    glVertex2i(180, 700 + tree1);
    glVertex2i(190, 720 + tree1);
    glVertex2i(200, 740 + tree1);
    glVertex2i(240, 780 + tree1);
    glVertex2i(260, 800 + tree1);
    glVertex2i(280, 820 + tree1);
    glVertex2i(300, 840 + tree1);
    glVertex2i(140, 740 + tree1);
    glVertex2i(160, 760 + tree1);
    glVertex2i(180, 780 + tree1);
    glVertex2i(200, 800 + tree1);
    glVertex2i(220, 820 + tree1);
    glVertex2i(240, 840 + tree1);
    glEnd();

    glBegin(GL_POLYGON);           // tree 1 upper body left
    glColor3f(0.49, 0.29, 0);
    glVertex2i(100, 700 + tree1);
    glVertex2i(140, 700 + tree1);
    glVertex2i(140, 740 + tree1);
    glVertex2i(120, 760 + tree1);
    glVertex2i(100, 780 + tree1);
    glVertex2i(100, 800 + tree1);
    glVertex2i(100, 900 + tree1);
    glVertex2i(60, 900 + tree1);
    glVertex2i(60, 800 + tree1);
    glVertex2i(70, 780 + tree1);
    glVertex2i(80, 760 + tree1);
    glVertex2i(90, 740 + tree1);
    glVertex2i(100, 700 + tree1);
    glEnd();

    glBegin(GL_POLYGON);           // tree upper body left
    glColor3f(0.49, 0.29, 0);
    glVertex2i(85, 780 );
    glVertex2i(115, 750);
    glVertex2i(185, 880);
    glVertex2i(145, 900);

    glEnd();

    glBegin(GL_TRIANGLES);           // tree upper body left
    glColor3f(0.506, 0.671, 0.243);
    glVertex2i(140, 850);
    glVertex2i(185, 880);
    glVertex2i(145, 900);
    glEnd();

    glBegin(GL_TRIANGLES);         // tree 1 leaves
    glColor3f(0.506, 0.671, 0.243);
    glVertex2i(60, 900 + tree1);
    glVertex2i(80, 840 + tree1);
    glVertex2i(100, 900 + tree1);
    glEnd();


    glBegin(GL_POLYGON);           // tree 2
    glColor3f(0.49, 0.29, 0);
    glVertex2i(100+300, 420+30);
    glVertex2i(60+300, 420+30);
    glVertex2i(80+300, 440+30);
    glVertex2i(80+300, 820+30);
    glVertex2i(100+300, 810+30);
    glVertex2i(100+300, 720+30);
    glVertex2i(120+300, 700+30);
    glVertex2i(140+300, 680+30);
    glVertex2i(140+300, 440+30);
    glVertex2i(160+300, 420+30);
    glEnd();
    glBegin(GL_QUADS);           // tree 2
    glColor3f(0.49, 0.29, 0);
    glVertex2i(140+300, 680+30);
    glVertex2i(120+300, 700+30);
    glVertex2i(200+300, 780+30);
    glVertex2i(200+300, 760+30);
    glEnd();

       // tree 2 leaf
    glColor3f(0.506, 0.671, 0.243);
    circle(70, 50, 100+300, 800+30);
    circle(70, 50, 130+300, 840+30);
    circle(70, 50, 150+300, 820+30);
    circle(70, 50, 190+300, 780+30);


                // KhorKuta

    glColor3f(0.988, 0.71, 0.122);
    khorKuta(60,120, 1850, 475);

    glBegin(GL_QUADS);
    glColor3f(0.824, 0.722, 0.522);
    glVertex2i(1785, 475);
    glVertex2i(1915, 475);
    glVertex2i(1915, 465);
    glVertex2i(1785, 465);
    glEnd();
    khorKuta(5,8, 1850, 595);

    glBegin(GL_LINES);           // Border
    glColor3f(0.98, 0.886, 0.682);
    glVertex2i(1810, 500);
    glVertex2i(1820, 540);

    glVertex2i(1830, 510);
    glVertex2i(1840, 550);

    glVertex2i(1870, 510);
    glVertex2i(1860, 550);

    glVertex2i(1890, 500);
    glVertex2i(1880, 540);

    glEnd();


                // boat

                // Boat 1

    glColor3f(0, 0, 0);
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

    //boat 2
    glBegin(GL_POLYGON); //main body
    glColor3f(0,0,0);

    glVertex2i(1200+15, 460);
    glVertex2i(1220+15, 430);
    glVertex2i(1280+15, 430);
    glVertex2i(1300+15, 460);

    glEnd();

    glBegin(GL_POLYGON); // upper
    glColor3f(0.976, 0.498, 0.051);

    glVertex2i(1220+15, 460);
    glVertex2i(1280+15, 460);
    glVertex2i(1270+15, 480);
    glVertex2i(1230+15, 480);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2i(1249+15, 480);
    glVertex2i(1251+15, 480);
    glVertex2i(1251+15, 510);
    glVertex2i(1249+15, 510);

    glEnd();

    glBegin(GL_TRIANGLES);   //flag
    glColor3f(0.973, 0.071, 0.11);

    glVertex2i(1251+15, 510);
    glVertex2i(1251+15, 490);
    glVertex2i(1270+15, 500);

    glEnd();

    glBegin(GL_POLYGON);  //khuta
    glColor3f(0,0,1);

    glVertex2i(1285+15, 460);
    glVertex2i(1288+15, 460);
    glVertex2i(1288+15, 470);
    glVertex2i(1285+15, 470);

    glEnd();

    glBegin(GL_POLYGON);  //bambo
    glColor3f(0.451, 0.271, 0.157);

    glVertex2i(1335, 460);
    glVertex2i(1340, 460);
    glVertex2i(1340, 490);
    glVertex2i(1335, 490);

    glEnd();

    glBegin(GL_QUADS);  //dori
    glColor3f(0,0,0);

    glVertex2i(1300, 466);
    glVertex2i(1300, 467);
    glVertex2i(1337, 480);
    glVertex2i(1337, 480);

    glEnd();


    // Flower And Grass

    drawGrass(0, 0);
    drawGrass(20, 0);
    drawGrass(-20, 10);
    drawGrass(-20, 20);
    drawGrass(30, -10);
    drawGrass(-30, -10);
    drawGrass(40, -10);
    drawGrass(-40, 10);

    drawGrass(-1360, 40);
    drawGrass(-1370, 30);
    drawGrass(-1380, 20);
    drawGrass(-1390, 10);
    drawGrass(-1400, 0);
    drawGrass(-1405, -10);
    drawGrass(-1400, -60);
    drawGrass(-1400, -120);
    drawGrass(-1400, -150);
    drawGrass(-1400, -180);

    flower(-690, -200);
    flower(-720, -220);
    flower(-710, -170);

    glBegin(GL_QUADS);   // Home to Kup road
    glColor3f(0.537, 0.275, 0.063);
    glVertex2i(1645, 445);
    glVertex2i(1675, 445);
    glVertex2i(1775-60, 290);
    glVertex2i(1745-80, 290);

    glColor3f(0.675, 0.875, 0.518);
    glVertex2i(1648, 445);
    glVertex2i(1672, 445);
    glVertex2i(1772-60, 290);
    glVertex2i(1748-80, 290);


    glEnd();


    //  house
    house(-100,-50);

        // Water Well

    glBegin(GL_QUADS);           //Kup
    glColor3f(0.475, 0.275, 0.169);
    glVertex2i(1630, 200);
    glVertex2i(1730, 200);
    glVertex2i(1730, 270);
    glVertex2i(1630, 270);
    glEnd();
    circle(50, 30, 1680, 200);

    glColor3f(0.757, 0.388, 0.2);
    circle(50, 30, 1680, 220);

    glColor3f(0.475, 0.275, 0.169);
    circle(50, 30, 1680, 230);

    glColor3f(0.757, 0.388, 0.2);
    circle(50, 30, 1680, 240);

    glColor3f(0.475, 0.275, 0.169);
    circle(50, 30, 1680, 250);

    glColor3f(0.757, 0.388, 0.2);
    circle(50, 30, 1680, 270);
    glColor3f(0.267, 0.792, 0.945);
    circle(40, 20, 1680, 270);

    glBegin(GL_QUADS);           //Kup Dandi
    glColor3f(0.475, 0.275, 0.169);
    glVertex2i(1633, 270);
    glVertex2i(1637, 270);
    glVertex2i(1637, 290);
    glVertex2i(1633, 290);

    glVertex2i(1633 + 90, 270);
    glVertex2i(1637 + 90, 270);
    glVertex2i(1637 + 90, 290);
    glVertex2i(1633 + 90, 290);


    glVertex2i(1633, 290);
    glVertex2i(1727, 290);
    glVertex2i(1727, 294);
    glVertex2i(1633, 294);

    glVertex2i(1653, 288);
    glVertex2i(1707, 288);
    glVertex2i(1707, 296);
    glVertex2i(1653, 296);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.953, 0.741, 0.259);
    glVertex2i(1663, 288);
    glVertex2i(1668, 296);

    glVertex2i(1673, 288);
    glVertex2i(1678, 296);

    glVertex2i(1683, 288);
    glVertex2i(1688, 296);

    glVertex2i(1693, 288);
    glVertex2i(1698, 296);

    glVertex2i(1698, 296);  // kup to balti
    glVertex2i(1750, 260);

    glVertex2i(1750, 260);
    glVertex2i(1754, 255);

    glEnd();


    glBegin(GL_QUADS);           //Balti
    glColor3f(0.573, 0.616, 0.624);
    glVertex2i(1745, 210);
    glVertex2i(1765, 210);
    glVertex2i(1770, 240);
    glVertex2i(1740, 240);
    glEnd();
    glColor3f(0.251, 0.29, 0.298);
    circleTop(15, 20, 1755, 240);
    glColor3f(0.129, 0.722, 0.153);
    circleTop(14, 17, 1755, 240);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.251, 0.29, 0.298);
    glVertex2i(1745, 210);
    glVertex2i(1765, 210);
    glVertex2i(1770, 240);
    glVertex2i(1740, 240);

    glEnd();

    glColor3f(0.267, 0.792, 0.945);
    circle(15, 8, 1755, 240);

    glBegin(GL_LINES);
    glColor3f(0.953, 0.741, 0.259);

    glVertex2i(1750, 260);
    glVertex2i(1754, 255);

    glVertex2i(1754, 260);
    glVertex2i(1758, 255);

    glEnd();


    // GHAT
    glBegin(GL_QUADS);
    glColor3f(0.451, 0.271, 0.157);
    glVertex2i(500, 460);
    glVertex2i(600, 460);
    glVertex2i(600, 455);
    glVertex2i(500, 455);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.898, 0.631, 0.427);
    glVertex2i(500, 460);
    glVertex2i(600, 460);
    glVertex2i(600, 340);
    glVertex2i(500, 320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.161, 0.761, 0.941);
    glVertex2i(520, 455);
    glVertex2i(528, 455);
    glVertex2i(528, 332);
    glVertex2i(520, 330);
    glVertex2i(550, 455);
    glVertex2i(558, 455);
    glVertex2i(558, 337);
    glVertex2i(550, 335);
    glVertex2i(580, 455);
    glVertex2i(588, 455);
    glVertex2i(588, 342);
    glVertex2i(580, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.451, 0.271, 0.157);
    glVertex2i(500, 460);
    glVertex2i(505, 460);
    glVertex2i(505, 520);
    glVertex2i(500, 520);
    glVertex2i(500, 320);
    glVertex2i(505, 320);
    glVertex2i(505, 380);
    glVertex2i(500, 380);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.953, 0.741, 0.259);
    glVertex2i(500, 510);
    glVertex2i(505, 514);
    glVertex2i(505, 514);
    glVertex2i(500, 518);
    glVertex2i(500, 519);
    glVertex2i(600, 460);
    glVertex2i(500, 370);
    glVertex2i(505, 374);
    glVertex2i(505, 374);
    glVertex2i(500, 378);
    glVertex2i(500, 379);
    glVertex2i(600, 340);
    glEnd();


    glutSwapBuffers();

    glFlush();	// Process all OpenGL routines

}

void key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        if(shift>=5)
        {
            shift -= 5;
            boithaPos = 100;
            glutPostRedisplay();
        }
        break;
    case GLUT_KEY_RIGHT:
        if(shift<=765)
        {
            shift += 5;
            boithaPos = 0;
            glutPostRedisplay();

        }
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'r':
        isRaining = true;
        break;
    case 's':
        isRaining = false;
        raindrops.clear();
        break;
    case 'd':
    case 'D':
        isDay = true;
        setBackgroundColor();
        glutPostRedisplay();
        break;
    case 'n':
    case 'N':
        isDay = false;
        setBackgroundColor();
        glutPostRedisplay();
        break;
    case 27:  // ESC key
        exit(0);
        break;

    }
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);            // Initalise GLUT
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB | GLUT_DEPTH);  // Set display mode

    glutInitWindowPosition(50, 50);        // Set window position
    glutInitWindowSize(1920, 1080);          // Set window size
    glutCreateWindow("Village Scenario");  // Create display window

    init();              // Execute initialisation procedure
    glutDisplayFunc(drawShapes);    // Send graphics to display window
    glutSpecialFunc(key);

    glutKeyboardFunc(keyboard);
    glutIdleFunc(drawShapes); // Register idle function for continuous rendering

    glutMainLoop();          // Display everything and wait

    return 0;
}
