/**
** Author: Joshua Alana
** Date Created: 08/10/2024
** Purpose: Reversing a Series of Numbers
**/

#include <stdio.h>

#define N 10

int main() {
	int a[N], *p;

	printf("Enter %d numbers: ", N);
	for (p = a; p < a + N; p++)
		scanf("%d", p);
	
	printf("In reverse Order: ");
	for (p = a + N - 1; p >= a; p--)
		printf("%d", *p);
	printf("\n");

	return 0;
}
