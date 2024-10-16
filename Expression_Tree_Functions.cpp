#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;
    
    Node(char data){
        this->data = data;
        this->left =NULL;
        this->right =NULL;
    }
};

Node* postfixToBST(string str){
    stack<Node*> st;
    Node* newNode;
    for(int i= 0;i < str.size();i++){
        if (str[i] == '+' || str[i] == '-' || str[i] == '*'
            || str[i] == '/' || str[i] == '^'){
            newNode = new Node(str[i]);
            Node* left = st.top();
            st.pop();
            Node* right = st.top();
            st.pop();
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
        else{
            newNode = new Node(str[i]);
            st.push(newNode); 
        }
    }
    return newNode;
}

Node* prefixToBST(string str){
    reverse(str.begin(),str.end());
    return postfixToBST(str);
}
void inOrder(Node* root){
    if(root==NULL) return ;
    inOrder(root->left);
    cout<<(char)root->data<<" ";
    inOrder(root->right);
}

int main(){
    Node* root = postfixToBST("DC-BA+*");
    Node* root2 = prefixToBST("*+AB-CD");
    inOrder(root);
    cout<<endl;
    inOrder(root2);
}
