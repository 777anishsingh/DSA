#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char val;
    int count;

    node(char ch, int cnt)
    {
        this->val = ch;
        this->count = cnt;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->count < b->count; // we have to make max heap on basis of no of count
    }
};

string reorganizeString(string &s)
{
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++; // frequency updation
    }

    priority_queue<node *, vector<node *>, compare> maxHeap;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i])
        {
            node *temp = new node(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";
    while (maxHeap.size() > 1)
    {

        node *firstNode = maxHeap.top();
        maxHeap.pop();
        node *secondNode = maxHeap.top();
        maxHeap.pop();

        ans.push_back(firstNode->val);
        firstNode->count--;
        ans.push_back(secondNode->val);
        secondNode->count--;

        if (firstNode->count > 0)
            maxHeap.push(firstNode);
        if (secondNode->count > 0)
            maxHeap.push(secondNode);
    }

    if (maxHeap.size() == 1)
    {
        node *singleElement = maxHeap.top();
        maxHeap.pop();
        ans.push_back(singleElement->val);
        singleElement->count--;
        if (singleElement->count > 0)
            return "";
    }
    return ans;
}

int main()
{
    string s = "aaabbbb";
    string ans = reorganizeString(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}