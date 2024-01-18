#include <iostream>
#include <queue>
using namespace std;

class info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    info(int data, int row, int col)
    {
        this->data = data;
        this->rowIndex = row;
        this->colIndex = col;
    }
};

class compare
{
public:
    bool operator()(info *a, info *b)
    {
        return a->data > b->data; // custom comparator
    }
};

void mergreKsortedArrays(int arr[][4], int col, int row, vector<int> &ans)
{
    priority_queue<info *, vector<info *>, compare> pq;

    // process first k elements
    for (int i = 0; i < row; i++)
    {
        int element = arr[i][0];
        info *temp = new info(element, i, 0);
        pq.push(temp);
    }

    while (!pq.empty())
    {
        info *temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        // store element in ans vector
        ans.push_back(topData);

        // next element for the same row, jisme se pop kiya hai abhi
        // use insert bhi to krna hai
        if (topCol + 1 < col)
        {
            // iska mtln row me or element abhi present hai
            info *newInfo = new info(arr[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(newInfo);
        }
    }
}

int main()
{

    int arr[3][4] = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 12, 14}};
    int row = 3;
    int col = 4;
    vector<int> ans;

    mergreKsortedArrays(arr, col, row, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}