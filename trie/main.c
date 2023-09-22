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
	TrieNode *currentNode = trie->root;

	for (int i = 0; word[i] != '\0'; i++)
	{
		int character_index = word[i] - 'a';

		if (currentNode->children[character_index] == NULL)
		{
			return false;
		}

		currentNode = currentNode->children[character_index];
	}

	return currentNode->is_end_of_word ? true : false;
}

bool is_node_free(TrieNode *node)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL)
		{
			return false;
		}
	}

	return true;
}

bool delete_helper(TrieNode *node, const char *word, int depth)
{
	if (node == NULL)
		return false;

	// Check if we've reached the end of the word we want to delete.
	if (depth == strlen(word))
	{
		node->is_end_of_word = false;

		// We can only delete if no children are present that needs this node
		if (is_node_free(node))
		{
			free(node);
			return true;
		}

		return false;
	}

	int character_index = word[depth] - 'a';
	// Recursively check the word
	delete_helper(node->children[character_index], word, depth + 1);

	// no children and not end of word then we can delete, if its end of word, means its a prefix of another word
	if (is_node_free(node) && !node->is_end_of_word)
	{
		free(node);
		node = NULL;
		return true;
	}

	return false;
}

bool delete_word(Trie *trie, const char *word)
{
	// If the Trie's root is empty or the word is empty, deletion is not possible.
	if (trie->root == NULL || word == NULL || strlen(word) == 0)
	{
		return false;
	}

	bool result = delete_helper(trie->root, word, 0);
	// The result of delete_helper will determine if the root node of the Trie should be deleted or not.
	if (result)
	{
		free(trie->root);
		trie->root = NULL;
	}
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
