#include <stdio.h>

int calculate_toll_tax(char vehicle_type) {
    int toll = 0;

   
    switch (vehicle_type) {
        case 'C': // Car
            toll = 50;
            break;
        case 'T': // Truck
            toll = 100;
            break;
        case 'B': // Bike
            toll = 20;
            break;
        case 'U': // Bus
            toll = 80;
            break;
        default:
            printf("Invalid vehicle type\n");
            return 0; // Return 0 if an invalid vehicle type is entered
    }

    return toll;
}

int main() {
    int n, total_toll_tax = 0;
    char vehicle_type;

   
    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    printf("Enter vehicle types (Car = C, Truck = T, Bike = B, Bus = U):\n");

    // Loop for each vehicle
    for (int i = 0; i < n; i++) {
        printf("Enter vehicle type for vehicle %d: ", i + 1);
        scanf(" %c", &vehicle_type); // Space before %c to handle newline character

        // Calculate toll tax for the given vehicle type
        total_toll_tax += calculate_toll_tax(vehicle_type);
    }

    // Display total toll tax
    printf("Total Toll Tax: ₹%d\n", total_toll_tax);

    return 0;
}
