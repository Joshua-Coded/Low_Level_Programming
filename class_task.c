#include <stdio.h>

// Function declarations
int G(int x);
int H(int x);
int F(int x);

int main()
{
    int x;

    // Prompt the user to enter a value for x
    printf("Enter the value of x: ");
    scanf("%d", &x);

    // Calculate and display the values of the functions
    printf("G(x) = 1000x: G(%d) = %d\n", x, G(x));
    printf("H(x) = 100x + 3: H(%d) = %d\n", x, H(x));
    printf("F(x) = 2x^2 + 4x + 300: F(%d) = %d\n", x, F(x));

    return 0;
}

// Function definitions
int G(int x)
{
    return 1000 * x;
}

int H(int x)
{
    return 100 * x + 3;
}

int F(int x)
{
    return 2 * x * x + 4 * x + 300;
}
