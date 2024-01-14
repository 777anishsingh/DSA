#include <iostream>
#include <queue>

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

node *insertIntoBST(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    // its not the first node
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void buildBST(node *&root)
{
    cout << "Enter the Node data: ";
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter the Node data: ";
        cin >> data;
    }
}

void inOrderTraversal(node* root){
    if(root==NULL) return;
//LNR
    inOrderTraversal(root->left);
    cout<< root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node* root){
    if(root==NULL) return;
//NLR
    cout<< root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root==NULL) return;
//LRN
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<< root->data<<" ";
}


int main()
{

    node *root = NULL;
    buildBST(root);

    cout<<"Inorder: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Preorder: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"Postorder: ";
    postOrderTraversal(root);
    cout<<endl;
     
    return 0;
}