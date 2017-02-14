import sys

class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def reverse(self):
		newhead = None
		curr = self.head
		while(curr):
			next = curr.next
			curr.next = newhead
			newhead = curr
			curr = next
		self.head = newhead

	def push(self, data):
		node = Node(data)
		node.next = self.head
		self.head = node

	def printList(self):
		temp = self.head
		while(temp):
			sys.stdout.write(str(temp.data))
			sys.stdout.write(" ")
			temp = temp.next
		sys.stdout.write("\n")
		sys.stdout.flush()

if __name__ == "__main__":
	alist = LinkedList()
	alist.push(1);
	alist.push(2);
	alist.push(3);
	alist.push(4);
	alist.push(5);
	alist.push(6);
	alist.push(7);
	alist.push(8);

	alist.printList()

	alist.reverse()

	alist.printList()

