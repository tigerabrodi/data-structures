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
