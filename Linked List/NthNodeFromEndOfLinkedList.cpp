#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

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


// Method 1 (Using the length of Linked List)
void NthNodeFromEndMethod1(Node *head, int n){
    if(head == NULL) return ; // if linked list is empty
    
    int len = 0;
    for(Node *curr = head; curr != NULL; curr = curr->next){
        len++;
    }

    if(len < n) return; // if length of linked list is less than n

    Node *curr = head;
    for(int i = 1; i < len-n+1; i++){
        curr = curr->next;
    }
    cout<<curr->data;
}

// Method2(using TWo Pointer Approach)
void NthNodeFromEndMethod(Node *head, int n){
    if(head == NULL) return;
    Node *fast = head;
    for(int i = 0; i < n; i++){
        if(fast == NULL) return;

        fast = fast->next;
    }

    Node *slow = head;

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    cout<<"-->"<<slow->data;
}


int main(){

    Node *head = NULL;

    for(int i = 0; i < 4; i++){
        int x ;
        cin>>x;
        head = InsertAtEnd(head, x);
    }
    int n;
    cin>>n;
    NthNodeFromEndMethod(head, n);

    return 0;
}