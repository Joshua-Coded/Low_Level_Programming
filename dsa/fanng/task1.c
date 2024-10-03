/*
** Author: Joshua Alana
** Date created: 03/10/2024
** purpose: Problem: Design a data structure that follows the LRU (Least Recently Used) cache eviction policy. Implement the LRUCache class with the following methods:

get(key): Return the value of the key if it exists in the cache, otherwise return -1.
put(key, value): Update the value of the key if it exists. If the key doesn't exist, insert the new key-value pair. When the cache reaches its capacity, it should invalidate the least recently used item before inserting a new item.
The cache should operate in O(1) time complexity for both operations.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for Doubly Linked List
struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
};

// Hash map entry (for mapping keys to list nodes)
struct MapEntry {
    int key;
    struct Node* node;
};

// Doubly linked list and hash map structures
struct Node* head = NULL;
struct Node* tail = NULL;
struct MapEntry* hashTable = NULL;
int capacity;
int size = 0;

// Function to create a new doubly linked list node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to remove a node from the doubly linked list
void removeNode(struct Node* node) {
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        head = node->next;  // If node is head

    if (node->next != NULL)
        node->next->prev = node->prev;
    else
        tail = node->prev;  // If node is tail

    free(node);
}

// Function to insert a node at the front of the list (most recent)
void insertAtFront(struct Node* node) {
    node->next = head;
    node->prev = NULL;
    if (head != NULL) 
        head->prev = node;
    
    head = node;
    if (tail == NULL) 
        tail = node;  // In case the list was empty
}

// Function to move a node to the front (used in both get and put)
void moveToFront(struct Node* node) {
    if (node == head) return;
    
    // Remove the node from its current position
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;

    if (node == tail) 
        tail = node->prev;
    
    // Insert it at the front
    insertAtFront(node);
}

// Hash function to map keys to indices
int hashFunc(int key) {
    return key % capacity;
}

// Function to check if a key exists in the hash table
struct Node* getFromHash(int key) {
    int index = hashFunc(key);
    if (hashTable[index].key == key) {
        return hashTable[index].node;
    }
    return NULL;
}

// Function to put a node in the hash table
void putInHash(int key, struct Node* node) {
    int index = hashFunc(key);
    hashTable[index].key = key;
    hashTable[index].node = node;
}

// Get value for a key (move it to front if exists)
int get(int key) {
    struct Node* node = getFromHash(key);
    if (node == NULL) {
        return -1;
    } else {
        moveToFront(node);
        return node->value;
    }
}

// Put key, value into the cache (insert and handle eviction)
void put(int key, int value) {
    struct Node* node = getFromHash(key);
    
    if (node != NULL) {
        // If the key exists, update the value and move to front
        node->value = value;
        moveToFront(node);
    } else {
        // If the key doesn't exist, create a new node
        struct Node* newNode = createNode(key, value);
        
        // If the cache is full, remove the LRU item
        if (size == capacity) {
            int lruKey = tail->key;
            removeNode(tail);
            putInHash(lruKey, NULL);  // Remove from hash map
            size--;
        }

        // Insert the new node at the front
        insertAtFront(newNode);
        putInHash(key, newNode);  // Add to hash map
        size++;
    }
}

int main() {
    // Set cache capacity
    capacity = 3;
    
    // Allocate space for hash table
    hashTable = (struct MapEntry*)calloc(capacity, sizeof(struct MapEntry));
    
    // Put and Get operations
    put(1, 10);  // Insert key 1 with value 10
    put(2, 20);  // Insert key 2 with value 20
    put(3, 30);  // Insert key 3 with value 30
    
    printf("Get(1): %d\n", get(1));  // Access key 1
    put(4, 40);  // Insert key 4 (this will evict key 2 since it's LRU)
    
    printf("Get(2): %d\n", get(2));  // Try accessing evicted key 2
    printf("Get(3): %d\n", get(3));  // Access key 3
    
    return 0;
}

