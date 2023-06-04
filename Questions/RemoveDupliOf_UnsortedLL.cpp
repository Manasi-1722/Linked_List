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
// **** Approach 1 :- Brute force **** //
Node* removeDuplicates(Node* head)
{
    if(head == NULL) return NULL;

    Node* curr = head;
    while(curr != NULL)
    {
        Node* temp = curr;
        while(temp->next != NULL)
        {
            if(curr->data == temp->next->data)
            {
                Node* next = temp->next->next;
                Node* nodeToDel = temp->next;
                delete(nodeToDel);
                temp->next = next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

Node* removeDuplicatesOptimal(Node* head)
{
    if(head == NULL)  return NULL;

    unordered_map<int, bool> visited;
    Node* curr = head;

    while(curr->next != NULL)
    {
        visited[curr->data] = true;

        if(visited[curr->next->data] == true)
        {
            curr->next = curr->next->next;
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

    insertAtTail(tail, 10);

    insertAtTail(tail, 17);

    insertAtTail(tail, 12);

    insertAtTail(tail, 2);

    cout << "Input - ";
    print(head);

    removeDuplicatesOptimal(head);

    cout << "Output - ";
    print(head);

    return 0;
}