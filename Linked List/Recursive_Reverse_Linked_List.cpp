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

Node *Revrse_LL_Method_One(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *new_head = Revrse_LL_Method_One(head->next);
    Node *new_tail = head->next;
    new_tail->next = head;
    head->next = NULL;
    return new_head;
}

void printList(Node *head){
    if(head == NULL) cout<<"NULL"<<endl;

    while(head != NULL){
        cout<<head->data<<" --> ";
        head= head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    Node *head = NULL;

    for(int i = 0; i < 4; i++){
        int x ;
        cin>>x;
        head = InsertAtEnd(head, x);
    }
    printList(head);
    head = Revrse_LL_Method_One(head);
    cout<<"Reversed Linked List :- "<<endl;
    printList(head);
 
    return 0;
}