#include<bits/stdc++.h>
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
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int data;
    cout << "Enter the data - " << endl;
    cin >> data;

    if (data == -1)
        return NULL;

    // step1
    node *root = new node(data);

    // step2
    // input for other ends of tree
    cout << "Enter data for left part " << data << " node " << endl;
    root->left = buildTree();

    // step3
    // input for other ends of tree
    cout << "Enter data for right part " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

void inOrderTraversal(node* root){
    if(root==NULL)
        return;

    //LNR
    //1. L - Left Part
    inOrderTraversal(root->left);
    //2. N - Current Node Print
    cout<<root->data<<" ";
    //3. R - Right Part
    inOrderTraversal(root->right);
}

int main()
{

    node *root = NULL;
    root = buildTree();

    inOrderTraversal(root);

    return 0;
}