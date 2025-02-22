#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int roll_no;
    char name[50];
    int marks;
} Student;


int compare(const void *a, const void *b) {
    return ((Student *)b)->marks - ((Student *)a)->marks; 
}


Student* binary_search(Student students[], int size, int roll_no) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].roll_no == roll_no) {
            return &students[mid]; 
        }
        else if (students[mid].roll_no < roll_no) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return NULL; 
}

int main() {
   
    Student students[] = {
        {101, "Alice", 85},
        {102, "Bob", 90},
        {103, "Charlie", 75}
    };

    int size = sizeof(students) / sizeof(students[0]);

    
    qsort(students, size, sizeof(Student), compare);

    
    printf("Sorted by Marks:\n");
    for (int i = 0; i < size; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }

    
    int roll_no_to_search = 102;
    Student *found_student = binary_search(students, size, roll_no_to_search);

    if (found_student != NULL) {
        printf("\nSearch Roll No %d: Found (%s, Marks: %d)\n", roll_no_to_search, found_student->name, found_student->marks);
    } else {
        printf("\nSearch Roll No %d: Not Found\n", roll_no_to_search);
    }

    
    printf("\nTop 3 Students:\n");
    for (int i = 0; i < 3 && i < size; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }

    return 0;
}
