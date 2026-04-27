#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Customer
{
    int id;
    string name;
};

void processRequests(queue<Customer> q)
{
    queue<Customer> finalQueue;
    queue<Customer> temp;
    while (!q.empty())
    {
        Customer current = q.front();
        if (current.id % 2 == 0)
            finalQueue.push(current);
        else
            temp.push(current);

        q.pop();
    }

    while (!temp.empty())
    {
        finalQueue.push(temp.front());
        temp.pop();
    }

    DisplayCustomers(finalQueue);
}

void DisplayCustomers(queue<Customer> q)
{
    while (!q.empty())
    {
        Customer customer = q.front();
        cout << "Customer ID: " << customer.id << ", Name: " << customer.name << endl;
        q.pop();
    }
}

int main()
{
    queue<Customer> q;
    q.push({101, "John"});
    q.push({102, "Ahmed"});
    q.push({103, "Bob"});
    q.push({104, "Omar"});
    q.push({105, "Rose"});
    processRequests(q);

    return 0;
}
