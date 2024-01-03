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
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree()
{

    int data;
    cout << "Enter the data " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);

    cout << "Enter data for left part " << data << " node " << endl;
    root->left = buildTree();

    cout << "Enter data for right part " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(node *root)
{
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
                levelOrderTraversal(temp->left);
            if (temp->right)
                levelOrderTraversal(temp->right);
        }
    }
}

void topViewTraversal(node *root)
{
    map<int, int> hdtoMap;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second;

        // if there is no entry for horizontal dist. HD in map,then creste a new entry
        if (hdtoMap.find(hd) == hdtoMap.end())
        {
            hdtoMap[hd] = frontNode->data;
        }

        // child ko dekhna h
        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    cout << "printing the top view " << endl;
    for (auto i : hdtoMap)
    {
        cout << i.second << " ";
    }
}

int main()
{
    node *root = buildTree();
    levelOrderTraversal(root);
    cout << endl;
    topViewTraversal(root);

    return 0;
}