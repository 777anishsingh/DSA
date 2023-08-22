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

node *reverseList(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *nextNode = curr->next;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return true;
    }

    if (head->next == NULL)
    {
        // single node
        return true;
    }

    // 1. find the middle node
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // slow pointer is pointing to middle/slow node

    // 2. reversse ll after middle

    node *reverseLLHead = reverseList(slow->next);

    slow->next = reverseLLHead;

    // 3. start comparison
    node *temp1 = head;
    node *temp2 = reverseLLHead;

    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

int main()
{ 
    node *head = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(30);
    node *fifth = new node(20);
    node *sixth = new node(10);
    // node *seven = new node(70);
    // node *eight = new node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    // sixth->next = seven;
    // seven->next = eight;

    // print(head);
    bool isValidPalindrome = isPalindrome(head);

    if (isValidPalindrome)
    {
        cout << "LL is a valid palidrome" << endl;
    }
    else
    {
        cout << "LL is not a palindrome" << endl;
    }

    return 0;
}