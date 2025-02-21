#include <stdio.h>
#include <string.h>

#define MAX_STOCK 10  


char stock[MAX_STOCK][100];  
int top = -1;  

void add_stock(const char* item) {
    if (top < MAX_STOCK - 1) {
        top++;  
        strcpy(stock[top], item);  
        printf("Stock Added: %s\n", item);
    } else {
        printf("Warehouse is full. Cannot add more stock.\n");
    }
}


void dispatch_item() {
    if (top >= 0) {
        printf("Dispatching Item: %s\n", stock[top]);  
        top--;  
    } else {
        printf("No items to dispatch. Warehouse is empty.\n");
    }
}


void display_remaining_stock() {
    if (top >= 0) {
        printf("Remaining Stock: ");
        for (int i = 0; i <= top; i++) {
            printf("%s", stock[i]);
            if (i < top) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("No remaining stock.\n");
    }
}

int main() {
    
    add_stock("Item A");
    add_stock("Item B");
    add_stock("Item C");

    
    dispatch_item();  

    
    display_remaining_stock();  

    return 0;
}

