#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Employee
{
public:
    int id;
    string name;
    double salary;
    int employmentYear;
    Employee(int i, string n, double s, int y)
    {
        id = i;
        name = n;
        salary = s;
        employmentYear = y;
    }
    Employee()
    {
        id = 0;
        name = "";
        salary = 0.0;
        employmentYear = 0;
    };
    void updateSalary(double newSalary)
    {
        salary = newSalary;
    }
    void upgrade(double increasePercentage)
    {
        salary += salary * increasePercentage / 100.0;
    }
};

int main()
{
    unordered_map<int, Employee> employeeMap; // Create an empty unordered_map.
    Employee emp1(1, "Alice", 50000, 2015);
    Employee emp2(2, "Bob", 60000, 2016);
    Employee emp3(3, "Charlie", 55000, 2017);

    employeeMap[emp1.id] = emp1; // Insert employee using operator[].
    employeeMap[emp2.id] = emp2; // Insert employee using operator[].
    employeeMap[emp3.id] = emp3; // Insert employee using operator[].

    int choice;
    cout << "1. Update Salary\n2. Upgrade Salary to all employees\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        int empId;
        double newSalary;
        cout << "Enter employee ID and new salary: ";
        cin >> empId >> newSalary;
        if (employeeMap.find(empId) != employeeMap.end())
        {
            employeeMap[empId].updateSalary(newSalary);
            cout << "Salary updated for employee ID " << empId << endl;
        }
        else
        {
            cout << "Employee not found." << endl;
        }
        break;

    case 2:
        double increasePercentage;
        cout << "Enter salary increase percentage: ";
        cin >> increasePercentage;
        for (auto it : employeeMap)
        {
            it.second.upgrade(increasePercentage);
            cout << "Employee ID " << it.first << " new salary: " << it.second.salary << endl;
        }
        cout << "Salary upgraded for all employees." << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}