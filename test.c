#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "fast.c"

int main() {
    // size_t rows = 5;
    // size_t cols = 3;
    // size_t rows = 4;
    // size_t cols = 2;
    // signed char a[4][2] = {{2, -11}, {-3, 2}, {1, 3}, {-2, 0}};
    // signed char a[5][3] = {{-119, 77, -56}, {11, 67, -8 }, {-101, -4, 75}, {-5, -22, -38 }, {-83, -104, 28 }};

    size_t rows = 7;
    size_t cols = 3;
    // 7 3
    signed char a[7][3]= {{-14, 17, 27 },{113, 116, 122}, {122, 89, 50} ,{18, 18, 77} ,{0, -25, -121 },{113, -110, -21},{-100, -114, 41} };

 signed char c[7] = {66,-90,-48,118,68,-21,10};
//     5 3
// -119 77 -56 
// 11 67 -8 
// -101 -4 75 
// -5 -22 -38 
// -83 -104 28 
    // signed char c[4] = {3, -5, 4, -3};
    // signed char c[5] = {121, -100, 16, -117, 123};

    // size_t rows = 2;
    // size_t cols = 1;

    // signed char a[2][1] = {56, -71};
    // signed char c[2] = {-94, 65};

// 2
// -94
// 65

//     2 1
// 56 
// -71 
    size_t i;
    size_t j;

//     5
// 121
// -100
// 16
// -117
// 123

    // a = malloc(rows*sizeof(signed char));

    // for (i = 0; i < rows; i++) {
    //     a[i] = malloc(n*sizeof(signed char));
    // }
    
    // printf("Start\n");
    
    // for (i = 0; i < rows; i++) {
    //     for (j = 0; j < cols; j++) {
    //         a[i][j] = i+j;
    //     }
    //     c[i] = i;
    // }
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
