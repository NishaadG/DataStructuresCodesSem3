#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Order {
    int orderID;
    string customerName;
    string items;

public:
    Order(int id, const string& name, const string& itemList) 
        : orderID(id), customerName(name), items(itemList) {}

    void display() const {
        cout << "Order ID: " << orderID 
             << ", Customer Name: " << customerName 
             << ", Items: " << items << endl;
    }
};

class Node {
public:
    Order data;
    Node* next;

    Node(const Order& givendata) : data(givendata), next(NULL) {}
};

class CircularQueue {
    Node* front;
    Node* rear;
    int queueSize;

public:
    CircularQueue() : front(NULL), rear(NULL), queueSize(0) {}

    bool isEmpty() const {
        return front == NULL;
    }

    void push(const Order& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        rear->next = front;
        queueSize++;
    }

    Order pop() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        Node* temp = front;
        Order val = front->data;
        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
        queueSize--;
        return val;
    }

    Order top() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }

    void printAll() const {
        if (isEmpty()) return;
        Node* temp = front;
        do {
            temp->data.display();
            temp = temp->next;
        } while (temp != front);
    }

    int size() const {
        return queueSize;
    }
};

class OrderManagement {
    CircularQueue queue;

public:
    void addOrder(const Order& order) {
        queue.push(order);
    }

    void processOrder() {
        try {
            Order temp = queue.pop();
            cout << "Processing Order: ";
            temp.display();
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    void displayOrders() const {
        cout << "Current Orders in Queue:" << endl;
        queue.printAll();
    }

    int countOrders() const {
        return queue.size();
    }
};

void displayMenu() {
    cout << "1. Add Order" << endl;
    cout << "2. Process Order" << endl;
    cout << "3. Display Orders" << endl;
    cout << "4. Count Orders" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    OrderManagement om;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        
        if (choice < 1 || choice > 5) {
            cout << "Invalid input. Choose again." << endl;
            continue;
        }
        
        if (choice == 1) {
            int id;
            string name, items;
            cout << "Enter Order ID: ";
            cin >> id;
            cout << "Enter Customer Name: ";
            getline(cin, name);
            cout << "Enter Items (comma separated): ";
            getline(cin, items);
            om.addOrder(Order(id, name, items));
        } else if (choice == 2) {
            om.processOrder();
        } else if (choice == 3) {
            om.displayOrders();
        } else if (choice == 4) {
            cout << "Count of orders: " << om.countOrders() << endl;
        }
    } while (choice != 5);

    return 0;
}
