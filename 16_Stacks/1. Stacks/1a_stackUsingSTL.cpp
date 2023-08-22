#include <bits/stdc++.h>
using namespace std;

/**************************************** Creation Using STL  *************************************/

int main()
{

    // creation
    stack<int> st;

    // inserion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // removal
    st.pop();

    // checking element on top
    cout << "Element on top is - " << st.top() << endl;

    // checking size
    cout << "size is - " << st.size() << endl;

    if (st.empty())
    {
        cout << "Stack is empty " << endl;
    }
    else
    {
        cout << "Stack is non empty " << endl;
    }

    return 0;
}