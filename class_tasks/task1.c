/**
* Author:  Joshua Alana
* Date: 1st/10/2024
*/

#include <stdio.h>

int main(){
	// define the array pointer for score and subjects
	char *subjects[] = {"Math", "Programming", "Physics", "English"};
	int scores[] = {12,90,40,100};

	
	// displays the score
	printf("Joshua scored as follows:\n");
	for (int i = 0; i < 4; i++){
	printf("%s: %d\n", subjects[i], scores[i]);	
}
return 0;
}
