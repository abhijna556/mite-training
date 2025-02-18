#include <stdio.h>
#include <stdlib.h>

// Structure to store student details
typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int n, i;
    Student *students;

    // Taking input for number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Allocating memory dynamically
    students = (Student *)malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input student details
    for (i = 0; i < n; i++) {
        printf("Enter Student %d Name: ", i + 1);
        scanf(" %[^\n]", students[i].name); // To read full name with spaces
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Displaying student records
    printf("\nStudent Records:\n");
    for (i = 0; i < n; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    // Freeing allocated memory
    free(students);

    return 0;
}
