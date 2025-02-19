#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome (ignoring case and spaces)
int isPalindrome(char str[]) {
    int start = 0, end = strlen(str) - 1;

    // Remove spaces and compare characters ignoring case
    while (start < end) {
        // Move start forward to the next non-space character
        if (isspace(str[start])) {
            start++;
        }
        // Move end backward to the previous non-space character
        else if (isspace(str[end])) {
            end--;
        }
        // Compare characters, ignoring case
        else if (tolower(str[start]) != tolower(str[end])) {
            return 0;  // Not a palindrome
        } else {
            start++;
            end--;
        }
    }

    return 1;  // It's a palindrome
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove the newline character from input

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}
