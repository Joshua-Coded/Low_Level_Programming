#include <stdio.h>

int main(){
	int num = 10;
	int *ptr = &num;


printf("Value of num: %d\n", *ptr);
printf("Address of num: %p\n", ptr);
return 0;
}
