#include "rectangle.h"

// The syntax is ClassName::member.
// The ::is called the scope resolution operator
rectangle::rectangle()
{
    width = 0;
    height = 0;
}

rectangle::rectangle(int w, int h)
{
    width = w;
    height = h;
}

// different approach
// rectangle::rectangle(int w, int h) : width(w), height(h) {};

float rectangle::area()
{
    return width * height;
}
