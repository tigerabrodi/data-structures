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

Node *search(BST *tree, int value)
{
	// 1. Create a Node pointer called 'current' and set it to the root of the tree.
	// 2. Use a while loop to navigate through the tree as long as 'current' is not NULL.
	// 3. In each iteration, compare 'value' with the value of 'current':
	//    a. If they're equal, return 'current' (you've found the node).
	//    b. If 'value' is less than the value of 'current', set 'current' to its 'left' child.
	//    c. Otherwise, set 'current' to its 'right' child.
	// 4. If you exit the loop without returning, this means the value is not in the tree. Return NULL.
}

void delete(BST *tree, int value)
{
	// 1. You'll need two pointers: one called 'current' to navigate and another called 'parent' to keep track of the parent node. Initialize both to NULL.
	// 2. First, find the node (and its parent) to be deleted using a loop similar to the search function.
	// 3. Once you find the node:
	//    a. If it's a leaf node (both left and right are NULL):
	//       - Check if it's a left or right child of its parent and set the corresponding pointer of the parent to NULL.
	//       - Free the node.
	//    b. If the node has only one child (either left or right, but not both):
	//       - Bypass the node: if the node is the left child of its parent, set the left child of the parent to the child of the node.
	//       - If the node is the right child of its parent, set the right child of the parent to the child of the node.
	//       - Free the node.
	//    c. If the node has two children:
	//       - Find either the in-order predecessor or the in-order successor of the node.
	//       - Copy its value to the node.
	//       - Then, delete the in-order predecessor/successor.
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
