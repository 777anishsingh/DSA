#include <bits/stdc++.h>
using namespace std;

// Queue Implementation using queue class

class Queue
{
public:
    int *arr;
    int size;
    int rear;
    int front;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return rear - front;
    }
};

int main()
{
    Queue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);
    q.push(55);

    cout << "Size of Queue is -> " << q.getSize() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "Size of Queue after pop operation -> " << q.getSize() << endl;
    cout << "Front element of Queue is -> " << q.getFront() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}