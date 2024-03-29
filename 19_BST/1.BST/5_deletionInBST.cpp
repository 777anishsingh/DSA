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

node *minValue(node *root)
{
    if (root == NULL)
    {
        cout << "No Node Present ";
    }

    node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

node *maxValue(node *root)
{
    if (root == NULL)
    {
        cout << "No Node Present ";
    }

    node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

node *deleetionInBST(node *root, int target)
{
    // target ko dhundo
    // target ko delete kro

    if (root == NULL)
        return NULL;

    if (target == root->data)
    {
        // ab delete krege
        // 1 case ->
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node *childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            node *childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        else
        {
            // a -> left subTree ki max value or right sub tree ka min value
            node *maxi = maxValue(root->left);
            // b -> replacement
            root->data = maxi->data;
            // c -> delete the actual node
            root->left = deleetionInBST(root->left, maxi->data);
        }
    }
    else if (root->data > target)
    {
        root->left = deleetionInBST(root->left, target);
    }
    else
    {
        root->right = deleetionInBST(root->right, target);
    }
    return root;
}

//******************************************** BETTER APPROACH **************************************************
node *deleteWithDiffApproach(node *root, int key)
{
    if (!root)
        return 0;
    if (root->data == key)
    {

        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return 0;
        }
        else if (!root->left)
        {
            auto temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if (!root->right)
        {
            auto temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        else
        {
            // right sub tree ka min nikalo ya to left ke max ko nikalo
            auto rScan = root->right;
            while (rScan->left)
            {
                rScan = rScan->left;
            }
            rScan->left = root->left;
            auto temp = root;
            root = root->right;
            delete temp;
            return root;
        }
    }
    else if (key > root->data)
    {
        root->right = deleteWithDiffApproach(root->right, key);
    }
    else
    {
        root->left = deleteWithDiffApproach(root->left, key);
    }
    return root;
}

int main()
{

    node *root = NULL;
    buildBST(root);
    levelOrderTraversal(root);

    int target;
    cout << "Enter the value to be deleted: ";
    cin >> target;

    while (target != -1)
    {
        root = deleteWithDiffApproach(root, target);
        cout << endl
             << "Printing the level Order Traversal: " << endl;
        levelOrderTraversal(root);
        cout << "Enter the value to be deleted: ";
        cin >> target;
    }

    deleetionInBST(root, target);

    return 0;
}