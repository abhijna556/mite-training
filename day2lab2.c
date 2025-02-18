#include <stdio.h>

// Recursive function to calculate factorial
long factorial(int n) {
    if (n == 0 || n == 1) // Base case
        return 1;
    else
        return n * factorial(n - 1); // Recursive case
}

int main() {
    int num;
    
    // Taking user input
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %ld\n", num, factorial(num));
    }

    return 0;
}
