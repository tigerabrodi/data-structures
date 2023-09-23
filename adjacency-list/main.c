#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct for a node in the adjacency list.
typedef struct AdjListNode
{
	int vertex;
	struct AdjListNode *next;
} AdjListNode;

// Define a struct for the adjacency list.
typedef struct
{
	AdjListNode *head;
} AdjList;

// Define a struct for the graph.
typedef struct
{
	int numVertices;
	AdjList *array;
} Graph;

AdjListNode *createAdjListNode(int vertex);	  // Already defined
Graph *createGraph(int numVertices);		  // Already defined
void addEdge(Graph *graph, int src, int dest);	  // Already defined
void removeEdge(Graph *graph, int src, int dest); // Already defined
bool isEdge(Graph *graph, int src, int dest);	  // Already defined
void DFS(Graph *graph, int startVertex);
void BFS(Graph *graph, int startVertex);
void printGraph(Graph *graph);		   // Already defined
void deleteNode(Graph *graph, int vertex); // Already defined
void freeGraph(Graph *graph);		   // Already defined

void removeEdge(Graph *graph, int src, int dest)
{
	// Vertex Validation:
	//    Check if 'src' and 'dest' are valid indices.
	//    If either is out of bounds, return without proceeding.
	if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices)
	{
		return;
	}

	// Start Traversal from Source:
	//    Initialize a pointer 'temp' pointing to the head of the adjacency list of 'src'.
	//    Declare another pointer 'prev' to keep track of the previous node, set it to NULL initially.
	AdjListNode *temp = graph->array[src].head;
	AdjListNode *prev = NULL;

	// Search for Destination Node in Source's Adjacency List:
	//    Traverse the list using a while-loop, checking each node's vertex value against 'dest'.
	//    Update 'prev' to point to 'temp' and 'temp' to move to the next node in each iteration.
	while (temp != NULL && temp->vertex != dest)
	{
		prev = temp;
		temp = temp->next;
	}

	// Remove Destination Node:
	//    If 'temp' points to NULL after the loop, 'dest' wasn't found. Return without changes.
	if (temp == NULL)
	{
		return;
	}

	//    If 'prev' is still NULL, it means 'dest' is the first node in the list.
	if (prev == NULL)
	{
		graph->array[src].head = temp->next;
	}
	//    If 'prev' is not NULL, adjust its 'next' pointer to skip the 'dest' node.
	else
	{
		prev->next = temp->next;
	}

	//   Free the memory allocated to the 'dest' node.
	free(temp);
	printf("Edge from %d to %d has been removed\n", src, dest);
}

bool isEdge(Graph *graph, int src, int dest)
{
	// 1. Vertex Validation:
	//    1.1. Ensure 'src' and 'dest' are valid vertex indices.
	//    1.2. If either is invalid, return false without further checks.

	// 2. Traverse Source's List:
	//    2.1. Set up a temporary pointer, say 'temp', to start from the head of the adjacency list of 'src'.

	// 3. Search for Destination Node:
	//    3.1. Using a while-loop, traverse through the adjacency list.
	//    3.2. In each iteration, compare 'temp->vertex' with 'dest'.
	//    3.3. If a match is found, exit the loop early.

	// 4. Result:
	//    4.1. After traversal, if 'temp' isn't NULL, return true (edge exists).
	//    4.2. Otherwise, return false.
}

void deleteNode(Graph *graph, int vertex)
{
	// 1. Vertex Validation:
	//    1.1. Ensure 'vertex' is a valid index.
	//    1.2. If it's not, return without changes.

	// 2. Remove Incoming Edges to the Vertex:
	//    2.1. Iterate through each vertex's adjacency list in the graph.
	//    2.2. For each vertex, use the 'removeEdge' function to eliminate any edge leading to the target 'vertex'.

	// 3. Clear Outgoing Edges from the Vertex:
	//    3.1. Traverse the adjacency list of 'vertex' and free all its nodes.
	//    3.2. Reset the head of 'vertex's adjacency list to NULL.

	// 4. Adjust the Graph's Vertex Array:
	//    4.1. Starting from the 'vertex' index, move all subsequent adjacency lists one position back.
	//    4.2. Decrease graph's 'numVertices' count by 1.
	//    4.3. Use realloc() to adjust the size of the graph's array to the new vertex count.
}

void freeGraph(Graph *graph)
{
	// 1. Check Graph's Existence:
	//    1.1. If 'graph' is NULL, return without doing anything.
	if (graph == NULL)
	{
		return;
	}

	// 2. Deallocate Each Vertex's Adjacency List:
	//    2.1. For each vertex in the graph:
	//    2.2. Traverse its adjacency list and free every node.
	//    2.3. Once all nodes are freed, reset the head of the adjacency list to NULL.

	// 3. Deallocate Graph's Adjacency List Array:
	//    3.1. Once all individual adjacency lists are freed, free the main array that held these lists.

	// 4. Deallocate the Graph Structure:
	//    4.1. Now that everything inside the graph is deallocated, free the graph structure itself.
}

// Function to create a new adjacency list node.
AdjListNode *createAdjListNode(int vertex)
{
	AdjListNode *new_node = (AdjListNode *)malloc(sizeof(AdjListNode));
	if (new_node == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}

	new_node->vertex = vertex;
	new_node->next = NULL;

	return new_node;
}

// Function to create a graph.
Graph *createGraph(int numVertices)
{
	Graph *new_graph = (Graph *)malloc(sizeof(Graph));
	if (new_graph == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}

	new_graph->numVertices = numVertices;
	new_graph->array = (AdjList *)malloc(numVertices * sizeof(AdjList));

	for (int i = 0; i < numVertices; i++)
	{
		new_graph->array[i].head = NULL;
	}

	return new_graph;
}

// Function to add an edge to the graph.
void addEdge(Graph *graph, int src, int dest)
{
	AdjListNode *newDestNode = createAdjListNode(dest);
	newDestNode->next = graph->array[src].head;
	graph->array[src].head = newDestNode;
}

// Function to print the graph.
void printGraph(Graph *graph)
{
	for (int i = 0; i < graph->numVertices; i++)
	{
		printf("\nAdjacency list of vertex %d: ", i);

		AdjListNode *temp = graph->array[i].head;

		while (temp != NULL)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}

		printf("NULL\n");
	}
}

int main()
{
	// Create a graph with a given number of vertices. For this example, let's use 5 vertices.
	Graph *graph = createGraph(5);

	// Add edges to the graph.
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	// Print the graph.
	printGraph(graph);

	return 0;
}
