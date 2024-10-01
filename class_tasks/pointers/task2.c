#include <stdio.h>

int main(){
int arr[5] = {1,2,3,4,5};
int *ptr = arr;

// traverse the array using pointer arithmetic
for (int i = 0; i < 5; i++){
	printf("Arr[%d] = %d\n", i, *(ptr + i));
}
return 0;
}
