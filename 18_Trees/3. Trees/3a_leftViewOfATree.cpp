#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(){

    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    node* root=new node(data);

    cout << "Enter data for left part " << data << " node " << endl;
    root->left=buildTree();

    cout << "Enter data for right part " << data << " node " << endl;
    root->right=buildTree();

    return root;

}

void preOrder(node* root){
    if(root==NULL) return;
//NLR
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(node* root){
    if(root==NULL) return;
//LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

void inOrder(node* root){
    if(root==NULL) return;
//LNR
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);

}

void levelOrderTraversal(node* root){
    if(root==NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    node* temp=q.front();
    q.pop();

    if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
        // cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

}

void leftView(node* root,int level,vector<int>& leftViewArr){
    if(root==NULL) return;

    if(level==leftViewArr.size()){
        leftViewArr.push_back(root->data);
    }
    leftView(root->left,level+1,leftViewArr);
    leftView(root->right,level+1,leftViewArr);
    
}
 
int main(){
    node* root=buildTree();
    levelOrderTraversal(root);

    vector<int> leftViewArr;
    leftView(root,0,leftViewArr);

    cout<<endl;
    for(int i=0;i<leftViewArr.size();i++){
        cout<<leftViewArr[i]<<" ";
    }

    return 0;
}