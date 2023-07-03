#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sumArray(int arr1[], int arr2[], int size1, int size2)
{

    int size3 = size1 + size2;

    int arr3[size3];
    for (int i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        arr3[i + size1] = arr2[i];
    }
    for (int i = 0; i < size3; i++)
    {
        cout << arr3[i] << " ";
    }
}

int main()
{
    int size1, size2;

    cout << "Enter the size of first array\n";
    cin >> size1;
    int arr1[size1];
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of second array\n";
    cin >> size2;
    int arr2[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    sumArray(arr1, arr2, size1, size2);

    return 0;
}
