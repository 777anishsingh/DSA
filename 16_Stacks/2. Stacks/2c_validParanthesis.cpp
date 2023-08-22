#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // opening braket

        if (ch == '[' || ch == '(' || ch == '{')
        {
            st.push(ch);
        }
        // closing bracket
        else
        {
            if (!st.empty())
            {
                char topCh = st.top();
                if (ch == ')' && topCh == '(')
                { // matching bracket
                    st.pop();
                }

                else if (ch == '}' && topCh == '{')
                { // matching bracket
                    st.pop();
                }

                else if (ch == ']' && topCh == '[')
                { // matching bracket
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string s = "({)}";

    if (isValid(s))
        cout << "Paranthesis is valid " << endl;
    else
        cout << "Not valid Paranthesis " << endl;

    return 0;
}