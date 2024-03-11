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

Node *InsertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void PrintList(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){

    Node *head = NULL;
    // head = new Node(40);
    // head = InsertAtBegin(head, 30);
    // head = InsertAtBegin(head, 20);
    // head = InsertAtBegin(head, 10);

    for(int i = 0; i < 3; i++){
        int x;
        cin>>x;
        head = InsertAtBegin(head, x);
    }

    PrintList(head);
    return 0;
}