#include <stdio.h>
#include <string.h>
#include "medicine.h"

// Display all medicines in the inventory
void printAllMedicines(Medicine *list, int size) {
    if (size == 0) {
        printf("Medicine Inventory System!\n");
        return;
    }

    
    // Create a separator line for table formatting
    const char *separator = "====================================================================================================================================================================\n";

    // Print the top border of the table
    printf("\n%s", separator);

    printf("| %-8s | %-20s | %-10s | %-30s | %-18s | %-15s | %-12s | %-8s | %-15s |\n",
           "ID", "Medicine Name", "Price", "Ingredients", "Pack Size", "Category", "Expiry Date", "Stock", "Dosage");


    // Print separator below the header
    printf("%s", separator);


    for (int i = 0; i < size; i++) {
        printf("| %-8s | %-20s | %-10.0f | %-30s | %-18s | %-15s | %-12s | %-8d | %-15s |\n",
               list[i].id,
               list[i].name,
               list[i].price,
               list[i].ingredients,
               list[i].packaging,
               list[i].category,
               list[i].expiry,
               list[i].quantity,
               list[i].dosage);
    }

    printf("%s", separator);
}
