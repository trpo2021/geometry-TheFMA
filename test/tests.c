#include "ctest.h"
#include <libgeometry/functions.h>
#include <math.h>
#include <stdio.h>

CTEST(test_circle, Error_name)
{
    int num_circle = 1;
    char str[] = {"ccle  (2 9, 7) "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(test_circle, Error_left_bracket)
{
    int num_circle = 1;
    char str[] = {"circle 1 3 , 5) "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 2;

    ASSERT_EQUAL(exp, real);
}

CTEST(test_circle, Error_X)
{
    int num_circle = 1;
    char str[] = {"circle (t 5 , 2) "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 3;

    ASSERT_EQUAL(exp, real);
}

CTEST(test_circle, Error_Y)
{
    int num_circle = 1;
    char str[] = {"circle  (2 , 7) "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 4;

    ASSERT_EQUAL(exp, real);
}

CTEST(test_circle, Error_comma)
{
    int num_circle = 1;
    char str[] = {"circle  (2 9 7) "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 5;

    ASSERT_EQUAL(exp, real);
}

CTEST(test_circle, Error_Radius)
{
    int num_circle = 1;
    char str[] = {"circle  (2 9, ) "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 6;

    ASSERT_EQUAL(exp, real);
}

CTEST(test_circle, Error_right_bracket)
{
    int num_circle = 1;
    char str[] = {"circle  (2 9, 7 "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 7;

    ASSERT_EQUAL(exp, real);
}

CTEST(test_circle, Error_EOF)
{
    int num_circle = 1;
    char str[] = {"circle  (2 9, 7)    TRPO "};
    char* pointer = str;
    char* end_pointer = str;
    figure_circle circle[num_circle];

    int real = test_circle(pointer, end_pointer, str, circle, num_circle);

    int exp = 8;

    ASSERT_EQUAL(exp, real);
}

CTEST(calculations_circle, Perimeter)
{
    figure_circle circle;
    circle.radius = 4;

    double real = perimeter_circle(circle);

    double exp = 25.13274;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(calculation_circle, Area)
{
    figure_circle circle;
    circle.radius = 4;

    double real = area_circle(circle);

    double exp = 50.26548;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(calculation_circle, Side_length)
{
    double x1, y1, x2, y2;
    x1 = 0;
    y1 = 0;
    x2 = 1;
    y2 = 2;
    double real = fabs(Lenght_between_points(x2, x1, y2, y1));

    double exp = 2.236;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(collisions, Circle_collision)
{
    int num_circle = 2;
    figure_circle circle[num_circle];
    circle[0].x = 4;
    circle[0].y = 3;
    circle[0].radius = 5;
    circle[1].x = 4;
    circle[1].y = 4;
    circle[1].radius = 4;

    int real = Intersection(circle[0], circle[1], num_circle);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(collisions, Circle_not_collision)
{
    int num_circle = 2;
    figure_circle circle[num_circle];
    circle[0].x = 56;
    circle[0].y = 48;
    circle[0].radius = 1;
    circle[1].x = 5;
    circle[1].y = 2;
    circle[1].radius = 1;

    int real = Intersection(circle[0], circle[1], num_circle);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}