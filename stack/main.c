#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Stack
{
	Node *top;
} Stack;

Stack *createStack()
{
	Stack *newStack = (Stack *)malloc(sizeof(Stack));
	newStack->top = NULL;
	return newStack;
}

void push(Stack *stack, int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	newNode->data = value;
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(Stack *stack)
{
	if (stack->top == NULL)
	{
		printf("Stack Underflow");
		return -1;
	}

	Node *temp = stack->top;
	int value = temp->data;
	stack->top = stack->top->next;
	free(temp);
	return value;
}

int peek(Stack *stack)
{
	if (stack->top == NULL)
	{
		printf("Stack is empty");
		return -1;
	}

	return stack->top->data;
}

int isEmpty(Stack *stack)
{
	return stack->top == NULL ? true : false;
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
