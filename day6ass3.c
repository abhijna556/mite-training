#include <stdio.h>


void selection_sort(int distances[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (distances[j] < distances[min_index]) {
                min_index = j;
            }
        }
        
        int temp = distances[min_index];
        distances[min_index] = distances[i];
        distances[i] = temp;
    }
}

int main() {
    
    int ambulance_distances[] = {10, 3, 7, 1, 5};
    int size = sizeof(ambulance_distances) / sizeof(ambulance_distances[0]);

    
    printf("Ambulances (Distance in km): [");
    for (int i = 0; i < size; i++) {
        printf("%d", ambulance_distances[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");

    
    selection_sort(ambulance_distances, size);

    
    printf("Sorted: [");
    for (int i = 0; i < size; i++) {
        printf("%d", ambulance_distances[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");

    
    printf("Nearest Ambulance Assigned: Distance %d km\n", ambulance_distances[0]);

    return 0;
}
