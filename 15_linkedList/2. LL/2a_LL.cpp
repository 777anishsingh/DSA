#include <bits/stdc++.h>
using namespace std;
//**************************************************************** Doubly Linked List *******************************************

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

void print(node *&head)  // T.C = O(n) & S.C = O(1)
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

int main()
{
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    print(first);

    return 0;
}