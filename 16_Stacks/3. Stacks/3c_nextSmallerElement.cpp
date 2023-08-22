#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];

        // apka answer stack me hai
        while (s.top() > curr)
        {
            s.pop();
        }

        // chota element mil gya ->ans store
        ans[i] = s.top();

        // push lrdo curr val
        s.push(curr);
    }

    cout << "Printing the next smallest element " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}