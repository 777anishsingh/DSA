#include <bits/stdc++.h>
using namespace std;
//************************************************** DELETION ********************************************

// 1. ************************ Deletion of a node of LL *************************************

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

void deleteNode(int position, node *&head, node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete, LL is empty " << endl;
        return;
    }

    // 1. delete at starting of LL
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // 2. delete from end of LL
    int len = findLength(head);
    if (position == len)
    {
        // step1 -> find prev
        int i = 1;
        node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        // step2 -> prev ke next ko null krdo
        prev->next = NULL;
        // step3 -> ek temp bnalo
        node *temp = tail;
        // step4 -> tail ko update krdo
        tail = prev;
        // step5 -> delete temp
        delete temp;
        return;
    }

    // 3. Delete from middle of LL

    // step1 -> find prev and curr
    int i = 1;
    node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    node *curr = prev->next;
    // step2 -> update the pointer of prev to next of curr
    prev->next = curr->next;
    // step3 -> put current next to null
    curr->next = NULL;
    // step4 -> delete current
    delete curr;
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    insertAtHead(tail, head, 20);
    insertAtHead(tail, head, 230);
    insertAtHead(tail, head, 60);
    insertAtHead(tail, head, 50);
    insertAtHead(tail, head, 30);

    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 50);

    print(head);
    cout << endl;

    deleteNode(3, head, tail);

    cout << endl;
    print(head);

    return 0;
}
