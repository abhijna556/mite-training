#include <stdio.h>

// Function to reverse a string using pointers
void reverseString(char *str) {
    char *end = str;
    char temp;

    // Move 'end' pointer to the last character of the string
    while (*end) {
        end++;
    }
    end--; // Move back to the last valid character

    // Swap characters from start and end
    while (str < end) {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main() {
    char str[100];

    // Taking user input
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);

    // Output the reversed string
    printf("Reversed String: %s\n", str);

    return 0;
}
