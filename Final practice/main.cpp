#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{

    unordered_map<int, Employee> employees;

    Employee e1(123, "Mohamed", 3200, 2005);
    Employee e2(234, "Nour", 5600, 2010);
    Employee e3(345, "Meena", 8900, 2008);

    employees[e1.id] = e1;
    employees[e2.id] = e2;
    employees[e3.id] = e3;

    int opt;
    cout << "Enter option 1 or 2:";
    cin >> opt;
    if (opt == 1)
    {
        int id;
        cout << "enter id:";
        cin >> id;
        employees[id].updateSalary(10000);
    }
    else
    {
        for (auto it = employees.begin(); it != employees.end(); it++)
        {
            (*it).second.Upgrade(10);
            cout << (*it).second.name << " " << (*it).second.salary << endl;
        }
    }

    return 0;
}