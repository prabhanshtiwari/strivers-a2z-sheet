#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    queue<int> temp = q;

    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
}