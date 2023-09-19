#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	int capacity;
	int size;
} Heap;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_up(Heap *heap, int index)
{
	// 1. Determine if we're at the root node.
	//    - If the current index is 0, we are at the root. No further action is needed.
	//    - Hint: Use a conditional statement to check the index value.

	// 2. If we're not at the root, find the parent node's index.
	//    - Use the formula: (index - 1) / 2.
	//    - Store the result in an integer variable, e.g., parent_index.

	// 3. Compare the current node's value with the parent node's value.
	//    - Access the heap data using heap->data[index] and heap->data[parent_index].

	// 4. Check if the current node's value is smaller than its parent's value (because we're building a min-heap).
	//    - If it's smaller:
	//       a. Swap the values of the current node and its parent node.
	//          - Hint: Use the swap function with addresses of the two values.
	//       b. Since we made a swap, we need to ensure the properties of the heap are maintained.
	//          - Call bubble_up recursively, but this time with the parent_index.
}

void bubble_down(Heap *heap, int index)
{
	// 1. Calculate the indices of the left and right children.
	//    - Use the formulas: left_child = 2 * index + 1 and right_child = 2 * index + 2.

	// 2. Check if the current node (index) is out of the heap's bounds.
	//    - If index >= heap->size, then the current node doesn't exist, and we can simply return.
	//    - Hint: Use a conditional statement to exit early if the index is out of bounds.

	// 3. Find out which child (left or right) has a smaller value.
	//    - First, ensure both children exist. If only one exists, use that one.
	//    - Otherwise, compare the values of both children and decide which is smaller.
	//    - Store the index of the smaller child in a variable, e.g., smaller_child_index.
	//    - Hint: You may need a couple of conditional statements to handle these checks.

	// 4. Now, compare the current node's value with the smaller child's value.
	//    - If the current node's value is larger (since this is a min-heap):
	//       a. Swap the values of the current node and the smaller child node.
	//          - Hint: Use the swap function with addresses of the two values.
	//       b. We need to ensure the properties of the heap below this node.
	//          - Call bubble_down recursively, but this time with the smaller_child_index.
}

// Initialize a heap with a given capacity.
Heap *init_heap(int capacity)
{
	// 1. Allocate memory for the Heap struct itself using malloc().
	// 2. Check if memory allocation was successful.
	// 3. Initialize the heap's capacity with the given value.
	// 4. Set the heap's size to 0.
	// 5. Allocate memory for the heap's data array using malloc().
	// 6. Check if memory allocation for data was successful.
	// 7. Return the initialized heap.
}

// Insert a new element into the heap.
void insert(Heap *heap, int value)
{
	// 1. Check if the heap is full. If so, you can resize or return an error.
	// 2. Add the new element to the next available position in the data array.
	// 3. Increase the heap's size.
	// 4. "Bubble up" the new element:
	//    a. While the inserted element is smaller than its parent:
	//       i. Swap the element with its parent.
	//       ii. Update the current position to be the parent's position.
}

// Get (and remove) the smallest element from the heap.
int pop_min(Heap *heap)
{
	// 1. Ensure the heap isn't empty.
	// 2. Save the top value (this is the minimum for a min-heap).
	// 3. Move the last value in the heap to the top.
	// 4. Reduce the size of the heap by one.
	// 5. "Bubble down" the swapped value to its proper position:
	//    a. While the element has children and is larger than at least one of its children:
	//       i. Identify the smallest child.
	//       ii. Swap the element with the smallest child.
	//       iii. Update the current position to the child's position.
	// 6. Return the saved top value.
}

int peek(Heap *heap)
{
	// 1. Ensure the heap isn't empty.
	if (heap->size == 0)
	{
		printf("Error: heap is empty\n");
		return -1;
	}

	return heap->data[0];
}

void free_heap(Heap *heap)
{
	free(heap->data);
	free(heap);
}

int main()
{
	// 1. Initialize the heap with some capacity, say 10.
	Heap *heap = heap_init(10);

	// 2. Insert some elements.
	heap_insert(heap, 5);
	heap_insert(heap, 2);
	heap_insert(heap, 8);
	heap_insert(heap, 1);

	// 3. Peek the minimum element. Should be 1.
	printf("Min element: %d\n", heap_peek(heap));

	// 4. Extract the minimum element. Should extract 1.
	printf("Extracted element: %d\n", heap_extract_min(heap));

	// 5. Again peek the minimum element. Now it should be 2.
	printf("Min element: %d\n", heap_peek(heap));

	// 6. Cleanup by freeing heap memory.
	heap_free(heap);

	return 0;
}