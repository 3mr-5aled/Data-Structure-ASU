#include <iostream>
#include <deque>
#include "Queue.h"
#include <string>
#include "Queue.cpp"

using namespace std;

struct Task
{
    int ID;
    string name;
};

void TaskOrganizer()
{

    cout << "Welcome to the Task Organizer!" << endl;
    bool Exitflag = false;
    Queue<Task> taskQueue(100);
    while (!Exitflag)
    {
        cout << "Please select an option:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Remove a task" << endl;
        cout << "3. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            Task newTask;
            cout << "Enter task ID: ";
            cin >> newTask.ID;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, newTask.name);
            taskQueue.enqueue(newTask);
            cout << "Task added!" << endl;
            break;
        }
        case 2:
        {
            if (!taskQueue.isEmpty())
            {
                Task removedTask = taskQueue.Front();
                cout << "Removed task: " << removedTask.ID << " - " << removedTask.name << endl;
                taskQueue.dequeue();
            }
            else
            {
                cout << "No tasks to remove!" << endl;
            }
            break;
        }
        case 3:
        {
            Exitflag = true;
            cout << "Exiting Task Organizer. Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please try again." << endl;
        }
        }
    }
}

int main()
{
    // using my Queue class
    // Task Organizer
    TaskOrganizer();

    // using deque
    deque<Task> taskDeque;
    taskDeque.push_back({1, "Task 1"});
    taskDeque.push_back({2, "Task 2"});
    cout << "Tasks in deque:" << endl;
    for (const auto &task : taskDeque)
    {
        cout << task.ID << " - " << task.name << endl;
    }
    taskDeque.pop_front();
    cout << "Tasks in deque after removing one:" << endl;
    for (const auto &task : taskDeque)
    {
        cout << task.ID << " - " << task.name << endl;
    }
    return 0;
}