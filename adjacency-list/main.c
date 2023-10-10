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
void DFS(Graph *graph, int currentVertex, bool visited[]);
void BFS(Graph *graph, int startVertex);
void printGraph(Graph *graph);		   // Already defined
void deleteNode(Graph *graph, int vertex); // Already defined
void freeGraph(Graph *graph);		   // Already defined

void DFS(Graph *graph, int currentVertex, bool visited[])
{
	// Step 1: Mark the Current Vertex as Visited

	// 1.1. Set `visited[currentVertex]` to true:
	// - This is to ensure that we don't process this vertex again and avoid infinite loops or redundant processing.
	visited[currentVertex] = true;

	// Step 2: Start Traversal to Explore Neighbors

	// 2.1. Begin with the first neighbor:
	// - Create a pointer named `temp`.
	// - Point `temp` to the beginning of the adjacency list of `currentVertex` (i.e., `graph->array[currentVertex].head`).
	AdjListNode *temp = graph->array[currentVertex].head;

	// 2.2. Loop to process all neighbors:
	// - Begin a while loop that continues as long as `temp` is not NULL. This is to ensure we traverse the entire adjacency list.
	while (temp != NULL)
	{
		//      2.2.1. Inside the loop, for each neighbor:
		//      - Check the `visited` status of the neighboring vertex (i.e., `temp->vertex`).
		//      - If it's not visited (i.e., `visited[temp->vertex]` is `false`):
		if (visited[temp->vertex] == false)
		{
			DFS(graph, temp->vertex, visited);
		}

		//          2.2.1.1. Recursive Dive into the Neighbor:
		//          - Call the DFS function recursively to start processing the unvisited neighboring vertex.
		//          - Pass in the `graph`, the current neighboring vertex (`temp->vertex`), and the `visited` array to this recursive call.

		//      2.2.2. Move to the next neighbor in the adjacency list:
		//      - Update the `temp` pointer to move it to the next node in the adjacency list (i.e., `temp = temp->next`).
		temp = temp->next;
	}

	// Step 3: Function Completion

	// 3.1. Once all neighbors are processed:
	// - The loop will end, the function will finish its current call, and it will return to its previous state (backtracking).
}

void StartDFS(Graph *graph, int startVertex)
{
	// Step 1: Set Up a Visited Tracker

	// 1.1. Create a `visited` array:
	// - Allocate a boolean array called `visited` with a size equal to the number of vertices in the graph (i.e., `graph->numVertices`).
	bool visited[graph->numVertices];

	// 1.2. Initialize all values to false:
	// - Iterate over this array using a loop.
	// - Set each entry in the `visited` array to `false`. This represents that no vertex has been visited yet.

	for (int i = 0; i < graph->numVertices; i++)
	{
		visited[i] = false;
	}

	// Step 2: Begin the DFS Process

	// 2.1. Call the recursive DFS function:
	// - Start the depth-first search by calling the DFS function.
	// - Pass in the `graph`, the provided `startVertex`, and the `visited` array as arguments.
	DFS(graph, startVertex, visited);

	// Step 3: Clean-up After Completion (if necessary)

	// 3.1. Once DFS completes:
	// - There's no additional cleanup required for stack-allocated memory.
	// - If you used any dynamically allocated memory (using malloc, calloc, etc.), ensure you free that memory to prevent leaks.
}

void BFS(Graph *graph, int startVertex)
{
	// Step 1: Data Structures Initialization

	// 1.1. Create the BFS Queue:
	// - Create an integer array named `queue` to hold vertices.
	// - The size of this array should equal `graph->numVertices`.
	// - Declare integer variables: `front` and `rear` for queue operations.
	// - Start with `front = -1` and `rear = -1` to indicate an empty queue.
	int queue[graph->numVertices];
	int front = -1;
	int rear = -1;

	// 1.2. Track Visited Vertices:
	// - Declare a boolean array named `visited` to track which vertices have been visited.
	// - Loop through and set all entries of `visited` to `false` since no vertex is visited at the start.
	bool visited[graph->numVertices];
	for (int i = 0; i < graph->numVertices; i++)
	{
		visited[i] = false;
	}

	// Step 2: Begin with the Start Vertex

	// 2.1. Mark the starting vertex:
	// - Set `visited[startVertex]` to `true` to mark the starting vertex as visited.
	visited[startVertex] = true;

	// 2.2. Add the starting vertex to the queue:
	// - Increment the `rear`.
	rear++;
	// - Add `startVertex` to the queue by setting `queue[rear] = startVertex`.
	queue[rear] = startVertex;
	// - Since this is the first element, make `front` point to `0`.
	front = 0;

	// Step 3: BFS Loop

	// 3.1. Process while Queue is not Empty:
	// - Create a loop that continues as long as `front` doesn't equal `-1` (means queue isn't empty).
	while (front != -1)
	{
		//      3.1.1. Dequeue from the front:
		//      - Fetch the front vertex of the queue into a variable named `currentVertex`.
		//      - Shift the `front` to the next element.
		//      - If after shifting, `front` exceeds `rear`, reset the queue by setting both `front` and `rear` to `-1`.
		int currentVertex = queue[front];
		front++;
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}

		//      3.1.2. Look at Neighbors:
		//      - Set a pointer `temp` to the beginning of the adjacency list of `currentVertex`.

		AdjListNode *temp = graph->array[currentVertex].head;

		//          3.1.2.1. Process all Neighbors:
		//          - Traverse the adjacency list. Continue the loop as long as `temp` isn't NULL.
		while (temp != NULL)
		{
			//              3.1.2.1.1. If the neighbor hasn't been visited:
			//              - Check if `visited[temp->vertex]` is `false`.
			if (visited[temp->vertex] == false)
			{
				visited[temp->vertex] = true;
				rear++;
				queue[rear] = temp->vertex;
				if (front == -1)
				{
					front = 0;
				}
			}

			temp = temp->next;

			//                  3.1.2.1.1.1. Mark the neighbor as visited:
			//                  - Update `visited[temp->vertex]` to `true`.

			//                  3.1.2.1.1.2. Enqueue the neighbor:
			//                  - Move `rear` to the next position.
			//                  - Place `temp->vertex` in the queue.
			//                  - If `front` is `-1` (queue was empty), set `front` to `0`.
		}

		//              3.1.2.1.2. Move to the next neighbor:
		//              - Update `temp` to the next node in the adjacency list (`temp = temp->next`).
	}

	// Step 4: BFS Completion
	// - At this point, BFS has processed all vertices reachable from `startVertex`.
	// - No manual memory cleanup is needed since we've used stack-allocated arrays.
}

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
	if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices)
	{
		return false;
	}

	// 2. Traverse Source's List:
	AdjListNode *temp = graph->array[src].head;

	// 3. Search for Destination Node:
	while (temp != NULL)
	{
		if (temp->vertex == dest)
		{
			return true; // edge found
		}
		temp = temp->next;
	}

	// 4. If loop completed, edge wasn't found.
	return false;
}

void deleteNode(Graph *graph, int vertex)
{
	// 1. Vertex Validation:
	//    1.1. Begin by validating the 'vertex' index.
	//    1.2. Check if the 'vertex' index is non-negative. We want to ensure it's not a negative number.
	//    1.3. Further, ensure that the 'vertex' index is within the range of existing vertices in our graph.
	//    1.4. If it's out of range or negative, our 'vertex' index is invalid.
	//    1.5. Print an error message for clarity and exit the function without making any changes.
	if (vertex < 0 || vertex >= graph->numVertices)
	{
		printf("Invalid vertex index\n");
		return;
	}

	// 2. Remove Incoming Edges to the Vertex:
	//    2.1. Each vertex in the graph might have an edge pointing to our target 'vertex'.
	//    2.2. Set up a loop to iterate over all vertices in the graph.
	//    2.3. Within the loop, for each vertex:
	//         2.3.1. Examine its adjacency list to determine if it has an edge leading to our target 'vertex'.
	//         2.3.2. Use an appropriate mechanism, like the 'removeEdge' function, to remove such edges when found.
	//         2.3.3. Continue checking until the entire list is traversed or the edge is found and removed.

	for (int i = 0; i < graph->numVertices; i++)
	{
		removeEdge(graph, i, vertex);
	}

	// 3. Clear Outgoing Edges from the Vertex:
	//    3.1. Our target vertex might have edges pointing to other vertices.
	//    3.2. Set a pointer, let's call it 'current', pointing at the start (head) of our target vertex's adjacency list.
	//    3.3. Initiate a loop to traverse through the adjacency list pointed by 'current'.
	//         3.3.1. In each iteration, store the next node in a temporary pointer.
	//         3.3.2. Free the memory of the current node.
	//         3.3.3. Move 'current' to the next node using our temporary pointer.
	//    3.4. Once the loop ends, set the head of the adjacency list of 'vertex' to NULL, ensuring it's clean and indicates no edges.
	AdjListNode *current = graph->array[vertex].head;

	while (current != NULL)
	{
		AdjListNode *temp = current->next;
		free(current);
		current = temp;
	}

	graph->array[vertex].head = NULL;

	// 4. Adjust the Graph's Vertex Array:
	//    4.1. With our target vertex deleted, there's a gap in our array of adjacency lists.
	//    4.2. To close this gap:
	//         4.2.1. Begin a loop from the deleted 'vertex' index, moving towards the end of the array.
	//         4.2.2. In each iteration, copy the content of the next index to the current index.
	//                This shift operation effectively removes the gap.

	for (int i = vertex; i < graph->numVertices - 1; i++)
	{
		graph->array[i] = graph->array[i + 1];
	}

	//    4.3. After the shifting is done, reduce the 'numVertices' field of the graph by 1.
	graph->numVertices--;
	//    4.4. As a final step, resize the graph's adjacency list array to its new size using realloc().
	AdjList *tempArray = (AdjList *)realloc(graph->array, graph->numVertices * sizeof(AdjList));

	if (tempArray != NULL)
	{
		graph->array = tempArray;
	}
	else
	{
		printf("Memory allocation failed");
		return;
	}

	// 5. Cleaning Up:
	//    5.1. Always ensure no memory leaks occur.
	//    5.2. All nodes of the deleted vertex's adjacency list and any other associated memory should have been released.
	printf("Vertex %d has been deleted\n", vertex);
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

	for (int i = 0; i < graph->numVertices; i++)
	{
		AdjListNode *current = graph->array[i].head;

		while (current != NULL)
		{
			AdjListNode *temp = current->next;
			free(current);
			current = temp;
		}

		graph->array[i].head = NULL;
	}

	// 3. Deallocate Graph's Adjacency List Array:
	//    3.1. Once all individual adjacency lists are freed, free the main array that held these lists.

	free(graph->array);

	// 4. Deallocate the Graph Structure:
	//    4.1. Now that everything inside the graph is deallocated, free the graph structure itself.

	free(graph);
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
