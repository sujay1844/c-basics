#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *node;

node head = NULL;

void append(int data)
{
	node new_link = (node)malloc(sizeof(struct node));
	new_link->data = data;
	new_link->next = NULL;

	if (head == NULL)
	{
		head = new_link;
		return;
	}
	node traverse = head;
	while (traverse->next != NULL)
	{
		traverse = traverse->next;
	}

	traverse->next = new_link;
}

void print()
{
	if (head == NULL)
	{
		printf("Linked list is empty.\n");
		return;
	}

	node traverse = head;
	while (traverse != NULL)
	{
		printf("%d->", traverse->data);
		traverse = traverse->next;
	}
	printf("\n");
}

int pop()
{
	if (head == NULL)
	{
		return 0;
	}
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
		return 0;
	}
	node traverse = head;
	while (traverse->next->next != NULL)
	{
		traverse = traverse->next;
	}
	int data = traverse->next->data;
	free(traverse->next);
	traverse->next = NULL;
	return data;
}

void prepend(int data)
{
	node new_node = (node)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = head;
	head = new_node;
}

int popleft()
{
	int data = head->data;
	head = head->next;
	return data;
}

int noOfNodes()
{
	if (head == NULL)
	{
		return 0;
	}
	int count = 0;

	node traverse = head;
	while (traverse != NULL)
	{
		traverse = traverse->next;
		count++;
	}
	return count;
}

int getData(int index) {
	if (head == NULL)
	{
		return 0;
	}
	int count = 0;

	node traverse = head;
	while (traverse != NULL)
	{
		if (count == index-1) {
			return traverse->data;
		}
		traverse = traverse->next;
		count++;
	}

}

void addPositionally(int index, int data) {
	int count = 0;
	node traverse = head;
	while (traverse->next != NULL)
	{
		if (count == index-1) {
			break;
		}
		traverse = traverse->next;
		count++;
	}
	node new_node = (node)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = traverse->next;

	traverse->next = new_node;

}

int popPositionally(int index) {
	int data;

	if(head == NULL) {
		return 0;
	}
	if(head->next == NULL) {
		data = head->data;
		free(head);
		head = NULL;
	}

	int count = 0;
	node traverse = head;
	while (traverse->next != NULL)
	{
		if (count == index-1) {
			break;
		}
		traverse = traverse->next;
		count++;
	}
	data = traverse->next->data;

	node next_node = traverse->next->next;
	free(traverse->next);
	traverse->next = next_node;
	return data;
}

int main()
{
	append(69);
	append(420);
	append(69);
	append(1);
	print();
	pop();
	print();
	printf("Prepending\n");
	prepend(34);
	prepend(27);
	print();
	popleft();
	printf("\n");
	print();
	printf("\n");
	printf("%d\n", noOfNodes());
	printf("2th element = %d\n", getData(2));
	addPositionally(2, 99);
	print();
}
