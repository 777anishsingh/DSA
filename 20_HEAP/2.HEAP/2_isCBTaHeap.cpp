#include <iostream>
using namespace std;

class info
{
public:
    int maxVal;
    bool isHeap;
    info(int val, bool isHeap)
    {
        this->maxVal = val;
        this->isHeap = isHeap;
    }
};

class node{
    public:
    int data;
    node* left;
    node*right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

info checkMaxHeap(node *root)
{
    if (root == NULL)
    {
        info temp(INT_MIN,1);

        return temp;
    }
    if (root->left == NULL && root->right == NULL)
    {
        info temp(root->data,1);

        return temp;
    }
    info left = checkMaxHeap(root->left);
    info right = checkMaxHeap(root->right);

    if (root->data > left.maxVal && root->data > right.maxVal && left.isHeap && right.isHeap)
    {
        info ans(root->data,1);

        return ans;
    }
    else{
        info ans(max( left.maxVal,max(right.maxVal,root->data)),0);

        return ans;
    }
}

int main()
{
    node* root=new node(6);
    root->left=new node(5);
    root->right=new node(4);

    root->left->left=new node(3);
    // root->left->right=new node(40);

    // root->right->left=new node(90);

    info res = checkMaxHeap(root);
    cout<<res.maxVal<<endl<<res.isHeap;


    return 0;
}