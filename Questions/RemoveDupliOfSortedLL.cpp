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
};  


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

Node* removeDuplicate(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head;
    while(curr != NULL)
    {
        if((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
        }
        else 
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    Node* node1 = new Node(10);

    // head & tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);

    insertAtTail(tail, 12);

    insertAtTail(tail, 17);

    insertAtTail(tail, 17);

    insertAtTail(tail, 22);

    print(head);

    removeDuplicate(head);

    print(head);
    return 0;
}