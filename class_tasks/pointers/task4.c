#include <stdio.h>
#include <stdlib.h>

int main(){

int n;
printf("Enter the number of elements: ");
scanf("%d", &n);

// dynamically allocate memory for n integers
int *arr = (int *) malloc(n * sizeof(int));

if (arr == NULL){
	printf("Memory allocation failed!\n");
	return 1;
}

//Accept input from the user
for (int i = 0; i < n; i++){
	printf("Enter element %d: ", i + 1);
	scanf("%d", &arr[i]);
}

// print the element
printf("yOU ENTERED: ");
for (int i = 0; i < n; i++){
	printf("%d", arr[i]);
}
printf("\n");

free(arr);
return 0;
}
