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
	AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
	// 2. Set the node's data with the provided data.
	newNode->data = data;
	// 3. Initialize the left and right pointers to NULL.
	newNode->left = NULL;
	newNode->right = NULL;
	// 4. Set the height of the node to 1 (considering itself).
	newNode->height = 1;
	// 5. Return the new node.
	return newNode;
}

// Right rotation for AVL tree balancing.
AVLNode *rightRotate(AVLNode *y)
{
	// The main idea: We are moving 'x' up and 'y' down to the right of 'x'.

	// Step 1: Set 'x' as the left child of 'y'.
	// - We need to access 'x' because 'x' will become our new root of the rotated subtree.
	AVLNode *x = y->left;

	// Step 2: Store the subtree 'B'.
	// - This is necessary because after the rotation, 'B' will move to be the left child of 'y'.
	// - If we don't store it, we'll lose access to it.
	AVLNode *T3 = x->right;

	// Step 3: Perform the Rotation.

	// Step 3.1: 'x' is the new root of this rotated subtree. So, the right child of 'x' should now point to 'y'.
	// TODO: Assign 'y' to the right child pointer of 'x'.
	x->right = y;

	// Step 3.2: 'y' is now one level down from its original position and on the right side of 'x'.
	// Its left child will now be the subtree 'B' (which we stored in 'T3').
	y->left = T3;

	// Step 4: Update heights.

	// Step 4.1: First, update the height of 'y'.
	// The height of any node = 1 + maximum of the heights of its left and right children.
	int yLeftHeight = getHeight(y->left);
	int yRightHeight = getHeight(y->right);
	y->height = (yLeftHeight > yRightHeight ? yLeftHeight : yRightHeight) + 1;

	// Step 4.2: Now, update the height of 'x'.
	// We are updating 'x' after 'y' because 'y' is now a child of 'x', and its height may have changed.
	int xLeftHeight = getHeight(x->left);
	int xRightHeight = getHeight(x->right);

	x->height = (xLeftHeight > xRightHeight ? xLeftHeight : xRightHeight) + 1;

	// Step 5: Return the new root.
	return x;
}

// Left rotation for AVL tree balancing.
AVLNode *leftRotate(AVLNode *x)
{
	// 1. Set 'y' as the right child of 'x' and 'T2' as the left child of 'y'.
	AVLNode *y = x->right;
	AVLNode *T2 = y->left;
	// 2. Perform rotation similarly to rightRotate but in the opposite direction.
	y->left = x;
	x->right = T2;
	// 3. Update heights.
	int xLeftHeight = getHeight(x->left);
	int xRightHeight = getHeight(x->right);
	x->height = (xLeftHeight > xRightHeight ? xLeftHeight : xRightHeight) + 1;

	int yLeftHeight = getHeight(y->left);
	int yRightHeight = getHeight(y->right);
	y->height = (yLeftHeight > yRightHeight ? yLeftHeight : yRightHeight) + 1;
	// 4. Return 'y' as the new root.

	return y;
}

// Insert a new data value into the AVL tree.
AVLNode *insert(AVLNode *node, int data)
{
	// 1. If the node is NULL, create a new node with the data and return it.

	if (!node)
		return createNewNode(data);

	// 2. If the data is less than node's data, insert it into the left subtree.
	if (data < node->data)
	{
		node->left = insert(node->left, data);
	}

	// 3. If the data is greater, insert it into the right subtree.
	if (data > node->data)
	{
		node->right = insert(node->right, data);
	}

	// 4. Update the height of the node.
	node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

	// 6. Check the balance factor to see if node became unbalanced after insertion.
	int balanceFactor = getBalanceFactor(node);

	// Step 6.1: Left-Left (LL) Imbalance: Perform Right Rotation.
	if (balanceFactor > 1 && data < node->left->data)
	{
		return rightRotate(node);
	}

	// Step 6.2: Right-Right (RR) Imbalance: Perform Left Rotation.
	if (balanceFactor < -1 && data > node->right->data)
	{
		return leftRotate(node);
	}

	// Step 6.3: Left-Right (LR) Imbalance: Perform Left Rotation on Left Child, then Right Rotation.
	if (balanceFactor > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Step 6.4: Right-Left (RL) Imbalance: Perform Right Rotation on Right Child, then Left Rotation.
	if (balanceFactor < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	// 7. Return the possibly updated node.
	return node;
}

// Print the AVL tree in in-order traversal.
void inOrder(AVLNode *root)
{
	// 1. If root is NULL, return immediately.
	if (!root)
		return;

	// 2. Recursively traverse the left subtree.
	inOrder(root->left);
	// 3. Print root's data.
	printf("%d ", root->data);
	// 4. Recursively traverse the right subtree.
	inOrder(root->right);
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
