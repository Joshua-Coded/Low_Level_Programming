#include <stdio.h>
#include <string.h>

#define SIZE 10

// Function to sort names using bubble sort

void bubble_sort_names(char names[SIZE][50]){
    char temp[50];
    for(int i = 0; i < SIZE - 1; i++){
        for (int j = 0; j < SIZE - 1; j++){
            if (strcmp(names[j], names[j+1]) > 0) {
                // swap the names
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }      
        }
    }
}

// function to calculate average age
float average_age(int ages[SIZE]){
    int sum = 0;
    for (int i = 0; i <SIZE; i++) {
        sum += ages[i];
    }
    return (float)sum / SIZE;
}

// FUNCTION TO FIND THE YOUNGEST AGE
