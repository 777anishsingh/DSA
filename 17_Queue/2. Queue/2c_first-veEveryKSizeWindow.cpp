#include <bits/stdc++.h>
using namespace std;

void firstNegative(int arr[], int n, int k)
{
    deque<int> q;
    vector<int> ans;

    // process first window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push_back(i);
    }

    // process remaing window
    for (int i = k; i < n; i++)
    {
        // answer of purani window
        if (q.empty())
            cout << 0 << " ";
        else
            cout << arr[q.front()] << " ";

        // out of window element ko remove krdo
        while (!q.empty() && i - q.front() >= k)
        {
            q.pop_front();
        }

        // check current element for insertion
        if (arr[i] < 0)
            q.push_back(i);
    }

    // answer for last window
    if (q.empty())
        cout << 0 << " ";
    else
        cout << arr[q.front()] << " ";
}

int main()
{
    int k = 3;

    int v[] = {12, -1, -7, 8, -15, 30, 16, 28};
    cout << "Neg elements -> ";
    firstNegative(v, 8, k);

    return 0;
}