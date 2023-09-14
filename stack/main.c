#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node
{
	int data;	   // store the data in the node
	struct Node *next; // pointer to the next node
} Node;

// Define the Stack structure
typedef struct Stack
{
	Node *top; // pointer to the top node
} Stack;

// Function to create a new stack
Stack *createStack()
{
	Stack *newStack = (Stack *)malloc(sizeof(Stack));
	newStack->top = NULL; // Initialize top as NULL
	return newStack;
}

// Push operation
void push(Stack *stack, int value)
{
	// TODO:
	// 1. Allocate memory for a new node
	// 2. Set the data of the node to the given value
	// 3. Point the 'next' of this node to the current top of the stack
	// 4. Update the top of the stack to this new node
}

// Pop operation
int pop(Stack *stack)
{
	// TODO:
	// 1. Check if stack is empty. If yes, print "Stack Underflow" and return some error value (e.g., -1)
	// 2. If not empty, get the value of the top node
	// 3. Update the top to point to the next node
	// 4. Free the memory of the old top node
	// 5. Return the value of the node that was removed
	return 0; // Placeholder return
}

// Peek operation
int peek(Stack *stack)
{
	// TODO:
	// 1. Check if stack is empty. If yes, print "Stack is empty" and return some error value (e.g., -1)
	// 2. If not empty, return the value of the top node
	return 0; // Placeholder return
}

// Check if stack is empty
int isEmpty(Stack *stack)
{
	// TODO:
	// 1. Check if top is NULL. If yes, return 1 (True)
	// 2. Otherwise, return 0 (False)
	return 0; // Placeholder return
}

int main()
{
	// Test the stack functions

	// 1. Create a new stack
	Stack *myStack = createStack();

	// 2. Push some values
	push(myStack, 1);
	push(myStack, 2);
	push(myStack, 3);

	// 3. Peek the top value and print
	printf("Top value: %d\n", peek(myStack)); // Expected output: 3

	// 4. Pop some values and print
	printf("Popped value: %d\n", pop(myStack)); // Expected output: 3
	printf("Popped value: %d\n", pop(myStack)); // Expected output: 2

	// 5. Check if stack is empty
	printf("Is stack empty? %d\n", isEmpty(myStack)); // Expected output: 0 (False)

	// 6. Pop remaining values
	printf("Popped value: %d\n", pop(myStack)); // Expected output: 1

	// 7. Check again if stack is empty
	printf("Is stack empty? %d\n", isEmpty(myStack)); // Expected output: 1 (True)

	// Cleanup
	free(myStack);

	return 0;
}
