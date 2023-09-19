#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	int *new_data = malloc(sizeof(int) * new_capacity);
	if (!new_data)
	{
		printf("Error: memory allocation failed\n");
		return;
	}

	for (size_t i = 0; i < arr->size; i++)
	{
		new_data[i] = arr->data[i];
	}

	free(arr->data);
	arr->data = new_data;
	arr->capacity = new_capacity;
}

void dynamic_array_append(DynamicArray *arr, int value)
{
	bool is_enough_capacity = arr->size < arr->capacity;
	if (is_enough_capacity)
	{
		arr->data[arr->size] = value;
		arr->size++;
	}
	else
	{
		dynamic_array_resize(arr, arr->capacity * 2);
		arr->data[arr->size] = value;
		arr->size++;
	}
}

void dynamic_array_pop(DynamicArray *arr)
{
	if (arr->size == 0)
	{
		printf("Error: array is empty\n");
		return;
	}

	arr->size--;
}

int dynamic_array_get(DynamicArray *arr, size_t index)
{
	// 1. Check if the index is valid (i.e., it's less than 'size').
	if (index <= arr->size)
	{
		return arr->data[index];
	}
	else
	{
		printf("Error: index out of bounds\n");
		return -1;
	}
}

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
