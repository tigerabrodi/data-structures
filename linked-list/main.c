#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main()
{
	Node *list1_head = NULL;

	list1_head = insert_at_head(list1_head, 1);

	print_list(list1_head);

	return 0;
}
