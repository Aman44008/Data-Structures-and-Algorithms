#include<bits/stdc++.h>
using namespace std;

// Structure of LINKED LIST
struct Node
{
    int data;
    Node *next;
    Node(int x){
        data =x;
        next = NULL;
    }
};

// Brute Force or Naive Approach
void MiddleElement(Node *head){
    if(head == NULL) return ;
    int count = 0;
    Node *curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    for(int i = 0; i < count/2; i++){
        curr = curr->next;

    }
    cout<<curr->data;
}
int main(){
    Node *head = NULL;

    for(int i = 0; i < 5; i++){
        int x;
        cin>>x;
        
    }

    return 0;
}