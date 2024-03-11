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

int searchInList(Node *head, int val){
    if(head == NULL) return -1;
    int count = 1;
    Node *curr = head;
    while(curr != NULL){
        if(val == curr->data)
            return count;
        count++;
        curr= curr->next;
    }
    return -1;
}

int searchInListWithRecursion(Node *head, int val){
    if(head == NULL) return -1;
    if(head->data == val) return 1;
    else{
        int res  = searchInListWithRecursion(head->next, val);
        if(res == -1) return -1;
        else return res+1;
    }
}

void printList(Node *head){
    Node *curr =head;
    while(curr != NULL){
        cout<<curr->data<<" --> ";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;

}

int main(){

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    printList(head);

    cout<<searchInList(head, 10)<<endl;

    cout<<searchInListWithRecursion(head, 30);

    return 0;
}