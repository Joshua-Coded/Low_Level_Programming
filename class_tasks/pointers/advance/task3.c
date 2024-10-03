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

// insert node at the end of the doubly linked list.

void insertAtEnd(struct Node** head, int data){
	struct Node* newNode = createNode(data);
	if(*head == NULL){
	*head = newNode;
} else {
	struct Node* temp = *head;
	while (temp->next != NULL){
	temp = temp->next;
}

	temp->next = newNode;
	newNode->prev = temp;
}
}


// function to traverse and display the list from the beginning
void displayFromBeginning(struct Node* head){
	struct Node* temp = head;
	printf("Doubly Linked List (beginning to end): ");
	while (temp != NULL){
	printf("%d ", temp->data);
	temp = temp->next;
	}
	printf("\n");
}

//function to traverse and display the list from the end

void displayFromEnd(struct Node* head){
	struct Node* temp = head;
	if(temp == NULL){
	return;
}

// go to the last node
	while (temp->next != NULL){
	temp = temp->next;
}

printf("Doubly Linked list (end to beginning): ");

// traverse backward using prev pointer

while(temp != NULL){
	printf("%d ", temp->data);
	temp = temp->prev;
}
printf("\n");

}


int main(){
	struct Node* head = NULL;

// insert elements in the list
insertAtBeginning(&head, 10);
insertAtBeginning(&head, 20);
insertAtEnd(&head, 30);
insertAtEnd(&head, 50);

// display the list from beginning and end
displayFromBeginning(head);
displayFromEnd(head);

return 0;

}
