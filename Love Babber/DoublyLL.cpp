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

    ~Node()
    {
        int value = this->data;

        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory free for with data - " << value << endl; 
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

// function which gives length of LL
int getLength(Node* head)
{
    Node* temp = head;
    int len = 0;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
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

void deleteNode(int position, Node* &head, Node* &tail)
{
    // deleting first node 
    if(position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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
        
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtPosition(head, tail, 3, 7);
    print(head);

    deleteNode(1, head, tail);  // delete 1, 2, 4 positions
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}