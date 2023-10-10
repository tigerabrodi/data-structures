#include <stdbool.h> // For the boolean type
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the graph using an adjacency matrix.
typedef struct
{
	int numVertices; // Number of vertices in the graph
	int **matrix;	 // Pointer to the 2D array (matrix)
} Graph;

Graph *createGraph(int numVertices);			 // Initializes a new graph with given number of vertices
void addEdge(Graph *graph, int vertex1, int vertex2);	 // Adds an edge between two vertices
void removeEdge(Graph *graph, int vertex1, int vertex2); // Removes an edge between two vertices
bool isEdge(Graph *graph, int vertex1, int vertex2);	 // Checks if an edge exists between two vertices
void printGraph(Graph *graph);				 // Prints the adjacency matrix
void freeGraph(Graph *graph);				 // Cleans up memory used by the graph

int main()
{
	int numVertices = 5; // Example size

	// Create a graph with 5 vertices.
	Graph *graph = createGraph(numVertices);

	// Add some edges.
	addEdge(graph, 0, 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 0);

	// Print the graph's adjacency matrix.
	printGraph(graph);

	// Check for an edge between vertex 1 and 2.
	if (isEdge(graph, 1, 2))
	{
		printf("There's an edge between vertex 1 and 2.\n");
	}
	else
	{
		printf("There's no edge between vertex 1 and 2.\n");
	}

	// Remove an edge and print again.
	removeEdge(graph, 1, 2);
	printGraph(graph);

	// Free the graph's memory.
	freeGraph(graph);

	return 0;
}
