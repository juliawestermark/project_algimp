#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "fast.c"

int main() {
    size_t rows = 5;
    size_t cols = 3;
    // signed char a[4][2] = {{2, -11}, {-3, 2}, {1, 3}, {-2, 0}};
    signed char a[5][3] = {{-119, 77, -56}, {11, 67, -8 }, {-101, -4, 75}, {-5, -22, -38 }, {-83, -104, 28 }};
//     5 3
// -119 77 -56 
// 11 67 -8 
// -101 -4 75 
// -5 -22 -38 
// -83 -104 28 
    // signed char c[4] = {3, -5, 4, -3};
    signed char c[5] = {121, -100, 16, -117, 123};
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
    #if 0
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
