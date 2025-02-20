#include <stdio.h>


struct Employee {
    int ID;
    char name[50];
    float salary;
};

// Function to write employee data to a file
void writeToFile(struct Employee emp[], int n) {
    FILE *file = fopen("employees.txt", "w");  // Open the file in write mode
    
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write employee details to the file
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %.2f\n", emp[i].ID, emp[i].name, emp[i].salary);
    }
    
    fclose(file);  // Close the file after writing
}

// Function to read employee data from the file and display it
void readFromFile() {
    FILE *file = fopen("employees.txt", "r");  
    
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    struct Employee emp;
    printf("Employees Data from File:\n");
    
    // Read and display employee data from the file
    while (fscanf(file, "%d %s %f", &emp.ID, emp.name, &emp.salary) != EOF) {
        printf("%d %s %.2f\n", emp.ID, emp.name, emp.salary);
    }
    
    fclose(file);  // Close the file after reading
}

int main() {
    int n;

    // Read number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];  // Array to store employee details

    // Read employee details from the user
    printf("Enter details (ID, Name, Salary):\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].ID);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);  // To read string with spaces
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Write employee data to the file
    writeToFile(emp, n);

    // Read and display employee data from the file
    readFromFile();

    return 0;
}
