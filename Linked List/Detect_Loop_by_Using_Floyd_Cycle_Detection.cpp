#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    bool visited;
    Node(int x){
        data = x;
        next = NULL;
    }
};

//<-------------Singly Linked List without Loop ----------->
// With this function there is no loop exists becacause this is
// a singly linked list...
Node *InsertAtEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }

    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = temp;
    return head;
}


//<-----------------Circular singly linked list ------------>
// when we take input with this function there is always exists a loop because
// this is a circular singly linked list..
Node *insertAtEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int t = temp->data;
    temp->data = head->data;
    head->data = t;
    return temp;
}


// Floyd Cycle Detecction
// T.C. = (n + m) ~ O(n);
bool isLoop(Node *head){
    if(head == NULL) return false;
    Node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        } 
    }
    return false;
}


int main(){

    Node *head = NULL;

    for(int i = 0; i < 6; i++){
        int x ;
        cin>>x;
        head = InsertAtEnd(head, x);
    }
    if(isLoop(head)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
 
    return 0;
}