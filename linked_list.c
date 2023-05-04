#include <stdio.h>
#include <stdlib.h>

struct Link
{
	int data;
	struct Link *next;
};

typedef struct Link *Link;

Link head = NULL;

void append(int data)
{
	Link newLink = (Link)malloc(sizeof(struct Link));
	newLink->data = data;
	newLink->next = NULL;

	if (head == NULL)
	{
		head = newLink;
		return;
	}

	Link current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newLink;
}

void prepend(int data)
{
	Link newLink = (Link)malloc(sizeof(struct Link));
	newLink->data = data;
	newLink->next = head;
	head = newLink;
}

void pop()
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Link current = head;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
}

void popleft()
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Link temp = head;
	head = head->next;
	free(temp);
}

void nodeCount()
{
	int count = 0;
	Link current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	printf("Node count: %d\n", count);
}

void addPositional(int data, int position)
{
	Link newLink = (Link)malloc(sizeof(struct Link));
	newLink->data = data;
	newLink->next = NULL;

	if (head == NULL)
	{
		head = newLink;
		return;
	}

	Link current = head;
	int count = 0;
	while (current->next != NULL)
	{
		if (count == position-1)
		{
			newLink->next = current->next;
			current->next = newLink;
			return;
		}
		count++;
		current = current->next;
	}
}

void print()
{
	Link current = head;
	while (current != NULL)
	{
		printf("%d->", current->data);
		current = current->next;
	}
	printf("\n");
}

void dispMenu() {
	int data, choice;
	printf("1. Append\n");
	printf("2. Prepend\n");
	printf("3. Print\n");
	printf("4. Pop\n");
	printf("5. Pop Left\n");
	printf("6. Node Count\n");
	printf("7. Add Positional\n");
	printf("9. Exit\n");
	printf("Enter choice: ");
	scanf("%d", &choice);
	printf("\n");
	switch (choice)
	{
	case 1:
		printf("Enter data: ");
		scanf("%d", &data);
		append(data);
		break;

	case 2:
		printf("Enter data: ");
		scanf("%d", &data);
		prepend(data);
		break;
	case 3:
		print();
		break;
	case 4:
		pop();
		break;
	case 5:
		popleft();
		break;
	case 6:
		nodeCount();
		break;
	case 7:
		printf("Enter data: ");
		scanf("%d", &data);
		printf("Enter position: ");
		scanf("%d", &choice);
		addPositional(data, choice);
		break;
	case 9:
		exit(0);
	
	default:
		break;
	}
}

int main() {
	while (1) {
		dispMenu();
	}
	return 0;
}

