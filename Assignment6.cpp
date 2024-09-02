/*creating/hosting website
digital marketing fo sending 10000 emails
cost of printing same number of pamplets
*/
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    string task;
    Node* next;
    Node(string givtask  , Node* givnext){
        task=givtask;
        next=givnext;
    }
    Node(string givtask){
        task=givtask;
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
    
    void push(string task){
        Node* newNode = new Node(task);
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
    string pop () {
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else{
            size--;
            string val = head->task;
            head=head->next;
            return val;
        }
    }
    
    string top(){
         if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else{
            return head->task;
        }
    }
    void printAll(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->task<<endl;
            temp=temp->next;
        }
    }
};

void DisplayMenu(){
    cout<<"Enter option 1 for Registering a new task."<<endl;
    cout<<"Enter option 2 for showing next task."<<endl;
    cout<<"Enter option 3 for completion of the next task"<<endl;
    cout<<"Enter option 4 for showing the complete to-do list"<<endl;
    cout<<"Enter option 5 for displaing specific priority tasks."<<endl;
    cout<<"Enter option 6 for exiting the system."<<endl;
    cout<<"Enter your choice  : " ;
}

int main(){
    Stack HighPriority;
    Stack MediumPriority;
    Stack LowPriority;
    int choice;
    do{
        DisplayMenu();
        cin>>choice;
        if(choice>6||choice<0) cout<< "Invalid input choose again ."<<endl;
        if(choice==1){
            string newTask;
            cout<<"Enter Name of the new task : "<<endl;
            cin>>newTask;
            int priority;
            cout<<"Enter prioriy of the task (1 for high priority , 2 for medium priority ,3 for high priority) : ";
            cin>>priority;
            if(priority==1){
                HighPriority.push(newTask);
            }
            else if(priority==2){
                MediumPriority.push(newTask);
            }
            else if(priority==3){
                LowPriority.push(newTask);
            }
            else{
                cout<<"Invalid Priority Input"<<endl;
            }
        }
        else if(choice==2){
            if(!HighPriority.isEmpty()){
                cout<<"Next Task is :"<<HighPriority.top()<<endl;
            }
            else if(!MediumPriority.isEmpty()){
               cout<<"Next Task is :"<<MediumPriority.top()<<endl;
            }
            else if(!LowPriority.isEmpty()){
                cout<<"Next Task is :"<<LowPriority.top()<<endl;
            }
            else{
                cout<<"No tasks in the list"<<endl;
            }
        }
        else if(choice==3){
            if(!HighPriority.isEmpty()){
                cout<<"Task Completed : "<<HighPriority.pop()<<endl;
            }
            else if(!MediumPriority.isEmpty()){
               cout<<"Task Completed : "<<MediumPriority.pop()<<endl;
            }
            else if(!LowPriority.isEmpty()){
                cout<<"Task Completed : "<<LowPriority.pop()<<endl;
            }
            else{
                cout<<"No tasks in the list"<<endl;
            }
            
        }
        else if(choice==4){
            cout<<"Tasks in the list : " <<endl;
            cout<<"High Priority : " <<endl;
            HighPriority.printAll();
            cout<<"Medium Priority : " <<endl;
            MediumPriority.printAll();
            cout<<"Low Priority : " <<endl;
            LowPriority.printAll();
        }
        else if(choice==5){
            int prioritychoice;
            cout<<"Enter the priority whose list should be displayed (1 for high priority , 2 for medium priority ,3 for high priority) : ";
            cin>>prioritychoice;
            if(prioritychoice==1){
                HighPriority.printAll();
            }
            else if(prioritychoice==2){
                MediumPriority.printAll();
            }
            else if(prioritychoice==3){
                LowPriority.printAll();
            }
            else{
                cout<<"Invalid Priority Input"<<endl;
            }
        }
    }while(choice!=6);
}
