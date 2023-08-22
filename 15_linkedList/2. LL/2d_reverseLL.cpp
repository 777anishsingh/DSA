#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        this->data = 0;
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
}

void insertAtHead(node *&tail, node *&head, int data) // head passed by refernce to avoid returning of head
{
    // if LL is empty
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step.1 -> Creation of new node
    node *newNode = new node(data);

    // step.2 -> set next of node to head
    newNode->next = head;

    // step.3 -> update head
    head = newNode;
}

void insertAtTail(node *&tail, node *&head, int data)
{
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step1. -> create a new node
    node *newNode = new node(data);

    // step2. -> Set tail-> next to newNode
    tail->next = newNode;

    // step3. -> set tail equal to newNode
    tail = newNode;
}

int findLength(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(node *&tail, node *&head, int data, int position)
{
    if (head == NULL)
    { // check empty LL
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step1 -> Find the position
    if (position == 0)
    { // if we insert at head or 0th position
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head); // if we insert at head or end position
    if (position >= len)
    {
        insertAtTail(tail, head, data);
        return;
    }

    int i = 1;
    node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    node *curr = prev->next;

    // step2 -> create a new node;
    node *newNode = new node(data);

    // step3 -> set newNode's next to current node
    newNode->next = curr;

    // step4 -> set prev node's next to newNode
    prev->next = newNode;
}

node *reverseRecursive(node *&prev, node *&curr)
{
    if (curr == NULL)
    {
        // LL is reversed
        return prev;
    }

    // 1 case solve a baki recursive call
    node *nextNode = curr->next;
    curr->next = prev;

    return reverseRecursive(curr, nextNode); // curr sent as previous value and forward sent as current value of node
}

node *reverseUsingLoop(node *&head)
{
    node *prev = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertAtHead(tail, head, 30);
    insertAtHead(tail, head, 20);
    insertAtHead(tail, head, 10);

    insertAtTail(tail, head, 40);

    cout << "The linked list-> ";
    print(head);
    cout << endl;

    // using recursion
    node *prev = NULL;
    node *curr = head;
    head = reverseRecursive(prev, curr);
    cout << endl;
    cout << "The reversed using recursion linked list-> ";
    print(head);
    cout << endl;

    // using loop
    head = reverseUsingLoop(head);
    cout << endl;
    cout << "The reversed using loop linked list-> ";
    print(head);
    cout << endl;

    return 0;
}