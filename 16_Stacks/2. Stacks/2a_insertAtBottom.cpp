#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int target)
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive call
    solve(s, target);

    // backtracking
    s.push(temp);
}

void insertAtBottom(stack<int> &s)
{
    if (s.empty())
    {
        cout << "Empty stack" << endl;
        return;
    }
    int target = s.top();
    s.pop();

    solve(s, target);
}

int main()
{

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    insertAtBottom(s);

    cout << "New stack is - " << endl;
    while (!s.empty())
    {
        cout << s.top() << " " << endl;
        s.pop();
    }
    cout << endl;

    return 0;
}