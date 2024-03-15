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

Node *ReverseLLMethodOne(Node *head){
    if(head == NULL && head->next == NULL){
        return head;
    }

    vector<int> vec;
    for(Node *curr = head; curr != NULL; curr= curr->next){
        vec.push_back(curr->data);
    }

    for(Node *curr = head; curr != NULL; curr = curr->next){
        curr->data = vec.back();
        vec.pop_back();
    }
    return head;
}

void printList(Node *head){
    if(head == NULL) cout<<"NULL";

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
    
    head = ReverseLLMethodOne(head);
    cout<<"Reversed Linked List :- "<<endl;
    printList(head);

    return 0;
}