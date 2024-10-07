/**
** Author: Joshua Alana
** Date Created: 07/10/2024
** Purpose:  Fibonacci Sequence
** Problem Statement: Write a recursive function to compute the nth Fibonacci number.
**/

#include <stdio.h>

// Recursive function to compute fibonacci number

int fibonacci(int n) {
// base cases: f(0) = 0, f(1) = 1

if ( n == 0) {
	return 0;
}	

if (n == 1) {
	return 1;
}

// recursive case: F(n) = F(n-1) + F(n -2)
	return fibonacci(n -1) + fibonacci(n -2);

}

int main() {
	int num;
	printf("Enter the position to get the Fibonacci number: ");
	scanf("%d", &num);

	// handle negative input
	if ( num < 0) {
	printf("Fibonacci sequence is not defined for negative numbers: \n");
} else {
	printf("Fibonacci number at position %d is: %d\n", num, fibonacci(num));
}
 return 0;

}

