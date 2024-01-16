#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool checkCBT(node *root)
{
    queue<node *> q;
    q.push(root);
    bool isNull = 0;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            isNull = 1;
        }
        else
        {
            if (isNull)
            {
                return false;
            }
            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(69);

    if (checkCBT(root))
    {
        cout << "This is a Valid CBT" << endl;
    }
    else
    {
        cout << "This is not a Valid CBT" << endl;
    }

    return 0;
}