#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};

class info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    info(int data, int row, int col)
    {
        this->data = data;
        this->rowIndex = row;
        this->colIndex = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->val > b->val; // custom comparator
    }
};

node *mergreKsortedArrays(vector<node *> &ll)
{
    priority_queue<node *, vector<node *>, compare> pq;

    for (int i = 0; i < ll.size(); i++)
    {
        node *tempHead = ll[i];
        if (tempHead)
            pq.push(tempHead);
    }

    node *head = NULL;
    node *tail = NULL;

    while (!pq.empty())
    {
        node *topNode = pq.top();
        pq.pop();

        if (head == NULL)
        {
            head = topNode;
            tail = topNode;
            if (tail->next)
                pq.push(tail->next);
        }
        else
        {
            tail->next = topNode;
            tail = topNode;
            if (tail->next)
                pq.push(tail->next);
        }
    }
    return head;
}

void printLL(node *head)
{
    node *temp = head;

    cout << "The Sorted Merged LL is: ";
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{

    node *head1 = new node(1);
    head1->next = new node(4);
    head1->next->next = new node(5);
    head1->next->next->next = NULL;

    node *head2 = new node(1);
    head2->next = new node(3);
    head2->next->next = new node(4);
    head2->next->next->next = NULL;

    node *head3 = new node(2);
    head3->next = new node(6);
    head3->next->next = NULL;

    vector<node *> arr{head1, head2, head3};

    node *head = mergreKsortedArrays(arr);

    printLL(head);

    return 0;
}