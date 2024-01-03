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

int heightOfTree(node *root)
{
    if (root == 0)
        return 0;

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

bool isBalancedBT(node* root){
    if(root==NULL)
        return true;
    
    int LH=heightOfTree(root->left);
    int RH=heightOfTree(root->right);
    int diff=abs(LH-RH);

    bool currNode=(diff<=1);//current node
    bool leftAns=isBalancedBT(root->left);
    bool rightAns=isBalancedBT(root->right);

    return (currNode&&leftAns&&rightAns);

}

int main()
{

    node *root = NULL;
    root = buildTree();

    levelOrderTraversal(root);

    cout << "is it Balanced ? -> " << isBalancedBT(root) << endl;

    return 0;
}