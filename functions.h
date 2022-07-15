//
// Created by jpkhawam on 7/15/22.
//

#ifndef TRIGONOMETRICFUNCTIONS_FUNCTIONS_H
#define TRIGONOMETRICFUNCTIONS_FUNCTIONS_H

#include <GL/glut.h>
#include "constants.h"

void drawAxes() {
    glBegin(GL_LINES);
    // X-AXIS
    glVertex2f(spaceBetween_XAxis_ScreenEdge, xAxis_YCoordinate);
    glVertex2f(xAxis_length + spaceBetween_XAxis_ScreenEdge, xAxis_YCoordinate);
    // draw > at the end of X-axis
    // bottom line
    glVertex2f(xAxis_length + spaceBetween_XAxis_ScreenEdge, xAxis_YCoordinate + 20);
    glVertex2f(xAxis_length + spaceBetween_XAxis_ScreenEdge + 20, xAxis_YCoordinate);
    // top line
    glVertex2f(xAxis_length + spaceBetween_XAxis_ScreenEdge, xAxis_YCoordinate - 20);
    glVertex2f(xAxis_length + spaceBetween_XAxis_ScreenEdge + 20, xAxis_YCoordinate);

    // Y-AXIS
    glVertex2f(yAxis_XCoordinate, spaceBetween_YAxis_BottomEdge);
    glVertex2f(yAxis_XCoordinate, SCREEN_HEIGHT - spaceBetween_YAxis_TopEdge);
    // draw ^ at the top of Y-axis
    // left line
    glVertex2f(yAxis_XCoordinate - 20, SCREEN_HEIGHT - spaceBetween_YAxis_TopEdge);
    glVertex2f(yAxis_XCoordinate, SCREEN_HEIGHT - spaceBetween_YAxis_TopEdge + 20);
    // right line
    glVertex2f(yAxis_XCoordinate + 20, SCREEN_HEIGHT - spaceBetween_YAxis_TopEdge);
    glVertex2f(yAxis_XCoordinate, SCREEN_HEIGHT - spaceBetween_YAxis_TopEdge + 20);
    glEnd();
}

void drawButtons() {
    float numberOfButtonsDrawn{};
    float maxNumberOfButtons = 4;
    for (int i = 0; i < (int) maxNumberOfButtons; i++) {
        float leftX = spaceBetween_Buttons_LeftEdge + numberOfButtonsDrawn * buttonWidth +
                      numberOfButtonsDrawn * spaceBetween_Buttons;
        float rightX = leftX + buttonWidth;
        float topY = SCREEN_HEIGHT - spaceBetween_Buttons_TopBottom;
        float bottomY = topY - buttonHeight;

        glBegin(GL_POLYGON);
        // draw polygons counter clock wise to make sure you draw the front face
        // so top left, bottom left, bottom right, top right
        glVertex2f(leftX, topY);
        glVertex2f(leftX, bottomY);
        glVertex2f(rightX, bottomY);
        glVertex2f(rightX, topY);
        glEnd();

        numberOfButtonsDrawn++;
    }
}

void drawSin() {

}

void drawCos() {

}

void drawTan() {

}

#endif //TRIGONOMETRICFUNCTIONS_FUNCTIONS_H
