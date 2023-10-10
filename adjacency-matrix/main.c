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

// Create a graph with the given number of vertices.
Graph *createGraph(int numVertices)
{
	// Allocate space for the graph's structure
	Graph *graph = malloc(sizeof(Graph));

	if (graph == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}

	// Set the number of vertices in the graph structure.
	graph->numVertices = numVertices;

	// Allocate memory for the adjacency matrix.
	for (int i = 0; i < numVertices; i++)
	{
		graph->matrix[i] = malloc(sizeof(int) * numVertices);

		if (graph->matrix[i] == NULL)
		{
			printf("Memory allocation failed.\n");
			exit(1);
		}

		for (int j = 0; j < numVertices; j++)
		{
			graph->matrix[i][j] = 0;
		}
	}

	// Return the newly created graph pointer.
	return graph;
}

void addEdge(Graph *graph, int vertex1, int vertex2)
{
	// Establish a connection (edge) between vertex1 and vertex2.
	graph->matrix[vertex1][vertex2] = 1;
	graph->matrix[vertex2][vertex1] = 1;
}

void removeEdge(Graph *graph, int vertex1, int vertex2)
{
	// Remove the connection (edge) between vertex1 and vertex2.
	// - Access the adjacency matrix inside the graph.
	// - Set the value at matrix position [vertex1][vertex2] to 0.

	// Since the graph is undirected:
	// - Also set the value at matrix position [vertex2][vertex1] to 0.
}

bool isEdge(Graph *graph, int vertex1, int vertex2)
{
	// Check if an edge exists between vertex1 and vertex2.
	// - Access the adjacency matrix at the position [vertex1][vertex2].
	// - If the value at this position is 1:
	//   - An edge exists: return 'true'.
	// - Otherwise:
	//   - No edge exists: return 'false'.
}

void printGraph(Graph *graph)
{
	// Print the adjacency matrix row by row.
	// - Loop through the rows from 0 to graph->numVertices-1.
	//   - For each row:
	//     - Use another loop to iterate through the columns from 0 to graph->numVertices-1.
	//       - Print the matrix value at the current row and column.
	//       - Add a space after each value for formatting.
	//     - After finishing a row (when the inner loop completes), print a newline.
}

void freeGraph(Graph *graph)
{
	// Free all allocated memory associated with the graph.

	// Begin by freeing the adjacency matrix:
	// - Loop through the rows of the matrix (from 0 to graph->numVertices-1).
	//   - For each row:
	//     - Free the memory associated with that row.

	// Once the matrix is freed:
	// - Free the graph structure itself.
}

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
