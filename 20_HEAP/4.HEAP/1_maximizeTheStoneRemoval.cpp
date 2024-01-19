#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> maxHeap;

    for (int i = 0; i < piles.size(); i++)
    {
        maxHeap.push(piles[i]);
    }

    while (k--)
    {
        int topElement = maxHeap.top();
        maxHeap.pop();

        topElement = topElement - floor(topElement / 2);
        maxHeap.push(topElement);
        ;
    }

    int sum = 0;
    while (!maxHeap.empty())
    {
        sum += maxHeap.top();
        maxHeap.pop();
    }
    return sum;
}

int main()
{
    vector<int> piles{4, 3, 6, 7};
    int k = 3;
    cout << "The max sum after the removal of the piles after remvoval of the stone = " << minStoneSum(piles, k);

    return 0;
}