#include "libgeometry/functions.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT_CIRCLE 4

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

    if ((pointer = search_digit(pointer, &digit)) == NULL)
        return 4;
    else
        circle[num_circle].y = digit;

    if ((pointer = search_comma(pointer)) == NULL)
        return 5;

    pointer++;

    if ((pointer = search_digit(pointer, &digit)) == NULL)
        return 6;
    else
        circle[num_circle].radius = digit;

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

double Lenght_between_points(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(y1 - x1, 2) + pow(y2 - x2, 2));
}

int Intersection(figure_circle circle_i, figure_circle circle_j, int num_circle)
{
    double lenght, sum_radius;

    for (int i = 0; i < num_circle; i++) {
        for (int j = 0; j < num_circle; j++) {
            if (i != j) {
                sum_radius = fabs(circle_i.radius + circle_j.radius);
                lenght = Lenght_between_points(
                        circle_i.x, circle_i.y, circle_j.x, circle_j.y);
                if (lenght <= sum_radius)
                    return 1;
            }
        }
    }
    return 0;
}
