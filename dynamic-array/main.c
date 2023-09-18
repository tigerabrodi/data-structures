#include <stdio.h>
#include <stdlib.h>

// The DynamicArray struct should contain a pointer to the underlying array,
// the current size (number of elements actually stored), and its capacity (maximum number of elements it can store without resizing).
typedef struct
{
	int *data;
	size_t size;
	size_t capacity;
} DynamicArray;

DynamicArray *dynamic_array_init(size_t initial_capacity)
{
	DynamicArray *arr = malloc(sizeof(DynamicArray));
	if (!arr)
	{
		printf("Error: memory allocation failed\n");
		return NULL;
	}
	arr->capacity = initial_capacity ? initial_capacity : 4;
	arr->data = malloc(sizeof(int) * arr->capacity);
	if (!arr->data)
	{
		printf("Error: memory allocation failed\n");
		free(arr);
		return NULL;
	}

	arr->size = 0;
	return arr;
}

void dynamic_array_resize(DynamicArray *arr, size_t new_capacity)
{
	// 1. Allocate new memory of size 'new_capacity'.
	// 2. Copy elements from old array to the new one.
	// 3. Free the old array memory.
	// 4. Update the data pointer in 'arr' to point to the new memory.
	// 5. Update 'capacity' to 'new_capacity'.
}

// Add an element to the end of the dynamic array
void dynamic_array_append(DynamicArray *arr, int value)
{
	// 1. Check if there is enough capacity to add a new element.
	// 2. If not, resize the array (typically to double its current capacity).
	// 3. Add the new element.
	// 4. Increment the 'size'.
}

// Remove the last element of the dynamic array
void dynamic_array_pop(DynamicArray *arr)
{
	// 1. Check if the array is empty.
	// 2. If not, decrement the 'size'.
	// 3. (Optional) If size is much smaller than capacity, you may decide to reduce the capacity to save memory.
}

// Access an element at a particular index
int dynamic_array_get(DynamicArray *arr, size_t index)
{
	// 1. Check if the index is valid (i.e., it's less than 'size').
	// 2. Return the element at the specified index.
}

// Free the dynamic array
void dynamic_array_free(DynamicArray *arr)
{
	// 1. Free the underlying data array.
	// 2. Free the dynamic array structure itself.
}

int main()
{
	DynamicArray *arr = dynamic_array_init(4);

	dynamic_array_append(arr, 1);
	dynamic_array_append(arr, 2);
	dynamic_array_append(arr, 3);
	dynamic_array_append(arr, 4);
	dynamic_array_append(arr, 5); // This should trigger a resize operation

	printf("Element at index 3: %d\n", dynamic_array_get(arr, 3)); // Expected: 4

	dynamic_array_pop(arr);
	printf("After pop, last element: %d\n", dynamic_array_get(arr, arr->size - 1)); // Expected: 4

	dynamic_array_free(arr);

	return 0;
}
