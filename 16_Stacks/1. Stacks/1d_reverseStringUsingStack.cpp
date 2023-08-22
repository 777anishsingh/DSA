#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str = "Anish";

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    { // to put every char into stack memory
        s.push(str[i]);
    }
    while (!s.empty())
    { // to print in reverse order LIFO
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}