#ifndef CALC_COORDINATE_H
#define CALC_COORDINATE_H
#include <math.h>
#define CUBE_WIDTH 10
#define WIDTH 160
#define HEIGHT 44

// 全局变量声明
extern float zbuffer[];
extern char buffer[];
extern  char BACKGROUND_CHAR;
extern  int PROPORTION;
extern  int FROM_CAM;
extern float X, Y, Z;
extern float A, B, C;
extern int two_dimension_x, two_dimension_y;
extern float depth;
extern float INCREASE;

// 函数声明
float calcX(int x, int y, int z);
float calcY(int x, int y, int z);
float calcZ(int x, int y, int z);
void surface(float cubeX, float cubeY, float cubeZ, char ch);

#endif // CALC_COORDINATE_H
