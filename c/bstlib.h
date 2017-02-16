#ifndef __BST_LIB_H
#define __BST_LIB_H
#include <stddef.h>
#include <string>

struct Node {
    int     val;
    Node    *left;
    Node    *right;
    Node(int data) : val(data), left(NULL), right(NULL) {}
};

class BST 
{
public:
    BST(int data) { _root = new Node(data); }
    BST(Node* root) : _root(root) {}
    BST(std::string data) { _root = deserializeLEVEL(data); }
    ~BST() {if(_root) delete _root;}
    void addNode(int data);
    void delNode(int data);
    bool findNode(int data);
    std::string serializeLEVEL();
    std::string serializeDLR();
    Node* deserializeLEVEL(std::string data);
    Node* deserializeDLR(std::string data);
private:
    std::string serialize(Node* node);
    bool search(Node* root, int data); 
    Node* insert(Node* root, int data);
    Node* remove(Node* root, int data);
    int minValue(Node* root);
    int maxValue(Node* root);
    
private:
    Node*   _root;
};

#endif
