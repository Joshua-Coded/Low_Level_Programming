#include <stdio.h>

void print(int nb) {

printf("%d\n", nb);
nb ++;
	if (nb < 10)
{
print(nb);
}
}

int main(void) {
print(4);
return (0);
}



