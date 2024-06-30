#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "./calc_coordinate.h"
int main() {
    // clear函数
    printf("\x1b[2J");
    while (true) {
        memset(buffer, BACKGROUND_CHAR, WIDTH * HEIGHT);
        memset(zbuffer, 0, WIDTH * HEIGHT * sizeof(float));
        for (float xStart = -CUBE_WIDTH; xStart < CUBE_WIDTH; xStart += INCREASE) {
            for (float yStart = -CUBE_WIDTH; yStart < CUBE_WIDTH; yStart += INCREASE) {
                surface(xStart, yStart, -CUBE_WIDTH, '.');
                surface(xStart, yStart, CUBE_WIDTH, '#');
                surface(xStart, -CUBE_WIDTH, yStart, '*');
                surface(xStart, CUBE_WIDTH, yStart, '&');
                surface(-CUBE_WIDTH, xStart, yStart, '?');
                surface(CUBE_WIDTH, xStart, yStart, '@');
            }
        }
        printf("\x1b[H");
        
        // 记得换行
        for(int z = 0; z < WIDTH * HEIGHT; z++){
        putchar(z % WIDTH ? buffer[z] : '\n');
      }
        A += 0.005;
        B += 0.005;
        usleep(3000);
    }
}