#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

Node *insert_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted);
Node *efficient_delete_matches(Node *head, int delete_value, int *num_deleted);
Node *append_lists(Node *head1, Node *head2);
bool is_member(Node *head, int value);
int count_matches(Node *head, int value);
int get_length(Node *head);
void print_list(Node *head);
void replaces_matches(Node *head, int old_value, int new_value);

int main()
{
	Node *list1_head = NULL;

	list1_head = insert_at_head(list1_head, 1);

	print_list(list1_head);

	return 0;
}

Node *efficient_delete_matches(Node *head, int delete_value, int *num_deleted)
{
	*num_deleted = 0;

	if (head == NULL)
		return NULL;

	Node *current, *temp, *new_head;

	current = head;

	while (current->value == delete_value)
	{
		temp = current;
		current = current->next;
		free(temp);
		*num_deleted += 1;

		if (current == NULL)
			return NULL;
	}

	new_head = current;

	while (current->next != NULL)
	{
		if (current->next->value == delete_value)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*num_deleted += 1;
		}
		else
			// Only advance if there was no deletion
			current = current->next;
	}
}

Node *delete_all_matches(Node *head, int delete_value, int *num_deleted)
{
	Node *current = head;
	bool deleted = false;
	*num_deleted = 0;

	do
	{
		current = delete_first_match(current, delete_value, &deleted);

		if (deleted)
			*num_deleted += 1;
	} while (deleted);

	return current;
}

Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
	if (head == NULL)
	{
		*was_deleted = false;
		return NULL;
	}

	if (head->value == delete_value)
	{
		Node *temp = head->next;
		free(head);
		*was_deleted = true;
		return temp;
	}

	Node *current = head->next;
	Node *prev = head;

	while (current != NULL)
	{

		if (current->value == delete_value)
		{
			prev->next = current->next;
			free(current);
			*was_deleted = true;
			return head;
		}

		prev = current;
		current = current->next;
	}

	*was_deleted = false;
	return head;
}

void replaces_matches(Node *node, int old_value, int new_value)
{
	if (node != NULL)
	{
		if (node->value == old_value)
			node->value = new_value;
		replaces_matches(node->next, old_value, new_value);
	}
}

int count_matches(Node *node, int value)
{
	if (node == NULL)
		return 0;
	else if (node->value == value)
		return 1 + count_matches(node->next, value);
	else
		return count_matches(node->next, value);
}

bool is_member(Node *node, int value)
{
	if (node == NULL)
		return false;
	else if (node->value == value)
		return true;
	else
		return is_member(node->next, value);
}

int get_length(Node *head)
{
	int length = 0;
	Node *current = head;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return length;
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