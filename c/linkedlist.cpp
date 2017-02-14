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
	Node* newHead = NULL;
	while(head) {
		Node* next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}
	return newHead;
}

Node* remove(Node* head, int data)
{
	if (head == NULL) return head;
	if (head->data == data) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	head->next = remove(head->next, data);
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
	
	printList(head);

	head = reverse(head);

	printList(head);

	head = remove(head, 3);

	printList(head);
	return 0;
}
