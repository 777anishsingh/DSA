#include <bits/stdc++.h>
using namespace std;

void reverse_K_Elements(queue<int> &q, int k)
{
    stack<int> s;
    int n = q.size();
    int count = 0;

    if (k <= 0 || k > n)
    {
        return;
    }

    // step1: put K elements of q into stack
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if (count == k)
            break;
    }

    // step2: put K elements from stack to queue
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // step3: push n-k elements fromt queue front to back
    count = 0;
    while (!q.empty() && n - k != 0)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if (count == n - k)
            break;
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverse_K_Elements(q, 4);

    cout << "Queue is -> ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}