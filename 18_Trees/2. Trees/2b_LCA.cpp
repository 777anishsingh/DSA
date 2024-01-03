//*************************************************************************** MOST IMPORTANT ****************************************************************

// node* lowestCommonAncestor(node* root,int x,int y){
//     if(root==NULL) return NULL;
//     if(root->data==x->data) return x;
//     if(root->data==y->data) return y;

//     node* leftAns=lowestCommonAncestor(root->left,x,y);
//     node* rightAns=lowestCommonAncestor(root->right,x,y);

//     if(leftAns==NULL && rightAns==NULL) return NULL;
//     else if(leftAns!=NULL && rightAns==NULL) return leftAns;
//     else if(rightAns!=NULL && leftAns==NULL) return rightAns;
//     else return root;

// }