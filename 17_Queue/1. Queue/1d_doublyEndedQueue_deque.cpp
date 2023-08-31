#include <bits/stdc++.h>
using namespace std;

//************************************************* DEQUE ************************************************
class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    //**************** PUSH AT REAR *****************
    
    void pushRear(int data)
    {
        // full queue
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue is full" << endl;
            return;
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

    //**************** PUSH AT FRONT *****************
    
    void pushFront(int data)
    {
        // full queue
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue is full" << endl;
            return;
        }

        // single element case -> single element
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = data;
        }

        // circular nature
        else if (front == 0 && rear != size - 1)
        {
            rear = 0;
            arr[front] = data;
        }

        // normal flow
        else
        {
            arr[front--] = data;
        }
    }

    //**************** POP AT FRONT *****************

    void popFront()
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

    //**************** POP AT REAR *****************

    void popRear()
    {
        // is empty
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }

        // single element after removal->queue is empty
        else if (front == rear)
        {
            arr[rear] = -1;
            front = rear = -1;
        }

        // ciruclar nature
        else if (rear == 0)
        {
            front = size - 1;
        }

        // normal flow
        else
        {
            rear--;
        }
    }
};

int main()
{

    return 0;
}