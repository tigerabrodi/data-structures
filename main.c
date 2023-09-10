#include <stdio.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

void print_list(Node *head);

int main()
{
	Node *list1_head = NULL;

	return 0;
}

Node *insert_at_head(Node *head, int new_value)
{
	Node *new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;

	if (head == NULL)
		return new_node;
	else
	{
		new_node->next = head;
		return new_node;
	}
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