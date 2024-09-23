#include <iostream>
#include <string>
using namespace std;

class Customer_Service {
    int reqID;
    string Name;
    string Task;

public:
    Customer_Service(int ID, string Name, string Task) {
        this->reqID = ID;
        this->Name = Name;
        this->Task = Task;
    }
    
    void display() const {
        cout << "ID: " << reqID << ", Name: " << Name << ", Task: " << Task << endl;
    }
};

class Node {
public:
    Customer_Service data; 
    Node* next;
    Node(Customer_Service givendata) {
        this->data = givendata;
        this->next = NULL;
    }
};
/*
    class Node {
public:
    Customer_Service data;
    Node* next;

    Node(Customer_Service givendata) : data(givendata), next(NULL) {}
};*/

class Queue {
    Node* front;
    Node* rear;

public:
    int size;

    Queue() : front(NULL), rear(NULL), size(0) {}

    bool isEmpty() {
        return front == NULL;
    }

    void push(Customer_Service data) {
        Node* newNode = new Node(data);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
        size++;
    }

    Customer_Service pop() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        Node* temp = front;
        Customer_Service val = front->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        size--;
        return val;
    }

    Customer_Service top() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }

    void printAll() {
        Node* temp = front;
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

class Customer_Service_Management {
    Queue queue;

public:
    void Add_Service(Customer_Service data) {
        queue.push(data);
    }

    void Process_Service() {
        try {
            Customer_Service temp = queue.pop();
            temp.display();
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    void Display_Services() {
        queue.printAll();
    }

    int Count_Services() {
        return queue.size;
    }
};

void DisplayMenu() {
    cout << "Enter option 1 for Adding Service" << endl;
    cout << "Enter option 2 for Processing Service" << endl;
    cout << "Enter option 3 for Displaying Services" << endl;
    cout << "Enter option 4 for Counting Services" << endl;
    cout << "Enter option 5 for Exiting" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Customer_Service_Management CMS;
    int choice;
    
    do {
        DisplayMenu();
        cin >> choice;
        
        if (choice < 1 || choice > 5) {
            cout << "Invalid input. Choose again." << endl;
            continue;
        }

        if (choice == 1) {
            int id;
            string name, task;
            cout << "Enter ID of task: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter type of service: ";
            cin >> task;
            CMS.Add_Service(Customer_Service(id, name, task));
        } else if (choice == 2) {
            CMS.Process_Service();
        } else if (choice == 3) {
            CMS.Display_Services();
        } else if (choice == 4) {
            cout << "Count of services: " << CMS.Count_Services() << endl;
        }
    } while (choice != 5);

    return 0;
}
