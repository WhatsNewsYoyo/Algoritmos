#include <iostream>
#include "BinaryTree.h"
using namespace std;


int main(){

    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    int valueToSearch = 30;
    Node * result = tree.search(tree.root, valueToSearch);
    cout<<result->data<<endl;
    
    cout << "InOrder: ";
    tree.inOrderTraversal(tree.root);
    cout<< endl;

    cout << "PreOrder: ";
    tree.preOrderTraversal(tree.root);
    cout<< endl;

    cout << "PostOrder: ";
    tree.postOrderTraversal(tree.root);
    cout<< endl;
    
    return 0;
}