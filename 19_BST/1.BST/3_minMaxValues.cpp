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

node* minValue(node* root){
    if(root==NULL){
        cout<<"No Node Present ";
    }

    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}

node* maxValue(node* root){
    if(root==NULL){
        cout<<"No Node Present ";
    }

    node* temp=root;
    while(temp->right){
        temp=temp->right;
    }
    return temp;
}

int main()
{

    node *root = NULL;
    buildBST(root);
    levelOrderTraversal(root);

    node* minimumValue=minValue(root);
    cout<<"The Minimum Value is: "<<minimumValue->data<<endl;

    node* MaximumValue=maxValue(root);
    cout<<"The Maximum Value is: "<<MaximumValue->data;

    return 0;
}