/**
** Author: Joshua Alana
** Date Created: 06/10/2024
** Purpose:  Implementing Custom malloc and free in C
** Problem: Implement a simplified version of malloc and free functions to dynamically allocate ** and deallocate memory.
** You will manage memory using a pre-allocated buffer and handle allocation, deallocation, and**  memory fragmentation.
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MEMORY_POOL_SIZE 5000  // Memory pool size

// Record structure (each record has a key, value, and pointer to the next record)
typedef struct Record {
    char* key;            // Pointer to the key string
    char* value;          // Pointer to the value string
    struct Record* next;  // Pointer to the next record in the database
} Record;

// Block structure to manage memory in our custom allocator
typedef struct Block {
    size_t size;           // Size of the block
    int free;              // Is the block free (1) or allocated (0)?
    struct Block* next;    // Pointer to the next block in memory
} Block;

#define BLOCK_SIZE sizeof(Block)

// Global memory pool and free list
char memory_pool[MEMORY_POOL_SIZE];  // Pre-allocated memory pool
Block* free_list = (Block*)memory_pool;  // Pointer to the first free block

// Initialize the memory pool
void initialize_memory_pool() {
    free_list->size = MEMORY_POOL_SIZE - BLOCK_SIZE;
    free_list->free = 1;
    free_list->next = NULL;
}

// Custom malloc function
void* my_malloc(size_t size) {
    Block* current = free_list;
    while (current != NULL) {
        if (current->free && current->size >= size) {
            if (current->size > size + BLOCK_SIZE) {
                Block* new_block = (Block*)((char*)current + BLOCK_SIZE + size);
                new_block->size = current->size - size - BLOCK_SIZE;
                new_block->free = 1;
                new_block->next = current->next;
                current->next = new_block;
                current->size = size;
            }
            current->free = 0;
            return (char*)current + BLOCK_SIZE;
        }
        current = current->next;
    }
    return NULL;
}

// Custom free function
void my_free(void* ptr) {
    if (ptr == NULL) return;
    Block* current = (Block*)((char*)ptr - BLOCK_SIZE);
    current->free = 1;
    if (current->next != NULL && current->next->free) {
        current->size += BLOCK_SIZE + current->next->size;
        current->next = current->next->next;
    }
}

// Record head pointer (our database)
Record* db = NULL;  // Head of the record list (our "database")

// Function to add a record to the database
void add_record(const char* key, const char* value) {
    Record* new_record = (Record*)my_malloc(sizeof(Record));
    if (!new_record) {
        printf("Memory allocation failed for record\n");
        return;
    }

    new_record->key = (char*)my_malloc(strlen(key) + 1);
    new_record->value = (char*)my_malloc(strlen(value) + 1);

    if (!new_record->key || !new_record->value) {
        printf("Memory allocation failed for key or value\n");
        return;
    }

    strcpy(new_record->key, key);
    strcpy(new_record->value, value);

    new_record->next = db;
    db = new_record;

    printf("Added record: {Key: %s, Value: %s}\n", key, value);
}

// Function to get the value for a given key
char* get_record(const char* key) {
    Record* current = db;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;  // Key not found
}

// Function to delete a record from the database
void delete_record(const char* key) {
    Record* current = db;
    Record* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                db = current->next;  // Remove from head of the list
            } else {
                prev->next = current->next;
            }

            my_free(current->key);  // Free the key
            my_free(current->value);  // Free the value
            my_free(current);  // Free the record itself

            printf("Deleted record with key: %s\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Record with key %s not found.\n", key);
}

// Function to display all records
void display_all_records() {
    Record* current = db;
    if (current == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nAll Records:\n");
    while (current != NULL) {
        printf("{Key: %s, Value: %s}\n", current->key, current->value);
        current = current->next;
    }
    printf("\n");
}

// Interactive menu-driven system
void interactive_menu() {
    int choice;
    char key[100], value[100];
    
    while (1) {
        printf("\n--- Simple Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Get Record\n");
        printf("3. Delete Record\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character
        
        switch (choice) {
            case 1:  // Add Record
                printf("Enter key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;  // Remove newline character
                printf("Enter value: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0;  // Remove newline character
                add_record(key, value);
                break;

            case 2:  // Get Record
                printf("Enter key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                char* val = get_record(key);
                if (val) {
                    printf("Retrieved record: {Key: %s, Value: %s}\n", key, val);
                } else {
                    printf("Record not found for key: %s\n", key);
                }
                break;

            case 3:  // Delete Record
                printf("Enter key to delete: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                delete_record(key);
                break;

            case 4:  // Display All Records
                display_all_records();
                break;

            case 5:  // Exit
                printf("Exiting program.\n");
                return;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Main function
int main() {
    initialize_memory_pool();  // Initialize memory pool
    interactive_menu();  // Start the interactive menu
    return 0;
}


