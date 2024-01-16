#include <iostream>
#include <vector>
using namespace std;

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestKaIndex = index;

    // max of these 3
    if (leftIndex <= n && arr[largestKaIndex] < arr[leftIndex])
    {
        largestKaIndex = leftIndex;
    }

    if (rightIndex <= n && arr[largestKaIndex] < arr[rightIndex])
    {
        largestKaIndex = rightIndex;
    }

    // after these condition largestindex will be pointing towards largest index among three
    if (index != largestKaIndex)
    {
        swap(arr[index], arr[largestKaIndex]);
        // ab recursion smbhal lega
        index = largestKaIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int size)
{
    for (int index = (size / 2); index > 0; index--)
    {
        heapify(arr, size, index);
    }
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{
    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    buildHeap(arr, 6);

    cout << "Heap Content = ";
    for (int i = 1; i <= 6; i++)
    {
        // indexing is from 1 therefore it starts from 1
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, 6);
    cout << "Heap sort = ";
    for (int i = 1; i <= 6; i++)
    {
        // indexing is from 1 therefore it starts from 1
        cout << arr[i] << " ";
    }

    return 0;
}