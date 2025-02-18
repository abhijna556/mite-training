#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    // Input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate factorial and print the result
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}
