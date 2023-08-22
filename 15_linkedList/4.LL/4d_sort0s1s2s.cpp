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
//********************************************************* with data replacement ***********************************************************
void sortZerOneTwo(node *head)
{
    int zero = 0, one = 0, two = 0;
    node *temp = head;

    // 1. count no of one two and zeros
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;
        if (temp->data == 1)
            one++;
        if (temp->data == 2)
            two++;
        temp = temp->next;
    }
    // 2. fill 0's, 1's, 2's in the original list
    temp = head;

    // fill zeros
    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    // fill ones
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    // fill twos
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

//********************************************************* Without data replacement ***********************************************************
node *sortWithoutDataReplacement(node *&head)
{
    if (head == NULL)
    {
        cout << "LL is Empty " << endl;
        return head;
    }

    if (head->next == NULL)
    {
        cout << "LL has single element " << endl;
        return head;
    }

    // create 3 dummy nodes
    node *zeroHead = new node(-1);
    node *zeroTail = zeroHead;

    node *oneHead = new node(-1);
    node *oneTail = oneHead;

    node *twoHead = new node(-1);
    node *twoTail = twoHead;

    // traverse the original LL
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        { // take the zero node
            node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            

            // append the zero node in zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
            // delete temp;
        }

        else if (curr->data == 1)
        {
            // take the zero node
            node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            

            // append the zero node in zeroHead LL
            oneTail->next = temp;
            oneTail = temp;
            // delete temp;
        }

        else if (curr->data == 2)
        {
            // take the zero node
            node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            

            // append the zero node in zeroHead LL
            twoTail->next = temp;
            twoTail = temp;
            // delete temp;
        }
    }

    // ab yaha pr, zero one and two teeno LL ready h

     // remove zero wali dummy nodes
    node *temp1 = zeroHead;
    zeroHead = zeroHead->next;
    temp1->next = NULL;
    delete temp1;
    
    // modify one wali list
    node *temp2 = oneHead;
    oneHead = oneHead->next;
    temp2->next = NULL;
    delete temp2;

    // modify two wali list
    node *temp3 = twoHead;
    twoHead = twoHead->next;
    temp3->next = NULL;
    delete temp3;

    // join list
    if (oneHead != NULL)
    {
        // one wali list is non empty
        zeroTail->next = oneHead;
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    {
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }
   
    // return head of modifies linked list
    return zeroHead;
}

int main()
{

    node *head = new node(0);
    node *second = new node(1);
    node *third = new node(0);
    node *fourth = new node(2);
    node *fifth = new node(0);
    node *sixth = new node(1);
    // node *seven = new node(70);
    // node *eight = new node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    // sixth->next = seven;
    // seven->next = eight;

    cout << "Unsorted input LL: ";
    print(head);
    cout << endl;

    // sortZerOneTwo(head);
    // node* curr=NULL;
    cout << "sorted output LL: ";
    head = sortWithoutDataReplacement(head);
    print(head);
    cout << endl;

    return 0;
}