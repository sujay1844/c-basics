# Positional
- Traverse until required position
	- keep a count of number of nodes traversed
	- if the count is equal to given position, stop
- Store the pointer to the next node
- Create node
- Link the current node to the new node
- Link the new node to the next node

```c
void addPositional(int data, int position) {
	Node* traverse = head;
	int count = 0;
	while (count == position) {
		traverse = traverse->link;
		count++;
	}
	Node* new_node = AddNode();
	new_node->link = traverse->link;
	traverse->link = new_node;
	return head;
}
```
# Print
- 
```c
void print() {
	traverse = head;
	while(traverse->link != NULL) {
		printf(traverse->value);
		traverse = traverse->link;
	}
}
```