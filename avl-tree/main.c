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

int main()
{
	// 1. Initialize an empty AVL Tree.
	// 2. Insert multiple values.
	// 3. Print the inOrder traversal of the AVL Tree.
	// 4. (You can add more functionalities to test if desired.)
}
