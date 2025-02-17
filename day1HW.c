#include <stdio.h>
#include <string.h>

int main() {
    int num_students;

   
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    int marks[num_students];
    char grades[num_students][10];
    
    printf("Enter marks: ");
    for (int i = 0; i < num_students; i++) {
        scanf("%d", &marks[i]);

        
        if (marks[i] >= 90 && marks[i] <= 100) {
            strcpy(grades[i], "Grade A");
        } else if (marks[i] >= 80 && marks[i] <= 89) {
            strcpy(grades[i], "Grade B");
        } else if (marks[i] >= 70 && marks[i] <= 79) {
            strcpy(grades[i], "Grade C");
        } else if (marks[i] >= 60 && marks[i] <= 69) {
            strcpy(grades[i], "Grade D");
        } else {
            strcpy(grades[i], "Grade F");
        }
    }

   
    printf("\nOutput:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: %s\n", i + 1, grades[i]);
    }

    return 0;
}

