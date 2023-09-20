#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node in the BST.
typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
} Node;

// Define the structure of the BST.
typedef struct
{
	Node *root;
} BST;

// Function declarations.
Node *create_node(int value);
BST *create_bst();
void insert(BST *tree, int value);
Node *search(BST *tree, int value);
void delete(BST *tree, int value);
void inorder_traversal(Node *node); // For testing purposes.

Node *create_node(int value)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Error: memory allocation failed\n");
		return NULL;
	}
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

BST *create_bst()
{
	BST *new_bst = (BST *)malloc(sizeof(BST));
	if (new_bst == NULL)
	{
		printf("Error: memory allocation failed\n");
		return NULL;
	}
	new_bst->root = NULL;
	return new_bst;
}

void insert(BST *tree, int value)
{
	Node *current = tree->root;
	if (current == NULL)
	{
		tree->root = create_node(value);
		return;
	}

	while (current != NULL)
	{
		if (value < current->value)
		{
			if (current->left == NULL)
			{
				current->left = create_node(value);
				return;
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				current->right = create_node(value);
				return;
			}
			current = current->right;
		}
	}
}

Node *search(BST *tree, int value)
{
	Node *current = tree->root;
	while (current != NULL)
	{
		if (value == current->value)
		{
			return current;
		}
		else if (value < current->value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	return NULL;
}

void delete(BST *tree, int value)
{
	// 1. Initialization
	// 1.1. Declare and initialize two pointers:
	//      - `current` pointing to tree->root (to find the node with the target value)
	//      - `parent` set to NULL (to keep track of `current` node's parent)
	Node *current = tree->root;
	Node *parent = NULL;

	// 2. Loop through the tree to find the node to delete (and its parent)
	// 2.1. Set up a `while` loop with conditions to check:
	//      - `current` is not NULL
	//      - `current` value doesn't match the value to delete

	while (current != NULL && current->value != value)
	{
		// 2.2. Inside the loop:
		// 2.2.1. Store the current node in `parent` before updating `current`
		parent = current;

		// 2.2.2. Decide which direction to move:
		//      - If the value to delete is LESS than `current->value`,
		//        set `current` to `current->left`
		//      - ELSE set `current` to `current->right`
		if (value < current->value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	if (current == NULL)
	{
		printf("Value not found\n");
		return;
	}

	if (current->left == NULL && current->right == NULL)
	{
		if (parent->left == current)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}

		free(current);
		return;
	}

	if (current->left != NULL && current->right == NULL)
	{
		if (parent->left == current)
		{
			parent->left = current->left;
		}
		else
		{
			parent->right = current->left;
		}

		free(current);
		return;
	}

	if (current->left == NULL && current->right != NULL)
	{
		if (parent->left == current)
		{
			parent->left = current->right;
		}
		else
		{
			parent->right = current->right;
		}

		free(current);
		return;
	}

	if (current->left != NULL && current->right != NULL)
	{
		Node *successor = current->right;
		while (successor->left != NULL)
		{
			successor = successor->left;
		}
		current->value = successor->value;
		delete (tree, successor->value);
		return;
	}

	if (parent == NULL)
	{
		if (current->left != NULL && current->right == NULL)
		{
			tree->root = current->left;
		}
		else if (current->left == NULL && current->right != NULL)
		{
			tree->root = current->right;
		}
		else
		{
			Node *successor = current->right;
			while (successor->left != NULL)
			{
				successor = successor->left;
			}
			current->value = successor->value;
			delete (tree, successor->value);
			return;
		}
	}

	if (parent->left == current)
	{
		parent->left = NULL;
	}
	else
	{
		parent->right = NULL;
	}

	free(current);
}

void inorder_traversal(Node *node)
{
	// 1. Check if 'node' is not NULL. If it's NULL, you can simply return.
	// 2. Recursively call inorder_traversal on the 'left' child of 'node'.
	// 3. Print the value of 'node'.
	// 4. Recursively call inorder_traversal on the 'right' child of 'node'.
}

int main()
{
	// Create a new BST.
	BST *tree = create_bst();

	// Insert some values.
	insert(tree, 50);
	insert(tree, 30);
	insert(tree, 70);
	insert(tree, 20);
	insert(tree, 40);
	insert(tree, 60);
	insert(tree, 80);

	// Print the BST in-order to see if values are inserted correctly.
	printf("In-order Traversal After Insertions:\n");
	inorder_traversal(tree->root);
	printf("\n");

	// Search for some values.
	printf("Search 25: %s\n", search(tree, 25) ? "Found" : "Not Found");
	printf("Search 70: %s\n", search(tree, 70) ? "Found" : "Not Found");

	// Delete some values and print the BST after each deletion.
	delete (tree, 20);
	printf("\nIn-order Traversal After Deleting 20:\n");
	inorder_traversal(tree->root);
	printf("\n");

	delete (tree, 30);
	printf("\nIn-order Traversal After Deleting 30:\n");
	inorder_traversal(tree->root);
	printf("\n");

	delete (tree, 50);
	printf("\nIn-order Traversal After Deleting 50:\n");
	inorder_traversal(tree->root);
	printf("\n");

	return 0;
}
