#include "Employee.h"

void Employee::updateSalary(double newSalary)
{
    salary = newSalary;
}

void Employee::Upgrade(float increase)
{
    if (2024 - year >= 10)
    {
        salary += salary * increase / 100
    }
}
