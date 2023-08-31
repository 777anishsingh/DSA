#include <bits/stdc++.h>
using namespace std;

class cirQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    cirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    void push(int data)
    {
        // full queue
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue is full" << endl;
        }

        // single element case -> single element
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }

        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }

        // normal flow
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        // is empty
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }

        // single element after removal->queue is empty
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }

        // ciruclar nature
        else if (front == size - 1)
        {
            front = 0;
        }

        // normal flow
        else
        {
            front++;
        }
    }
};

int main()
{
    cirQueue queue(5);

    queue.push(1);
    queue.push(2);
    queue.push(3);

    queue.pop();
    queue.pop();

    queue.push(4);
    queue.push(5);
    queue.push(6);

    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();

    return 0;

    return 0;
}
