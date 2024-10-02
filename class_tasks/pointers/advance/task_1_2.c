/**
** Author: Joshua Alana
** Date created: 2/10/2024
** Purpose: Create a program that manages a list of students using an array of structures. Each** student has a name and a grade.
** Use pointers to dynamically allocate memory for the array of structures, accept user input, ** and print the list of students.
*/

#include <stdio.h>
#include <stdlib.h>

struct Student {
	char name[50];
	float grade;
};

int main(){
	int n;

	printf("Enter number of students: ");
	scanf("%d", &n);
	getchar();

	// dynamically allocate memory for an array of n students
	
	struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
	
	if (students == NULL){
	printf("Memory Allocation failed\n");
	return 1;
	}	

	// accept input for each student
	
	for (int i = 0; i < n; i++){
	printf("Enter name of student %d: ", i + 1);
	fgets(students[i].name, sizeof(students[i].name), stdin);

	printf("Enter grade of student %d: ", i + 1);
	scanf("%f", &students[i].grade);
	getchar();
	
}

	// print lists of students
	printf("\nStudent List:\n");
	for (int i = 0; i < n; i++){
	printf("Name: %s", students[i].name);
	printf("Grade: %.2f\n", students[i].grade);
}

	// free the memory
	free(students);
	return 0;
	
}
