#include <bits/stdc++.h>
using namespace std;

void insertAtSorted(stack<int> &s, int target)
{

    // base cases
    if (s.empty())
    {
        s.push(target);
        return;
    }
    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertAtSorted(s, target);

    // B.t
    s.push(topElement);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int target = s.top();
    s.pop();
    sortStack(s);

    insertAtSorted(s, target);
}

int main()
{
    stack<int> s;

    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);
    // s.push(60);
    // s.push(70);

    sortStack(s);

    cout << "Sorted stack is - " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}