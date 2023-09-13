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