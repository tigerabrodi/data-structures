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
	// 2. Return the calculated index.
}

bool insert_into_priority_queue(PriorityQueue *PQ, int value, int priority)
{
	// 1. Check if the current 'size' of the PriorityQueue is equal to its 'capacity'.
	// 2. If the queue is full, return false to indicate insertion failure.
	// 3. Create a new Node at the 'size' index of the 'nodes' array.
	// 4. Set the 'value' and 'priority' fields of the new Node.
	// 5. Initialize a variable, say 'currentIndex', to the current 'size' of the PriorityQueue.
	// 6. Start a loop to 'bubble up' the newly added node:
	//    a. Inside the loop, calculate the parent index of 'currentIndex'.
	//    b. Compare the priority of the node at 'currentIndex' with the node at its parent index.
	//    c. If the current node's priority is greater than its parent's priority, swap the two nodes.
	//    d. Update 'currentIndex' to the parent index.
	//    e. If no swap was made or 'currentIndex' is now 0, break out of the loop.
	// 7. Increment the 'size' of the PriorityQueue.
	// 8. Return true to indicate successful insertion.
}

bool delete_from_priority_queue(PriorityQueue *PQ, int *value)
{
	// 1. Check if 'size' of PriorityQueue is 0 (empty).
	// 2. If empty, return false.
	// 3. Set the output parameter '*value' to the value of the root node.
	// 4. Replace the root node with the node at the last index in 'nodes' array.
	// 5. Decrease the 'size' of the PriorityQueue by 1.
	// 6. Initialize a variable, say 'currentIndex', to 0.
	// 7. Start a loop to 'bubble down' the root node:
	//    a. Inside the loop, calculate the indices of the left and right children of 'currentIndex'.
	//    b. Determine which child has a higher priority.
	//    c. Compare the priority of the higher priority child with the node at 'currentIndex'.
	//    d. If the child's priority is greater, swap the child node with the current node.
	//    e. Update 'currentIndex' to the index of the swapped child.
	//    f. If no swap was made or 'currentIndex' is a leaf node, break out of the loop.
	// 8. Return true to indicate successful deletion.
}

Node *peek(PriorityQueue *PQ)
{
	// 1. Check if 'size' of PriorityQueue is 0.
	// 2. If empty, return NULL.
	// 3. Return a pointer to the root node without removing it.
}

bool is_empty(PriorityQueue *PQ)
{
	// 1. Compare 'size' of the PriorityQueue to 0.
	// 2. Return the result of the comparison.
}

void free_priority_queue(PriorityQueue *PQ)
{
	// 1. Use free to deallocate memory of the 'nodes' array inside the PriorityQueue.
	// 2. Use free to deallocate memory of the PriorityQueue itself.
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
