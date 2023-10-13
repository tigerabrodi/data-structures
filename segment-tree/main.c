#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *tree;    // The array that will store the segment tree nodes
	int max_size; // Maximum number of nodes in the tree
} SegmentTree;

void initialize_tree(SegmentTree *segment_tree, int original_arr[], int original_arr_total_length)
{
	// Step 1: Find the next power of 2.
	size_t next_power_of_2 = 1;

	while (next_power_of_2 < original_arr_total_length)
	{
		next_power_of_2 *= 2;
	}

	// Step 2: Calculate tree size.
	int size = (2 * next_power_of_2) - 1;
	segment_tree->max_size = size;

	// Step 3: Allocate memory for the tree.
	segment_tree->tree = malloc(size * sizeof(int));

	if (!segment_tree->tree)
	{
		printf("Error allocating memory for segment tree.\n");
		exit(1);
	}

	// Step 4: Initialize all tree nodes to 0.
	for (int i = 0; i < segment_tree->max_size - 1; i++)
	{
		segment_tree->tree[i] = 0;
	}

	// Step 5: Call build_tree to fill segment tree values.
	build_tree(segment_tree, original_arr, 0, original_arr_total_length - 1, 0);
}

int build_tree(SegmentTree *segment_tree, int arr[], int left, int right, int pos)
{
	// Step 1: Base case for leaf node.
	// - Check if `left` is equal to `right`.
	// - If true, set the tree node at position `pos` to arr[left] and return this value.

	// Step 2: Recursive case.
	// - Calculate midpoint `mid` of segment.
	// - Recursively build left subtree and store the returned value.
	// - Recursively build right subtree and store the returned value.

	// Step 3: Set current tree node value.
	// - Combine values from left and right subtree.
	// - Store this combined value at current tree node `pos`.

	// Step 4: Return current tree node value.
}

int query_sum(SegmentTree *segment_tree, int ql, int qr, int left, int right, int pos)
{
	// Step 1: Total overlap case.
	// - Check if `ql` is less than or equal to `left` and `qr` is greater than or equal to `right`.
	// - If true, return tree node value at position `pos`.

	// Step 2: No overlap case.
	// - Check if `ql` is greater than `right` or `qr` is less than `left`.
	// - If true, return 0 (since we're dealing with sums).

	// Step 3: Partial overlap.
	// - Compute the midpoint of segment.
	// - Get sum from left child.
	// - Get sum from right child.

	// Step 4: Return combined sum.
	// - Return sum of left child and right child.
}

void update_value(SegmentTree *segment_tree, int arr[], int n, int i, int new_val)
{
	// Step 1: Calculate difference.
	// - Find difference between new value and original value.

	// Step 2: Update array.
	// - Set arr[i] to new value.

	// Step 3: Propagate update to segment tree.
	// - Call update_tree function.
	// - Pass segment start, end, difference, and tree position.
}

void update_tree(SegmentTree *segment_tree, int left, int right, int i, int diff, int pos)
{
	// Step 1: Base case for out-of-bounds.
	// - If i is less than `l` or greater than `right`, just return.

	// Step 2: Update current tree node.
	// - Increment tree node at position `pos` by `diff`.

	// Step 3: If not a leaf node, propagate changes.
	// - Calculate midpoint.
	// - Update left child if `i` is less than or equal to midpoint.
	// - Otherwise, update right child.
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};			      // Original array
	int original_arr_total_length = sizeof(arr) / sizeof(arr[0]); // Length of the original array

	// Initialize and build the segment tree
	SegmentTree segment_tree;
	initialize_tree(&segment_tree, arr, original_arr_total_length);

	// Query sum
	int sum = query_sum(&segment_tree, 1, 3, 0, original_arr_total_length - 1, 0);
	printf("Sum of values in given range = %d\original_arr_total_length", sum); // Should output the sum of values from index 1 to 3

	// Update a value
	update_value(&segment_tree, arr, original_arr_total_length, 1, 10); // Update value at index 1 to 10

	// Query again to see the updated sum
	sum = query_sum(&segment_tree, 1, 3, 0, original_arr_total_length - 1, 0);
	printf("Updated sum of values in given range = %d\n", sum);

	// Clean-up if needed
	free(segment_tree.tree);

	return 0;
}
