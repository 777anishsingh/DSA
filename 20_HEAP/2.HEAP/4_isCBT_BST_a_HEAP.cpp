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

void storeInorderTrav(node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    storeInorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    storeInorderTrav(root->right, inorder);
}

void replaceUsingPostOrder(node *&root, vector<int> &inorder, int &index)
{
    if (!root)
        return;
//post order traversal se answer niklega
    // LRN
    replaceUsingPostOrder(root->left, inorder, index);
    replaceUsingPostOrder(root->right, inorder, index);
    root->data = inorder[index++];
}

node *CBT_BST_TO_HEAP(node *root)
{
    // store inorder
    vector<int> inorder;
    storeInorderTrav(root, inorder);

    // replace node val with sorted inorder values using post order trav
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);
    return root;
}

void levelOrderTraversal(node *&root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{

    node *root = new node(100);
    root->left = new node(50);
    root->right = new node(150);
    root->left->left = new node(40);
    root->left->right = new node(60);
    root->right->left = new node(110);
    root->right->right = new node(120);
    root->left->left->left = new node(20);

    cout<<"Tree without HEAP property "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    CBT_BST_TO_HEAP(root);
    cout<<"Tree with HEAP property "<<endl;
    levelOrderTraversal(root);

    return 0;
}