/**
** Author: Joshua Alana
** Date Created: 07/10/20204
** Purpose:  A program that finds the largest and smallest number in an array and print them
**/

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main() {
	int b[N], i, big, small;
	
	printf("Enter %d numbers: ", N);
	for ( i = 0; i < N; i++)
	    scanf("%d", &b[i]);
	
	max_min(b, N, &big, &small);

	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);

	return 0;
}

void max_min(int a[], int n, int *max, int *min) {
	int i;
	*max = *min = a[0];
	for (int i = 1; i < n; i++) {
	if (a[i] > *max)
		*max = a[i];
	
	else if (a[i] < *min)
		*min = a[i];
}
}
