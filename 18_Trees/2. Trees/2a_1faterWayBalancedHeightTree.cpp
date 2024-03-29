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
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int data;
    cout << "Enter the data - " << endl;
    cin >> data;

    if (data == -1)
        return NULL;

    // step1
    node *root = new node(data);

    // step2
    // input for other ends of tree
    cout << "Enter data for left part " << data << " node " << endl;
    root->left = buildTree();

    // step3
    // input for other ends of tree
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
        // A
        node *temp = q.front();
        // B
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
            // C
            cout << temp->data << " ";
            // D
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

bool isbalanced = true;
    int height(node* root){
        if(!root) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);

        if(isbalanced && abs(lh-rh)>1){
            isbalanced=false;
        }
        return max(lh,rh)+1;
    }


    bool isBalanced(node* root) {
        height(root);
        return isbalanced;
    }

int main()
{

    node *root = NULL;
    root = buildTree();

    levelOrderTraversal(root);

    cout << "is it Balanced ? -> " << isBalanced(root) << endl;

    return 0;
}