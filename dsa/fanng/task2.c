/**
** Author: Joshua Alana
** Date Created: 06/10/2024
** Purpose: Trapping Rain Water
** Problem: Given n non-negative integers representing an elevation map where the width of each** bar is 1, compute how much water it can trap after raining.
**/

#include <stdio.h>

// function too compute the trapped rainwater using 2 pointers

int trap(int* height, int n) {
	if (n ==0) return 0;  // if there are no bars, no water is trapped
	
	int left = 0, right = n -1;
	int left_max = 0, right_max = 0;
	int water_trapped = 0;


	// Loop untill the left and right pointers meet
	
	while (left <= right) {
	      if(height[left] < height[right]) {
		 if (height[left] >= left_max) {
		    // update left_max if neccessary
			left_max = height[left];		 
		  } else {
			water_trapped += left_max - height[left];
		  }
		left++;	   
	} else {
	   if (height[right] >= right_max) {
		// update right_max if neccessary
		right_max = height[right];
	} else {
		water_trapped += right_max - height[right];
} right--;
	
}
}

return water_trapped;
}

int main() {
// example input

int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
int n = sizeof(height) / sizeof(height[0]);

int result = trap(height, n);
printf("Trapped rainwater : %d\n", result);
return 0;
}




