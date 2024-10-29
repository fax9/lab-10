#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
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

void inOrderTrav(Node* root){
    if(root == NULL)return ;

    inOrderTrav(root->left);
    cout<<root->data<<" ";
    inOrderTrav(root->right);
}

int main(){
    Node* root = NULL;


   root = inseart(root,50);
    root = inseart(root,30);
    root = inseart(root,10);
    root = inseart(root,60);
    root = inseart(root,80);
    root = inseart(root,90);
    root = inseart(root,70);

    cout<<"\n In Order Trav of BST is: ";
    inOrderTrav(root);

    return 0;
}

