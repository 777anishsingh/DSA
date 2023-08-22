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

// ************************************************** Check if Loop is present **********************************************************
bool checkForLoop(node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return false;
    }

    node *slow = head;
    node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            // cout << "Loop present" << endl;
            return true;
        }
    }

    return false;
}

// ************************************************** Find the Starting point of Loop **********************************************************
node *stratingOfLoop(node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

// ************************************************** removal of Loop from LL **********************************************************
node *removeLoop(node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }
    node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
    return slow;
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
    node *nine = new node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = third;

    // print(head);
    cout << "Loop is present(1) or Not(0)? -> " << checkForLoop(head);
    cout << endl
         << "Starting point of loop is -> " << stratingOfLoop(head)->data;

    removeLoop(head);
    print(head);

    cout << "Remove loop ? -> " << checkForLoop(head);

    return 0;
}