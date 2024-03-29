#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    bool visited;
    Node(int x){
        data = x;
        next = NULL;
        visited = false;
    }
};

//<-------------Singly Linked List without Loop ----------->
// With this function there is no loop exists becacause this is
// a singly linked list...
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


//<-----------------Circular singly linked list ------------>
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
    if(head == NULL) return false;

    Node *curr= head;
    while(curr != NULL){
        if(curr->visited == true){
            return true;
        }
        curr->visited = true;
        curr = curr->next;
    }
    return false;
}

// Approach 3: Modification of linked list pointers/reference
// T.C. = O(n)
bool isLoop_method_three(Node *head){
    if(head == NULL) return false;

    Node *temp = new Node(0);
    Node *curr= head;

    while(curr != NULL){
        if(curr->next == NULL){
            return false;
        }
        if(curr->next == temp){
            return true;
        }

        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}

// Approach 4: Hashing
// T.C. = O(n)
// S.C. = O(n)
bool isLoop_method_four(Node *head){
    if(head == NULL) return false;
    unordered_set<Node*> st;
    for(Node *curr= head; curr != NULL; curr = curr->next){
        if(st.find(curr) != st.end()){
            return true;
        }

        st.insert(curr);
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
    if(isLoop_method_four(head)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
 
    return 0;
}