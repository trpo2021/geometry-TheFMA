#include "libgeometry/functions.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT_CICLE 8

static char* figure_calling(char* pointer, char* end_pointer, char* stroka)
{
    bool flag = 0;
    char figure[] = "circle";
    while (isalpha(*end_pointer) != 0)
        end_pointer++;

    if ((end_pointer - pointer) <= 6) {
        if (strncasecmp(stroka, figure, 6) == 0)
            flag = 1;
    } else if (strncasecmp(stroka, figure, end_pointer - pointer) == 0)
        flag = 1;
    pointer = end_pointer;
    if (flag == 1)
        return pointer;
    else {
        // printf("Expected 'circle'\n");
        return NULL;
    }
}

static char* search_brackets(char* pointer, char sign)
{
    while (*pointer != '\n') {
        if (*pointer == sign) {
            pointer++;
            return pointer;
        }
        if (*pointer == ' ') {
            pointer++;
        } else {
            // printf("expected '%c'\n", sign);
            return 0;
        }
    }
    if (*pointer == '\n') {
        // printf("expected '%c'\n", sign);
        return 0;
    }
    return 0;
}

static char* search_digit(char* pointer, double* digit)
{
    char* end;
    while (isdigit(*pointer) == 0) {
        if (*pointer == ' ')
            pointer++;
        else {
            // printf("ERROR X\n");
            return 0;
        }
    }
    if (isdigit(*pointer) != 0) {
        *digit = strtod(pointer, &end);
        pointer = end;
    }
    return pointer;
}

static char* search_comma(char* pointer)
{
    bool flag = 0;

    while (*pointer != '\n') {
        if ((*pointer != ' ') && (*pointer != ',')) {
            // printf("ERROR: expected ','\n");
            return 0;
        } else if (*pointer == ',') {
            flag = 1;
            break;
        } else
            pointer++;
    }

    if (flag == 0) {
        // printf("ERROR: expected ','\n");
        return 0;
    } else
        return pointer;
}

static char* end_string(char* pointer)
{
    while (*pointer != '\n') {
        if (*pointer != ' ') {
            // printf("ERROR: no items expected\n");
            return 0;
        } else
            pointer++;
    }
    return pointer;
}

int test_circle(
        char* stroka,
        char* pointer,
        char* end_pointer,
        figure_circle* circle,
        int num_circle)
{
    double digit;

    if ((pointer = figure_calling(pointer, end_pointer, stroka)) == NULL)
        return 1;

    if ((pointer = search_brackets(pointer, '(')) == NULL)
        return 2;

    if ((pointer = search_digit(pointer, &digit)) == NULL)
        return 3;
    else
        circle[num_circle].x = digit;

    printf("X = %.2f\n", digit);

    if ((pointer = search_digit(pointer, &digit)) == NULL)
        return 4;
    else
        circle[num_circle].y = digit;

    printf("Y = %.2f\n", digit);

    // new_pointer = pointer;
    if ((pointer = search_comma(pointer)) == NULL)
        return 5;

    pointer++;

    if ((pointer = search_digit(pointer, &digit)) == NULL)
        return 6;
    else
        circle[num_circle].radius = digit;

    printf("Radius = %.2f\n", digit);

    if ((pointer = search_brackets(pointer, ')')) == NULL)
        return 7;

    if (end_string(pointer) == NULL)
        return 8;

    return 0;
}

double perimeter_circle(figure_circle circle)
{
    return 2 * M_PI * circle.radius;
}

double area_circle(figure_circle circle)
{
    return M_PI * pow(circle.radius, 2);
}
