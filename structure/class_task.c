#include <stdio.h>
#include <string.h>

// A structure definition
struct Student
{
    char name[50];
    char email[50];
    float grade;
};

// Function to calculate average grade
float calculateAverage(struct Student students[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += students[i].grade;
    }
    return sum / size;
}

int main()
{
    // Initialize an array of 5 students with data
    struct Student students[5];

    // Initialize each student's data
    strncpy(students[0].name, "Alice Johnson", sizeof(students[0].name) - 1);
    strncpy(students[0].email, "alice@example.com", sizeof(students[0].email) - 1);
    students[0].grade = 85.5;

    strncpy(students[1].name, "Bob Smith", sizeof(students[1].name) - 1);
    strncpy(students[1].email, "bob@example.com", sizeof(students[1].email) - 1);
    students[1].grade = 90.0;

    strncpy(students[2].name, "Cathy Brown", sizeof(students[2].name) - 1);
    strncpy(students[2].email, "cathy@example.com", sizeof(students[2].email) - 1);
    students[2].grade = 78.3;

    strncpy(students[3].name, "David Wilson", sizeof(students[3].name) - 1);
    strncpy(students[3].email, "david@example.com", sizeof(students[3].email) - 1);
    students[3].grade = 92.7;

    strncpy(students[4].name, "Eva Clark", sizeof(students[4].name) - 1);
    strncpy(students[4].email, "eva@example.com", sizeof(students[4].email) - 1);
    students[4].grade = 88.9;

    // Calculate and display average
    float average = calculateAverage(students, 5);
    printf("\nClass Average: %.2f\n", average);

    return 0;
}
