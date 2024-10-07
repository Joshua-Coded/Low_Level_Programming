/**
** Author: Joshua Alana
** Date Created: 07/10/2024
** Purpose:  Recursive Binary Search
** Problem Statement: Implement binary search using recursion to find a target value in a sorted array.
**/

#include <stdio.h>

// Recursive function to perform binary search

int binary_search(int arr[], int target, int left, int right) {
	// base case: if the target is invalid, the target is not found

	if (left > right) {
		return -1;
}

	int mid = left + (right - left) / 2; // calclate the middle index
	
	// if the target is found at the mid index
	
	if (arr[mid] == target) {
	 return mid;
}

	// if the target is smaller than the middle element, search the left half
	
	if (target < arr[mid]) {
		return binary_search(arr, target, left, mid - 1);
}

	// otherwise search the right half
	return binary_search(arr, target, mid + 1, right);
}

int main() {
	int arr[] = {1,3,5,3,65,4,9,56,87,45,34,64,23};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target;

	printf("Enter the target value to search for: ");
	scanf("%d", &target);

	int result = binary_search(arr, target, 0, n - 1);
	
	if (result != -1) {
		printf("Target %d found at index %d.\n", target, result);
} else {
	printf("Target %d not founf in the array.\n", target);

}
return 0;
}
