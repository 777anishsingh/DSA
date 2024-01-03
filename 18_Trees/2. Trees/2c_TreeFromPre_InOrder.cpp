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

// Normal search - O(n) time complexity
int search(int inOrder[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == element)
            return i;
    }
    return -1;
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

node *constructTreeFromPreAndInorderTraversal(map<int, int> &valueToIndexMap, int preOrder[], int inOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size)
{
    /******** In preorderIndex we always pass by refernce so as not to always start with 0 ********************************************/
    // Base case
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
        return NULL;

    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    node *root = new node(element);

    // element search krna pdega
    //  int position=search(inOrder,size,element); O(n)
    int position = valueToIndexMap[element]; // using map a faster approach O(1)

    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, position - 1, size);
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, size);

    return root;
}

int main()
{

    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    node *root = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the entire Tree " << endl;
    levelOrderTraversal(root);
    return 0;
}