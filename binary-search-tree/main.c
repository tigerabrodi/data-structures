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
	Node *current = tree->root;
	Node *parent = NULL;

	// Search for the node to delete.
	while (current != NULL && current->value != value)
	{
		parent = current;
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

	// Node with only one child or no child.
	if (current->left == NULL || current->right == NULL)
	{
		Node *temp;
		if (current->left == NULL)
		{
			temp = current->right;
		}
		else
		{
			temp = current->left;
		}

		// Node to be deleted is the root.
		if (parent == NULL)
		{
			tree->root = temp;
		}
		else
		{
			if (current == parent->left)
			{
				parent->left = temp;
			}
			else
			{
				parent->right = temp;
			}
		}

		free(current);
		return;
	}

	// Node with two children; get the in-order successor (smallest in the right subtree).
	Node *successor = current->right;
	Node *successorParent = current;

	while (successor->left != NULL)
	{
		successorParent = successor;
		successor = successor->left;
	}

	// Copy the successor's value to the node to be deleted.
	current->value = successor->value;

	// Delete the in-order successor.
	if (successorParent->left == successor)
	{
		successorParent->left = successor->right;
	}
	else
	{
		successorParent->right = successor->right;
	}

	free(successor);
}

void inorder_traversal(Node *node)
{
	if (node == NULL)
	{
		return;
	}

	inorder_traversal(node->left);
	printf("%d ", node->value);
	inorder_traversal(node->right);
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
