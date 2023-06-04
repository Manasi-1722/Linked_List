#include <bits/stdc++.h>
using namespace std;


// TC - O(N + M)  && SC - O(max(N, M))
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


Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int val)
{
    Node* temp = new Node(val);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}


Node* add(Node *first, Node *second)
{
    int carry = 0;

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if(first != NULL)
        {
            val1 = first->data;
        }

        int val2 = 0;
        if(second != NULL)
        {
            val2 = second->data;
        }
        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create node and add in answer LL
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if(first != NULL)
            first = first->next;
        
        if(second != NULL)
            second = second->next;
    }

    return ansHead;
}

Node *addTwoLists(Node *first, Node *second)
{
    // step 1 : reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step 2 : add two LL
    Node* ans = add(first, second);

    // step 3 : reverse ans LL
    ans = reverse(ans);

    //step 4 :
    return ans;
}

int main()
{

    Node* first = new Node(1);

    // head & tail pointed to node1
    Node *head1 = first;
    Node *tail1 = first;

    insertAtTail(head1, tail1, 4);

    insertAtTail(head1, tail1, 0);

    print(first);

    Node* second = new Node(3);

    // head & tail pointed to node1
    Node *head2 = second;
    Node *tail2 = second;

    insertAtTail(head2, tail2, 3);

    insertAtTail(head2, tail2, 7);

    print(second);

    Node* result = addTwoLists(first, second);
    print(result);


    return 0;
}