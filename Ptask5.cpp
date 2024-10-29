#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* inseart(Node* root, int value){

    if(root == NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left = inseart(root->left,value);
    }
    else if(value > root->data){
        root->right = inseart(root->right,value);
    }

    return root;
}

void preOrderTrav(Node* root){
    if(root == NULL)return ;
    cout<<root->data<<" ";

    preOrderTrav(root->left);
    preOrderTrav(root->right);
}

int main(){
    Node* root = NULL;
    int value, amount;
    cout<<"\n Enter the number of values u wanna enter: ";
    cin>>amount;
    for(int i = 0; i<=amount; i++){
        cout<<"\n Enter values: ";
        cin>>value;
       root = inseart(root,value); }


    cout<<"\n Pre Order Trav of BST is: ";
    preOrderTrav(root);

    return 0;
}

