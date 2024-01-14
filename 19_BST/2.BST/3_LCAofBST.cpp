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

node *lowestCommonAncestor(node *root, node *p, node *q)
{
    // base case
    if (root == NULL)
        return NULL;

    // case1: p and q both comes in left subtree of root node
    if (p->data < root->data && q->data < root->data)
    {
        node *leftAns = lowestCommonAncestor(root->left, p, q);
        return leftAns;
    }

    // case1: p and q both comes in right subtree of root node
    else if (p->data > root->data && q->data > root->data)
    {
        node *rightAns = lowestCommonAncestor(root->right, p, q);
        return rightAns;
    }

    // case1: p in left subtree and q in right subtree
    else if (p->data < root->data && q->data > root->data)
    {
        return root;
    }
    else if (p->data > root->data && q->data < root->data)
    {
        return root;
    }
    return root;
}

int main()
{

    node *root = NULL;
    buildBST(root);

    cout<<endl;
    levelOrderTraversal(root);

    int x,y;
    cout<<endl<<"Enter the node value of 1st Node: ";
    cin>>x;
    node* p = new node(x);

    cout<<"Enter the node value of 2nd Node: ";
    cin>>y;
    node* q = new node(y);

    node* LCA = lowestCommonAncestor(root,p,q);

    cout<<endl<<"The LCA of the above 2 node is: "<<LCA->data<<endl;

    return 0;
}