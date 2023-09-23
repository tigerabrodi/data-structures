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

AdjListNode *createAdjListNode(int vertex);    // Already defined
Graph *createGraph(int numVertices);	       // Already defined
void addEdge(Graph *graph, int src, int dest); // Already defined
void removeEdge(Graph *graph, int src, int dest);
bool isEdge(Graph *graph, int src, int dest);
void DFS(Graph *graph, int startVertex);
void BFS(Graph *graph, int startVertex);
void printGraph(Graph *graph); // Already defined
void deleteNode(Graph *graph, int vertex);
void freeGraph(Graph *graph);

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
	// 1. Memory Allocation:
	//    1.1. Use malloc to allocate memory for a new Graph structure.
	//    1.2. Check if memory allocation was successful. If not, handle the error (e.g., print an error message and return NULL).

	// 2. Graph Initialization:
	//    2.1. Assign the 'numVertices' parameter value to the 'numVertices' field of the new graph.
	//    2.2. Use malloc to allocate an array of AdjList structures of size 'numVertices' for the 'array' field of the graph.
	//    2.3. Check if memory allocation for the array was successful. If not, handle the error.

	// 3. Adjacency Lists Initialization:
	//    3.1. Use a loop to iterate through each adjacency list in the array.
	//    3.2. For each adjacency list, initialize its 'head' to NULL.

	// 4. Return:
	//    4.1. Return the newly created Graph structure.
}

// Function to add an edge to the graph.
void addEdge(Graph *graph, int src, int dest)
{
	// 1. Source to Destination:
	//    1.1. Create a new adjacency list node for the destination vertex using 'createAdjListNode'.
	//    1.2. Set the 'next' field of this new node to point to the current head of the source vertex's adjacency list.
	//    1.3. Update the head of the source vertex's adjacency list to the new node (essentially adding the node at the beginning of the list).

	// 2. If Undirected Graph (Destination to Source):
	//    2.1. Create a new adjacency list node for the source vertex.
	//    2.2. Set the 'next' field of this new node to point to the current head of the destination vertex's adjacency list.
	//    2.3. Update the head of the destination vertex's adjacency list to the new node.
}

// Function to print the graph.
void printGraph(Graph *graph)
{
	// 1. Loop Initialization:
	//    1.1. Initialize a loop to iterate through each vertex of the graph using the 'numVertices' field for the loop limit.

	// 2. Print Each Vertex and Adjacent Vertices:
	//    2.1. For each vertex, print its number/index.
	//    2.2. Initialize a temporary pointer to iterate through the adjacency list (starting from the head of the current vertex's adjacency list).
	//    2.3. Use a loop to traverse the adjacency list of the current vertex:
	//         - Print the vertex number of each node in the adjacency list until reaching the end (NULL).
	//         - Move the temporary pointer to the next node in the list after printing.

	// 3. Line Break:
	//    3.1. Print a newline character after processing each vertex to separate the vertices in the output.
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
