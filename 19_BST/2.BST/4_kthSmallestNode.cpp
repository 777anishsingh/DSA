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
        cout << "Enter the Node data " << endl;
        cin >> data;
    }
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

int kthSmallest(node *root, int &k)
{
    if (root == NULL)
        return -1;

    // LNR
    // L
    int leftAns = kthSmallest(root->left, k);
    if (leftAns != -1)
        return leftAns;
    // N
    k--;
    if (k == 0)
    {
        return root->data;
    }
    // R
    int rightAns = kthSmallest(root->right, k);
    return rightAns;
}

int main()
{

    node *root = NULL;
    buildBST(root);

    levelOrderTraversal(root);
    cout<<endl;

    int k;
    cout<<"Enter the value of k:  ";
    cin>>k;

    while(k!=-1){
        cout<<"The Value of Kth smallest node is = "<<kthSmallest(root,k)<<endl;
        cout<<endl<<"Enter the value of k:  ";
        cin>>k;
    }

    return 0;
}