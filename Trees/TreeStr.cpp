#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;

    }
};


void inorderTraversal(Node* root){
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout<<root-> data<< " "; 
    // change this according to preorder / inorder / postorder traversal
    inorderTraversal(root->right);
    
}

int main(){
    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right  = new Node(3);
    root -> left -> right = new Node(4);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}


    