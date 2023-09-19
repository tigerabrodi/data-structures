#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
	if (index == 0)
	{
		return;
	}

	int parent_index = (index - 1) / 2; // formula to get parent index
	if (heap->data[index] < heap->data[parent_index])
	{
		swap(&heap->data[index], &heap->data[parent_index]);
		bubble_up(heap, parent_index);
	}
}

void bubble_down(Heap *heap, int index)
{
	// If index is out of heap's bounds
	if (index >= heap->size)
	{
		return;
	}

	int left_child_index = 2 * index + 1;
	int right_child_index = 2 * index + 2;

	// Initialize both children's values to an invalid value.
	// INT_MAX is a convenient value because we're working with a min-heap.
	int left_child = INT_MAX;
	int right_child = INT_MAX;

	// Check if child indices are within bounds before fetching values
	if (left_child_index < heap->size)
	{
		left_child = heap->data[left_child_index];
	}

	if (right_child_index < heap->size)
	{
		right_child = heap->data[right_child_index];
	}

	// impossible tbh
	if (right_child == INT_MAX && left_child == INT_MAX)
	{
		return;
	}

	int child_to_use;
	int child_index;

	if (left_child < right_child)
	{
		child_to_use = left_child;
		child_index = left_child_index;
	}
	else
	{
		child_to_use = right_child;
		child_index = right_child_index;
	}

	// If the current node is larger than the smallest child, swap and recurse
	if (heap->data[index] > child_to_use)
	{
		swap(&heap->data[index], child_to_use);
		bubble_down(heap, child_index);
	}
}

Heap *init_heap(int capacity)
{
	Heap *heap = malloc(sizeof(Heap));
	if (!heap)
	{
		printf("Error: memory allocation failed\n");
		return NULL;
	}
	heap->capacity = capacity;
	heap->size = 0;
	heap->data = malloc(sizeof(int) * capacity);
	if (!heap->data)
	{
		printf("Error: memory allocation failed\n");
		free(heap);
		return NULL;
	}

	return heap;
}

void insert(Heap *heap, int value)
{
	if (heap->size == heap->capacity)
	{
		printf("Error: heap is full\n");
		return;
	}

	heap->data[heap->size] = value;

	heap->size++;

	bubble_up(heap, heap->size - 1);
}

int pop_min(Heap *heap)
{
	if (heap->size == 0)
	{
		printf("Error: heap is empty\n");
		return -1;
	}

	int min_value = heap->data[0];

	heap->data[0] = heap->data[heap->size - 1];

	heap->size--;

	bubble_down(heap, 0);
	return min_value;
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