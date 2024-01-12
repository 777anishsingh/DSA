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

node *buildTree()
{

    int data;
    cout << "Enter the data " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);

    cout << "Enter data for left part " << data << " node " << endl;
    root->left = buildTree();

    cout << "Enter data for right part " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

void printLeftBoundary(node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    cout << root->data << " ";
    if (root->left != NULL)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafNodes(node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printRightBoundary(node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right != NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeafNodes(root->left);
    printLeafNodes(root->right);
    printRightBoundary(root->right);
}

int main()
{

    node *root = buildTree();

    boundaryTraversal(root);

    return 0;
}