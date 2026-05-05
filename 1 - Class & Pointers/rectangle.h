#pragma once
class rectangle
{
private:
    float width;
    float height;

public:
    rectangle();
    rectangle(int, int);
    float area();
    ~rectangle(void) {};
};

// The interface(.h file) lists the class and it's members(data and functions)
// The implementation(.cpp file) provides implementations of the functions.