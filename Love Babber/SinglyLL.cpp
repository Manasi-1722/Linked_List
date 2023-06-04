#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;

        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory free for - " << value << endl; 
    }
    
};


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

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    // initialize temp to head and than traverse
    Node* temp = head;
    int cnt = 1;
    // traverse
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
    // creating new node for d
    Node* nodeToInsert = new Node(d);

    // new node's next should point temp's node
    nodeToInsert->next = temp->next;

    // temp's next should point to new node
    temp->next = nodeToInsert;
}


void deleteNode(int position, Node* &head, Node* &tail)
{
    // deleting first node 
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    // deleting middle n last node 
    else 
    {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // condition to update tail 
        if(curr->next == NULL)
        {
            tail = prev;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node* node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;


    // head & tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtTail(tail, 12);

    print(head);

    insertAtTail(tail, 17);

    print(head);

    insertAtPosition(head, tail, 3, 14);

    print(head);

    cout << "Head - " << head->data << endl;
    cout << "Tail - " << tail->data << endl;

    deleteNode(4, head, tail);
    print(head);

    cout << "Head - " << head->data << endl;
    cout << "Tail - " << tail->data << endl;

    insertAtPosition(head, tail, 4, 20);

    print(head);

    cout << "Head - " << head->data << endl;
    cout << "Tail - " << tail->data << endl;
    
    return 0;
}