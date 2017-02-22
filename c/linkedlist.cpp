#include <iostream>

using namespace std;
struct Node
{
	int 	data;
	Node	*next;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

void printList(Node* head)
{
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* reverse(Node* head)
{
	Node* p = NULL;
	Node* c = head;
    Node* n = NULL;
	while(c) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	return p;
/*
    Node* n = c->next;
    while(c) {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
        if (n==0) break;
    }
    return c;
*/
}

Node* reverseBetween(Node* head, int m, int n)
{
    if (head == NULL) return head;
    if (m >= n) return head;
    n -= m;

    Node prehead;
    prehead.next = head;
    
    // find m-1 and m
    Node* p = &prehead;
    while(--m) {
        p = p->next;
    }
    Node* headm = p->next;

    while(n>0) {
        Node* next = headm->next;
        headm->next = next->next;
        next->next = p->next;
        p->next = next;
        n--;
    }
    return prehead.next;
}

Node* remove(Node* head, int data)
{
/*
	if (head == NULL) return head;
	if (head->data == data) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	head->next = remove(head->next, data);
*/
    Node* p = NULL;    
    Node* c = head;
    Node* n = NULL;
    while(c) {
        n = c->next;
        if(c->data == data) {
            if (p == NULL) {
                head = n;
            }
            else {
                p->next = n;
            }
            delete c;
        }
        else {
            p = c;
        }
        c = n;
    }
	return head;
}

int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(3);
	head->next->next->next->next->next->next = newNode(7);
	head->next->next->next->next->next->next->next = newNode(8);
	head->next->next->next->next->next->next->next->next = newNode(8);
	
	printList(head);

	head = reverse(head);
	printList(head);

	head = remove(head, 2);
	printList(head);

	head = reverseBetween(head, 1, 2);
	printList(head);
	head = reverseBetween(head, 2, 4);
	printList(head);
	head = reverseBetween(head, 1, 6);
	printList(head);

	return 0;
}
