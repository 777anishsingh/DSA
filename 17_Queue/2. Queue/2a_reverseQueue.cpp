#include <bits/stdc++.h>
using namespace std;

void reverseUsingStack(queue<int> &q)
{
    stack<int> s;

    // step1: put all elements of q into stack
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    // step2: put all elements from stack to queue
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }
}

void reverseUsingRecursion(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int temp = q.front();
    q.pop();
    reverseUsingRecursion(q);
    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Normal Queue is -> ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseUsingStack(q);

    cout << endl
         << "Queue Reversed using stack is  -> ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseUsingRecursion(q);

    cout << endl
         << "Queue Reversed using Recursion is -> ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}