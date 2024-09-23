#include <stdio.h>
#include <string>
using namespace std;

class Customer_Service{
    int reqID;
    string Name;
    string Task;
    Customer_Service(int ID , string Name , string Task){
        this->reqID = reqID;
        this->Name = Name;
        this->Task = Task;
    }
};

class Node{
    public:
    Customer_Service data;
    Node* next;
    Node(Customer_Service givendata){
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
    
    void push(Customer_Service data){
        Node* newNode = new Node(data);
        if(front==NULL){
            front=newNode;
            rear=newNode;
        }
        else if(newNode==NULL){
            cout<<"Queue is full" <<endl ;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
        size++;
    }
    Customer_Service pop () {
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            size--;
            Customer_Service val = front->data;
            front=front->next;
            return val;
        }
    }
    
    Customer_Service top(){
         if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        else{
            return front->data;
        }
    }
    /*void printAll(){
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }*/
};
class Customer_Service_Management{
    public:
    Customer_Service_Management(){
        Queue queue;
    }
    void Add_Service(Customer_Service data){
        queue.push(data)
    }
    
    void Process_Service(){
        Customer_Service temp = queue.pop();
         temp;
    }
};



void DisplayMenu(){
    cout<<"Enter option 1 for Adding Service"<<endl;
    cout<<"Enter option 2 for Process Service" <<endl;
    cout<<"Enter option 3 for Display the services"<<endl;
    cout<<"Enter option 4 for count of services" <<endl;
    cout<<"Enter option 5 for exiting" <<endl;
    cout<<"Enter your choice  : ";
}
    

int main(){
    Customer_Service_Management CMS;
    int choice;
    do{
        DisplayMenu();
        cin>>choice;
        if(choice>6||choice<0) cout<< "Invalid input choose again ."<<endl;;
        if(choice==1){
            int id;
            string name , string task;
            cout<<"Enter ID of task : ";
            cin>>id;
            cout<<"Enter Name : ";
            cin>>name;
            cout<<"Enter type of service : "
            cin>>task;
            CMS.add_service(id,name,task);
        }
        else if(choice==2){
            
            cout<<"Task : " <<CMS.pop() <<endl;
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
