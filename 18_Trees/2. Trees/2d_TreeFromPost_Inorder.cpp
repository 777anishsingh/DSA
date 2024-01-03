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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // used as marker for levelwise printing of the tree

    while (!q.empty())
    {
        // A
        node *temp = q.front();
        // B
        q.pop();

        if (temp == NULL) // checking to make it level
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

// O(1)-T.C time complexity
void createMapping(int inorder[], int size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

node *constructTreeFromPreAndInorderTraversal(map<int, int> &valueToIndexMap, int postOrder[], int inOrder[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int size)
{
    /******** In preorderIndex we always pass by refernce so as not to always start with 0 ********************************************/
    // Base case
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
        return NULL;

    int element = postOrder[postOrderIndex];
    postOrderIndex--;

    node *root = new node(element);

    // element search krna pdega
    //  int position=search(inOrder,size,element); O(n)
    int position = valueToIndexMap[element]; // using map a faster approach O(1)

    /****************************              Due to LRN in post order we write the right subtree first                  **********************************/
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postOrderIndex, position + 1, inOrderEnd, size);

    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, position - 1, size);

    return root;
}

int main()
{

    int inOrder[] = {8,14,6,2,10,4};
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postOrderIndex = 5;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    node *ans = constructTreeFromPreAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the entire Tree " << endl;
    levelOrderTraversal(ans);
    return 0;
}