#include <stdio.h>
#include <stdlib.h>

struct Person {
char name[50];
int age;
char address[100];
};

int main(){
// dynamically allocate memory for a Person Structure
struct Person *person = (struct Person *)malloc(sizeof(struct Person));

if (person == NULL) {
	printf("Memory Allocation failed!!\n");
	return 1;
}

// ACCEPT INPUT FROM THE USER
printf("Enter name: ");
fgets(person->name, sizeof(person->name), stdin);

printf("Enter age: ");
scanf("%d", &person->age);
getchar();

printf("Enter address: ");
fgets(person->address, sizeof(person->address), stdin);


// print the person's information

printf("\nPerson Information:\n");
printf("Name: %s", person->name);
printf("Age: %d\n", person->age);
printf("Address: %s", person->address);

// free the dynamically allocated memory
free(person);
return 0;




}
