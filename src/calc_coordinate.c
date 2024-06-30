/*
 * @Author: Xiao Peng zxpcs0x3@gmail.com
 * @Date: 2024-06-30 10:08:04
 * @LastEditors: Xiao Peng zxpcs0x3@gmail.com
 * @LastEditTime: 2024-06-30 22:21:45
 * @FilePath: /spining-cube/src/calcX.c
 * @Description: calculate the spining-cube's coordinate of X 
 */
#include "calc_coordinate.h"

// 全局变量定义
float zbuffer[WIDTH * HEIGHT];
char buffer[WIDTH * HEIGHT];
char BACKGROUND_CHAR = ' ';
int PROPORTION = 30;
int FROM_CAM = 50;
float X, Y, Z;
float A, B, C;
int two_dimension_x, two_dimension_y;
float depth;
float INCREASE = 0.5f;

/// @brief calcX
/// @param i 
/// @param j 
/// @param k 
/// @return spining-cube's coordinate of X 
float calcX(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

/// @brief calcY
/// @param i 
/// @param j 
/// @param k 
/// @return spining-cube's coordinate of Y
float calcY(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) +
           j * sin(A) * sin(B) *  sin(C) + k * cos(A) * sin(B) * sin(C) -
           i * cos(B) * sin(C);  
}

/// @brief calcZ
/// @param i 
/// @param j 
/// @param k 
/// @return spining-cube's coordinate of Z
float calcZ(int i, int j, int k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}
