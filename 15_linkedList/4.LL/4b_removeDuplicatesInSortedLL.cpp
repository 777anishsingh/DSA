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
    cout << endl;
}

void removeDuplicates(node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }

    if (head->next == NULL)
    {
        cout << "LL has single node" << endl;
        return;
    }

    // LL with more than 1 node

    node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            node *temp = curr->next;
            // equal
            curr->next = curr->next->next;

            // delete node
            temp->next = NULL;
            delete temp;
        }
        else
        { // not equal
            curr = curr->next;
        }
    }
}

int main()
{

    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(2);
    node *fourth = new node(3);
    node *fifth = new node(3);
    node *sixth = new node(4);
    // node *seven = new node(70);
    // node *eight = new node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    // sixth->next = seven;
    // seven->next = eight;

    cout << "Input LL: ";
    print(head);
    cout << endl;

    removeDuplicates(head);
    cout << "Output LL: ";
    print(head);

    return 0;
}