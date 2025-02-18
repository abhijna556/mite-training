#include <stdio.h>

// Function to calculate final payable amount after discount
float calculateFinalAmount(float billAmount) {
    float discount = 0;

    // Check for discount based on the bill amount
    if (billAmount >= 500 && billAmount <= 1000) {
        discount = 0.10; // 10% discount
    } else if (billAmount > 1000) {
        discount = 0.20; // 20% discount
    } else {
        discount = 0.00; // No discount
    }

    // Calculate final payable amount
    float finalAmount = billAmount - (billAmount * discount);
    return finalAmount;
}

int main() {
    float billAmount;

    // Input total bill amount
    printf("Enter total bill amount: ₹");
    scanf("%f", &billAmount);

    // Calculate final payable amount
    float finalAmount = calculateFinalAmount(billAmount);

    // Output final payable amount
    printf("Final Payable Amount: ₹%.2f\n", finalAmount);

    return 0;
}
