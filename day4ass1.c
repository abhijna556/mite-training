#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
struct Medicine {
    int id;
    char name[100];
    char expiry_date[11];  // Format: YYYY-MM-DD
    float price;
};

// Function to compare medicines by expiry date
int compare_expiry(const void *a, const void *b) {
    return strcmp(((struct Medicine *)a)->expiry_date, ((struct Medicine *)b)->expiry_date);
}

// Function to save medicines to a file
void save_to_file(struct Medicine *medicines, int count) {
    FILE *file = fopen("medicine_inventory.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%.2f\n", medicines[i].id, medicines[i].name, medicines[i].expiry_date, medicines[i].price);
    }
    fclose(file);
    printf("Records saved in \"medicine_inventory.txt\"\n");
}

int main() {
    int n;
    printf("Enter number of medicines: ");
    scanf("%d", &n);

    struct Medicine medicines[n];

    // Input medicine details
    for (int i = 0; i < n; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &medicines[i].id);
        getchar();
        printf("Enter Name: ");
        fgets(medicines[i].name, sizeof(medicines[i].name), stdin);
        medicines[i].name[strcspn(medicines[i].name, "\n")] = '\0';  
        printf("Enter Expiry Date (YYYY-MM-DD): ");
        scanf("%s", medicines[i].expiry_date);
        printf("Enter Price: ");
        scanf("%f", &medicines[i].price);
    }

    // Sort medicines by expiry date
    qsort(medicines, n, sizeof(struct Medicine), compare_expiry);

    // Display sorted medicines
    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, medicines[i].name, medicines[i].expiry_date);
    }

    // Save data to file
    save_to_file(medicines, n);

    return 0;
}
