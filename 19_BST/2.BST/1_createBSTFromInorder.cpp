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

node* BSTFromInorder(vector<int> inorder, int start, int end){
    if(start>end) return NULL;

    //ek case solve kro
    int mid = (start+end)/2;
    int element = inorder[mid];

    //1 case solve krna hai
    node* root = new node(element);

    //baki recursion sambhal lega
    root->left = BSTFromInorder(inorder, start, mid-1);
    root->right = BSTFromInorder(inorder, mid+1, end);

    return root;

}

int main()
{

    vector<int> inorder={10,20,30,40,50,60,70};
    int start = 0;
    int end = inorder.size()-1;

    node* root = BSTFromInorder(inorder, start, end);

    cout<<"The BST from the Inorder Traversal is: "<<endl;
    levelOrderTraversal(root);

    return 0;
}
