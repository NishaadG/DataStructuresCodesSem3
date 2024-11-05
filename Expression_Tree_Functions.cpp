#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    
    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* postfixToBST(string str) {
    stack<Node*> st;
    Node* newNode;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            newNode = new Node(str[i]);
            Node* right = st.top();
            st.pop();
            Node* left = st.top();
            st.pop();
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        } else {
            newNode = new Node(str[i]);
            st.push(newNode); 
        }
    }
    return st.top();
}

Node* prefixToBST(string str) {
    reverse(str.begin(), str.end());
    return postfixToBST(str);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << (char)root->data << " ";
    inOrder(root->right);
}

int main() {
    string postfixExpr, prefixExpr;
    
    cout << "Enter postfix expression: ";
    cin >> postfixExpr;
    
    cout << "Enter prefix expression: ";
    cin >> prefixExpr;
    
    Node* root = postfixToBST(postfixExpr);
    Node* root2 = prefixToBST(prefixExpr);
    
    cout << "Inorder traversal of BST from postfix expression: ";
    inOrder(root);
    cout << endl;
    
    cout << "Inorder traversal of BST from prefix expression: ";
    inOrder(root2);
    cout << endl;

    return 0;
}
