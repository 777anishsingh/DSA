#include <bits/stdc++.h>
using namespace std;

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