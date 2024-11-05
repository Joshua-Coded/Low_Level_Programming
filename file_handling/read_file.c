#include <stdio.h>
#include <stdlib.h>

void read_file_with_fgetc(FILE *file) {
    int ch;
    printf("Reading file with fgetc:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);  // Print the character read
    }
}

void read_file_with_fgets(FILE *file) {
    char buffer[256];
    fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
    printf("\nReading file with fgets:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);  // Print the line read
    }
}

void read_file_with_fscanf(FILE *file) {
    char word[256];
    fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
    printf("\nReading file with fscanf:\n");
    while (fscanf(file, "%255s", word) != EOF) {
        printf("%s\n", word);  // Print the word read
    }
}

int main() {
    // Open the file for reading
    FILE *file = fopen("test_file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");  // Print error if file opening fails
        return EXIT_FAILURE;
    }

    // Read the file using different functions
    read_file_with_fgetc(file);
    read_file_with_fgets(file);
    read_file_with_fscanf(file);

    fclose(file); // Close the file
    return EXIT_SUCCESS;
}

