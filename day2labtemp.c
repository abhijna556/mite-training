#include <stdio.h>

// Function to convert temperature based on choice
float convertTemperature(float temp, int choice) {
    switch (choice) {
        case 1: // Celsius to Fahrenheit
            return (temp * 9 / 5) + 32;
        case 2: // Fahrenheit to Celsius
            return (temp - 32) * 5 / 9;
        case 3: // Celsius to Kelvin
            return temp + 273.15;
        default:
            return -1; // Invalid choice
    }
}

int main() {
    float temp, result;
    int choice;

    // Taking user input
    printf("Enter Temperature: ");
    scanf("%f", &temp);

    // Display menu options
    printf("Choose Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    // Call the conversion function
    result = convertTemperature(temp, choice);

    // Display the result
    if (result != -1) {
        switch (choice) {
            case 1:
                printf("Temperature in Fahrenheit: %.2f\n", result);
                break;
            case 2:
                printf("Temperature in Celsius: %.2f\n", result);
                break;
            case 3:
                printf("Temperature in Kelvin: %.2f\n", result);
                break;
        }
    } else {
        printf("Invalid choice! Please enter 1, 2, or 3.\n");
    }

    return 0;
}
