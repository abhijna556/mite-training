#include <stdio.h>
#include <stdlib.h>

// Structure to store student details
typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation for students
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("Enter Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Display student records
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    // Free allocated memory
    free(students);
    return 0;
}
