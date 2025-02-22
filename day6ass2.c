#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[50];
    int price;
} Product;


int compare(const void *a, const void *b) {
    return ((Product *)a)->price - ((Product *)b)->price; 
}


Product* binary_search(Product products[], int size, const char *name) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(products[mid].name, name);
        if (comparison == 0) {
            return &products[mid]; 
        }
        else if (comparison < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return NULL; 
}

int main() {
    
    Product products[] = {
        {"Laptop", 50000},
        {"Mobile", 20000},
        {"Headphones", 5000}
    };

    int size = sizeof(products) / sizeof(products[0]);

    
    qsort(products, size, sizeof(Product), compare);

   
    printf("Sorted by Price:\n");
    for (int i = 0; i < size; i++) {
        printf("%s (%d)\n", products[i].name, products[i].price);
    }

    
    const char *product_to_search = "Mobile";
    Product *found_product = binary_search(products, size, product_to_search);

    if (found_product != NULL) {
        printf("\nSearch '%s': Found (Price: %d)\n", product_to_search, found_product->price);
    } else {
        printf("\nSearch '%s': Not Found\n", product_to_search);
    }

    
    printf("\nCheapest Product: %s (%d)\n", products[0].name, products[0].price);
    printf("Most Expensive Product: %s (%d)\n", products[size - 1].name, products[size - 1].price);

    return 0;
}
