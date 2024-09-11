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

class Queue{
    Node* front=NULL;
    Node* rear=NULL;
    public:
    int size=0;
    Queue(){
        front = NULL;
    }
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    void push(int data){
        Node* newNode = new Node(data);
        if(front==NULL){
            front=newNode;
            rear=newNode;
        }
        else if(newNode==NULL){
            cout<<"Stack is full" <<endl ;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
        size++;
    }
    int pop () {
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        else{
            size--;
            int val = front->data;
            front=front->next;
            return val;
        }
    }
    
    int top(){
         if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        else{
            return front->data;
        }
    }
    void printAll(){
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};
void DisplayMenu(){
    cout<<"Enter option 1 for push function"<<endl;
    cout<<"Enter option 2 for pop function" <<endl;
    cout<<"Enter option 3 for top function"<<endl;
    cout<<"Enter option 4 for size of queue" <<endl;
    cout<<"Enter option 5 for printing all values of queue" <<endl;
    cout<<"Enter option 6 for exiting the system" <<endl;
    cout<<"Enter your choice  : ";
}
    

int main(){
    Queue Q;
    int choice;
    do{
        DisplayMenu();
        cin>>choice;
        if(choice>6||choice<0) cout<< "Invalid input choose again ."<<endl;;
        if(choice==1){
            int val;
            cout<<"Enter value to be pushed : ";
            cin>>val;
            Q.push(val);
        }
        else if(choice==2){
            cout<<"Value that has been popped : " <<Q.pop() <<endl;
        }
        else if(choice==3){
            cout<<"Value of topmost element in stack : "<<Q.top()<<endl;
        }
        else if(choice==4){
            cout<<"Size of stack is : " << Q.size<<endl;
        }
        else if(choice==5){
            Q.printAll();
        }
    }while(choice!=6);
}
