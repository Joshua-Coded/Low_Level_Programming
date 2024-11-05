// simple and basic file functions.
// fopen() for opening files
// fclose() for closing files

/******************************
 * Author: Joshua Alana
 * Date Created: 05/11/2024
 * Purpose: To learn how to write into a file

*/

#include <stdio.h>

int main()
{
    FILE *filePtr;
    filePtr = fopen("example1.txt", "w");

    if (filePtr == NULL)
    {
        printf("File could not opened.\n");
        return 1;
    }

    fprintf(filePtr, "Hello Joshua!!! the best kernel engineer in the world!!!!\n");
    fclose(filePtr);
    return 0;
}