#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Employee
{
public:
    int id;
    string name;
    int year;
    double salary;

    Employee(int i, string n, double s, int y)
    {
        name = n;
        id = i;
        salary = s;
        year = y;
    }
    Employee()
    {
        name = "";
        id = 0;
        salary = 0;
        year = 0;
    }
    void updateSalary(double newSalary);
    void Upgrade(float increase);
};