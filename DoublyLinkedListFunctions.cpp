#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int givdata  , Node* givnext , Node* givprev){
        data=givdata;
        next=givnext;
        prev=givprev;
    }
    Node(int givendata){
        data = givendata;
        next=NULL;
        prev=NULL;
    }
};

Node* constructDLL(vector <int > &arr) {
        Node *head=new Node(arr[0]);
        Node *mover=head;
        for(int i=1;i<arr.size();i++){
            Node*temp=new Node(arr[i]);
            temp->prev=mover;
            mover->next=temp;
            mover=temp;
        }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* insertAtHead(Node* head , int value){
    Node* newNode = new Node(value);
    if(head==NULL) return newNode;
    newNode->next=head;
    head->prev=newNode;
    return newNode;
}

void insertAtTail(Node* head , int value){
    Node* newNode = new Node(value);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteNode(Node* head , int value){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==value){
            break;
        }
        temp=temp->next;
    }
    if(temp->data==value){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
    else{
        cout<<"value not found";
    }
}

void insertAtPosition(Node* head , int pos ,  int value){
    Node* temp = head;
    Node* newNode = new Node(value);
    while(temp!=NULL){
        
    }
}

void insertAfterValue (Node* head , int val , int actualval){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==val){
            break;
        }
        temp=temp->next;
    }
    if(temp->data==val){
        Node* newNode = new Node(actualval);
        newNode->next=temp->next;
        temp->next->prev=newNode;
        newNode->prev=temp;
        temp->next=newNode;
    }
}

int main(){
    vector <int > arr ={1,2,3,4,5};
    Node* head =constructDLL(arr);
    insertAfterValue(head,3 , 123);
    printDLL(head);
}
