#include <stdio.h>
#include <stdlib.h>

// Node structure for our Queue
typedef struct QNode
{
	int data;
	struct QNode *next;
} QNode;

// Queue structure
typedef struct Queue
{
	QNode *front; // points to the front node in the queue
	QNode *rear;  // points to the rear node in the queue
} Queue;

Queue *initializeQueue()
{
	Queue *new_queue = (Queue *)malloc(sizeof(Queue));
	if (new_queue == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	new_queue->front = NULL;
	new_queue->rear = NULL;

	return new_queue;
}

void enqueue(Queue *q, int value)
{
	QNode *new_node = (QNode *)malloc(sizeof(QNode));
	if (new_node == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	new_node->data = value;
	if (q->front == NULL)
	{
		q->front = new_node;
		q->rear = new_node;
	}
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
}

int dequeue(Queue *q)
{
	// TODO: Implement function
	return -1; // Placeholder return
}

int peek(Queue *q)
{
	// TODO: Implement function
	return -1; // Placeholder return
}

int isEmpty(Queue *q)
{
	// TODO: Implement function
	return 1; // Placeholder return
}

void freeQueue(Queue *q)
{
	// TODO: Implement function
}

int main()
{
	// Initialize a new queue
	Queue *myQueue = initializeQueue();

	// Enqueue some items
	enqueue(myQueue, 1);
	enqueue(myQueue, 2);
	enqueue(myQueue, 3);

	// Peek the front item
	printf("Front item: %d\n", peek(myQueue)); // Expected output: 1

	// Dequeue items and display
	printf("Dequeued item: %d\n", dequeue(myQueue)); // Expected output: 1
	printf("Dequeued item: %d\n", dequeue(myQueue)); // Expected output: 2

	// Check if the queue is empty
	if (isEmpty(myQueue))
	{
		printf("Queue is empty!\n");
	}
	else
	{
		printf("Queue is not empty!\n");
	}

	// Dequeue remaining items
	printf("Dequeued item: %d\n", dequeue(myQueue)); // Expected output: 3

	// Check if the queue is empty again
	if (isEmpty(myQueue))
	{
		printf("Queue is empty!\n");
	}
	else
	{
		printf("Queue is not empty!\n");
	}

	// Cleanup resources
	freeQueue(myQueue);

	return 0;
}
