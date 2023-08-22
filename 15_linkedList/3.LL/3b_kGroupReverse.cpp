#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;

    node()
    {
        this->next = 0;
        this->next = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node *&head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    } 
    return len;
}
 
// ************************************************** Reverse in K groups **********************************************************
node *kGroupReverse(node *&head, int k)
{
    if (head == NULL)
    { // LL is empty
        // cout << "LL is Empty" << endl;
        return NULL;
    }

    // if length of LL is less than k group given
    int len = getLength(head);
    if (k > len) // if k group value is greater then LL length
    {
        // cout << "Enter valid value for K" << endl;
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *nextNode = curr->next;
    int count = 0;

    // stepA: operation for first k elements
    while (count < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    // stepB: recursive call
    if (nextNode != NULL)
    {
        // we still have nodes to reverse
        head->next = kGroupReverse(nextNode, k);
    }

    // stepC: return prev as head will now be prev
    return prev;
};

int main()
{
    node *head = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);
    node *fifth = new node(50);
    // node *sixth = new node(60);
    // node *seven = new node(70);
    // node *eight = new node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = sixth;
    // sixth->next = seven;
    // seven->next = eight;

    cout << "The Linked List is -> ";
    print(head);

    head = kGroupReverse(head, 3);
    cout << "The reversed Linked List int K groups is -> ";
    print(head);

    return 0;
}