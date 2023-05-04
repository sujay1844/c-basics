
class Node:
	def __init__(self, value):
		self.value = value
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None
	def append(self, value):
		if self.head is None:
			self.head = Node(value)
			return
		node = self.head
		while node.next:
			node = node.next
		node.next = Node(value)
		return
	def prepend(self, value):
		if self.head is None:
			self.head = Node(value)
			return
		node = Node(value)
		node.next = self.head
		self.head = node
		return
	def print(self):
		node = self.head
		while node:
			print(node.value)
			node = node.next
		return

	def pop(self):
		if self.head is None:
			return None
		node = self.head
		self.head = self.head.next
		return node.value
	
	def popleft(self):
		if self.head is None:
			return None
		node = self.head
		self.head = self.head.next
		return node.value
	
	def __len__(self):
		len = 0
		node = self.head
		while node:
			len += 1
			node = node.next
		return len
	
	def __getitem__(self, index):
		if index >= len(self):
			raise IndexError("Index out of range")
		node = self.head
		for i in range(index):
			node = node.next
		return node.value

	def __str__(self):
		node = self.head
		string = ""
		while node:
			string += str(node.value) + "->"
			node = node.next
		return string


linked_list = LinkedList()
linked_list.append(1)
linked_list.append(2)
linked_list.append(3)
linked_list.prepend(4)
print(linked_list)

while True:
	print("1. Append")
	print("2. Prepend")
	print("3. Pop")
	print("4. Pop Left")
	print("5. Length")
	print("6. Get Item")
	print("7. Print")
	print("8. Exit")
	choice = int(input("Enter your choice: "))

	
	if choice == 1:
		value = int(input("Enter value: "))
		linked_list.append(value)

	elif choice == 2:
		value = int(input("Enter value: "))
		linked_list.prepend(value)

	elif choice == 3:
		linked_list.pop()
	elif choice == 4:
		linked_list.popleft()
	elif choice == 5:
		print(len(linked_list))
	elif choice == 6:
		index = int(input("Enter index: "))
		print(linked_list[index])
	elif choice == 7:
		linked_list.print()
	elif choice == 8:
		break