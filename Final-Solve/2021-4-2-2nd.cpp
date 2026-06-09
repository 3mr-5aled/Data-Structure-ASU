#include <iostream>
#include <queue>

using namespace std;

int main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int n = q.size();
    float average;
    float sum;
    while (!q.empty())
    {
        sum += q.front();
        q.pop();
    }
    average = sum / n;

    cout << "average = " << average << endl;

    return 0;
}