#include <iostream>
#include <queue>
#include <stack>

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

int countBST(node *root1, node *root2, int key)
{
    stack<node *> s1, s2;
    node *a = root1;
    node *b = root2;
    int ans = 0;

    while (1)
    {
        while (a)
        {
            s1.push(a);
            a = a->left;
        }

        while (b)
        {
            s2.push(b);
            b = b->right;
        }

        if (s1.empty() || s2.empty())
        {
            break;
        }

        auto aTop = s1.top();
        auto bTop = s2.top();

        int sum = aTop->data + bTop->data;

        if (sum == key)
        {
            ans++;
            s1.pop();
            s2.pop();
            a = aTop->right;
            b = bTop->left;
        }

        else if (sum < key)
        {
            s1.pop();
            a = aTop->right;
        }
        else
        {
            s2.pop();
            b = bTop->left;
        }
    }
    return ans;
}

int main()
{
    node *root1 = NULL;
    buildBST(root1);
    levelOrderTraversal(root1);

    cout << endl;

    node *root2 = NULL;
    buildBST(root2);
    levelOrderTraversal(root2);

    cout << endl
         << "Enter the Value of The Key: ";
    int key;
    cin >> key;

    while (key != -1)
    {
        int ans = countBST(root1, root2, key);
        if (ans)
            cout << "The pairs found = " << ans << endl;
        else
            cout << "Pair Not Found ";

        cout << endl
             << "Enter the Value of The Key: ";
        cin >> key;
    }

    return 0;
}
