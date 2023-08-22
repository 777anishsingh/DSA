#include <bits/stdc++.h>
using namespace std;

/******************************************* stack creation using array **********************************************/

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int(size);
        this->size = size;
        top = -1;
    }

    /******************************************** PUSH FUNCTION **************************************/
    void push(int data)
    {
        if (size - top > 1)
        { // space available
            top++;
            arr[top] = data;
        }
        else
        {
            // space not available
            cout << "Stack overflow" << endl;
        }
    }

    /******************************************** POP FUNCTION **************************************/
    void pop()
    {
        if (top == -1)
        {
            // stack is empty
            cout << "Stack underflow " << endl;
        }
        else
        {
            // stack is non empty
            top--;
        }
    }

    /******************************************** GET TOP FUNCTION **************************************/

    int getTop()
    {
        if (top == -1)
        {
            // stack empty
            cout << "Stack Empty " << endl;
        }
        else
        {
            return arr[top];
        }
        return -1;
    }

    /******************************************** GET SIZE FUNCTION **************************************/

    int getSize()
    {
        return top + 1;
    }

    /******************************************** CHECK IF STACK EMPTY FUNCTION **************************************/

    bool empty()
    {
        if (top == -1)
        { // stack is empty
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(10);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Stack size - " << s.getSize() << endl;
    
    return 0;
}