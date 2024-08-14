#include <bits/stdc++.h>
//display , new node, delete node , update info , search.
using namespace std;
class Node{
    public:
    int id;
    string name;
    int priority;
    Node* next;
    Node(int id ,string name  , int priority){
        this->id=id;
        this->name = name;
        this->priority = priority;
        next=NULL;
    }
};

void DisplayMenu(){
    cout<<"Enter option 1 for registering a new patient in the queue."<<endl;
    cout<<"Enter option 2 for updating information of a patient" <<endl;
    cout<<"Enter option 3 for removing a patient from the queue"<<endl;
    cout<<"Enter option 4 for searching  a patient" <<endl;
    cout<<"Enter option 5 for exiting the system" <<endl;
    cout<<"Enter your choice  : ";
}

Node* newRegister(int id,string Name , int priority){
    Node* temp = new Node (id , Name , priority);
    return temp;
}

Node* addAtEnd(Node* head , Node *  newNode){
    if(head==NULL) return newNode;
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

Node* addAtStart(Node* head , Node* newNode){
    if(head==NULL) return newNode;
    newNode->next=head;
    return newNode;
}

void printInfo(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<"ID of patient  : "<<temp->id<<endl;
        cout<<"Name of patient : "<<temp->name<<endl;
        cout<<"Priority of patient : "<<temp->priority<<endl;
        temp=temp->next;
    }
}

void changeData(Node* head , int changechoice , int data,string Namechoice){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->name==Namechoice){
            break;
        }
        temp=temp->next;
    }
    if(changechoice==1){
        temp->id=data;
    }
    else if(changechoice==2){
        temp->priority=data;
    }
}
int main(){
    int choice;
    Node* head=NULL;
    do{
        DisplayMenu();
        cin>>choice;
        if(choice==1){
            string Name;
            int priority;
            int id;
            int position;
            cout<<"Enter Name of patient : " << endl;
            cin>>Name;
            cout<<"Enter Priority of the patients condition (1 : mild , 2 : severe , 3 : extremely severe ) : "<<endl;
            cin>>priority;
            cout<<"Enter ID of the patient : " <<endl;
            cin>>id;
            Node* newNode =newRegister(id , Name , priority);
            cout<<"Enter place at which patient should be added  (1 : start , 2 : middle , 3 : end ) : "<<endl; 
            cin>>position;
            if(position==1){
                head = addAtStart(head , newNode);
            }
            else if(position==2){
                head = addAtEnd(head , newNode);
            }
        }
        else if(choice==2){
            printInfo(head);
            string tbfname;
            int changechoice;
            cout<<"Enter name of patient whose info has to be changed : "<<endl;
            cin>>tbfname;
            cout<<"Enter data that has to be changed  ( 1 : ID , 2 : Priority , 3 : Name )  : :" <<endl;
            cin>>changechoice;
            cout<<"Enter changed to : "<<endl;
            int data;
            cin>>data;
            changeData(head , changechoice , data , tbfname);
            printInfo(head);
        }
    } while(choice!=5);
}