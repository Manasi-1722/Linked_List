#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->child = NULL;
    }
};

// traverse
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Input - 10,12,17
// Output - 10->12->17
void insertAtTail(Node *&tail, int d) // adds new node at the end
{
    // create a new node
    Node *temp = new Node(d);

    // point old node's next to new node's data
    tail->next = temp;

    // move tail from old node to new node
    tail = temp;
}

Node *merge(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a && b)
    {

        if (a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }
    if (a)
    {
        temp->child = a;
    }
    else
    {
        temp->child = b;
    }

    return res->child;
}

Node *flattenLinkedList(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    Node *down = head;
    Node *up = head->next;

    // recursive call
    up = flattenLinkedList(up);
    down->next = NULL;


    Node *result = merge(down, up);
    return result;
}

int main()
{

// Don't know to write int main function //
// refer GFG for this 
    return 0;
}


