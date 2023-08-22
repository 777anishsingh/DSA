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

int getLength(node *head)
{
    int len = 0;

    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

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

// ************************************************** 2 pointer or Turtle approach **********************************************************
node *getMiddleNodeTwoPointer(node *&head)
{
    if (head == NULL)
    { // LL is empty
        cout << "LL is Empty" << endl;
        return head;
    }

    if (head->next == NULL)
    { // LL has single element
        return head;
    }

    node *slow = head;
    // node *fast = head;
    node *fast = head->next;

    while (slow != NULL && fast != NULL)
    { // LL has more tha 1 element
        fast = fast->next;
        if (fast != NULL)
        { // runs if fast can go more tha 1 steps
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

// ************************************************** Itterative approach **********************************************************
node *getMiddleNodeIterative(node *&head)
{

    if (head == NULL)
    { // LL is empty
        cout << "LL is Empty" << endl;
        return head;
    }

    if (head->next == NULL)
    { // LL has single element
        return head;
    }
    int length = getLength(head);
    if (length % 2 == 0)
    {
        int evenLength = length / 2;
        // cout<<endl<<"Length of EVEN ->"<<evenLength<<endl;
        node *temp = head;
        while (evenLength-- > 1)
        {
            temp = temp->next;
        }
        return temp;
    }
    else
    {
        int oddLength = (length + 1) / 2;
        // cout<<endl<<"Length of ODD ->"<<oddLength<<endl;
        node *temp = head;
        while (oddLength-- >= 0)
        {
            temp = temp->next;
            --oddLength;
        }
        return temp;
    }
}

int main()
{
    node *head = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);
    node *fifth = new node(50);
    node *sixth = new node(60);
    node *seven = new node(70);
    node *eight = new node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;

    print(head);

    cout << "Middle node using turtle algorith[2 Pointer] approach " << getMiddleNodeTwoPointer(head)->data << endl;
    cout << "Middle node using itterative approach " << getMiddleNodeIterative(head)->data << endl;

    return 0;
}