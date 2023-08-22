#include <bits/stdc++.h>
using namespace std;
//**************************************************************** Deletion Doubly Linked List *******************************************

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

void insertAtPosition(node *&head, node *&tail, int &data, int &position)
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

void deleteFromPosition(node *&head, node *&tail, int &position)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    if (head->next == NULL)
    {
        node *temp = head;
        head = NULL;
        delete temp;
        return;
    }
    if (position == 1)
    {
        //************************************************ want to delete the first node ************************************************************
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int length = getLength(head);
    if (position > length)
    {
        cout << "Pleaseenter valid length" << endl;
    }

    //*********************************************************** delete from tail*************************************************
    while (position == length)
    {
        node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    //********************************** delete from middle position******************************************
    // step1
    int i = 1;
    node *left = head;
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }
    node *currNode = left->next;
    node *right = currNode->next;

    // step2
    left->next = right;
    // step3
    right->prev = left;
    // step4
    currNode->prev = NULL;
    // step5
    currNode->next = NULL;
    // step6
    delete currNode;
    return;
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

    //*************************insertion at any position************************************
    int *position1 = new int;
    int *data1 = new int;
    cout << endl
         << "Enter the data value to be added in LL " << endl;
    cin >> *data1;
    cout << "Enter the Position to add new Data " << endl;
    cin >> *position1;

    insertAtPosition(head, tail, *data1, *position1);
    cout << endl;
    print(head);

    cout << endl;

    //*****************************deletion at any position***********************************
    int *position2 = new int; 
    cout << endl
         << "Enter the Position to add new Data " << endl;
    cin >> *position2;

    deleteFromPosition(head, tail, *position2);
    cout << endl;
    print(head);
    cout << endl;

    // free up the heap space
    delete position1;
    delete data1;
    delete position2;

    return 0;
}