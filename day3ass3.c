#include <stdio.h>

int main() {
    int scores[100], numMatches;
    int highest, lowest;
    float average, sum = 0;

    // Input number of matches
    printf("Enter number of matches: ");
    scanf("%d", &numMatches);

    // Input scores for the matches
    printf("Enter scores of %d matches: ", numMatches);
    for (int i = 0; i < numMatches; i++) {
        scanf("%d", &scores[i]);
        sum += scores[i]; // Calculate sum of scores
    }

    // Initialize highest and lowest to the first score
    highest = scores[0];
    lowest = scores[0];

    // Find the highest and lowest score
    for (int i = 1; i < numMatches; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    // Calculate the average score
    average = sum / numMatches;

    // Output the results
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);

    return 0;
}
