#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Request
{
    int id;
    string description;
    int importance;
    char status;
};

unordered_map<int, Request> request_table;
queue<int> high_priority_requests;
queue<int> medium_priority_requests;
queue<int> low_priority_requests;
vector<int> request_order;

void request_service(int request_id, string request_description, int importance)
{
    Request request;
    request.id = request_id;
    request.description = request_description;
    request.importance = importance;
    request.status = 'n';

    request_table[request_id] = request;
    request_order.push_back(request_id);

    if (importance == 3)
    {
        high_priority_requests.push(request_id);
    }
    else if (importance == 2)
    {
        medium_priority_requests.push(request_id);
    }
    else
    {
        low_priority_requests.push(request_id);
    }
}

void print_requests()
{
    for (int request_id : request_order)
    {
        const Request &request = request_table[request_id];
        cout << request.id << ' ' << request.status << '\n';
    }
}

int get_next_request()
{
    auto fetch_next = [](queue<int> &requests) -> int
    {
        while (!requests.empty())
        {
            int request_id = requests.front();
            requests.pop();

            auto it = request_table.find(request_id);
            if (it != request_table.end() && it->second.status == 'n')
            {
                it->second.status = 'd';
                return request_id;
            }
        }

        return -1;
    };

    int next_request = fetch_next(high_priority_requests);
    if (next_request != -1)
    {
        return next_request;
    }

    next_request = fetch_next(medium_priority_requests);
    if (next_request != -1)
    {
        return next_request;
    }

    return fetch_next(low_priority_requests);
}

void set_request_status(int request_id, char status)
{
    auto it = request_table.find(request_id);
    if (it != request_table.end())
    {
        it->second.status = status;
    }
}

int main()
{
    request_service(101, "Reset password", 2);
    request_service(102, "System down", 3);
    request_service(103, "Update profile", 1);
    request_service(104, "Cannot login", 3);

    cout << "All requests:\n";
    print_requests();

    cout << "Next request: " << get_next_request() << '\n';
    cout << "Next request: " << get_next_request() << '\n';

    set_request_status(103, 'd');

    cout << "After updates:\n";
    print_requests();

    return 0;
}
