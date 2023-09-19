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
	// 1. Check if the heap has reached its capacity.
	//    - If heap->size is equal to heap->capacity, then the heap is full.
	//    - You may either return an error message or resize the heap array to accommodate more elements.

	// 2. If there's space, insert the new value at the end of the array (heap->data).
	//    - Remember, heap->data[heap->size] will be the position of the new value.

	// 3. Increment the size of the heap.
	//    - This means increasing heap->size by 1.

	// 4. Now, it's time to ensure the min-heap property is maintained.
	//    - Start "bubbling up" the newly inserted value.
	//       a. Using a while loop or recursive function, check if the inserted value is smaller than its parent.
	//          i. Use the formula (current_index - 1) / 2 to get the parent's index.
	//          ii. If the value at the current position is less than its parent's value, swap them.
	//          iii. Set the current index to the parent's index and repeat the loop/recursive call.
}

int pop_min(Heap *heap)
{
	// 1. First, check if the heap is empty.
	//    - If heap->size is 0, print an error or handle it as you see fit. Possibly return a sentinel value like -1 or INT_MIN.

	// 2. Store the minimum value (which is at the top/root of the heap).
	//    - Use an integer variable, e.g., min_value = heap->data[0].

	// 3. Replace the root of the heap with the last element in the heap.
	//    - This means setting heap->data[0] to heap->data[heap->size - 1].

	// 4. Now, decrease the size of the heap.
	//    - Decrement heap->size by 1.

	// 5. As we've disturbed the min-heap property by replacing the root, we need to "bubble down".
	//    - Using a loop or recursive function, perform the following while the current element has children:
	//       a. Determine the index of the smaller child (could be left or right).
	//       b. If the current value is larger than the smallest child's value, swap them.
	//       c. Update the current position to the swapped child's position and repeat.

	// 6. After the element has been bubbled down to its appropriate position, you can return the stored min_value.
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