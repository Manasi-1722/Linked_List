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

// ############ Non circular LL create code ############ //
// Input - 10,12,17  
// Output - 10->12->17
// void insertAtTail(Node* &tail, int d)  // adds new node at the end 
// {
//     // create a new node
//     Node* temp = new Node(d);

//     // point old node's next to new node's data
//     tail->next = temp;

//     // move tail from old node to new node 
//     tail = temp;
    
// }

// // *** Traverse *** //
// void print(Node* &head)
// {
//     Node* temp = head;

//     while(temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

// }

// ############ Circular LL create code ############ //
void insertNode(Node* &tail, int element, int d)
{
    // empty linked list
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    // assuming that the element is present in the list
    else 
    {
        // non-empty list  
        Node* curr = tail;   // element found -> curr is that element wala node

        while(curr->data != element)
        {
            curr = curr -> next;
        }
        Node* temp = new Node(d);  
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail)
{
    Node* temp = tail;

    if(tail == NULL)
    {
        cout << "Empty";
    } 
    do{
        cout << tail->data << " ";
        tail = tail->next;
    } while(tail != temp);
    cout << endl;
}


bool isCircular(Node* &head)
{
    if(head == NULL)
    {
        return true;
    }

    Node* temp = head->next;
    while(temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if(temp == head)
    {
        return true;
    }

    return false;
}
int main()
{
    // Node* node1 = new Node(10);
    // // head & tail pointed to node1
    // Node* head = node1;
    // Node* tail = node1;

    // print(head);

    // insertAtTail(tail, 12);

    // print(head);

    // insertAtTail(tail, 17);

    // print(head);


    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);
 
    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    if(isCircular(tail))   // non circular put head instead of tail
    {
        cout << "Linked list is circular in nature" << endl;
    }
    else 
    {
        cout << "Linked list is not circular in nature" << endl;
    }


    return 0;
}