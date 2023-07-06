#include <bits/stdc++.h>
using namespace std;

/********************************************************************* MERGE SORT **************************************************************************/
/*
void merge(int Originalarr[], int s, int e)
{

    int mid = (s + e) / 2;

    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    // creation of copy of array
    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    // copying of left part of arr
    int OriginalIndex = s;
    for (int i = 0; i < leftLength; i++)
    {
        leftArr[i] = Originalarr[OriginalIndex++];
    }

    // copying of right part of array
    OriginalIndex = mid + 1;
    for (int i = 0; i < rightLength; i++)
    {
        rightArr[i] = Originalarr[OriginalIndex++];
    }

    // merging of the arrays copied above
    int LeftIndex = 0;
    int rightIndex = 0;
    OriginalIndex = s;

    while (LeftIndex < leftLength && rightIndex < rightLength)
    {
        if (leftArr[LeftIndex] <= rightArr[rightIndex])
        {
            Originalarr[OriginalIndex++] = leftArr[LeftIndex++];
        }
        else
        {
            Originalarr[OriginalIndex++] = rightArr[rightIndex++];
        }
    }

    // for remaing left elements
    while (LeftIndex < leftLength)
    {
        Originalarr[OriginalIndex++] = leftArr[LeftIndex++];
    }
    // for remaing right elements
    while (rightIndex < rightLength)
    {
        Originalarr[OriginalIndex++] = rightArr[rightIndex++];
    }
}

void mergeSortNext(int Originalarr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    // left part
    mergeSortNext(Originalarr, s, mid);

    // right part
    mergeSortNext(Originalarr, mid + 1, e);

    // merge two arrays
    merge(Originalarr, s, e);
}

void mergeSort(int Originalarr[], int n)
{
    mergeSortNext(Originalarr, 0, n - 1);
}

int main()
{

    int originalarr[] = {34, 2, 5, 6, 34, 9, 0, 0, 0};
    int n = 9;
    mergeSort(originalarr, n);
    for (int i = 0; i < n; i++)
    {
        cout << originalarr[i] << " ";
    }
}
*/

/********************************************************************* COUNT INVERSIONS **************************************************************************/
// No of inversion most important ==>line no 97 & 112 are important for this

int inversions = 0; // global variables
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
            inversions += mid - left + 1; // this is the main line else is merge sort
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int numberOfInversions(vector<int> &arr, int n)
{
    mergeSort(arr, 0, n - 1);
    return inversions;
}

int main()
{

    vector<int> arr;
    arr.push_back(22);
    arr.push_back(22);
    arr.push_back(16);
    arr.push_back(28);
    arr.push_back(15);
    arr.push_back(19);
    arr.push_back(1);
    arr.push_back(16);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(10);
    arr.push_back(17);
    arr.push_back(28);
    arr.push_back(25);

    cout << "No of inversions are - " << numberOfInversions(arr, arr.size());

    return 0;
}