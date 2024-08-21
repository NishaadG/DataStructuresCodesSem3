//id , name, quantity , price , total value, category wise value? , individual value
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int id;
    string name;
    int quantity;
    int price;
    Node* next;
    Node(int id ,string name  , int quantity , int price){
        this->id=id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        next=NULL;
    }
    
};

void DisplayMenu(){
    cout<<"Enter option 1 for registering a new item in the list."<<endl;
    cout<<"Enter option 2 for updating information of an item" <<endl;
    cout<<"Enter option 3 for removing an item from the list"<<endl;
    cout<<"Enter option 4 for calculating total value of items in the list" <<endl;
    cout<<"Enter option 5 for exiting the system" <<endl;
    cout<<"Enter your choice  : ";
}

Node* newItem(int id,string Name , int quantity ,int price){
    Node* temp = new Node (id , Name , quantity,price);
    return temp;
}

int main(){
    int choice;
    Node* head=NULL;
    do{
        DisplayMenu();
        cin>>choice;
        if(choice>5||choice<0) cout<< "Invalid input choose again ."<<endl;;
        if(choice==1){
            string Name;
            int quantity , price , id;
            cout<<"Enter Name of the product : " << endl;
            cin>>Name;
            
    }while(choice!=5);
}
