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

    while (fgets(stroka, sizeof(stroka), stdin)) {
        pointer = stroka;
        end_pointer = stroka;
        Num_Error
                = test_circle(pointer, end_pointer, stroka, circle, num_circle);
        if (Num_Error == 0) {
            printf("Perimeter = %.2f\n",
                   circle[num_circle].perimeter
                   = perimeter_circle(circle[num_circle]));
            printf("Area = %.2f\n",
                   circle[num_circle].area = area_circle(circle[num_circle]));
            num_circle++;
            printf("Data entered correctly\n");
            printf("\n");

        } else {
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
}
