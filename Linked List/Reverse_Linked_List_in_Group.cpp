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


// Recursive Approach
// T.C. = O(n)
// Auxilary Space = O(n/k)
Node *Reverse_In_Group_Recusive_Solution(Node *head, int k){
    Node *curr = head, *next = NULL, *prev = NULL;
    int count = 0;
    while(curr!=NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next != NULL){
        Node *new_head = Reverse_In_Group_Recusive_Solution(next, k);
        head->next = new_head;

    }
    return prev;
}


// Iterative Approach
// T.C. = O(n)
// S.C. = O(1)
Node *Reverse_In_Group_Itretive_Solution(Node *head, int k){
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while(curr != NULL){
        Node *first = curr, *prev = NULL;
        int count = 0;
        while(curr != NULL && count < k){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass){
            head = prev;
            isFirstPass = false;
        }
        else{
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
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

    for(int i = 0; i < 8; i++){
        int x ;
        cin>>x;
        head = InsertAtEnd(head, x);
    }

    int k;
    cin>>k;
    printList(head);
    cout<<"After Reversing in group of "<<k<<endl;
    // head =Reverse_In_Group_Recusive_Solution(head, k); // function call for Recursive Approach
    head =Reverse_In_Group_Itretive_Solution(head, k); //function call for Iterative Approach

    printList(head);

 
    return 0;
}