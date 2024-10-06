//id , name, quantity , price , total value, category wise value? , individual value
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int id;
    string name;
    int quantity;
    int price;
    string category;
    Node* next;
    Node* prev;
    Node(int id ,string name  , int quantity , int price,string category){
        this->id=id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->category = category;
        next=NULL;
        prev = NULL;
    }
    
};

void DisplayMenu(){
    cout<<"Enter option 1 for registering a new item in the list."<<endl;
    cout<<"Enter option 2 for updating information of an item" <<endl;
    cout<<"Enter option 3 for removing an item from the list"<<endl;
    cout<<"Enter option 4 for calculating total value of items in the list" <<endl;
    cout<<"Enter option 5 for calculating value of a specific category" <<endl;
    cout<<"Enter option 6 to exit the system"<<endl;
    cout<<"Enter your choice  : ";
}

Node* removeItem( Node* head , string nametbr){
    if(head->name==nametbr){
        return head->next;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(nametbr==temp->name){
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(temp->name==nametbr){
        prev->next=temp->next;
        return head;
    }
    else{
        cout<<"Name not found."<<endl;
        return head;
    }
}

Node* newItem(int id,string Name , int quantity ,int price , string category){
    Node* temp = new Node (id , Name , quantity,price,category);
    return temp;
}

Node* addAtStart(Node* head , Node* newNode){
    if(head==NULL) return newNode;
    newNode->next=head;
    return newNode;
}

Node* addAtEnd(Node* head , Node *  newNode){
    if(head==NULL) return newNode;
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void printInfo(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<"ID of product : "<<temp->id<<endl;
        cout<<"Name of product : "<<temp->name<<endl;
        cout<<"Quantity of product : "<<temp->quantity<<endl;
        cout<<"Price of the product : "<<temp->price<<endl;
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
    if(temp->name==Namechoice){
        if(changechoice==1){
            temp->id=data;
        }
        else if(changechoice==2){
            temp->quantity=data;
        }
        else if(changechoice==3){
            temp->price = data;
        }
    }
}

int totalValue(Node* head){
    Node* temp  = head;
    int totalprice = 0;
    while(temp!=NULL){
        int currentprice = temp->quantity * temp->price;
        cout<<"Total value of " <<temp->name << " is "<<currentprice <<endl;
        totalprice+=currentprice;
        temp=temp->next;
    }
    return totalprice;
}

int categoryValue (Node* head , string catname){
    Node* temp = head;
    int totalprice = 0;
    while(temp!=NULL){
        if(temp->category==catname){
            int currentprice = temp->quantity * temp->price;
            cout<<"Total value of " <<temp->name << " is "<<currentprice <<endl;
             totalprice+=currentprice;
        }
        temp=temp->next;
    }
    return totalprice;
}

int main(){
    int choice;
    Node* head=NULL;
    do{
        DisplayMenu();
        cin>>choice;
        if(choice>6||choice<0) cout<< "Invalid input choose again ."<<endl;;
        if(choice==1){
            string Name , category;
            int quantity , price , id;
            cout<<"Enter Name of the product : " << endl;
            cin>>Name;
            cout<<"Enter id of product : "<<endl;
            cin>>id;
            cout<<"Enter quantity of product : "<<endl;
            cin>>quantity;
            cout<<"Enter price of product : "<<endl;
            cin>>price;
            cout<<"Enter category of the product (enter default for no category ) : " <<endl;
            cin>>category;
            Node* newNode = newItem(id , Name ,quantity , price,category);
            head = addAtEnd(head , newNode);
        }
        else if(choice==2){
            printInfo(head);
            string tbfname;
            int changechoice;
            cout<<"Enter name of product whose info has to be changed : "<<endl;
            cin>>tbfname;
            cout<<"Enter data that has to be changed  ( 1 : ID , 2 : Quantity , 3 : Price )  :" <<endl;
            cin>>changechoice;
            cout<<"Enter changed to : "<<endl;
            int data;
            cin>>data;
            changeData(head , changechoice , data , tbfname);
            printInfo(head);
        }
        else if(choice==3){
            printInfo(head);
            string tbrname;
            cout<<"Enter Name of Item to be removed : " << endl;
            cin>>tbrname;
            head =removeItem(head , tbrname);
            cout<<"New List : " <<endl;
            printInfo(head);
        }
        else if(choice==4){
            int total = totalValue(head);
            cout<<"Total Value of list is "<<total<<endl;
        }
        else if(choice==5){
            string catname;
            cout<<"Enter category whose value is to be calculated : " <<endl;
            cin>>catname;
            int catvalue = categoryValue(head , catname);
            cout<<"Value of " << catname << " is "<<catvalue<<endl;
        }
    }while(choice!=6);
}
