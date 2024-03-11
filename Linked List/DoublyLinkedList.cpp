#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *pre;
    Node(int x){
        data = x;
        next = NULL;
        pre = NULL;
    }
};

Node *InsertAtBegining(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = head;
        temp->pre = head;
        return temp;
    }
    temp->next = head;
    head->pre = temp;
    return temp;
}

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
    temp->pre = curr;
    return head;
}

Node *ReverseDLL(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL, *curr = head;
    while(curr != NULL){
        prev = curr->pre;
        curr->pre = curr->next;
        curr->next = prev;
        curr = curr->pre;
    }
    return prev->pre;
}

Node *DeleteHead(Node *head){
    if(head == NULL)
        return head;
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    head->pre = NULL;
    delete temp;
    return head; 
}

Node *deleteAtEnd(Node *head){
    if(head == NULL)
        return head;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = NULL;
    delete temp;
    return head;
    
}


void PrintList(Node *head){
    while(head != NULL){
        cout<<head->data<<" --> ";
        head = head->next; 
    }
    cout<<"NULL"<<endl;
}

void PrintListReverse(Node* prev){
    while(prev != NULL){
        cout<<prev->data<<" <-- "
        prev = prev->pre;
    }
    cout<<"NULL"<<endl;
}

int main(){

    Node *head = NULL;
    // Node *tail = head;

    for(int i = 0; i < 3; i++){
        int x;
        cin>>x;
        head = InsertAtBegining(head, x);
        // head = InsertAtEnd(head, x);
        // if(i==0)
        //     tail = head;
    }

    PrintList(head);
    // PrintListReverse(tail);

    head = ReverseDLL(head);
    PrintList(head);

    // head = DeleteHead(head);
    // PrintList(head);

    head = deleteAtEnd(head);
    PrintList(head);

    return 0;
}