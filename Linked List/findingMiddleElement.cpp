#include<bits/stdc++.h>
using namespace std;

// Structure of LINKED LIST
struct Node{
    int data;
    Node *next;
    Node(int x){
        data =x;
        next = NULL;
    }
};

// Insertion at the End of the Linked List
Node *InsertAtEnd(Node *head, int x){
    Node *temp = new Node(x);

    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Brute Force or Naive Approach 
// T.C. O(n + n) ---> As We are accessing linked list element two times.
void MiddleElement(Node *head){
    if(head == NULL) return ;
    int count = 0;
    Node *curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    curr = head;
    for(int i = 0; i < count/2; i++){
        curr = curr->next;

    }
    cout<<curr->data;
}

// Optimize or Fast and Slow Approach
// T.C. O(n)
void MiddleElementOptimize(Node *head){
    if(head == NULL) return ;

    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data<<"\n";
}
int main(){
    Node *head = NULL;

    cout<<"Enter Any five element into LL :- "<<endl;
    for(int i = 0; i < 6; i++){
        int x;
        cin>>x;
        head = InsertAtEnd(head, x);
    }

    MiddleElementOptimize(head); //function call to find middle Element

    return 0;
}