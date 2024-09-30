/**
*Author: Joshua Alana
*Purpose: Problem Statement: Given an integer array arr[] of size n, find the largest sum of a contiguous subarray.
*Date Created: 30th/09/2024
*/

#include <stdio.h>
#include <limits.h>

int maxSubArray(int arr[], int n){
	int max_so_far = INT_MIN, max_ending_here = 0;
	
	for (int i = 0; i < n; i++){
	max_ending_here += arr[i];

	if (max_so_far < max_ending_here){
	max_so_far = max_ending_here;
}

if(max_ending_here < 0){
max_ending_here = 0;
}	
}
return max_so_far;
}

int main()
{
int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5,4};
int n = sizeof(arr) / sizeof(arr[0]);

int result = maxSubArray(arr, n);
printf("The largest sum of contiguous subarray is: %d\n", result);
return 0;

}
