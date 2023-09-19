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
	// 1. Check if we're at the root of the heap (index 0). If so, return since we can't go up further.
	// 2. Compute the parent index: (index - 1) / 2.
	// 3. Compare the value at the current index with the value at the parent index.
	// 4. If the current value is smaller than its parent (since this is a min-heap), then:
	//    - Swap the values.
	//    - Recursively bubble up using the parent index.
}

void bubble_down(Heap *heap, int index)
{
	// 1. Compute left and right child indices: 2 * index + 1 and 2 * index + 2, respectively.
	// 2. If the current index is out of bounds (i.e., >= heap->size), simply return.
	// 3. Determine which of the left or right child is smaller.
	// 4. If the current value is greater than the smaller child:
	//    - Swap with the smaller child.
	//    - Recursively bubble down using the smaller child's index.
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