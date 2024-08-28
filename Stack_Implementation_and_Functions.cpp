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

class Stack{
    Node* head;
    public:
    int size=0;
    Stack(){
        head = NULL;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    void push(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head=newNode;
        }
        else if(newNode==NULL){
            cout<<"Stack is full" <<endl ;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
        size++;
    }
    int pop () {
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else{
            size--;
            int val = head->data;
            head=head->next;
            return val;
        }
    }
    
    int top(){
         if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else{
            return head->data;
        }
    }
    void printAll(){
        Node* temp = head;
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
    cout<<"Enter option 4 for size of stack" <<endl;
    cout<<"Enter option 5 for printing all values of stack" <<endl;
    cout<<"Enter option 6 for exiting the system" <<endl;
    cout<<"Enter your choice  : ";
}

//voi
int main() {
    Stack st;
    int choice;
    do{
        DisplayMenu();
        cin>>choice;
        if(choice>6||choice<0) cout<< "Invalid input choose again ."<<endl;;
        if(choice==1){
            int val;
            cout<<"Enter value to be pushed : ";
            cin>>val;
            st.push(val);
        }
        else if(choice==2){
            cout<<"Value that has been popped : " <<st.pop() <<endl;
        }
        else if(choice==3){
            cout<<"Value of topmost element in stack : "<<st.top()<<endl;
        }
        else if(choice==4){
            cout<<"Size of stack is : " << st.size<<endl;
        }
        else if(choice==5){
            st.printAll();
        }
    }while(choice!=6);
}
