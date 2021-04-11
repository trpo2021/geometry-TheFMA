#pragma once
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT_CICLE 8

typedef struct {
    double x;
    double y;
    double radius;
    double perimeter;
    double area;
} figure_circle;

double perimeter_circle(figure_circle circle);
double area_circle(figure_circle circle);
int test_circle(char*, char*, char*, figure_circle* circle, int);
