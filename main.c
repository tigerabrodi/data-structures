#include <stdio.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

void print_list(Node *head);

int main()
{
	Node a, b, c;
	a.value = 1;
	b.value = 2;
	c.value = 3;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	print_list(&a);

	return 0;
}

void print_list(Node *head)
{
	Node *current = head;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}