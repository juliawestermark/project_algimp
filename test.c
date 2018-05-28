#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "fast.c"

int main() {
    size_t rows = 4;
    size_t cols = 2;
    signed char a[4][2] = {{2, -11}, {-3, 2}, {1, 3}, {-2, 0}};
    signed char c[4] = {3, -5, 4, -3};
    size_t i;
    size_t j;

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

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%hhd \t", a[i][j]);
        }
        printf("<= \t %hhd", c[i]);
        printf("\n");
    }
        printf("\n");

    // printf("End\n");
    
    if (fm(rows, cols, a, c)) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    return 0;
}
