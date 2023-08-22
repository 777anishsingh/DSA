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

node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *nextLL = curr->next;

    while (curr != 0)
    {
        nextLL = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextLL;
    }
    return prev;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *solve(node *&head1, node *&head2)
{
    // step1: reverse the LL

    head1 = reverse(head1);
    head2 = reverse(head2);

    // step2: add the LL

    node *ansHead = NULL;
    node *ansTail = NULL;
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == NULL)
        {
            return head2;
        }

        if (head2 == NULL)
        {
            return head1;
        }

        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;
        carry = sum / 10;

        // create new node for digit
        node *newNode = new node(digit);
        if (ansHead == NULL)
        { // attaching the newNode into answer wali LL
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // jb head1 list ki length head2 list se jada hai
    while (head1 != NULL)
    {
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;

        node *newNode = new node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    // jb head2 list ki length head1 list se jada hai
    while (head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;

        node *newNode = new node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;

        node *newNode = new node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // step3: then reverse again

    ansHead = reverse(ansHead);
    return ansHead;
}

int main()
{

    node *head1 = new node(9);
    node *second1 = new node(9);
    head1->next = second1;

    node *head2 = new node(9);
    node *second2 = new node(9);
    // node *third2 = new node(4);
    head2->next = second2;
    // second2->next = third2;

    node *ans = solve(head1, head2);

    print(ans);

    return 0;
}