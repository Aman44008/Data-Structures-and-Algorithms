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

Node *InsertAtGivenPosition(Node *head, int x, int pos){
    Node *temp = new Node(x);
    if(pos == 1){
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    int i = 1;
    while(i != pos-1){
        curr = curr->next;
        i++;
    }
    if(curr->next == NULL){
        curr->next = temp;
        return head;
    }
    cout<<"   ll "<<curr->data<<endl;
    temp->next = curr->next;
    cout<<"kkk"<<curr->next->data<<endl;
    curr->next = temp;
    return head;
}

Node *deleteHead(Node *head){
    if(head == NULL)
        return NULL;
    else{
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *deleteTail(Node *head){
    if(head == NULL) return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;

}

void printList(Node *head){
    while(head != NULL){
        cout<<head->data<<" --> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}


int main(){

    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next->next = new Node(50);

    head = InsertAtGivenPosition(head, 20, 5);
    printList(head);
    head = deleteHead(head);
    printList(head);
    head = deleteHead(head);
    printList(head);
    head = deleteHead(head);
    printList(head);
    head = deleteHead(head);
    printList(head);
    head = deleteHead(head);
    printList(head);


    head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next->next = new Node(50);
    head = InsertAtGivenPosition(head, 20, 5);
    printList(head);
    head = deleteTail(head);
    printList(head);
    head = deleteTail(head);
    printList(head);
    head = deleteTail(head);
    printList(head);
    head = deleteTail(head);
    printList(head);
    head = deleteTail(head);
    printList(head);

    return 0;
}