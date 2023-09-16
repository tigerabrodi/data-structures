#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct Node
{
	char *key;
	char *value;
	struct Node *next;
} Node;

typedef struct HashTable
{
	Node *buckets[TABLE_SIZE];
} HashTable;

HashTable *createHashTable();
unsigned int hashFunction(const char *key);
void insert(HashTable *table, const char *key, const char *value);
char *get(HashTable *table, const char *key);
void delete(HashTable *table, const char *key);
void freeHashTable(HashTable *table);

HashTable *createHashTable()
{
	HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));
	if (newTable == NULL)
	{
		printf("Error: Could not allocate memory for the hash table.\n");
		exit(1);
	}

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		newTable->buckets[i] = NULL;
	}

	return newTable;
}

unsigned int hashFunction(const char *key)
{
	// step 1: Implement a hash function. For simplicity, you can sum up the ASCII values of the characters in the key and modulo with TABLE_SIZE.
	return 0; // Placeholder return.
}

void insert(HashTable *table, const char *key, const char *value)
{
	// step 1: Calculate the hash for the given key using the hashFunction.
	// step 2: Check if a node with the given key already exists in the linked list at the calculated hash index. If yes, update its value.
	// step 3: If not, create a new node, assign the key and value, and insert it at the beginning of the linked list for that bucket.
}

char *get(HashTable *table, const char *key)
{
	// step 1: Calculate the hash for the given key using the hashFunction.
	// step 2: Traverse the linked list at the calculated hash index to find the node with the given key.
	// step 3: If found, return the value. If not found, return NULL or an appropriate message.
	return NULL; // Placeholder return.
}

void delete(HashTable *table, const char *key)
{
	// step 1: Calculate the hash for the given key using the hashFunction.
	// step 2: Traverse the linked list at the calculated hash index and find the node with the given key.
	// step 3: If found, delete the node and free the memory. Adjust the pointers accordingly. If not found, print an appropriate message.
}

void freeHashTable(HashTable *table)
{
	// step 1: Traverse through each bucket of the hash table.
	// step 2: For each bucket, free the memory of each node in the linked list.
	// step 3: Once all nodes in all buckets are freed, free the memory of the hash table.
}

int main()
{
	// Create a new hash table
	HashTable *myTable = createHashTable();

	// Insert key-value pairs
	insert(myTable, "name", "John");
	insert(myTable, "age", "25");
	insert(myTable, "city", "New York");

	// Get and display values
	printf("Name: %s\n", get(myTable, "name")); // Expected: John
	printf("Age: %s\n", get(myTable, "age"));   // Expected: 25

	// Delete a key-value pair
	delete (myTable, "city");

	// Try getting a deleted key's value
	printf("City: %s\n", get(myTable, "city")); // Expected: (Some error message or NULL indication)

	// Cleanup resources
	freeHashTable(myTable);

	return 0;
}
