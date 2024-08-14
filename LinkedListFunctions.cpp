#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int givdata  , Node* givnext){
        data=givdata;
        next=givnext;
    }
    Node(int givendata){
        data = givendata;
        next=NULL;
    }
};

Node* constructLL(vector <int > &arr) {
        Node *head=new Node(arr[0]);
        Node *mover=head;
        for(int i=1;i<arr.size();i++){
            Node*temp=new Node(arr[i]);
            mover->next=temp;
            mover=temp;
        }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* insertAtHead(int value , Node* head){
    Node *newHead = new Node(value , head);
    return newHead;
}

void insertAtTail(int value , Node* head){
    Node *tail = new Node(value);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=tail;
}

void insertAtPosition(int value , int pos , Node*  head){
    int count=1;
    Node* temp = head;
    Node* prev  = NULL;
    while(temp!=NULL){
        if(count==pos) break;
        prev = temp;
        temp=temp->next;
        count++;
    }
    if(count==pos){
        Node* newNode = new Node(value , temp);
        prev->next=newNode;
    }
    else{
        cout<<"Invalid Position";
    }
}

void insertAfterValue(int value , int nodeval , Node* head){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==value) break;
        temp=temp->next;
    }
    if(temp->data=value){
        Node* newNode= new Node(nodeval , temp->next);
        temp->next=newNode;
    }
    else{
        cout<<"Value not found"<<endl;
    }
}

int LLsize(Node* head){
    Node* temp = head;
    int count=1;
    while(temp!=NULL){
        count++;
    }
    return count;
}

void insertMiddle(int val , Node* head){
    int middle = LLsize(head) /2 ;
    insertAtPosition(middle , val  ,head);
}

void removeValue(int val , Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data==val) break;
        prev=temp;
        temp=temp->next;
    }
    if(temp->data=val){
        prev->next=temp->next;
        delete temp;
    }
    else{
        cout<<"Value not found";
    }
}
int main() {
    vector <int> arr = {1,2,3,5};
    int n = sizeof(arr);
    Node* head = constructLL(arr );
    printLL(head);
    return 0;
