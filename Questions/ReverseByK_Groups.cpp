#include <bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int data;
        Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }    
};

// *** Traverse *** //
void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}


// Input - 10,12,17  
// Output - 17->12->10
void insertAtHead(Node* &head, int d)   // adds new node at start    
{
    // create a new node
    Node* temp = new Node(d);

    // point new node's next to head
    temp->next = head;

    // make that new node's data as head now 
    head = temp;

}

// Input - 10,12,17  
// Output - 10->12->17
void insertAtTail(Node* &tail, int d)  // adds new node at the end 
{
    // create a new node
    Node* temp = new Node(d);

    // point old node's next to new node's data
    tail->next = temp;

    // move tail from old node to new node 
    tail = temp;   
}


Node* kReverse(Node* &head, int k)
{
    // base case
    if(head == NULL)
    {
        return NULL;
    }

    // step 1 :- reverse first k grp 
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int cnt = 0;

    while(curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // step 2 :- Recursion 
    if(next != NULL)
    {
        head->next = kReverse(next, k);
    }

    // step 3:- return head of reversed list
    return prev;
}
int main()
{
    int k;
    cin>>k;

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);

    print(head);

    insertAtTail(tail, 17);

    print(head);

    insertAtTail(tail, 22);

    print(head);

    kReverse(head, k);

    print(head);

    return 0;
}