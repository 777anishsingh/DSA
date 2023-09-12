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

void postOrderTraversal(node* root){
    if(root==NULL)
        return;

    //LNR
    //1. L - Left Part
    postOrderTraversal(root->left);
    //2. R - Right Part
    postOrderTraversal(root->right);
    //3. N - Current Node Print
    cout<<root->data<<" ";
}
    
int main()
{ 
    
    node *root = NULL;
    root = buildTree();

    postOrderTraversal(root);

    return 0;
}