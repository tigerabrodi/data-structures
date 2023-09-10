#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

Node *insert_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
void print_list(Node *head);

int main()
{
	Node *list1_head = NULL;

	list1_head = insert_at_head(list1_head, 1);

	print_list(list1_head);

	return 0;
}

Node *delete_at_tail(Node *head)
{
	if (head == NULL)
		return NULL;
	else if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		Node *current = head;
		Node *prev = NULL;

		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}

		prev->next = NULL;
		free(current);
		return head;
	}
}

Node *delete_at_head(Node *head)
{
	if (head == NULL)
		return NULL;
	else
	{
		Node *new_head = head->next;
		free(head);
		return new_head;
	}
}

Node *insert_at_tail(Node *head, int new_value)
{
	Node *new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;

	if (head == NULL)
		return new_node;
	else
	{
		Node *current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		return head;
	}
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