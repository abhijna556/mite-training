#include <stdio.h>

// Function to handle ATM transactions
void atmTransaction(int choice, float *balance) {
    float amount;
    switch (choice) {
        case 1: // Withdraw Money
            printf("Enter Amount: ");
            scanf("%f", &amount);
            if (amount > *balance) {
                printf("Insufficient Balance!\n");
            } else {
                *balance -= amount;
                printf("Transaction Successful. Remaining Balance: ₹%.2f\n", *balance);
            }
            break;
        
        case 2: // Deposit Money
            printf("Enter Amount: ");
            scanf("%f", &amount);
            if (amount > 0) {
                *balance += amount;
                printf("Transaction Successful. Updated Balance: ₹%.2f\n", *balance);
            } else {
                printf("Invalid Amount!\n");
            }
            break;
        
        case 3: // Check Balance
            printf("Current Balance: ₹%.2f\n", *balance);
            break;
        
        default:
            printf("Invalid Choice! Please try again.\n");
    }
}

int main() {
    float balance = 10000.0; // Initial balance
    int choice;
    
    printf("ATM Transaction System\n");
    printf("1. Withdraw Money\n2. Deposit Money\n3. Check Balance\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    atmTransaction(choice, &balance);
    
    return 0;
}
