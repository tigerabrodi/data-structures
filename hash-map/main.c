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

HashTable *create_hash_function();
unsigned int hash_function(const char *key);
void insert(HashTable *table, const char *key, const char *value);
char *get(HashTable *table, const char *key);
void delete(HashTable *table, const char *key);
void free_hash_table(HashTable *table);

HashTable *create_hash_function()
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

unsigned int hash_function(const char *key)
{
	int hash = 0;

	// compute length outside loop to avoid calling strlen() on each iteration which is O(n^2)
	int length = strlen(key);
	for (int i = 0; i < length; i++)
	{
		// The multiplication is to ensure that strings like "ab" and "ba" don't have the same hash.
		hash += key[i] * (i + 1);
	}

	return hash % TABLE_SIZE;
}

void insert(HashTable *table, const char *key, const char *value)
{
	unsigned int hash = hash_function(key);

	// Check if the key already exists in the hash table
	for (Node *node = table->buckets[hash]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);	     // free the previous value
			node->value = strdup(value); // copy the new value
			return;
		}
	}

	// If the key does not exist in the hash table, create a new node and insert it at the head of the linked list
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Error: Could not allocate memory for a new node.\n");
		exit(1);
	}

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		printf("Error: Could not allocate memory for the key.\n");
		exit(1);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		printf("Error: Could not allocate memory for the value.\n");
		exit(1);
	}

	new_node->next = table->buckets[hash]; // Point the new node's next to the current head of the list
	table->buckets[hash] = new_node;       // Update the bucket's head to the new node
}

char *get(HashTable *table, const char *key)
{
	unsigned int hash = hash_function(key);
	for (Node *node = table->buckets[hash]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			return node->value;
		}
	}

	return NULL;
}

void delete(HashTable *table, const char *key)
{
	unsigned int hash = hash_function(key);

	Node *prev = NULL;
	Node *current = table->buckets[hash];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			if (prev == NULL)
			{
				// Node to delete is the head of the list for this bucket
				table->buckets[hash] = current->next;
			}
			else
			{
				prev->next = current->next;
			}

			free(current->key);
			free(current->value);
			free(current);
			return;
		}

		prev = current;
		current = current->next;
	}
	printf("Error: Key not found in hash table.\n");
}

void free_hash_table(HashTable *table)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		Node *node = table->buckets[i];
		while (node != NULL)
		{
			Node *temp = node;
			node = node->next;

			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
}

int main()
{
	// Create a new hash table
	HashTable *myTable = create_hash_function();

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
	free_hash_table(myTable);

	return 0;
}
