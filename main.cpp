#include <GL/glut.h>
#include "functions.h"

bool g_PAUSED = true;
bool g_MODE_SIN = false;
bool g_MODE_COS = false;
bool g_MODE_TAN = false;

void render(void);

void reshape(int, int);

void timer(int);

void onKeyboardPress(unsigned char characterPressed, __attribute__((unused)) int x, __attribute__((unused)) int y);

void onMouseEvent(int button, __attribute__((unused)) int state, int x, int y);

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    // GLUT_DOUBLE means double buffer
    // the front buffer is the buffer shown on the screen, the back buffer is the buffer on which we draw
    // when we want to display the back buffer, we can just swap the two via glutSwapBuffers()
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    // you can modify these values in "constants.h" to match your screen resolution
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Trigonometric Functions");

    // set the default background color (when color buffer is cleared)
    glClearColor(0.2, 0.2, 0.2, 0.2);

    // set display function, called when the window is created
    glutDisplayFunc(render);
    // specify viewport, called whenever the window is created, or whenever the window is resized
    glutReshapeFunc(reshape);
    // set a timer function to keep refreshing display
    glutTimerFunc(1000, timer, 0);

    // set keyboard event function
    glutKeyboardFunc(onKeyboardPress);
    // set mouse event function
    glutMouseFunc(onMouseEvent);

    // tells OpenGL the initialization process is over and tells it to start rendering
    glutMainLoop();
}

void render(void) {
    // clears the color bits from the framebuffer (effectively clearing the screen)
    glClear(GL_COLOR_BUFFER_BIT);
    // resets all the transformations of the current matrix
    glLoadIdentity();

    drawAxes();
    drawButtons();
    // then by if statements, call to either of 3 functions depending on which animation is active

    // swap the back buffer with the front buffer to display what we just drew
    glutSwapBuffers();
}

// the width and height are provided from the api whenever they are changed
void reshape(int windowWidth, int windowHeight) {
    // set the viewport (the area in the window in which to draw)
    // everything outside the viewport will be clipped
    // glViewport(x, y, width, height). The (x, y) coordinates are where in the window to start drawing the viewport
    // aka the coordinates of the bottom left corner of the viewport
    glViewport(0, 0, windowWidth, windowHeight); // full screen

    // set the projection matrix, we are currently in the model view (GL_MODELVIEW) matrix
    // we should always be in the model view matrix when drawing
    // switch to the projection matrix to set the desired projection
    glMatrixMode(GL_PROJECTION);
    // reset the parameters of the projection matrix
    glLoadIdentity();
    // set the projection as a 2 dimensional cartesian orthogonal frame
    // --------------
    // |     ^ y    |
    // |     |      |
    // |-----|----->| x
    // |     |      |
    // |     |      |
    // --------------
    // farthest left,    right,      bottom,     top
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
    // we are done modifying the projection matrix, go back to model view matrix
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    // ask OpenGL to call the display function again
    glutPostRedisplay();
    // 60 frames per second
    glutTimerFunc(1000 / 60, timer, 0);
}

// x and y are mouse cursor position when key was pressed
void onKeyboardPress(unsigned char characterPressed, __attribute__((unused)) int x, __attribute__((unused)) int y) {
    if (characterPressed == 'q')
        exit(0);
}

void onMouseEvent(int button, __attribute__((unused)) int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON)
        exit(0);
}
