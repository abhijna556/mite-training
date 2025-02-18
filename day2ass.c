#include <stdio.h>
#include <string.h>

void check_eligibility(int age, char pre_existing_condition[], int salary) {
    // Check if age is between 18 and 60
    if (age >= 18 && age <= 60) {
        // Check if there's no pre-existing condition
        if (strcmp(pre_existing_condition, "no") == 0) {
            // Check if monthly salary is ₹25,000 or more
            if (salary >= 25000) {
                printf("Eligible for Medical Insurance\n");
            } else {
                printf("Not Eligible for Medical Insurance (Salary too low)\n");
            }
        } else {
            printf("Not Eligible for Medical Insurance (Pre-existing condition)\n");
        }
    } else {
        printf("Not Eligible for Medical Insurance (Age out of range)\n");
    }
}

int main() {
    int age, salary;
    char pre_existing_condition[4]; // "yes" or "no"
    
    // Taking inputs from the user
    printf("Enter Age: ");
    scanf("%d", &age);
    
    printf("Any Pre-existing Condition? (yes/no): ");
    scanf("%s", pre_existing_condition);
    
    printf("Enter Monthly Salary: ");
    scanf("%d", &salary);
    
    // Check eligibility
    check_eligibility(age, pre_existing_condition, salary);
    
    return 0;
}
