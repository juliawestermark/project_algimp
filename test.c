#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "fast.c"

int main() {
    // size_t rows = 5;
    // size_t cols = 3;
    // signed char a[4][2] = {{2, -11}, {-3, 2}, {1, 3}, {-2, 0}};
    // signed char a[5][3] = {{-119, 77, -56}, {11, 67, -8 }, {-101, -4, 75}, {-5, -22, -38 }, {-83, -104, 28 }};

    // size_t rows = 7;
    // size_t cols = 3;
    // signed char a[7][3]= {{-14, 17, 27 },{113, 116, 122}, {122, 89, 50} ,{18, 18, 77} ,{0, -25, -121 },{113, -110, -21},{-100, -114, 41} };
    // signed char c[7] = {66,-90,-48,118,68,-21,10};

    // size_t rows = 4;
    // size_t cols = 2;
    // signed char c[4] = {3, -5, 4, -3};
    // signed char c[5] = {121, -100, 16, -117, 123};

    // size_t rows = 2;
    // size_t cols = 1;
    // signed char a[2][1] = {56, -71};
    // signed char c[2] = {-94, 65};

    // size_t rows = 5;
    // size_t cols = 3;
    // signed char c[5] = {51,-77,-18,-18,30};
    // signed char a[5][3] = {{-124, 106, -55 },{103, -94, 115}, {55, -90, 98 },{104, -67, 86} ,{-38, -36, -91}};

    size_t rows = 8;
    size_t cols = 3;
    
    signed char c[8] = {-33,52,-2,79,-6,32,109,63};
    signed char a[8][3] ={{-104, 103, -69 },{-8, 41, -28}, {-60, 25, -80 },{-29, -92, 56 },{-47, -26, -118}, {97, 100, 90 },{19, -76, 88 },{76, -38, -76}}; 

    size_t i;
    size_t j;

    #if 1
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%hhd \t", a[i][j]);
        }
        printf("<= \t %hhd", c[i]);
        printf("\n");
    }
        printf("\n");

    // printf("End\n");
    #endif
    
    if (fm(rows, cols, a, c)) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    return 0;
}
