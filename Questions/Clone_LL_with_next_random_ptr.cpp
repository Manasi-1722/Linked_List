#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
    Node* random;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};


void insertAtTail(Node* &head, Node* &tail, int d)
{
    Node* newNode = new Node(d);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// First Approach - using map
// TC - O(n)   SC - O(n)
Node* cloneLL(Node* head)
{
    // step 1 : create a clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 : create a map n do mapping between all nodes
    unordered_map<Node*, Node*> oldToNew;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL)
    {
        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // step 3 : set random pointers
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL)
    {
        cloneNode->random = oldToNew[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // step 4 : return head
    return cloneHead;
}


// Optimised solution - Changing Links // 
// TC - O(n)   SC - O(1)
Node* copyList(Node* head)
{
    // step 1 : create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 : clone nodes add between original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }
    
    // step 3 : set random pointers

    temp = head;
    while(temp != NULL)
    {
        if(temp->next != NULL)
        {
            temp->next->random = temp->random ?
                temp->random->next : temp->random;
        }  
        temp = temp->next->next;         
    }

    // step 4 : revert changes done in step 2

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL)
    {
        originalNode ->next = cloneNode->next;
        originalNode = originalNode->next;

        if(originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
        
    }

    // step 5 : return ans
    return cloneHead;
}




