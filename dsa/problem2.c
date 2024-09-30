#include <stdio.h>

/***
 * Author: Joshua Alana
 * Purpose: Problem Statement: Given an array arr[], move all zeroes to the end of the array
 *          while maintaining the relative order of non-zero elements.
 * Date: 30th/09/2024
 */

// Function to move all zeroes to the end of the array
void moveZeroesToEnd(int arr[], int n)
{
    int count = 0;  // Count of non-zero elements
    
    // Traverse the array. If element is non-zero, place it at count and increment count
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];  // Move non-zero element to the left
        }
    }
    
    // Now fill the remaining positions with zeroes
    while (count < n) {
        arr[count++] = 0;
    }
}

int main() {
    // Initialize the array with some elements, including zeroes
    int arr[] = {0, 0, 2, 5, 0, 70, 4, 3, 5, -2, 10};
    
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to move zeroes to the end
    moveZeroesToEnd(arr, n);

    // Print the modified array
    printf("Array after moving zeroes to end: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

