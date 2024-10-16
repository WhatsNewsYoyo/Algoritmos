#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

struct Node{
    int data;
    Node * right;
    Node * left;

    Node(int value);
};

class BinaryTree{
    public:
    Node * root;

    //Constructor
    BinaryTree();
    Node * insert(Node*node, int value);
    Node * search(Node*node, int value);
    void inOrderTraversal(Node *node);
    void preOrderTraversal(Node *node);
    void postOrderTraversal(Node *node);
};


#endif