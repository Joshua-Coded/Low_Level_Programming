/**
 * @file read_from_file.c
 * @author Joshua Alana (alana@tech.com)
 * @brief Learning how to read from a file
 * @version 0.1
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */

// functions to use fscanf(), fgets(), fgetc()

#include <stdio.h>

int main()
{
    FILE *filePtr;
    char buffer[100];

    filePtr = fopen("example1.txt", "r");

    if (filePtr == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }

    while (fgets(buffer, 100, filePtr))
    {
        printf("%s", buffer);
    }

    fclose(filePtr);
    return 0;
}