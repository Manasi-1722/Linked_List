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
void insertAtTail(Node *&tail, int d) // adds new node at the end
{
    // create a new node
    Node *temp = new Node(d);

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

// **** Brute force **** //

// bool checkPalindrome(vector<int> arr)
// {
//     int n = arr.size();
//     int s = 0;
//     int e = n - 1;
//     while (s <= e)
//     {
//         if (arr[s] != arr[e])
//         {
//             return false;
//         }
//         s++;
//         e--;
//     }
//     return true;
// }

// bool isPalindrome(Node *head)
// {
//     vector<int> arr;

//     Node *temp = head;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     return checkPalindrome(arr);
// }


// **** Optimal solution **** //
Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
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

bool isPalindrome(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    // step 1 : 
    Node *middle = getMid(head);

    // step 2 :
    Node *temp = middle->next;
    middle->next = reverse(temp);

    // step 3:
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    // step 4 : optional
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}
int main()
{
    Node *node1 = new Node(10);

    // head & tail pointed to node1
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 12);

    insertAtTail(tail, 11);

    insertAtTail(tail, 11);

    insertAtTail(tail, 19);

    insertAtTail(tail, 10);

    print(head);

    if (isPalindrome(head))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}