#include "bstlib.h"
#include <queue>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void BST::addNode(int data)
{
    _root = insert(_root, data);
}

void BST::delNode(int data)
{
    _root = remove(_root, data);
}

Node* BST::insert(Node* root, int data)
{
    if (!root) {
        root = new Node(data);
    }
    else if (data < root->val) {
        // add to left tree
        root->left = insert(root->left, data);
    }
    else {
        // add to right tree
        root->right = insert(root->right, data);
    }
    return root;
}

Node* BST::remove(Node* root, int data)
{
    if (root) {
        if (data < root->val) {
            // remove from left tree
            root->left = remove(root->left, data);
        }
        else if (data > root->val) {
            // remove from right tree
            root->right = remove(root->right, data);
        }
        else {
            // match
            if (root->left == NULL && root->right == NULL) {
                // no subtree
                delete root;
                root = NULL;
            }
            else if (root->left) {
                // only left tree exists
                Node* tmp = root;
                root = root->left;
                delete tmp;
            }
            else if (root->right) {
                // only right tree exists
                Node* tmp = root;
                root = root->right;
                delete tmp;
            }
            else {
                // both trees exists
                // swap with min value from right tree
                root->val = minValue(root->right);
                // delete the node from right tree
                root->right = remove(root->right, root->val);                    
            }
        }
    }
    return root;
}

bool BST::findNode(int data)
{
    return search(this->_root, data);
}

bool BST::search(Node* root, int data)
{
    if (root) {
        if (root->val == data) return true;
        if (root->left && search(root->left, data)) return true;
        if (root->right && search(root->right, data)) return true;
    }
    return false;
}

int BST::minValue(Node* root)
{
    if (root->left == NULL) return root->val;
    return minValue(root->left);
}

int BST::maxValue(Node* root)
{
    if (root->right == NULL) return root->val;
    return maxValue(root->right);
}

string BST::serializeLEVEL()
{
    string res = "";
    if (_root) {
        queue<Node*> Q;
        Node* node = _root;
        Q.push(node);
        while (!Q.empty()) {
            node = Q.front();
            if (node->val == 0) {
                res += "#,";
            }
            else {
                res += to_string(node->val) + ",";
            }
            if (node->left && node->right == NULL) {
                Q.push(node->left);
                Q.push(new Node(0));
            }
            else if (node->right && node->left == NULL) {
                Q.push(new Node(0));
                Q.push(node->right);
            }
            else if (node->left && node->right) {
                Q.push(node->left);
                Q.push(node->right);
            }
            Q.pop();
        }
    }
    return res;
}

Node* BST::deserializeLEVEL(string data)
{
    Node* root = NULL;
    vector<Node*> V;
    stringstream ss(data);
    string line;
    while (getline(ss, line, ',')) {
        // create nodes and add to vector
        if (line == "#") V.push_back(new Node(0));
        else V.push_back(new Node(atoi(line.c_str())));
    }
    // link the nodes
    int len = V.size();
    if (len > 0) {
        root = V[0];
        for (int i=0; i*2+1<len; i++) {
            V[i]->left = V[i*2+1];
            V[i]->right = V[i*2+2];
        }
    }
    return root;
}

string BST::serializeDLR()
{
    return this->serialize(_root);
}

string BST::serialize(Node* root)
{
    string res = "";
    if (root) {
        res += to_string(root->val) + ",";
        if (root->left && root->right == NULL) {
            res += serialize(root->left);
            res += "#,";
        }
        else if (root->left == NULL && root->right) {
            res += "#,";
            res += serialize(root->right);
        }
        else if (root->left && root->right) {
            res += serialize(root->left);
            res += serialize(root->right);
        }
    }
    return res;
}

Node* BST::deserializeDLR(string data)
{
    Node* root = NULL;
    stringstream ss(data);
    string line;
    while(getline(ss, line, ',')) {
        if (line != "#") {
            root = insert(root, atoi(line.c_str()));
        }
    }
    return root;
}

