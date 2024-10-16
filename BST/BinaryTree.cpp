#include "BinaryTree.h"
#include <iostream>

using namespace std;

Node::Node(int value){
    data = value;
    left = nullptr;
    right = nullptr;
}

BinaryTree::BinaryTree(){
    root = nullptr;
}

Node * BinaryTree::insert(Node*node, int value){
    if (node ==nullptr){
        return new Node (value);
    }

    if (value < node -> data){
        node -> left = insert(node ->left, value);
    }
    else {
        node -> right = insert(node ->right, value);
    }

    return node;
}

Node *BinaryTree::search(Node * node, int value){
    if(node == nullptr || node-> data ==value){
        return node;
    }

    if (value < node->data){
        return search (node->left, value);
    }

    return search(node->right, value);

}

void BinaryTree::inOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    inOrderTraversal(node->left);
    cout << node->data<<" ";
    inOrderTraversal(node->right);
}

void BinaryTree::preOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    cout << node->data <<" ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void BinaryTree::postOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data <<" ";
}
