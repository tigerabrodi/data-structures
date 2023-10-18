#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode
{
	int data;
	int height; // to store the height of the subtree rooted at this node
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;

typedef struct AVLTree
{
	AVLNode *root;
} AVLTree;

// Utility function to get the height of a node.
int getHeight(AVLNode *node);

// Utility function to get the balance factor of a node.
int getBalanceFactor(AVLNode *node);

// Utility function to swap two values.
void swap(int *a, int *b);

// A utility function to create a new AVL node with given key.
AVLNode *createNewNode(int data);

// Function to perform a right rotation.
AVLNode *rightRotate(AVLNode *y);

// Function to perform a left rotation.
AVLNode *leftRotate(AVLNode *x);

// Function to insert a key in the subtree rooted with node.
AVLNode *insert(AVLNode *node, int data);

// A utility function to print in-order traversal.
void inOrder(AVLNode *root);

#include <stdio.h>
#include <stdlib.h>

// Define AVL node structure.
typedef struct AVLNode
{
	int data;
	int height;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;

// Get the height of a given node.
int getHeight(AVLNode *node)
{
	if (!node)
		return 0;
	return node->height;
}

// Calculate the balance factor of a node.
int getBalanceFactor(AVLNode *node)
{
	// 1. If node is NULL, return 0.
	if (!node)
		return 0;
	// 2. Return the difference between the height of the left child and the height of the right child.
	return getHeight(node->left) - getHeight(node->right);
}

// Swap the values of two integers.
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Create a new AVL tree node.
AVLNode *createNewNode(int data)
{
	// 1. Dynamically allocate memory for a new AVLNode.
	// 2. Set the node's data with the provided data.
	// 3. Initialize the left and right pointers to NULL.
	// 4. Set the height of the node to 1 (considering itself).
	// 5. Return the new node.
}

// Right rotation for AVL tree balancing.
AVLNode *rightRotate(AVLNode *y)
{
	// 1. Set 'x' as the left child of 'y' and 'T3' as the right child of 'x'.
	// 2. Perform rotation: Set the right child of 'x' as 'y' and left child of 'y' as 'T3'.
	// 3. Update heights of 'y' and 'x'.
	// 4. Return 'x' as the new root.
}

// Left rotation for AVL tree balancing.
AVLNode *leftRotate(AVLNode *x)
{
	// 1. Set 'y' as the right child of 'x' and 'T2' as the left child of 'y'.
	// 2. Perform rotation similarly to rightRotate but in the opposite direction.
	// 3. Update heights.
	// 4. Return 'y' as the new root.
}

// Insert a new data value into the AVL tree.
AVLNode *insert(AVLNode *node, int data)
{
	// 1. If the node is NULL, create a new node with the data and return it.
	// 2. If the data is less than node's data, insert it into the left subtree.
	// 3. If the data is greater, insert it into the right subtree.
	// 4. Update the height of the node.
	// 5. Calculate balance factor to check if the node became unbalanced after insertion.
	// 6. Based on the balance factor and the value of data, decide the type of rotation needed.
	// 7. Return the possibly updated node.
}

// Print the AVL tree in in-order traversal.
void inOrder(AVLNode *root)
{
	// 1. If root is NULL, return immediately.
	// 2. Recursively traverse the left subtree.
	// 3. Print root's data.
	// 4. Recursively traverse the right subtree.
}

int main()
{
	AVLNode *root = NULL; // Start with an empty AVL tree.

	// Insert elements into AVL tree.
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	// Print AVL tree in in-order to see sorted order.
	inOrder(root);

	return 0;
}
