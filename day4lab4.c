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
};


void appendStudentRecord() {
    FILE *file = fopen("students.txt", "a");  
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student student;

    // Read student details from the user
    printf("Appending student:\n");
    printf("Enter ID, Name (single word), Marks for 3 subjects:\n");
    scanf("%d", &student.ID);
    scanf("%s", student.name);  
    scanf("%d %d %d", &student.marks.subject1, &student.marks.subject2, &student.marks.subject3);

    // Write student details to the file
    fprintf(file, "%d %s %d %d %d\n", student.ID, student.name, student.marks.subject1, student.marks.subject2, student.marks.subject3);

    fclose(file); 
}

// Function to display all student records from the file
void displayStudentRecords() {
    FILE *file = fopen("students.txt", "r");  

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student student;
    printf("Student Records:\n");

   
    while (fscanf(file, "%d %s %d %d %d", &student.ID, student.name, &student.marks.subject1, &student.marks.subject2, &student.marks.subject3) != EOF) {
        printf("%d %s %d %d %d\n", student.ID, student.name, student.marks.subject1, student.marks.subject2, student.marks.subject3);
    }

    fclose(file);  
}

int main() {
    int choice;

    
    printf("1. Append Student Record\n");
    printf("2. Display Student Records\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            appendStudentRecord(); 
            break;
        case 2:
            displayStudentRecords();  
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

