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

// traverse
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

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}    



int middle_Node(Node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head->data;
    }

    if(head->next->next == NULL)
    {
        return head->next->data;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }
    return slow->data;
    
    
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);

    print(head);

    insertAtTail(tail, 17);

    print(head);

    // insertAtPosition(head, tail, 3, 14);
    // 10 -> 12 -> 17 
    // ans = 12
    insertAtTail(tail, 19);
    print(head);
    // 10 -> 12 -> 17 -> 19 
    // ans = 17

    insertAtTail(tail, 21);
    print(head);

    insertAtTail(tail, 27);
    print(head);
     
    cout << "Middle element - " << middle_Node(head);
    // print(head);
    return 0;
}