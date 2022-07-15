#include <GL/glut.h>

void render(void);

void reshape(int, int);

void onKeyboardPress(unsigned char characterPressed, int x, int y);

void onMouseEvent(int button, int state, int x, int y);

void drawAxes();

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    // GLUT_DOUBLE means double buffer
    // the front buffer is the buffer shown on the screen, the back buffer is the buffer on which we draw
    // when we want to display the back buffer, we can just swap the two via glutSwapBuffers()
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    // if your screen isn't this resolution you should modify these
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Trigonometric Functions");

    // set the default background color (when color buffer is cleared)
    glClearColor(0.2, 0.2, 0.2, 0.2);

    // set display function, called when the window is created
    glutDisplayFunc(render);
    // specify viewport, called whenever the window is created, or whenever the window is resized
    glutReshapeFunc(reshape);

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
    gluOrtho2D(0, 1920, 0, 1080);
    // we are done modifying the projection matrix, go back to model view matrix
    glMatrixMode(GL_MODELVIEW);
}

// x and y are mouse cursor position when key was pressed
void onKeyboardPress(unsigned char characterPressed, int x, int y) {
    if (characterPressed == 'q')
        exit(0);
}

void onMouseEvent(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON)
        exit(0);
}

void drawAxes() {
    glBegin(GL_LINES);
        // X-AXIS
        glVertex2f(100, 440);
        glVertex2f(1820, 440);
            // draw > at the end of X-axis
            // bottom line
            glVertex2f(1820, 460);
            glVertex2f(1840, 440);
            // top line
            glVertex2f(1820, 420);
            glVertex2f(1840, 440);
        // Y-AXIS
        glVertex2f(960, 100);
        glVertex2f(960, 780);
            // draw ^ at the top of Y-axis
            // left line
            glVertex2f(940, 780);
            glVertex2f(960, 800);
            // right line
            glVertex2f(980, 780);
            glVertex2f(960, 800);
    glEnd();
}
