/**
** Author: Joshua Alana
** Date Created: 2/10/2024
** Purpose: Problem 1: Implement a Doubly Linked List
* In this problem, you will implement a doubly linked list using pointers in C. A doubly linked list is a data structure where each node contains data and two pointers: one that points to the next node and one that points to the previous node.

* Requirements:
* Write a program to insert nodes at the beginning and end of the doubly linked list.
* Write a function to traverse and display the list from the beginning.
* Write a function to traverse and display the list from the end.
*/


#include <stdio.h>
#include <stdlib.h>

// our structure for the doubly linked list node

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// function to create a new node

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

// insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data){
	struct Node* newNode = createNode(data);
	if(*head == NULL){
	*head = newNode;
} else {
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
}
}


