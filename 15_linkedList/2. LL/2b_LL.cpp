#include <bits/stdc++.h>
using namespace std;
//**************************************************************** Insertion Doubly Linked List *******************************************

class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(node *&head) // T.C = O(n) & S.C = O(1)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(node *&head) // T.C = O(n) & S.C = O(1)
{
    int len = 0;
    node *temp = head;

    while ((temp != NULL))
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// 1. **************************************************************Inserting At head of LL************************************************
void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL) // empty LL
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // LL is non empty
    // step1-> create new node
    node *newNode = new node(data);
    // step2-> newnode ke next ko head se connect
    newNode->next = head;
    // step3-> head ke prev ko newNode se connect
    head->prev = newNode;
    // step4-> head ko update krdo
    head = newNode;
}

// 2. **************************************************************Inserting At Tail of LL************************************************
void insertAtTail(node *&head, node *&tail, int data)
{
    if (head == NULL)
    { // LL is empty

        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // LL is non empty
    // step1-> node creation
    node *newNode = new node(data);
    // step2-> tail ke next ko newnode se connect
    tail->next = newNode;
    // step3-> newnode ke prev ko tail se connect
    newNode->prev = tail;
    // step4-> tail ko update kre
    tail = newNode;
}

// 3. **************************************************************Inserting At any position of LL************************************************
void insertAtPosition(node *&head, node *&tail, int data, int position)
{
    if (head == NULL)
    { // LL is empty

        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 1)
    { // insert at head
        insertAtHead(head, tail, data);
        return;
    }

    int length = getLength(head);
    if (position > length)
    { // insert at tail
        insertAtTail(head, tail, data);
        return;
    }

    // insert at middle of LL
    // step1-> find prev & curr acc. to position
    node *prevNode = head;
    int i = 1;
    while (i < position - 1)
    {
        prevNode = prevNode->next;
        i++;
    }
    node *currNode = prevNode->next;

    // step2-> create a node
    node *newNode = new node(data);
    // step3-> prevnode ke next ko newNode se connect
    prevNode->next = newNode;
    // step4-> newNode ke prev ko prevNode se connect
    newNode->prev = prevNode;
    // step5-> currNode ke prev ko newNode se connect
    currNode->prev = newNode;
    // step6-> newNode ke next ko currNode se connect
    newNode->next = currNode;
}

int main()
{
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);

    node *head = first;
    node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;

    insertAtHead(head, tail, 101);
    cout << endl;
    print(head);

    cout << endl;

    insertAtTail(head, tail, 69);
    cout << endl;
    print(head);

    cout << endl;

    insertAtPosition(head, tail, 420, 6);
    cout << endl;
    print(head);

    return 0;
}