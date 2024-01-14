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
    cout << "Enter the Node data ";
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter the Node data ";
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



bool searchInBST(node *root, int target)
{
    if (root == NULL)
        return false;

    // agr root->data hi target ke qual ho
    if (root->data == target)
        return true;
    if (root->data < target)
    {
        return searchInBST(root->right, target);
    }
    else
    {
        return searchInBST(root->left, target);
    }
}

int main()
{

    node *root = NULL;
    buildBST(root);
    levelOrderTraversal(root);

    int target;
    cout << "Enter The Target Value: ";
    cin >> target;
    while (target != -1)
    {
        bool isFound = searchInBST(root, target);

        if (isFound==true)
        {
            cout << "= Found" << endl;
        }
        else
        {
            cout << "= Not Found" << endl;
        }
        cout<<"Enter The Target: ";
        cin >> target;
    }

    return 0;
}