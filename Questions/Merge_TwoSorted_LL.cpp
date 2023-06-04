#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


// *** Traverse *** //
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

void insertAtTail(Node* &head, Node* &tail, int val)
{
    Node* temp = new Node(val);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node* solve(Node* first, Node* second)
{
    // If first list has only one element
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }

    // make pointers
    Node* curr1 = first;
    Node* next1 = curr1->next;

    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL)
    {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // add node in between the node of first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else 
        {
            // go one step ahead 
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL)
            {
                curr1 ->next = curr2;
                return first;
            }
        }
    } 
    return first;
}
Node* mergeSortedLL(Node* first, Node* second)
{
    if(first == NULL)
    {
        return second;
    }

    if(second == NULL)
    {
        return first;
    }


    if(first->data <= second->data)
    {
        return solve(first, second);
    } 
    else 
    {
        return solve(second, first);
    }
}
int main()
{
    Node* first = new Node(1);

    // head & tail pointed to node1
    Node *head1 = first;
    Node *tail1 = first;

    insertAtTail(head1, tail1, 3);

    insertAtTail(head1, tail1, 5);

    print(first);

    Node* second = new Node(2);

    // head & tail pointed to node1
    Node *head2 = second;
    Node *tail2 = second;

    insertAtTail(head2, tail2, 4);

    insertAtTail(head2, tail2, 5);

    print(second);

    Node* result = mergeSortedLL(first, second);
    print(result);


    return 0;
}