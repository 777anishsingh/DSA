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

int successor(node *root, int key)
{
    int succ = -1;
    node *currNode = root;

    while (currNode)
    {
        if (currNode->data > key)
        {
            succ = currNode->data;
            currNode = currNode->left;
        }
        else
        {
            currNode = currNode->right;
        }
    }
    return succ;
}

int predecessor(node *root, int key)
{
    int pred = -1;
    node *currNode = root;

    while (currNode)
    {
        if (currNode->data < key)
        {
            pred = currNode->data;
            currNode = currNode->right;
        }
        else
        {
            currNode = currNode->left;
        }
    }
    return pred;
}

pair<int, int> predecessorSuccessor(node *root, int key)
{
    int succ = successor(root, key);
    int pred = predecessor(root, key);

    return {pred, succ};
}

int main()
{
    node *root = NULL;
    buildBST(root);

    levelOrderTraversal(root);

    cout << "Enter the key value: ";
    int key;
    cin >> key;
    while (key != -1)
    {

        int succ = predecessorSuccessor(root, key).second;
        int pred = predecessorSuccessor(root, key).first;

        cout << endl
             << "The Successor = " << succ << endl;
        cout << "The Predcessor = " << pred << endl;
        cout << endl
             << "Enter the Key Value: ";
        cin >> key;
    }

    return 0;
}
