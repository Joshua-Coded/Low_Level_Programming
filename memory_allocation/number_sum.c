#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to hold result statistics
typedef struct {
    unsigned long long sum;
    double time_taken;
    size_t memory_used;
} Result;

// Function to perform addition and track memory usage
Result add_numbers(unsigned long n) {
    Result result = {0, 0, 0};
    clock_t start, end;
    
    // Allocate memory to store numbers
    unsigned long *numbers = (unsigned long*)malloc(n * sizeof(unsigned long));
    if (numbers == NULL) {
        printf("Error: Memory allocation failed!\n");
        return result;
    }

    // Record memory usage
    result.memory_used = n * sizeof(unsigned long);
    printf("\nMemory allocated: %zu bytes\n", result.memory_used);

    // Start timing
    start = clock();

    // Initialize array and calculate sum
    for (unsigned long i = 0; i < n; i++) {
        numbers[i] = i + 1;
        result.sum += numbers[i];
    }

    // End timing
    end = clock();
    result.time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Free memory
    free(numbers);
    printf("Memory freed successfully\n");

    return result;
}

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    unsigned long n;
    char input[100];
    Result result;

    while (1) {
        printf("\n=== Number Addition Program ===\n");
        printf("1. Enter a number to sum up to\n");
        printf("2. Exit\n");
        printf("Choose (1-2): ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            continue;
        }

        // Remove newline if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "2") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        else if (strcmp(input, "1") == 0) {
            printf("\nEnter the number (must be positive): ");
            if (scanf("%lu", &n) != 1 || n <= 0) {
                printf("Invalid input! Please enter a positive number.\n");
                clear_input_buffer();
                continue;
            }
            clear_input_buffer();

            // Perform calculation and get results
            printf("\nCalculating sum of numbers from 1 to %lu...\n", n);
            result = add_numbers(n);

            // Display results
            printf("\n=== Results ===\n");
            printf("Sum: %llu\n", result.sum);
            printf("Time taken: %.6f seconds\n", result.time_taken);
            printf("Operations per second: %.2f\n", (double)n / result.time_taken);
            printf("Memory used: %zu bytes (%.2f MB)\n", 
                   result.memory_used, 
                   (double)result.memory_used / (1024 * 1024));

            // Performance analysis
            if (result.time_taken > 1.0) {
                printf("\nPerformance Note: This calculation took over 1 second.\n");
                printf("Consider using a smaller number for better performance.\n");
            }
        }
        else {
            printf("Invalid choice! Please choose 1 or 2.\n");
        }
    }

    return 0;
}
