#include <stdio.h>
#include <string.h>


struct Employee {
    int emp_id;
    char name[100];
    float basic_salary;
    float allowances;
    float gross_salary;
};

// Function to compute Gross Salary
void compute_gross_salary(struct Employee *emp) {
    emp->gross_salary = emp->basic_salary + emp->allowances;
}

// Function to save payroll data to a file
void save_to_file(struct Employee *employees, int count) {
    FILE *file = fopen("payroll.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f,%.2f,%.2f\n", employees[i].emp_id, employees[i].name,
                employees[i].basic_salary, employees[i].allowances, employees[i].gross_salary);
    }
    fclose(file);
    printf("Record saved in \"payroll.txt\"\n");
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Enter Emp ID: ");
        scanf("%d", &employees[i].emp_id);
        getchar();  
        printf("Enter Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';  // Remove newline
        printf("Enter Basic Salary: ₹");
        scanf("%f", &employees[i].basic_salary);
        printf("Enter Allowances: ₹");
        scanf("%f", &employees[i].allowances);

        // Compute Gross Salary
        compute_gross_salary(&employees[i]);
    }

    // Input to search employee's salary
    int search_id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    // Search for employee and display salary info
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].emp_id == search_id) {
            printf("\nEmployee: %s\n", employees[i].name);
            printf("Gross Salary: ₹%.2f\n", employees[i].gross_salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee ID not found!\n");
    }

    // Save payroll data to file
    save_to_file(employees, n);

    return 0;
}
