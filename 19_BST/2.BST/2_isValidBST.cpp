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

node *buildBST()
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
    root->left = buildBST();

    // step3
    // input for other ends of tree
    cout << "Enter data for right part " << data << " node " << endl;
    root->right = buildBST();

    return root;
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

bool solve(node* root, long long lowerBound, long long upperBound){
    if(root==NULL) return true;

    bool condition1 = ( root->data > lowerBound );
    bool condition2 = ( root->data < upperBound );

    bool leftAns = solve(root->left, lowerBound, root->data);
    bool rightAns = solve(root->right, root->data, upperBound);

    return leftAns && rightAns && condition1 && condition2;

    
}

bool isValidBST(node* root){
    long long lowerBound = INT_MIN;
    long long upperBound = INT_MAX;

    bool ans = solve(root, lowerBound, upperBound);

    return ans;

}

int main()
{
    node *root = NULL;
    root = buildBST();


    levelOrderTraversal(root);

    if(isValidBST(root)) cout<<"= Valid BST Found "<<endl;
    else cout<<"= BST not Valid "<<endl;

    return 0;
}