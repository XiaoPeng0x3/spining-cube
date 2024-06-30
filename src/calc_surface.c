#include "calc_coordinate.h"
static int index = 0;
// 计算每个表面上的值
float DEEPTH;
void surface(float i, float j, float k, char ch) {
    // 根据变换函数求出变换后的坐标
    X = calcX(i, j, k);
    Y = calcY(i, j, k);
    Z = calcZ(i, j, k) + FROM_CAM;

    // 开始想办法压缩到二维平面里面
    // 使用z-suffer算法，目的就是根据z值去进行压缩
    DEEPTH = 1 / Z;
    // 假设压缩后的二维坐标为 two_dimension_x, two_dimension_y
    two_dimension_x = (int) (WIDTH / 2 + PROPORTION * DEEPTH * X * 2); // 变大可以获取更好的视野
    two_dimension_y = (int) (HEIGHT / 2 + PROPORTION * DEEPTH * Y);
    // 然根据这个坐标来进行判断
    index = two_dimension_x + two_dimension_y * WIDTH;
    // 数组不越界
    if (index >= 0 && index < WIDTH * HEIGHT) {
        // z- buffer算法，z小的遮挡z大的
        if (DEEPTH > zbuffer[index]) {
            // 被遮挡
            zbuffer[index] = DEEPTH;
            buffer[index] = ch;
        }
    }
}