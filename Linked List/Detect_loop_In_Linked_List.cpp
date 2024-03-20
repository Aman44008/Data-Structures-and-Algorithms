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
///<-------------Singly Linked List without Loop ----------->
// Node *InsertAtEnd(Node *head, int x){
//     Node *temp = new Node(x);
//     if(head == NULL){
//         return temp;
//     }

//     Node *curr = head;
//     while(curr->next != NULL){
//         curr = curr->next;
//     }

//     curr->next = temp;
//     return head;
// }


//<-----------------Circular linked list ------------>
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

bool isLoop_method_one(Node *head){
    if(head == NULL){
        return false;
    }

    for(Node *curr = head; curr != NULL; curr = curr->next){
        Node *temp = curr;
        for(Node *curr_new = head; curr_new != temp; curr_new = curr_new->next){
            if(curr_new == temp->next){
                return true;
            }
        }
    }
    return false;
}


int main(){

    Node *head = NULL;

    for(int i = 0; i < 6; i++){
        int x ;
        cin>>x;
        head = insertAtEnd(head, x);
    }
    
    cout<<isLoop_method_one(head);
 
    return 0;
}