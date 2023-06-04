#include <bits/stdc++.h>
using namespace std;


// In Circular LL we don't use head pointer 
class Node 
{
    public:
    int data;
    Node* next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory free for with data - " << value << endl;
    }
};

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

void deleteNode(Node* &tail, int value)
{
    // empty list
    if(tail == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    else 
    {
        // non-empty
        // assuming that "value is present in LL"

        Node* prev = tail;
        Node* curr = prev->next;
        
        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        // 1 Node LL
        if(curr == prev)
        {
            tail = NULL;
        }
        // 2 Node 
        else if(tail == curr)
        {
            tail = prev;
        } 

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
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

int main()
{

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);
 /*
    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 7, 8);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    deleteNode(tail, 4);
    print(tail);
 */
    deleteNode(tail, 3);
    print(tail);


    return 0;
}