#include <bits/stdc++.h>
using namespace std;

// Q1 - linear search
bool linearSearch(int *arr, int key, int size)
{
    if (size == 0)
        return false;

    if (arr[0] == key)
        return true;
    else
        return linearSearch(arr + 1, key, size - 1);
}

// Q2
bool binarySearch(int *arr, int s, int e, int key)
{
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
        return true;

    else if (arr[mid > key])
        return binarySearch(arr, s, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, e, key);
}

int main()
{

    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;

    int start = 0;
    int end = size - 1;

    int *arr = new int[size];
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the value of key " << endl;
    cin >> key;

    if (/*linearSearch(arr, key, size)*/ binarySearch(arr, start, end, key))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}