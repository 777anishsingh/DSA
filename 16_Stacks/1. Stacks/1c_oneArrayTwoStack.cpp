#include <bits/stdc++.h>
using namespace std;

/*************************************************** IMPLEMENT 2 STACKS IN ONE ARRAY *****************************************************/

class Stack
{
private:
    int *arr;
    int top1;
    int top2;
    int size;

public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // functions
    void push1(int data)
    {
        // space not available
        if (top2 - top1 == 1)
        {
            cout << "overflow in stack 1" << endl;
        }
        // space available
        else
        {
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        { // stack empty
            cout << "underflow in stack 1" << endl;
        }
        else
        { // stack is non empty
            arr[top1] = 0;
            top1--;
        }
    }

    void push2(int data)
    {
        // space not available
        if (top2 - top1 == 1)
        {
            cout << "overflow in stack 2" << endl;
        }
        // space available
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == size)
        { // stack is empty
            cout << "underflow in stack 2" << endl;
        }
        else
        { // not empty
            arr[top2] = 0;
            top2++;
        }
    }

    void print()
    {
        cout << endl;
        cout << "top1 " << top1 << endl;
        cout << "top2 " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();

    s.push2(100);
    s.print();
    s.push2(110);
    s.print();
    s.push2(120);
    s.print();
    s.push2(130);
    s.print();
    s.push2(140);

    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();

    s.pop2();
    s.print();
    s.pop2();
    s.print();
    s.pop2();
    s.print();

    return 0;
}