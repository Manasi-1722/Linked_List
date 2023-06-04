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

// Using Map Approach
// TC - O(n)   SC - O(n)

bool detectLoop(Node* head)
{
    if(head == NULL)
        return false;

    map<Node*, bool> visited;
    
    Node* temp = head;

    while(temp != NULL)
    {
        if(visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    } 

    return false;  
}


// Optimal Solution 
// TC - O(n)   SC - O(1)
Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast)
        {
            cout << "Present at - " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}


Node* getStartingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}


void removeLoop(Node* head)
{
    if(head == NULL) 
    {
        return;
    } 
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
    while(temp->next != startOfLoop)
    {
        temp = temp->next;
    }  
    temp->next = NULL; 

}

int main()
{
    Node* node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;


    // head & tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtTail(tail, 12);

    print(head);

    insertAtTail(tail, 17);

    print(head);

    insertAtTail(tail, 22);

    print(head);

    // cout << "Head - " << head->data << endl;
    // cout << "Tail - " << tail->data << endl;

    tail->next = head->next;
    // print(head);

    // if(detectLoop(head))
    // {
    //     cout << "Cycle is present" << endl;
    // }
    // else 
    // {
    //     cout << "No cycle is present" << endl;
    // }
 
    if(floydDetectLoop(head) != NULL)
    {
        cout << "Cycle is present" << endl;
    }
    else 
    {
        cout << "No cycle is present" << endl;
    }

    Node* loop = getStartingNode(head);
    cout << "Loop starts at " << loop->data << endl;

    removeLoop(head);
    print(head);

    return 0;
}