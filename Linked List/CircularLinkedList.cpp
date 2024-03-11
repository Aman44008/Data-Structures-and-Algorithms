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

Node *insertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return head; 
}

//<---------------- Insert At End In O(n)------------------>

// Node *insertAtEnd(Node *head, int x){
//     Node *temp = new Node(x);
//     if(head == NULL){
//         temp->next = temp;
//         return temp;
//     }
//     Node *curr = head;
//     while(curr->next != head){
//         curr = curr->next; 
//     }
//     curr->next = temp;
//     temp->next = head;
//     return head;
// }

//<---------------- Insert At End In O(1)------------------>

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

//<------------------- Deletion of Head O(n)-------------->

Node *DeleteHeadNode(Node *head){
    if(head == NULL || head->next == NULL) return NULL;
    // if(head->next == NULL){
    //     Node *temp = head;

    //     head = head->next;
    //     delete temp;
    //     return head;
    // }

    Node *curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = head->next;
    delete head;
    return curr->next;
}


//<------------------- Deletion of Head O(1)-------------->

Node *DeleteHead(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head;
    head->next = head->next->next;
    delete temp;
    return head;
}

//<-------------- Delete kth Node from CLL ----------------->

Node* DeleteKthNode(Node* head, int k){
    if(head == NULL) return head;
    if(k==1) return DeleteHead(head);

    Node* curr = head;
    for(int i = 0; i < k - 2; i++)
        curr = curr->next;
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

void PrintList(Node *head){
    if(head == NULL){
        cout<<"NULL"<<endl;
        return;
    }
    //using for loop

    // cout<<head->data<<" --> ";
    // for(Node *curr = head->next; curr != head; curr = curr->next){
    //     cout<<curr->data<<" --> ";
    // }

    //using do while loop
    
    Node *curr = head;
    do{
        cout<<curr->data<<" --> ";
        curr = curr->next;
    }while(curr != head);
    cout<<"NULL"<<endl;
    return;
}

void check(Node *head){
    if(head == NULL) return;

    while(head != NULL){
        cout<<head->data<<" ---> ";
        head = head->next;
    }
}

int main(){

    Node *head = NULL;

    for(int i = 0; i < 5; i++){
        int x;
        cin>>x;
        // head = insertAtBegin(head, x);
        head = insertAtEnd(head, x);
        // PrintList(head);
    }
    PrintList(head);

    // head = DeleteHeadNode(head);

    head = DeleteKthNode(head, 2);

    PrintList(head);
    // head->next = head;
    // PrintList(head);

    // head->next = new Node(20);
    // head->next->next = head;
    // PrintList(head);

    // head->next->next = new Node(30);
    // head->next->next->next = head;
    // PrintList(head);

    // head->next->next->next = new Node(40);
    // head->next->next->next->next = head;

    // check(head);

    return 0;
}