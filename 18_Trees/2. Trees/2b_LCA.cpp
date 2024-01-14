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
        // C
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            // D
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        
    }
}

node* lowestCommonAncestor(node* root,node* x,node* y){
    if(root==NULL) return NULL;
    if(root->data==x->data) return x;
    if(root->data==y->data) return y;

    node* leftAns=lowestCommonAncestor(root->left,x,y);
    node* rightAns=lowestCommonAncestor(root->right,x,y);

    if(leftAns==NULL && rightAns==NULL) return NULL;
    else if(leftAns!=NULL && rightAns==NULL) return leftAns;
    else if(rightAns!=NULL && leftAns==NULL) return rightAns;
    else return root;
}

int main()
{

    node *root = NULL;
    root = buildTree();

    cout<<endl;
    levelOrderTraversal(root);

    int x,y;
    cout<<endl<<"Enter the node value of 1st Node: ";
    cin>>x;
    node* p = new node(x);

    cout<<"Enter the node value of 2nd Node: ";
    cin>>y;
    node* q = new node(y);

    node* LCA = lowestCommonAncestor(root,p,q);

    cout<<endl<<"The LCA of the above 2 node is: "<<LCA->data<<endl;

    return 0;
}
