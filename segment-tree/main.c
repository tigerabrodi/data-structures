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
	// Step 1: Base Case - Single element segment.
	if (left == right)
	{
		segment_tree->tree[pos] = arr[left];
		return arr[left];
	}

	// Step 2: Recursive Breakdown - Splitting the segment.
	int mid = (left + right) / 2;
	int left_sum = build_tree(segment_tree, arr, left, mid, 2 * pos + 1);
	int right_sum = build_tree(segment_tree, arr, mid + 1, right, 2 * pos + 2);

	// Step 3: Aggregating Values - Combining the halves.
	int sum = left_sum + right_sum;
	segment_tree->tree[pos] = sum;

	// Step 4: Return the segment's sum.
	return sum;
}

int query_sum(SegmentTree *segment_tree, int query_start, int query_end, int left, int right, int pos)
{
	// Step 1: Total Overlap Case - The Query Range Completely Covers the Segment.
	if (query_start <= left && query_end >= right)
	{
		return segment_tree->tree[pos];
	}

	// Step 2: No Overlap Case - The Query Range and Segment Don't Intersect at All.
	if (query_start > right || query_end < left)
	{
		return 0;
	}

	// Step 3: Partial Overlap - The Query Range Partially Overlaps the Segment.
	int mid = (left + right) / 2;
	int left_sum = query_sum(segment_tree, query_start, query_end, left, mid, 2 * pos + 1);
	int right_sum = query_sum(segment_tree, query_start, query_end, mid + 1, right, 2 * pos + 2);

	// Step 4: Combine and Return - Gather Results from Children and Combine.
	int total_sum = left_sum + right_sum;
	return total_sum;
}

void update_value(SegmentTree *segment_tree, int arr[], int n, int i, int new_val)
{
	// Step 1: Calculate Difference Between New and Original Values.
	int diff = new_val - arr[i];

	// Step 2: Update the Original Array.
	arr[i] = new_val;

	// Step 3: Update the Segment Tree.
	update_tree(segment_tree, 0, n - 1, i, diff, 0);
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
