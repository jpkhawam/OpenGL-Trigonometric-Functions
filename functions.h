//
// Created by jpkhawam on 7/15/22.
//

#ifndef TRIGONOMETRICFUNCTIONS_FUNCTIONS_H
#define TRIGONOMETRICFUNCTIONS_FUNCTIONS_H

#include <GL/glut.h>
#include <cmath>
#include <string>

extern bool g_MODE_SIN;
extern bool g_MODE_COS;
extern bool g_MODE_TAN;
extern bool g_MODE_ASIN;
extern bool g_MODE_ACOS;
extern bool g_MODE_ATAN;

void drawAxes() {
    glLineWidth(2);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    // X-AXIS
    glVertex2f(-4, 0);
    glVertex2f(4, 0);
    // draw > at the end of X-axis
    // bottom line
    glVertex2f(4, 0.1);
    glVertex2f(4 + 0.4, 0);
    // top line
    glVertex2f(4, -0.1);
    glVertex2f(4 + 0.4, 0);

    // Y-AXIS
    glVertex2f(0, -1);
    glVertex2f(0, 1);
    // draw ^ at the top of Y-axis
    // left line
    glVertex2f(0 - 0.2, 1);
    glVertex2f(0, 1 + 0.15);
    // right line
    glVertex2f(0 + 0.2, 1);
    glVertex2f(0, 1 + 0.15);
    glEnd();
}

void drawButtons() {
    float numberOfButtonsDrawn{};
    float maxNumberOfButtons = 7;
    float buttonWidth = 0.85;
    float spacing = 0.15;
    glColor3f(1, 1, 1);
    for (int i = 0; i < (int) maxNumberOfButtons; i++) {
        glBegin(GL_POLYGON);
        // draw polygons counter clock wise to make sure you draw the front face
        // so top left, bottom left, bottom right, top right
        glVertex2f(-3.4 + numberOfButtonsDrawn * (buttonWidth + spacing), 1.4);
        glVertex2f(-3.4 + numberOfButtonsDrawn * (buttonWidth + spacing), 1.25);
        glVertex2f(-2.6 + numberOfButtonsDrawn * (buttonWidth + spacing), 1.25);
        glVertex2f(-2.6 + numberOfButtonsDrawn * (buttonWidth + spacing), 1.4);
        glEnd();

        numberOfButtonsDrawn++;
    }
}

void drawSin(float offset) {
    int numberOfPoints{};
    for (float i = -4; numberOfPoints < 200; i = i + 0.01) {
        glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
        glVertex2f(i + offset, std::sin(i + offset));
        glEnd();
        numberOfPoints++;
    }
}

void drawCos(float offset) {
    int numberOfPoints{};
    for (float i = -4; numberOfPoints < 200; i = i + 0.01) {
        glBegin(GL_POINTS);
        glColor3f(0, 1, 0);
        glVertex2f(i + offset, std::cos(i + offset));
        glEnd();
        numberOfPoints++;
    }
}

void drawTan(float offset) {
    int numberOfPoints{};
    for (float i = -4; numberOfPoints < 200; i = i + 0.01) {
        glBegin(GL_POINTS);
        glColor3f(0, 0, 1);
        if (std::tan(i + offset) < 1.15 && std::tan(i + offset) > -1.35)
            glVertex2f(i + offset, std::tan(i + offset));
        glEnd();
        numberOfPoints++;
    }
}

void drawAsin(float offset) {
    int numberOfPoints{};
    for (float i = -4; numberOfPoints < 200; i = i + 0.01) {
        glBegin(GL_POINTS);
        glColor3f(1, 1, 0);
        glVertex2f(i + offset, std::asin(i + offset));
        glEnd();
        numberOfPoints++;
    }
}

void drawAcos(float offset) {
    int numberOfPoints{};
    for (float i = -4; numberOfPoints < 200; i = i + 0.01) {
        glBegin(GL_POINTS);
        glColor3f(1, 0, 1);
        glVertex2f(i + offset, std::acos(i + offset));
        glEnd();
        numberOfPoints++;
    }
}

void drawAtan(float offset) {
    int numberOfPoints{};
    for (float i = -4; numberOfPoints < 200; i = i + 0.01) {
        glBegin(GL_POINTS);
        glColor3f(0, 1, 1);
        glVertex2f(i + offset, std::atan(i + offset));
        glEnd();
        numberOfPoints++;
    }
}

void drawString(float x, float y, std::string string) {
    glRasterPos2f(x, y);
    for (int i = 0; i < string.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string.at(i));
    }
}

#endif //TRIGONOMETRICFUNCTIONS_FUNCTIONS_H
