/**
** Author: Joshua Alana
** Date Created: 07/10/2024
** Purpose: Factorial of a Number
** Problem Statement: Write a recursive function to compute the factorial of a number n.
** The factorial of a non-negative integer n is the product of all positive integers less than or equal to n.

**/

#include <stdio.h>

// Recursive function to compute factorial
int factorial(int n) {
	
// base case: if n == 0, or == 1 return 1;
	if (n == 0 || n == 1) {
		return 1;
	}	

	// recursive case: if n > 1, n * factorial(n -1)
	return n * factorial(n - 1);
}

int main() {
	int num;
	printf("Enter the number to compute: ");
	scanf("%d", &num);

	// handle negative number
	if( num < 0 ) {
	printf("There is no negative numbers for factorial: \n");
} else {
	printf("Factorial of %d is: %d\n", num, factorial(num));
}

return 0;
	
}

