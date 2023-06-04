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

// First Approach - Replace data 
// TC - O(n)    SC - O(1)
Node* sortList(Node* head)
{
    int zero, one, two = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zero++;
        }
        else if(temp->data == 1)
        {
            one++;
        }
        else if(temp->data == 2)
        {
            two++;
        }

        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        if(zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if(one != 0)
        {
            temp->data = 1;
            one--;
        }
        else if(two != 0)
        {
            temp->data = 2;
            two--;
        }

        temp = temp->next;
    }

    return head;
}


// Second Approach - Replace links
// TC - O(n)    SC - O(1)

void insertAtTails(Node* &tail, Node* curr)
{
    tail->next = curr;
    tail = curr;
}

Node* sortIt(Node* head)
{
    // step 1 : make all pointers
    Node* zeroH = new Node(-1);
    Node* zeroT = zeroH;

    Node* oneH = new Node(-1);
    Node* oneT = oneH;

    Node* twoH = new Node(-1);
    Node* twoT = twoH;


    // step 2 : separate them it different LL
    Node* curr = head;
    while(curr != NULL)
    {
        int value = curr->data;
        if(value == 0)
        {
            insertAtTails(zeroT, curr);
        }
        else if(value == 1)
        {
            insertAtTails(oneT, curr);
        }
        else if(value == 2)
        {
            insertAtTails(twoT, curr);
        }

        curr = curr->next;
    }

    // step 3 : merge them 
    if(oneH->next != NULL )
    {
        zeroT->next = oneH->next;
    }
    else 
    {
        zeroT->next = twoH->next;
    }

    oneT->next = twoH->next;
    twoT->next = NULL;

    // step 4 : steup head
    head = zeroH->next;

    // step 5 : delete dummy nodes
    delete(zeroH);
    delete(oneH);
    delete(twoH);

    return head;
}

int main()
{
    Node* node1 = new Node(0);

    // head & tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);

    insertAtTail(tail, 2);

    insertAtTail(tail, 1);

    insertAtTail(tail, 2);

    insertAtTail(tail, 0);

    cout << "Input - ";
    print(head);

    sortIt(head);

    cout << "Output - ";
    print(head);


    return 0;
}