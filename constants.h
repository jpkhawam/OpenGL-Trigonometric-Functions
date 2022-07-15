//
// Created by jpkhawam on 7/15/22.
//

#ifndef TRIGONOMETRICFUNCTIONS_CONSTANTS_H
#define TRIGONOMETRICFUNCTIONS_CONSTANTS_H

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;

constexpr int buttonHeight = 260;
constexpr int buttonWidth = 390;
constexpr int spaceBetween_Buttons = 50;
constexpr int spaceBetween_Buttons_SideEdge = 105;
constexpr int spaceBetween_Buttons_TopBottom = 20;

constexpr int spaceBetween_XAxis_ScreenEdge = 100;
constexpr int spaceBetween_YAxis_BottomEdge = 100;
constexpr int spaceBetween_YAxis_TopEdge = 300;

constexpr int yAxis_length = SCREEN_HEIGHT - spaceBetween_YAxis_BottomEdge - spaceBetween_YAxis_TopEdge;
constexpr int xAxis_YCoordinate = spaceBetween_YAxis_BottomEdge + yAxis_length / 2;
constexpr int xAxis_length = SCREEN_WIDTH - 2 * spaceBetween_XAxis_ScreenEdge;
constexpr int yAxis_XCoordinate = SCREEN_WIDTH - spaceBetween_XAxis_ScreenEdge - xAxis_length / 2;

#endif //TRIGONOMETRICFUNCTIONS_CONSTANTS_H
