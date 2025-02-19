#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100
#define MAX_NAME_LENGTH 50
#define MAX_DEST_LENGTH 50

// Structure to store passenger details
struct Passenger {
    char name[MAX_NAME_LENGTH];
    int age;
    char destination[MAX_DEST_LENGTH];
};

// Function to add a new passenger
void addPassenger(struct Passenger passengers[], int *n, char name[], int age, char destination[]) {
    strcpy(passengers[*n].name, name);
    passengers[*n].age = age;
    strcpy(passengers[*n].destination, destination);
    (*n)++;
}

// Function to sort passengers by destination 
void sortPassengersByDestination(struct Passenger passengers[], int n) {
    struct Passenger temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(passengers[i].destination, passengers[j].destination) > 0) {
                temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }
}


void searchPassengersByDestination(struct Passenger passengers[], int n, char destination[]) {
    int found = 0;
    printf("Passengers traveling to %s:\n", destination);
    for (int i = 0; i < n; i++) {
        if (strcmp(passengers[i].destination, destination) == 0) {
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found traveling to %s.\n", destination);
    }
}

int main() {
    struct Passenger passengers[MAX_PASSENGERS];
    int n = 0;
    int numPassengers;
    
    // Input number of passengers
    printf("Enter number of passengers: ");
    scanf("%d", &numPassengers);
    getchar(); 
    
    // Add passengers
    for (int i = 0; i < numPassengers; i++) {
        char name[MAX_NAME_LENGTH], destination[MAX_DEST_LENGTH];
        int age;
        
        printf("Passenger %d:\n", i + 1);
        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';  
        
        printf("Age: ");
        scanf("%d", &age);
        getchar();  
        
        printf("Destination: ");
        fgets(destination, sizeof(destination), stdin);
        destination[strcspn(destination, "\n")] = '\0';  
        
        addPassenger(passengers, &n, name, age, destination);
    }
    
    // Sort passengers by destination
    sortPassengersByDestination(passengers, n);
    
    // Display sorted list
    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", passengers[i].name, passengers[i].destination);
    }
    
    
    char searchDest[MAX_DEST_LENGTH];
    printf("\nEnter destination to search: ");
    fgets(searchDest, sizeof(searchDest), stdin);
    searchDest[strcspn(searchDest, "\n")] = '\0';  
    
    searchPassengersByDestination(passengers, n, searchDest);
    
    return 0;
}
