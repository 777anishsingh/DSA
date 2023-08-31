#include <bits/stdc++.h>
using namespace std;

int main()
{
    // creation
    queue<int> q;

    // insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // size
    cout << "size of queue -> " << q.size() << endl;

    // removal
    q.pop();
    cout << "Front element -> " << q.front() << endl;
    cout << "size of queue -> " << q.size() << endl;

    if (q.empty())
    {
        cout << "Q is empty" << endl;
    }
    else
    {
        cout << "Q is not empty" << endl;
    }

    cout << "Front element -> " << q.front() << endl;

    return 0;
}