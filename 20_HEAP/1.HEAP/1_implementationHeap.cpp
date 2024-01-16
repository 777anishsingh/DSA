#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
    int *arr;
    int capacity;
    int size;

    heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        // size is showing current no of heap
        size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow " << endl;
            return;
        }

        // size increase kr jaega
        size++;
        int index = size;

        arr[index] = val;

        // take val to its current position
        while (index > 1)
        {
            int parentIndex = index / 2;

            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            // indexing is from 1 therefore it starts from 1
            cout << arr[i] << " ";
        }
    }

    int deleteFromHeap()
    {
        int answer = arr[1];
        // replacement
        arr[1] = arr[size];
        // lasr element ko uski original position se hta do
        size--;
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // now find the largest element
            int largestKaIndex = index;

            // check left child
            if (leftIndex <= size && arr[largestKaIndex] < arr[leftIndex])
            {
                largestKaIndex = leftIndex;
            }
            // vhevk for right child
            if (rightIndex <= size && arr[largestKaIndex] < arr[rightIndex])
            {
                largestKaIndex = rightIndex;
            }

            // if no change
            if (index == largestKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }
        return answer;
    }
};

int main()
{

    heap h(20);
    // insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    // h.insert(69);
    // h.insert(7);

    cout << "Printing the heap content = ";
    h.printHeap();

    int ans = h.deleteFromHeap();
    cout << endl
         << "Deleted Node = " << ans << endl;

    cout << "Printing the heap content after deletion = ";
    h.printHeap();
    return 0;
}