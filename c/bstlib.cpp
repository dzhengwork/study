#include <iostream>
#include <assert.h>

struct BstNode
{
	int 	data;
	BstNode	*left;
	BstNode	*right;
};

BstNode* createBstNode(int data)
{
	BstNode* node = new BstNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL) {
		root = createBstNode(data);
	}
	else if (data < root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data)
{
	if (root == NULL) {
		return false;
	}
	if (data < root->data) {
		return Search(root->left, data);
	}
	if (data > root->data) {
		return Search(root->right, data);
	}
	return true;

}

int MinValue(BstNode* root)
{
	if (root->left == NULL) {
		return root->data;
	}
	else {
		return MinValue(root->left);
	}
}

BstNode* Remove(BstNode* root, int data)
{
	if (root == NULL) {
		return NULL;
	}
	else if (data < root->data) {
		root->left = Remove(root->left, data);
	}
	else if (data > root->data) {
		root->right = Remove(root->right, data);
	}
	else {
		// find the node to be removed
		// no child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// one child on right
		else if (root->left == NULL) {
			BstNode* tmp = root;
			root = root->right;
			delete tmp;
		}
		// one child on left
		else if (root->right == NULL) {
			BstNode* tmp = root;
			root = root->left;
			delete tmp;
		}
		else {
			// min value of right tree
			int min = MinValue(root->right);
			root->data = min;
			root->right = Remove(root->right, min);
		}

	}
	return root;
}

