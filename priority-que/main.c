#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for malloc, realloc and free

typedef struct
{
	int value;
	int priority;
} Node;

typedef struct
{
	Node *nodes;  // Array to store heap elements
	int capacity; // Capacity of the priority queue
	int size;     // Current number of elements in the priority queue
} PriorityQueue;

PriorityQueue *init_priority_queue(int capacity)
{
	// 1. Use malloc to allocate memory for a new PriorityQueue structure.
	PriorityQueue *PQ = malloc(sizeof(PriorityQueue));

	// 2. Check if the malloc call succeeded. If not, handle the error (e.g., return NULL).
	if (!PQ)
	{
		return NULL;
	}

	// 3. Set the 'capacity' field of the newly created PriorityQueue structure to the provided capacity.
	PQ->capacity = capacity;

	// 4. Set the 'size' field to 0.
	PQ->size = 0;

	// 5. Use malloc to allocate memory for an array of Nodes of size 'capacity' to act as the heap storage.
	PQ->nodes = malloc(capacity * sizeof(Node));

	// 6. Check if the malloc call for the nodes succeeded. If not, handle the error (e.g., free previously allocated memory and return NULL).
	if (!PQ->nodes)
	{
		free(PQ);
		return NULL;
	}

	// 7. Return the pointer to the initialized PriorityQueue structure.
	return PQ;
}

int parent(int index)
{
	// 1. Calculate the index of the parent node using the formula.
	int parent_index = (index - 1) / 2;
	// 2. Return the calculated index.
	return parent_index;
}

int left_child(int index)
{
	// 1. Calculate the index of the left child using the formula.
	int left_index = (2 * index) + 1;
	// 2. Return the calculated index.
	return left_index;
}

int right_child(int index)
{
	// 1. Calculate the index of the right child using the formula.
	int right_index = (2 * index) + 2;
	// 2. Return the calculated index.
	return right_index;
}

bool insert_into_priority_queue(PriorityQueue *PQ, int value, int priority)
{
	// Step 1: Capacity Check
	if (PQ->size == PQ->capacity)
	{
		return false;
	}

	// Step 2: Node Creation
	PQ->nodes[PQ->size].value = value;
	PQ->nodes[PQ->size].priority = priority;

	// Step 3: Bubble Up
	int current_index = PQ->size;
	while (true)
	{
		int parent_index = parent(current_index);
		if (PQ->nodes[current_index].priority > PQ->nodes[parent_index].priority)
		{
			Node temp = PQ->nodes[current_index];
			PQ->nodes[current_index] = PQ->nodes[parent_index];
			PQ->nodes[parent_index] = temp;
			current_index = parent_index;
		}
		else
		{
			break;
		}
	}

	// Step 4: Final Adjustments
	PQ->size++;
	return true;
}

bool delete_from_priority_queue(PriorityQueue *PQ, int *value)
{
	// 1. Check for Emptiness
	// 2. Handle Empty Case
	if (PQ->size == 0)
	{
		return false;
	}

	// 3. Extract Root:
	//   - Access the 'value' of the root node (index 0) of 'nodes' array.
	//   - Assign this 'value' to the output parameter '*value'.
	*value = PQ->nodes[0].value;

	// 4. Replace Root with Last Node:
	int last_index = PQ->size - 1;
	PQ->nodes[0] = PQ->nodes[last_index];

	// 5. Adjust Queue Size:
	//   - Decrement the 'size' of the PriorityQueue by 1.
	PQ->size--;

	// 6. Initialize Bubble Down:
	//   - Set a variable (e.g., 'currentIndex') to 0.
	int current_index = 0;

	// 7. Bubble Down Procedure:
	while (true)
	{
		int left_index = left_child(current_index);
		int right_index = right_child(current_index);
		int higher_priority_child_index = left_index;
		if (PQ->nodes[left_index].priority < PQ->nodes[right_index].priority)
		{
			higher_priority_child_index = right_index;
		}

		if (PQ->nodes[current_index].priority < PQ->nodes[higher_priority_child_index].priority)
		{
			Node temp = PQ->nodes[current_index];
			PQ->nodes[current_index] = PQ->nodes[higher_priority_child_index];
			PQ->nodes[higher_priority_child_index] = temp;
			current_index = higher_priority_child_index;
		}
		else
		{
			break;
		}
	}

	// 8. Successful Deletion:
	return true;
}

Node *peek(PriorityQueue *PQ)
{
	if (PQ->size == 0)
	{
		return NULL;
	}
	return &PQ->nodes[0];
}

bool is_empty(PriorityQueue *PQ)
{
	if (PQ->size == 0)
	{
		return true;
	}
	return false;
}

void free_priority_queue(PriorityQueue *PQ)
{
	free(PQ->nodes);
	free(PQ);
}

int main()
{
	// Initialize a priority queue with a certain capacity
	PriorityQueue *PQ = init_priority_queue(10);

	// Insert some values with priorities
	insert_into_priority_queue(PQ, 5, 1);
	insert_into_priority_queue(PQ, 10, 3);
	insert_into_priority_queue(PQ, 3, 2);

	// Peek the top value
	Node *top = peek(PQ);
	printf("Highest Priority: Value: %d, Priority: %d\n", top->value, top->priority);

	// Remove and print the top value
	int removedValue;
	if (delete_from_priority_queue(PQ, &removedValue))
	{
		printf("Removed Value: %d\n", removedValue);
	}

	// Peek the top value after removal
	top = peek(PQ);
	printf("Highest Priority after Removal: Value: %d, Priority: %d\n", top->value, top->priority);

	// Free the priority queue
	free_priority_queue(PQ);

	return 0;
}
