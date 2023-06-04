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

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right)
{
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;

}

Node* mergeSort(Node* head)
{
    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    // find middle element 
    Node* mid = findMid(head);

    // divide LL in two halves and sort them
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // recursive calls 
    left = mergeSort(left);
    right = mergeSort(right);
   
    // merge them and return ans
    Node* ans = merge(left, right);
    return ans;
}

// Node *sortLL(Node *head)
// {
//     // base case
//     if(head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     // find middle element 
//     Node* mid = findMid(head);

//     // divide list in two halves
//     Node* left = head;
//     Node* right = mid->next;
//     mid->next = NULL;

//     // recursive calls 
//     left = sortLL(left);
//     right = sortLL(right);

   
//     Node* result = merge(left, right);
//     return result;
// }


int main()
{
    Node* node1 = new Node(8);

    // head & tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);

    insertAtTail(tail, 3);

    insertAtTail(tail, 1);

    insertAtTail(tail, 7);

    insertAtTail(tail, 0);

    cout << "Input - ";
    print(head);

    mergeSort(head);

    cout << "Output - ";
    print(head);

    return 0;
}


// #include <bits/stdc++.h> 
// /**********************************************************************

//     Following is the class structure of the Node class for reference:

//     class Node{
//     public:
//         int data;
//         Node *next;
//         Node(int data)
//         {
// 	        this->data = data;
// 	        this->next = NULL;
//         }
//     };

// ********************************************************************/

// Node* findMid(Node* head)
// {
//     Node* slow = head;
//     Node* fast = head->next;

//     while(fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// Node* merge(Node* left, Node* right)
// {
//     if(left == NULL)
//     {
//         return right;
//     }
//     if(right == NULL)
//     {
//         return left;
//     }

//     Node* ans = new Node(-1);
//     Node* temp = ans;

//     while(left != NULL && right != NULL)
//     {
//         if(left->data < right->data)
//         {
//             temp->next = left;
//             temp = left;
//             left = left->next;
//         }
//         else
//         {
//             temp->next = right;
//             temp = right;
//             right = right->next;
//         }
//     }

//     while(left != NULL)
//     {
//         temp->next = left;
//         temp = left;
//         left = left->next;
//     }

//     while(right != NULL)
//     {
//         temp->next = right;
//         temp = right;
//         right = right->next;
//     }

//     ans = ans->next;
//     return ans;

// }



