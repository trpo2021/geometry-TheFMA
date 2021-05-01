#include "libgeometry/functions.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT_CIRCLE 8

int main()
{
    char stroka[100];
    char* pointer = stroka;
    char* end_pointer = stroka;
    int num_circle = 0;
    figure_circle circle[COUNT_CIRCLE];
    int Num_Error;
    // int i, j;

    while (fgets(stroka, sizeof(stroka), stdin)) {
        pointer = stroka;
        end_pointer = stroka;
        Num_Error
                = test_circle(pointer, end_pointer, stroka, circle, num_circle);
        if (Num_Error == 0)
            num_circle++;
        else {
            switch (Num_Error) {
            case 1:
                printf("Expected 'circle'\n\n");
                break;
            case 2:
                printf("Expected '('\n\n");
                break;
            case 3:
                printf("Expected X\n\n");
                break;
            case 4:
                printf("Expected Y\n\n");
                break;
            case 5:
                printf("Expected ','\n\n");
                break;
            case 6:
                printf("Expected Radius\n\n");
                break;
            case 7:
                printf("Expected ')'\n\n");
                break;
            case 8:
                printf("No items expected\n\n");
                break;
            }
        }
    }
    printf("\n");
    return 0;

    /*int presence_intersections[num_circle][num_circle];

    for (i = 0; i < num_circle; i++) {
        for (j = 0; j < num_circle; j++) {
            presence_intersections[i][j] = 0;
        }
    }

    for (i = 0; i < num_circle; i++) {
        for (j = 0; j < num_circle; j++) {
            if (i != j)
                presence_intersections[i][j]
                        = Intersection(circle[i], circle[j], num_circle);
        }
    }

    for (i = 0; i < num_circle; i++) {
        printf("%d. circle (%.2f %.2f, %.2f)\n",
               i + 1,
               circle->x,
               circle->y,
               circle->radius);
        printf("Perimeter = %.2f\n",
               circle->perimeter = perimeter_circle(circle[i]));
        printf("Area = %.2f\n", circle->area = area_circle(circle[i]));
        printf("Intersections: \n");
        for (j = 0; j < num_circle; j++) {
            if (presence_intersections[i][j] == 1)
                printf("\t %d. circle\n");
        }
    }*/
}
