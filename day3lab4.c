#include <stdio.h>
#include <limits.h>  // For INT_MAX

// Function to find the most frequent element in an array
int mostFrequentElement(int arr[], int n) {
    int freq[1000] = {0}; 
    int maxFreq = 0; 
    int result = INT_MAX;  

   
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > maxFreq || (freq[arr[i]] == maxFreq && arr[i] < result)) {
            maxFreq = freq[arr[i]];
            result = arr[i];
        }
    }

    return result;
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    
    // Input the elements of the array
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and output the most frequent element
    int mostFrequent = mostFrequentElement(arr, n);
    printf("Most Frequent Element: %d\n", mostFrequent);

    return 0;
}
