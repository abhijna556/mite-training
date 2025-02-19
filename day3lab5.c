#include <stdio.h>
#include <string.h>

// Function to find a substring in a given string
int findSubstring(char str[], char sub[]) {
    int n = strlen(str);
    int m = strlen(sub);

    // Check if the substring is longer than the main string
    if (m > n) {
        return -1;
    }

    // Iterate through the main string
    for (int i = 0; i <= n - m; i++) {
        
        int j = 0;
        while (j < m && str[i + j] == sub[j]) {
            j++;
        }

       
        if (j == m) {
            return i;  
        }
    }

    return -1;  
}

int main() {
    char str[100], sub[50];

    // Input the main string
    printf("Enter main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  
   
    printf("Enter substring: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = '\0';  

    
    int index = findSubstring(str, sub);
    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring not found\n");
    }

    return 0;
}
