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
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){

    Node *head = NULL;
    for(int i = 0; i < 5; i++){
        int x;
        cin>>x;
        head = InsertAtEnd(head,x);
    }

    PrintList(head);

    return 0;
}