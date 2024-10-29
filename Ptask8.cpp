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
        root->left = inseart(root->left, value);
    }
    else if(value > root->data){
        root->right = inseart(root->right, value);
    }
    return root;
}

void inOrderTrav(Node* root, int arr[], int &index){
    if(root == NULL) return;

    inOrderTrav(root->left, arr, index);
    arr[index++] = root->data;  // Storing elements in sorted order
    inOrderTrav(root->right, arr, index);
}

// Function to sort an array using BST
void bstSort(int arr[], int n) {
    Node* root = NULL;

    // Inserting all elements of the array into the BST
    for(int i = 0; i < n; i++){
        root = inseart(root, arr[i]);
    }

    // Performing in-order traversal to store sorted elements back in array
    int index = 0;
    inOrderTrav(root, arr, index);
}

int main(){
    int arr[] = {50, 30, 10, 60, 80, 90, 70};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\n Before Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    bstSort(arr, n);

    cout << "\n After Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
