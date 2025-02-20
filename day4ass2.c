#include <stdio.h>
#include <string.h>


struct Car {
    int car_id;
    char model[100];
    union {
        float rent_per_day;
        float total_rent;
    };
    int is_daily_rent; // 1 for daily rent, 0 for total rent
};

// Function to save car data to a file
void save_to_file(struct Car *cars, int count) {
    FILE *file = fopen("car_rentals.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%f,%d\n", cars[i].car_id, cars[i].model, 
                cars[i].is_daily_rent ? cars[i].rent_per_day : cars[i].total_rent, 
                cars[i].is_daily_rent);
    }
    fclose(file);
    printf("Data saved in \"car_rentals.txt\"\n");
}

int main() {
    int n;
    printf("Enter number of cars: ");
    scanf("%d", &n);
    struct Car cars[n];

    // Input car details
    for (int i = 0; i < n; i++) {
        printf("Car %d:\n", i + 1);
        printf("Enter Car ID: ");
        scanf("%d", &cars[i].car_id);
        getchar();  // Consume newline
        printf("Enter Model: ");
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        cars[i].model[strcspn(cars[i].model, "\n")] = '\0';  // Remove newline
        printf("Enter Rent Type (1 for daily, 0 for total): ");
        scanf("%d", &cars[i].is_daily_rent);
        
        if (cars[i].is_daily_rent) {
            printf("Enter Rent Per Day: ₹");
            scanf("%f", &cars[i].rent_per_day);
        } else {
            printf("Enter Total Rent: ₹");
            scanf("%f", &cars[i].total_rent);
        }
    }

    // Display available cars
    printf("\nCars Available:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - ₹", i + 1, cars[i].model);
        if (cars[i].is_daily_rent) {
            printf("%.2f/day\n", cars[i].rent_per_day);
        } else {
            printf("%.2f (Total Rent)\n", cars[i].total_rent);
        }
    }

    // Save data to file
    save_to_file(cars, n);

    return 0;
}
