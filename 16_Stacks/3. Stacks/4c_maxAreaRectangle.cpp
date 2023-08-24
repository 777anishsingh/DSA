#include <bits/stdc++.h>
using namespace std;

//****************  https://youtu.be/IPT6emqnxg8?si=qLqJHndqhg8FuHNO   ***********************************

vector<int> previousSmallest(vector<int> &v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> nextSmallest(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{

    vector<int> prev = previousSmallest(heights);
    vector<int> next = nextSmallest(heights);

    int getMaxArea = INT_MIN;
    int size = heights.size();

    for (int i = 0; i < heights.size(); i++)
    {
        int len = heights[i];

        if (next[i] == -1)
        {
            next[i] = size;
        }

        int width = next[i] - prev[i] - 1;
        int area = len * width;
        getMaxArea = max(area, getMaxArea);
    }
    return getMaxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{

    int maxi = INT_MIN;
    vector<int> histogram(matrix[0].size(), 0);
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                histogram[j]++;
            }
            else
            {
                histogram[j] = 0;
            }
        }
        maxi = max(maxi, largestRectangleArea(histogram));
    }
    return maxi;
}

int main()
{

    vector<vector<char>> matrix({{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}});

    cout << maximalRectangle(matrix) << endl;

    return 0;
}
