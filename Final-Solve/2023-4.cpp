#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Request
{
public:
    int request_id;
    int importance;
    string request_description;
    char status; // n - new, d - done
    Request() {} // Default constructor
    Request(int id, string description, int imp, char stat = 'n')
    {
        request_id = id;
        request_description = description;
        importance = imp;
        status = stat; // Initialize status to the provided value
    }
};

class HelpDesk
{
public:
    // (request_id, Request)
    unordered_map<int, Request> requests;

    // (importance, request_id)
    priority_queue<pair<int, int>> importance;

    void request_service(int request_id, string request_description, int importance)
    {
        requests[request_id] = Request(request_id, request_description, importance);
        this->importance.push(make_pair(importance, request_id));
    }

    void print_requests()
    {
        for (auto it = requests.begin(); it != requests.end(); it++)
        {
            cout << "Request: " << (it)->second.request_id << " , Description: " << (it)->second.request_description << " , Status: " << (it)->second.status << endl;
        }
    }

    int get_next_request()
    {
        while (!importance.empty())
        {
            int request_id = importance.top().second;
            if (requests[request_id].status == 'n')
            {
                return request_id;
            }
            importance.pop();
        }
        return -1; // No new requests available
    }

    void set_request_status(int request_id, char status)
    {
        if (requests.find(request_id) != requests.end())
        {
            requests[request_id].status = status;
        }
    }
};

int main()
{
    HelpDesk helpDesk;

    helpDesk.request_service(1, "Fix server issue", 1);
    helpDesk.request_service(2, "Fix printer", 1);
    helpDesk.request_service(3, "Fix Phone", 2);
    helpDesk.request_service(4, "Fix Laptop", 3);
    helpDesk.request_service(5, "Fix Mouse", 2);
    helpDesk.request_service(6, "Fix Keyboard", 1);
    helpDesk.request_service(7, "Update software", 3);

    helpDesk.print_requests();

    //  n - new, d - done
    cout << "Next request to process: " << helpDesk.get_next_request() << endl;
    helpDesk.set_request_status(7, 'd');
    cout << "Next request to process: " << helpDesk.get_next_request() << endl;
    helpDesk.set_request_status(4, 'd');
    cout << "Next request to process: " << helpDesk.get_next_request() << endl;

    return 0;
}