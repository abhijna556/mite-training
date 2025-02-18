#include <stdio.h>

// Function to calculate final payable amount after discount
float calculateFinalAmount(float billAmount) {
    float discount = 0.0;
    
    if (billAmount >= 500 && billAmount <= 1000) {
        discount = 0.10 * billAmount;
    } else if (billAmount > 1000) {
        discount = 0.20 * billAmount;
    }
    
    return billAmount - discount;
}

int main() {
    float billAmount;
    
    // Taking input from the user
    printf("Enter total bill amount: ₹");
    scanf("%f", &billAmount);
    
    // Calculate final amount
    float finalAmount = calculateFinalAmount(billAmount);
    
    // Determine discount percentage for output message
    int discountPercentage = (billAmount >= 500 && billAmount <= 1000) ? 10 : (billAmount > 1000 ? 20 : 0);
    
    // Display the final payable amount
    printf("Final Payable Amount: ₹%.2f (after %d%% discount)\n", finalAmount, discountPercentage);
    
    return 0;
}
