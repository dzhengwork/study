#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

struct BstNode
{
	int 	val;
	BstNode	*left;
	BstNode	*right;
    BstNode(int data) : val(data), left(NULL), right(NULL) {};
};

BstNode* firstLarger(BstNode* root, int data)
{
    if (root == NULL) return NULL;
    
    if (root->val > data) {
        BstNode* l = firstLarger(root->left, data);
        if (l) {
            return l;
        }
        return root;
    }
    else if (root->val < data) {
        return firstLarger(root->right, data);
    }
    return root;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL) {
		root = new BstNode(data);
	}
	else if (data < root->val) {
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
	if (data < root->val) {
		return Search(root->left, data);
	}
	if (data > root->val) {
		return Search(root->right, data);
	}
	return true;

}

int MinValue(BstNode* root)
{
	if (root->left == NULL) {
		return root->val;
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
	else if (data < root->val) {
		root->left = Remove(root->left, data);
	}
	else if (data > root->val) {
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
			root->val = min;
			root->right = Remove(root->right, min);
		}

	}
	return root;
}

string serializeLEVEL(BstNode* root) {
    string res = "";
    if (root == NULL) return res;

    queue<BstNode*> Q;
    Q.push(root);

    while(!Q.empty()) {
        BstNode* node = Q.front();
        if (node->val == 0) {
            res += "#,";
        }
        else {
            res += to_string(node->val) + ",";
        }
        Q.pop();

        if (node->left && node->right) {
            Q.push(node->left);
            Q.push(node->right);
        }
        else if (node->left) {
            Q.push(node->left);
            Q.push(new BstNode(0));
        }
        else if (node->right) {
            Q.push(new BstNode(0));
            Q.push(node->right);
        }
    }
    return res;
}

BstNode* deserializeLEVEL(string data) {
	BstNode* root = NULL;

    vector<BstNode*> v;
    stringstream ss(data);
    string line;
    int n;
    int lr = 0;
    while (getline(ss, line, ',')) {
        if (line != "#") n = atoi(line.c_str());
        else n = 0;
        v.push_back(new BstNode(n));
    }
    root = v[0];
    int len = v.size();
    for (int i=0; (i*2+1) < len; i++) {
        if(v[i]) {
            if(v[i*2+1]->val != 0) v[i]->left = v[i*2+1];
            if(v[i*2+2]->val != 0) v[i]->right = v[i*2+2];
        }
    }
    return root;
}

string serializeDLR(BstNode* root) {
    string res = "";
    if (root == NULL) return res;
    
    res += to_string(root->val) + ",";
    string lstr = serializeDLR(root->left);
    string rstr = serializeDLR(root->right);

    if (lstr.size() == 0 && rstr.size() == 0) {
    }
    else if (lstr.size() == 0) {
        // makeup left with #
        lstr = "#,";
    }
    else if (rstr.size() == 0) {
        // makeup right with #
        rstr = "#,";
    }
    res += lstr;
    res += rstr;
    return res;
}

BstNode* deserializeDLR(string data) {
	BstNode* root = NULL;

    stringstream ss(data);
    string line;
    int n;
    while (getline(ss, line, ',')) {
        if (line != "#") {
            n = atoi(line.c_str());
	        root = Insert(root, n);	
        }
    }
    return root;
}

int main()
{
	BstNode* root = NULL;
	root = Insert(root, 15);	
	root = Insert(root, 10);	
	root = Insert(root, 20);	
	root = Insert(root, 25);	
	root = Insert(root, 8);	
	root = Insert(root, 12);	

    string ser;
    cout << "Serialized DLR:" << endl;
    ser = serializeDLR(root);
    cout << ser << endl;

    cout << "De-Serialized DLR:" << endl;
    BstNode* root2 = deserializeDLR(ser);
    ser = serializeDLR(root2);
    cout << ser << endl;

    cout << "Serialized Level-order:" << endl;
    ser = serializeLEVEL(root);
    cout << ser << endl;

    cout << "De-Serialized LEVEL:" << endl;
    BstNode* root3 = deserializeLEVEL(ser);
    ser = serializeLEVEL(root3);
    cout << ser << endl;

	cout << "enter number to search: ";
	int num;
	cin >> num;
	if(Search(root, num)) {
		cout << "found" << endl;
		root = Remove(root, num);
		assert(Search(root, num) == false);
		cout << num << " deleted" << endl;
	}
	else {
		cout << "not found" << endl;
	}

	cout << "enter number to search: ";
	cin >> num;
    BstNode* f = firstLarger(root, num);
    if (f) {
		cout << "found: " << f->val << endl;
	}
	else {
		cout << "not found" << endl;
	}

	return 0;
}
