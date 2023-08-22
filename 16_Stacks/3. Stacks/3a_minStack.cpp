#include <bits/stdc++.h>
using namespace std;

class MinStack
{

private:
    vector<pair<int, int>> st;

public:
    // Constructor
    MinStack()
    {
        // Write your code here.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int val)
    {
        if (st.empty())
        {
            pair<int, int> p; //= make_pair(val,val); //stl to make pair
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
        {
            cout << "Empty Stack -> ";
            return -1;
        }

        int popval = st.back().first;
        st.pop_back();
        return popval;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
        {
            cout << "Empty Stack -> ";
            return -1;
        }

        return st.back().first;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin() // T.C = O(1) mission accomplished
    {
        if (st.empty())
        {
            cout << "Empty Stack -> ";
            return -1;
        }

        return st.back().second;
    }
};

int main()
{

    MinStack stack;
    stack.push(34);
    stack.push(20);
    stack.push(30);
    stack.push(4);
    stack.push(100);
    stack.push(70);
    stack.push(30);

    cout << "Poped Value - " << stack.pop() << endl;

    cout << "Top value - " << stack.top() << endl;

    cout << "Min val - " << stack.getMin() << endl;

    return 0;
}