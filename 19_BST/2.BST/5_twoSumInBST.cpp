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

bool twoSum(node *root, int k, vector<int> &inorder)
{
    if (root == NULL)
        return false;
    int start = 0;
    int end = inorder.size() - 1;

    while (start < end)
    {
        if (inorder[start] + inorder[end] == k)
            return true;
        else if (inorder[start] + inorder[end] > k)
        {
            end--;
        }
        else if (inorder[start] + inorder[end] < k)
        {
            start++;
        }
    }
    return false;
}

void inorderTrav(node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrav(root->right, inorder);
}

int main()
{

    node *root = NULL;
    buildBST(root);

    levelOrderTraversal(root);
    cout << endl;

    vector<int> inorder;
    inorderTrav(root, inorder);

    int k;
    cout << "Enter the value of k:  ";
    cin >> k;

    while (k != -1)
    {
        if (twoSum(root, k, inorder))
            cout << "= Sum Found" << endl;
        else
            cout << "= Sum Not Found" << endl;
        cout << endl
             << "Enter the value of k:  ";
        cin >> k;
    }

    return 0;
}
