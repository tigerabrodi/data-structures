#include <stdio.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

void print_list(Node *head);

int main()
{

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