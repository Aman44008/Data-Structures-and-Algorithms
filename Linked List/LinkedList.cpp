#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *InsertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;    
}


Node *InsertAtEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL)
        return temp;
    
    Node *curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}

void PrintList(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr =  curr->next;
    }
    
}

int main(){

    Node *head = NULL;

    for(int i = 0; i < 3; i++){
        int x;
        cin>>x;
        head = InsertAtBegin(head, x);
    }

    for(int i = 0; i < 3; i++){
        int x;
        cin>>x;
        head = InsertAtEnd(head, x);
    }


    PrintList(head);

    return 0;
}