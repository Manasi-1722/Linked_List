#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;    
    }
};

// traverse a linked list 
void print(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int d)
{
    // condition when head is Null
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else 
    {
        // create a new node
        Node* temp = new Node(d);

        // head's prev is pointed to temp
        head->prev = temp;

        // temp's next is pointed to head
        temp->next = head;

        // update head with temp
        head = temp;
    
    }

}

void insertAtTail(Node* &tail, int d)
{
    // condition when tail is null
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
    }
    else 
    {
        // create a new node
        Node* temp = new Node(d);

        // tail's next is pointed to temp
        tail->next = temp;

        // temp's prev is pointed to tail
        temp->prev = tail;

        // update tail with temp
        tail = temp;

    }

}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // *** Inserting at start *** //
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    // *** Inserting at end *** //
    if(temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // *** Inserting at middle *** // 
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

}

Node* reverseDLL(Node* head)
{

    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL)
    {
        Node* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        
        prev = curr;
        curr = curr->prev;
    }
    
    return prev;

    // *** 2nd method *** // 
    // Node* temp = NULL;
    // Node* curr = head;


    // while(curr != NULL)
    // {
    //     temp = curr->prev;
    //     curr->prev = curr->next;
    //     curr->next = temp;
    //     curr = curr->prev;
    // }

    // if(temp != NULL)
    // {
    //     *head = temp->prev;
    // }
}


int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    // 11 -> 10
    insertAtHead(head, 11);
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtPosition(head, tail, 3, 7);
    print(head);

    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;

    cout << "Reverse - ";
    head = reverseDLL(head);
    print(head);

    


    return 0;
}