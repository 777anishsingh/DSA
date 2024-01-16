#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        long long element = nums[i];
        if (element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    return pq.top();
}

int findKthSmallest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        long long element = nums[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    return pq.top();
}

int main()
{
    vector<int> nums{3,7,4,5,6,8,9,10};
    int k = 4;
    cout << "4th Smallest Element in the Array = " << findKthSmallest(nums, k) << endl;
    cout << "4th Largest Element in the Array = " << findKthLargest(nums, k);

    return 0;
}