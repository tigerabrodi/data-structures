#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of children for each node. This assumes lowercase English letters.
#define ALPHABET_SIZE 26

typedef struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool is_end_of_word;
} TrieNode;

typedef struct Trie
{
	TrieNode *root;
} Trie;

TrieNode *init_trie_node(void)
{
	TrieNode *new_node = (TrieNode *)malloc(sizeof(TrieNode));

	if (new_node == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		new_node->children[i] = NULL;
	}

	new_node->is_end_of_word = false;
	return new_node;
}

Trie *init_trie(void)
{
	Trie *new_trie = (Trie *)malloc(sizeof(Trie));

	if (new_trie == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}

	TrieNode *new_node = init_trie_node();
	new_trie->root = new_node;

	return new_trie;
}

void insert(Trie *trie, const char *word)
{
	TrieNode *currentNode = trie->root;

	for (int i = 0; word[i] != '\0'; i++)
	{
		int character_index = word[i] - 'a';

		if (currentNode->children[character_index] == NULL)
		{
			TrieNode *new_node = init_trie_node();
			if (new_node == NULL)
			{
				printf("Memory allocation failed");
				return;
			}
			currentNode->children[character_index] = new_node;
		}

		currentNode = currentNode->children[character_index];
	}

	currentNode->is_end_of_word = true;
}

bool search_word(Trie *trie, const char *word)
{
	// 1. Start at the root of the Trie.
	TrieNode *currentNode = trie->root;

	// 2. Loop through each character in the word.
	// 2.1. Calculate the index for the character.
	// 2.2. Check if a node for this character exists at the current node's children.
	// 2.2.1. If it doesn't exist, the word isn't in the Trie. Return false.
	// 2.2.2. Move to the child node.

	// 3. After processing the word, check if the current node is marked as an end of a word.
	// 3.1. If it is, return true. Otherwise, return false.
}

// Helper Function for delete: Check if a TrieNode is free (has no children).
bool is_node_free(TrieNode *node)
{
	// 1. Loop through each pointer in the `children` array.
	// 1.1. If any pointer is not NULL, return false.
	// 2. If all pointers are NULL, return true.
}

bool delete_helper(TrieNode *node, const char *word, int depth)
{
	// 1. Base case: If Trie is empty, return false.
	if (node == NULL)
		return false;

	// 2. If the last character of the word is being processed:
	if (depth == strlen(word))
	{
		// 2.1. If the current node is the end of the word, unmark it.
		// 2.2. If the current node doesn't have any children, delete it and return true.
		// 2.3. Otherwise, simply return false.
	}

	// 3. Recursive case:
	// 3.1. Calculate the index for the character.
	// 3.2. Recursively call deleteHelper for the next depth.
	// 3.3. After the recursive call, check if the current node doesn't have any children and is not the end of a word. If so, delete it and return true.
	// 3.4. If the node has children or is an end of another word, return false.
}

bool delete_word(Trie *trie, const char *word)
{
	// 1. If the Trie is empty or the word is empty, return false.

	// 2. Call the recursive deleteHelper function starting with the root, word, and depth 0.
}

int main()
{
	Trie *trie = init_trie();

	// Insert some words
	insert(trie, "apple");
	insert(trie, "app");
	insert(trie, "bat");
	insert(trie, "batman");

	// Search for some words
	printf("Searching 'apple': %s\n", search_word(trie, "apple") ? "Found" : "Not Found");
	printf("Searching 'bat': %s\n", search_word(trie, "bat") ? "Found" : "Not Found");
	printf("Searching 'banana': %s\n", search_word(trie, "banana") ? "Found" : "Not Found");

	// Delete a word and search again
	delete_word(trie, "apple");
	printf("After deleting 'apple'. Searching 'apple': %s\n", search_word(trie, "apple") ? "Found" : "Not Found");
	printf("After deleting 'apple'. Searching 'app': %s\n", search_word(trie, "app") ? "Found" : "Not Found");

	return 0;
}
