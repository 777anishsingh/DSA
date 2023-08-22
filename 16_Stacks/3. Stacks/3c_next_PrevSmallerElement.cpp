#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    // left to right ->prev smaller
    for (int i = 0; i < v.size(); i++)
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

    return ans;
}

vector<int> nextSmaller(vector<int> &v)
{

    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    // right to left -> next smaller
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
    return ans;
}

int main()
{

    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans1 = nextSmaller(v);
    cout << "Next smaller element - ";
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }

    vector<int> ans2 = previousSmaller(v);
    cout << endl << "prev smaller element - ";
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    return 0;
}