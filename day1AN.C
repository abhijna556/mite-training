#include <stdio.h>

int main() {
    char customerName[100];
    int customerID;
    int unitsConsumed;
    float baseBill, totalBill, surcharge = 0.0;

    // customer details
    printf("Enter Customer Name: ");
    fgets(customerName, sizeof(customerName), stdin);
   
    printf("Enter Customer ID: ");
    scanf("%d", &customerID);
   
    printf("Enter Total Units Consumed: ");
    scanf("%d", &unitsConsumed);

    // Calculate base bill
    baseBill = 100; // Fixed charge

    if (unitsConsumed <= 100) {
        baseBill += unitsConsumed * 5;
    } else if (unitsConsumed <= 300) {
        baseBill += (100 * 5) + ((unitsConsumed - 100) * 7);
    } else {
        baseBill += (100 * 5) + (200 * 7) + ((unitsConsumed - 300) * 10);
    }

    // Check for surcharge
    if (baseBill > 1000) {
        surcharge = baseBill * 0.05; // 5% surcharge
    }

    // Calculate total bill
    totalBill = baseBill + surcharge;

    // Output results
    printf("\nCustomer Name: %s", customerName);
    printf("Customer ID: %d\n", customerID);
    printf("Units Consumed: %d\n", unitsConsumed);
    printf("Base Bill: ₹%.2f\n", baseBill);
    printf("Surcharge: ₹%.2f\n", surcharge);
    printf("Total Bill: ₹%.2f\n", totalBill);

    return 0;
}
