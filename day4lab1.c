#include <stdio.h>


struct Marks {
    int subject1;
    int subject2;
    int subject3;
};


struct Student {
    int ID;
    char name[50];
    struct Marks marks;
    int total;
    float average;
    char grade;
};

// Function to read student details
void readStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d (ID, Name, Marks in 3 subjects):\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].ID);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  // To read string with spaces
        printf("Marks in 3 subjects: ");
        scanf("%d %d %d", &students[i].marks.subject1, &students[i].marks.subject2, &students[i].marks.subject3);
    }
}

// Function to calculate total marks, average, and grade
void calculateGrades(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        students[i].total = students[i].marks.subject1 + students[i].marks.subject2 + students[i].marks.subject3;
        students[i].average = students[i].total / 3.0;

        // Assign grade based on average
        if (students[i].average >= 90) {
            students[i].grade = 'A';
        } else if (students[i].average >= 75) {
            students[i].grade = 'B';
        } else if (students[i].average >= 60) {
            students[i].grade = 'C';
        } else {
            students[i].grade = 'D';
        }
    }
}

// Function to display student details
void displayStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - Total: %d, Average: %.2f, Grade: %c\n", students[i].name, students[i].total, students[i].average, students[i].grade);
    }
}

int main() {
    int n;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    struct Student students[n];  // Array to hold student details
    
    readStudents(students, n);  // Read student details
    calculateGrades(students, n);  // Calculate total, average, and grade
    displayStudents(students, n);  // Display student details
    
    return 0;
}
