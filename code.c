#include<windows.h>
#include<stdio.h>
#include<glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define CIRCLE_RADIUS  0.15f
# define PI 3.14159265358979323846
int eggs_caught = 0, missed_eggs = 0, level_count = 1, points = 0;


int egg_xc, egg_yc;
// for coordinates of egg
int basket_x, basket_y;
// for coordinates of basket
int a = 600, b = 650; // for default size of the screen
int s = 0;
// for menu option
int dropped_eggs = 0;
int speed_1 = 1.5, speed_2 = 2, speed_3 = 2.25, speed_4 = 2.5;
int w = 48, h = 48;

void myinit();
void start_screen(int, int);
void cloud1();
void egg();
void basket(int, int);
void duck(int, int);
void print_score();
void egg_start();
void color();
void score();
void display(void);
void basket_set(int, int);
void myReshape(int, int);
void keys(unsigned char, int, int);
void menu(int);
//Initializes the OpenGL graphics window, sets the viewport, and sets the projection matrix.
void myinit()
{
    glViewport(0, 0, a, b);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//resets the current matrix to the identity matrix
    gluOrtho2D(0, (GLdouble)a, 0, (GLdouble)b);// sets up an orthographic projection for 2D rendering. This means that the z-coordinate of each vertex will be ignored
    glMatrixMode(GL_MODELVIEW);//means that subsequent matrix operations will affect the modelview matrix, which controls the position and orientation of the objects in the scene.
    glutPostRedisplay();
    // marks the current window as needing to be redisplayed
}
//Displays the starting screen for the game, with the title and a message to start the game.
void start_screen(int i, int j)
{
    int k;
    char cat[4] = "EGG";
    char orr[9] = "CATCHING";
    char hatch[5] = "GAME";
    char start[20] = "Press S for start";
    glColor3f(1, 1, 1);
    glRasterPos2i(180, 270);//sets the position of the text on the screen
    for (k = 0; k < 4; k++)//the function loops through the characters in the character array and displays them on the screen
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cat[k]);
    glColor3f(1, 1, 1);
    glRasterPos2i(230, 270);
    for (k = 0; k < 9; k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, orr[k]);
    glColor3f(1, 1, 1);
    glRasterPos2i(337, 270);
    for (k = 0; k < 5; k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hatch[k]);
    glColor3f(1, 1, 0);
    glRasterPos2i(220, 230);
    for (k = 0; k < 20; k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, start[k]);
    glColor3f(1, .5, .5);

}

void sun()
{
    //The circle is centered at (500, 600) and has a radius of 80 pixels.
    //using the parametric equation of a circle in polar coordinates.
    float theta;

    //GLfloat angle;
    glLineWidth(1.5);
    glColor3f(1, 0.4, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(500 + 80 * cos(theta) / 2, 600 + 80 * sin(theta) / 2);
    }

    glEnd();
    glFlush();
}
void cloud1()
{
    //The cloud is drawn using four separate polygons,

    float theta;

    //GLfloat angle;
    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(170 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);
    }

    glEnd();
    //GLfloat angle;
    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(200 + 50 * cos(theta) / 2, 580 + 50 * sin(theta) / 2);
    }
    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(210 + 50 * cos(theta) / 2, 600 + 50 * sin(theta) / 2);
    }
    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(240 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);
    }

    glEnd();
    glFlush();
}

void cloud2()
{
    float theta;
    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(420 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
    }

    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(455 + 45 * cos(theta) / 2, 550 + 45 * sin(theta) / 2);
    }

    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(455 + 45 * cos(theta) / 2, 530 + 45 * sin(theta) / 2);
    }

    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * PI * i / 180;
        glVertex2f(490 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
    }

    glEnd();
    glFlush();

}


void line(int i, int j)
{

    glBegin(GL_QUADS);
    glColor3f(1.0, .5, 1);
    glVertex2f(0.0 + i, 10.0 + j);
    glVertex2f(0.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 10.0 + j);
    glEnd();
    glFlush();
}


void backk(int i, int j)
{


    glColor3f(0, .8, 1);
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, -500 + j);
    glVertex2f(0.0 + i, -500 + j);
    glEnd();
    glFlush();


}
void ground(int i, int j)
{

    glBegin(GL_QUADS);
    glColor3f(0, 1.0, 0.35);
    glVertex2f(0.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, -j);
    glVertex2f(0.0 + i, -j);
    glEnd();
}





void egg()
{

    float x, y, z;
    int t;
    glColor3f(1.0, 10, 1.0);
    glBegin(GL_POLYGON);
    for (t = 0; t <= 360; t += 1)
    {
        x = egg_xc + 8 * (cos(t));
        y = egg_yc + 10 * (sin(t));
       
        glVertex2f(x, y);
    }
    glEnd();
}
void basket(int i, int j)
{
    j = 10;
    if (i >= a - 60)i = a - 60;
    glColor3f(1.0, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 30.0 + j);
    glVertex2f(10.0 + i, 10.0 + j);
    glVertex2f(50.0 + i, 10.0 + j);
    glVertex2f(60.0 + i, 30.0 + j);
    glEnd();
}
void duck(int i, int j)
{
    int h;
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(45 + i, 25 + j);
    glVertex2f(70 + i, 0 + j);
    glVertex2f(95 + i, 0 + j);
    glVertex2f(120 + i, 25 + j);
    glVertex2f(95 + i, 50 + j);
    glVertex2f(70 + i, 50 + j);
    glVertex2f(95 + i, 75 + j);
    glVertex2f(82.5 + i, 87.5 + j);
    glVertex2f(32.5 + i, 37.5 + j);
    glEnd();
    glFlush();
    for (h = 0; h < 13; h += 4)
    {
        glBegin(GL_LINES);
        glColor3f(0.7, 0.4, 0);
        glVertex2f(57.5 + h + i, 32.5 + h + j);
        glVertex2f(100 + h + i, 10 + h + j);
        glEnd();
        glFlush();
    }
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(82.5 + i, 87.5 + j);
    glVertex2f(65 + i, 87.5 + j);
    glVertex2f(50 + i, 75 + j);
    glVertex2f(70 + i, 75 + j);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(76 + i, 81 + j);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(72.5 + i, 87.5 + j);
    glVertex2f(67.5 + i, 92.5 + j);
    glVertex2f(72.5 + i, 90 + j);
    glVertex2f(77.5 + i, 92.5 + j);
    glEnd();
    glFlush();
}

void print_score()
{
    printf("\nLevel reached: %d\n\n", level_count);
    printf("\nNo. of eggs dropped= %d \n", dropped_eggs);
    printf("\nNo. of eggs caught = %d\n", eggs_caught);
    printf("\nNo. of eggs missed = %d\n", missed_eggs);

    getchar();// to wait for the user to press a key.
    exit(0);
}
void egg_start()
{   //egg's starting vertical position is set to 375.
    egg_yc = 375;
    if (missed_eggs >= 5)
    {
        printf("\n\n\t\t\t\tGAME OVER\n\n");
        print_score();
    }
    dropped_eggs++;
//egg's horizontal position is randomized using a switch statement that generates a random
//integer between 0 and 8 and assigns the corresponding value to egg_xc
    switch (rand() % 9)
    {
    case 0:egg_xc = 115; break;
    case 1:egg_xc = 255; break;
    case 2:egg_xc = 390; break;
    case 5:egg_xc = 115; break;
    case 3:egg_xc = 255; break;
    case 4:egg_xc = 390; break;
    case 7:egg_xc = 115; break;
    case 6:egg_xc = 255; break;
    case 8:egg_xc = 390; break;
    }
}




void score()
{
    if (egg_yc <= 50 && (egg_xc >= basket_x && egg_xc <= basket_x + 60))
    {
        printf("\a");// produce a beep sound
        eggs_caught++;
        egg_yc = -10;//after an egg has been caught by the basket
        //remove it from the screen and prepare for the next egg to be dropped.
    }
    missed_eggs = dropped_eggs - eggs_caught;
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//It clears the screen
    ground(0, 650);
    backk(0, 650);
    duck(40, 375);
    duck(180, 375);
    duck(320, 375);
    sun();
    cloud1();
    cloud2();
    line(0, 355);

    int i;
   
    char level1[12] = "LEVEL 1";
    char level2[12] = "LEVEL 2";
    char level3[12] = "LEVEL 3";
    char level4[12] = "LEVEL 4";

    if (s >= 1)
    {

        if (level_count == 1)
        {
            glColor3f(1, 1, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level1[i]);
        }
        else if (level_count == 2)
        {
            glColor3f(1, 0, 0);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level2[i]);
        }
        else if (level_count == 3)
        {
            glColor3f(0, 1, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level3[i]);
        }
        if (level_count == 4)
        {
            glColor3f(1, 0, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level4[i]);
        }
        //checks if the current egg has reached the bottom of the screen, 
        //in which case it starts a new egg by calling the egg_start() function
        if (egg_yc <= 10)
            egg_start();

        egg();
        basket(basket_x, basket_y);
        if (eggs_caught >= 10)
        {
            egg_yc -= speed_2;//translation
            level_count = 2;
        }
        if (eggs_caught >= 20)
        {
            egg_yc -= speed_3;
            level_count = 3;
        }
        if (eggs_caught >= 30)
        {
            egg_yc -= speed_4;
            level_count = 4;
        }
        else
            egg_yc -= speed_1;
        score();//to check if the egg has been caught by the basket or missed
        //and updates the scores 
    }
    else
        start_screen(40, 300);
    // swaps the back and front buffers
    //of the window and flushes the drawing commands to the graphics hardware.
    glFlush();
    glutSwapBuffers();
}
//This means that whenever the mouse moves within the window, 
//the basket_set() function is called.
void basket_set(int a, int b)
{
    basket_x = a;
    basket_y = b;
    glutPostRedisplay();
}
//myReshape() is an important function for ensuring that the game is displayed properly on 
//the screen,regardless of the window size.(when window size is changed)
void myReshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    a = w;
    b = h;
}
void keys(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
    {
        printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
        print_score();
    }//s to 1 indicates that the game has started.
    if (key == 's' || key == 'S') s += 1;

    if (key == 'a' || key == 'A')
    {
        egg_xc -= 10;//moves the egg to the left by 10 pixels
        if (egg_xc <= 0) egg_xc = 10;
    }
    if (key == 'd' || key == 'D')
    {
        egg_xc += 10;//moves the egg to the right by 10 pixels,
        if (egg_xc >= 500) egg_xc = 490;
    }

}
//The game has a menu that can be accessed by right-clicking on the screen, which provides 
//options to start the game, print the score, quit the game, etc.
void menu(int id)
{
    switch (id)
    {
    case 1: s += 1;
        break;
    case 2:print_score();
        break;
    case 3: printf("\n\n\n\t\tQUIT BY PLAYER\n");
        break;
    default:exit(0);
    }
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    printf("******************************************************************");
    printf("\n\t\t\t\t EGG CATCHING GAME\n\n");
    printf("******************************************************************");
    printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the eggs in the basket.\n\t To move Basket use mouse.\n");
    printf("\n <2> To Start, press key 's' or 'S' or \n\tClick Right mouse button then click 'Start Game'.\n");
    printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right mouse button then click 'Quit'.\n");
    printf("\n\n RULES : If the player misses 5 eggs,then 'Game Over'.\n");
    printf("\nFor each level, speed is Increased\n\n");
    printf("\n\nBEST OF LUCK\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(a, b);
    glutCreateWindow("EGG GAME");
    myinit();
    glutInitWindowPosition(100, 100);
    glutCreateMenu(menu);
    glutAddMenuEntry("Start game", 1);
    glutAddMenuEntry("score", 2);
    glutAddMenuEntry("Quit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutPassiveMotionFunc(basket_set);
    glutIdleFunc(display);
    glutReshapeFunc(myReshape);
    glutMainLoop();
}
// it enters the main event loop with the glutMainLoop() function, which handles all the events
//and updates the screen as necessary.
