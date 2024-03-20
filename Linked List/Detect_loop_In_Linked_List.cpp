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

//<-------------Singly Linked List without Loop ----------->
// With this function there is no loop exists becacause this is
// a singly linked list...
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


// Approach 1: Naive Solution
// T.C. = O(n^2)
// S.C. = O(1)
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
// Approach 2 : Modification in structure of Linked List
// if modification to linked list structure are allowed.
// T.C. = O(n)
bool isLoop_method_two(Node *head){

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