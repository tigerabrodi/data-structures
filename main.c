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
Node *reverse_list(Node *head);
Node *insert_after(Node *head, int new_value, int after_value);
Node *add_values_of_two_lists(Node *head1, Node *head2);
Node *duplicate_list_and_return_new_head(Node *node);
void delete_list(Node *head);
bool is_member(Node *head, int value);
int count_matches(Node *head, int value);
int get_length(Node *head);
void print_list(Node *head);
void replaces_matches(Node *head, int old_value, int new_value);
void sort_list(Node *head);
void delete_duplicates(Node *head);

int main()
{
	Node *list1_head = NULL;

	list1_head = insert_at_head(list1_head, 1);

	print_list(list1_head);

	return 0;
}

Node *duplicate_list_and_return_new_head(Node *original_head)
{
	if (original_head == NULL)
		return NULL;

	Node *new_head = calloc(1, sizeof(Node));
	new_head->value = original_head->value;
	new_head->next = NULL;

	Node *current1 = original_head->next;
	Node *current2 = new_head;

	while (current1 != NULL)
	{
		// Duplicate the node from the original list
		Node *new_node = calloc(1, sizeof(Node));
		new_node->value = current1->value;
		new_node->next = NULL;

		// Link the new node to the end of the new list
		current2->next = new_node;

		// Move to the next nodes
		current1 = current1->next;
		current2 = current2->next;
	}

	return new_head;
}

Node *add_values_of_two_lists(Node *head1, Node *head2)
{
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL && head2 != NULL)
		return head2;

	if (head2 == NULL && head1 != NULL)
		return head1;

	Node *current1 = head1;
	Node *current2 = head2;
	Node *new_head = NULL;

	if (current1->next == NULL && current2->next == NULL)
	{
		new_head = calloc(1, sizeof(Node));
		new_head->value = current1->value + current2->value;
		return new_head;
	}

	while (current1->next != NULL && current2->next != NULL)
	{
		if (new_head == NULL)
		{
			new_head = calloc(1, sizeof(Node));
			new_head->value = current1->value + current2->value;
		}
		else
		{
			Node *new_node = calloc(1, sizeof(Node));
			new_node->value = current1->value + current2->value;
			new_head->next = new_node;
			// move new head to the next node to continue traversing
			new_head = new_head->next;
		}
		current1 = current1->next;
		current2 = current2->next;
	}
}

void delete_list(Node *head)
{
	if (head == NULL)
		return NULL;

	delete_list(head->next);

	// After the recursive call returns, it's safe to free the current node.
	free(head);
}

Node *insert_after(Node *head, int new_value, int after_value)
{
	Node *new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;

	if (head == NULL)
		return new_node;
	else
	{
		Node *current = head;

		while (current != NULL)
		{
			if (current->value == after_value)
			{
				new_node->next = current->next;

				current->next = new_node;

				return head;
			}
			current = current->next;
		}

		return head;
	}
}

void delete_duplicates(Node *head)
{
	if (head == NULL)
		return;

	if (head->next == NULL)
		return;

	Node *current1, *current2, *duplicate;

	current1 = head;

	while (current1 != NULL && current1->next != NULL)
	{
		current2 = current1;

		while (current2->next != NULL)
		{
			if (current1->value == current2->next->value)
			{
				duplicate = current2->next;
				current2->next = current2->next->next;
				free(duplicate);
			}
			else
				current2 = current2->next;
		}

		current1 = current1->next;
	}
}

void sort_list(Node *head)
{
	if (head == NULL)
		return;

	if (head->next == NULL)
		return;

	bool swapped = false;

	do
	{
		swapped = false;
		Node *current = head;
		Node *prev = NULL;

		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
			if (current != NULL)
			{
				if (prev->value > current->value)
				{
					int temp = prev->value;
					prev->value = current->value;
					current->value = temp;
					swapped = true;
				}
			}
		}

	} while (swapped);
}

// Function to reverse a singly linked list
Node *reverse_list(Node *head)
{
	// If the list is empty, we just return NULL.
	if (head == NULL)
		return NULL;

	// If there's only one node in the list, it remains the same when reversed.
	if (head->next == NULL)
		return head;

	// Initialize 'current' to point to the first node of the list.
	Node *current = head;

	// Initialize 'next_node' to point to the second node of the list (or NULL if it doesn't exist).
	Node *next_node = head->next;

	// Set the next of the head node to NULL. This will be the tail once the list is reversed.
	current->next = NULL;

	// Iterate through the list to reverse the direction of each node.
	while (next_node != NULL)
	{
		// Capture the node following 'next_node' before we change 'next_node's next pointer.
		Node *temp = next_node->next;

		// Redirect the 'next_node's next pointer back to the 'current' node.
		// This is where the actual reversal of the pointer direction happens for this node.
		next_node->next = current;

		// Move 'current' to where 'next_node' is.
		current = next_node;

		// Move to the next node in the original sequence.
		next_node = temp;
	}

	// At this point, the 'current' pointer points to the new head of the reversed list.
	// Return this new head.
	return current;
}

// append
Node *append_lists(Node *head1, Node *head2)
{
	if (head1 == NULL)
		return head2;

	Node *current = head1;
	while (current->next != NULL)
		current = current->next;
	current->next = head2;

	return head1;
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