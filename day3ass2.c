#include <stdio.h>
#include <string.h>

// Function to count occurrences of a pattern in the DNA sequence
int countPatternOccurrences(char *dnaSequence, char *pattern) {
    int count = 0;
    char *ptr = dnaSequence;

    
    while ((ptr = strstr(ptr, pattern)) != NULL) {
        count++;
        ptr++;
    }

    return count;
}

int main() {
    char dnaSequence[1000], pattern[100];

    // Input the DNA sequence
    printf("Enter DNA Sequence: ");
    fgets(dnaSequence, sizeof(dnaSequence), stdin);
    dnaSequence[strcspn(dnaSequence, "\n")] = '\0';  

    // Input the pattern to search for
    printf("Enter pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';  

    // Count occurrences of the pattern in the DNA sequence
    int count = countPatternOccurrences(dnaSequence, pattern);

    // Output the result
    printf("Pattern found %d time(s) in the DNA sequence.\n", count);

    return 0;
}
